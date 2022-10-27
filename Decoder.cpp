#include "Decoder.h"

huffman::Decoder::Decoder(const std::string& archive_name) {
    std::ifstream* input_file_stream = new std::ifstream(archive_name, std::ios::binary);
    this->input_stream_ = new bit_io::BitReader(*input_file_stream);
}

huffman::Decoder::~Decoder() {
    delete this->input_stream_;
}

size_t huffman::Decoder::FromBinaryCodeToSizeT(const bit_io::BinaryCode& read_symbol) {
    size_t symbol = 0;
    for (size_t i = 0; i < read_symbol.size(); ++i) {
        symbol |= ((static_cast<size_t>(read_symbol[i])) << i);
    }
    return symbol;
}

std::vector<huffman::HuffmanTree::HuffmanCode> huffman::Decoder::MakeCanonHuffmanCodes(
    const std::vector<std::pair<huffman::Letter, size_t>>& huffman_codes) {
    std::vector<huffman::HuffmanTree::HuffmanCode> canon_codes(huffman_codes.size());
    canon_codes[0] = {huffman_codes[0].first, {}};
    for (size_t i = 0; i < huffman_codes[0].second; ++i) {
        canon_codes[0].code.push_back(false);
    }
    for (size_t i = 1; i < huffman_codes.size(); ++i) {
        size_t pos_of_last_zero = canon_codes[i - 1].code.size();
        for (size_t reversed_j = 0; reversed_j < canon_codes[i - 1].code.size(); ++reversed_j) {
            size_t j = canon_codes[i - 1].code.size() - 1 - reversed_j;
            if (!canon_codes[i - 1].code[j]) {
                pos_of_last_zero = j;
                break;
            }
        }
        bit_io::BinaryCode new_canon_code;
        if (pos_of_last_zero == canon_codes[i - 1].code.size()) {
            new_canon_code.push_back(true);
            for (size_t j = 0; j < canon_codes[i - 1].code.size(); ++j) {
                new_canon_code.push_back(false);
            }
        } else {
            for (size_t j = 0; j < canon_codes[i - 1].code.size(); ++j) {
                if (j == pos_of_last_zero) {
                    new_canon_code.push_back(true);
                } else if (j > pos_of_last_zero) {
                    new_canon_code.push_back(false);
                } else {
                    new_canon_code.push_back(canon_codes[i - 1].code[j]);
                }
            }
        }
        while (huffman_codes[i].second > new_canon_code.size()) {
            new_canon_code.push_back(false);
        }
        canon_codes[i] = {huffman_codes[i].first, new_canon_code};
    }
    return canon_codes;
}

void huffman::Decoder::Decode() {
    bool is_finished_decoding = false;
    while (!is_finished_decoding) {
        size_t symbols_count = this->FromBinaryCodeToSizeT(this->input_stream_->Get(huffman::LETTER_SIZE));
        std::vector<huffman::Letter> letters(symbols_count);
        for (size_t i = 0; i < symbols_count; ++i) {
            letters[i] = this->FromBinaryCodeToSizeT(this->input_stream_->Get(huffman::LETTER_SIZE));
        }
        size_t number_of_current_used_symbols = this->FromBinaryCodeToSizeT(
            this->input_stream_->Get(huffman::LETTER_SIZE));
        size_t number_of_used_symbols = number_of_current_used_symbols;
        size_t cur_length = 1;
        size_t letter_id = 0;
        std::vector<std::pair<huffman::Letter, size_t>> code_lengths;
        code_lengths.reserve(symbols_count);
        while (number_of_used_symbols != symbols_count) {
            for (size_t i = 0; i < number_of_current_used_symbols; ++i) {
                code_lengths.push_back({letters[letter_id], cur_length});
                ++letter_id;
            }
            ++cur_length;
            number_of_current_used_symbols = this->FromBinaryCodeToSizeT(
                this->input_stream_->Get(huffman::LETTER_SIZE));
            number_of_used_symbols += number_of_current_used_symbols;
        }
        for (size_t i = 0; i < number_of_current_used_symbols; ++i) {
            code_lengths.push_back({letters[letter_id], cur_length});
            ++letter_id;
        }
        std::vector<huffman::HuffmanTree::HuffmanCode> canon_codes = MakeCanonHuffmanCodes(code_lengths);
        auto huffman_tree = new huffman::HuffmanTree(canon_codes);
        huffman::Letter cur_letter = huffman_tree->DecodeWithTree(this->input_stream_);
        std::string filename;
        while (cur_letter != huffman::FILENAME_END) {
            size_t cur = 0;
            for (size_t i = 0; i < huffman::LETTER_SIZE; ++i) {
                cur |= (cur_letter[i] << i);
            }
            filename += static_cast<char>(cur);
            cur_letter = huffman_tree->DecodeWithTree(this->input_stream_);
        }
        std::ofstream* output_file_stream = new std::ofstream(filename, std::ios::binary);
        bit_io::BitWriter* writer = new bit_io::BitWriter(*output_file_stream);
        cur_letter = huffman_tree->DecodeWithTree(this->input_stream_);
        while (cur_letter != huffman::ONE_MORE_FILE && cur_letter != huffman::ARCHIVE_END) {
            for (size_t i = 0; i < huffman::BITS_IN_BYTE; ++i) {
                writer->WriteOneBit(cur_letter[i]);
            }
            cur_letter = huffman_tree->DecodeWithTree(this->input_stream_);
        }
        delete writer;
        if (cur_letter == huffman::ARCHIVE_END) {
            is_finished_decoding = true;
        }
    }
}