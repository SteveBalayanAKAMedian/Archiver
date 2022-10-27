#include "Encoder.h"

bool huffman::Encoder::CanCreate(const std::vector<std::string>& filenames) {
    for (const auto& filename : filenames) {
        std::ifstream tmp_ifstream(filename);
        if (!tmp_ifstream.good()) {
            tmp_ifstream.close();
            return false;
        }
        tmp_ifstream.close();
    }
    return true;
}

huffman::Encoder::Encoder(const std::string& address, const std::vector<std::string>& filenames) {
    if (!huffman::Encoder::CanCreate(filenames)) {
        throw std::runtime_error("Something is wrong with files to encode.");
    }
    this->address_ = address;
    std::ofstream* output_stream = new std::ofstream(address, std::ios::binary);
    this->writer_ = new bit_io::BitWriter(*output_stream);
    this->filenames_ = filenames;
}

huffman::Encoder::~Encoder() {
    delete this->writer_;
}

huffman::Letter huffman::Encoder::FromBinaryCodeToLetter(const bit_io::BinaryCode& read_symbol) {
    huffman::Letter symbol = 0;
    for (size_t i = 0; i < read_symbol.size(); ++i) {
        symbol |= ((static_cast<size_t>(read_symbol[i])) << i);
    }
    return symbol;
}

std::unordered_map<huffman::Letter, size_t> huffman::Encoder::CountOccurence(
    bit_io::BitReader* reader, const std::string& filename) {
    std::unordered_map<huffman::Letter, size_t> counter;
    while (!reader->IsEndOfFile()) {
        huffman::Letter symbol = this->FromBinaryCodeToLetter(reader->Get(huffman::BITS_IN_BYTE));
        ++counter[symbol];
    }
    for (auto symbol : filename) {
        ++counter[huffman::Letter(symbol)];
    }
    counter[huffman::FILENAME_END] = counter[huffman::ONE_MORE_FILE] = counter[huffman::ARCHIVE_END] = 1;
    return counter;
}

std::vector<huffman::HuffmanTree::HuffmanCode> huffman::Encoder::BuildHuffmanCodes(
    const std::unordered_map<huffman::Letter, size_t>& counter) {
    PriorityQueue priority_queue;
    for (const auto& key : counter) {
        auto [letter, weight] = key;
        priority_queue.Insert({weight, new huffman::HuffmanTree(letter)});
    }
    while (priority_queue.Size() > 1) {
        auto [left_weight, left_tree] = priority_queue.ExtractRoot();
        auto [right_weight, right_tree] = priority_queue.ExtractRoot();
        priority_queue.Insert({left_weight + right_weight, huffman::HuffmanTree::Merge(left_tree, right_tree)});
    }
    auto tree_root = priority_queue.ExtractRoot().second;
    return tree_root->MakeCodes();
}

bool CompareHuffmanCodes(const huffman::HuffmanTree::HuffmanCode& a, const huffman::HuffmanTree::HuffmanCode& b) {
    if (a.code.size() == b.code.size()) {
        return a.letter.to_ulong() < b.letter.to_ulong();
    }
    return a.code.size() < b.code.size();
}

std::vector<std::pair<huffman::Letter, bit_io::BinaryCode>> huffman::Encoder::MakeCanonHuffmanCodes(
    std::vector<huffman::HuffmanTree::HuffmanCode>& huffman_codes) {
    std::sort(huffman_codes.begin(), huffman_codes.end(), CompareHuffmanCodes);
    std::vector<std::pair<huffman::Letter, bit_io::BinaryCode>> canon_codes(huffman_codes.size());
    canon_codes[0] = {huffman_codes[0].letter, {}};
    for (size_t i = 0; i < huffman_codes[0].code.size(); ++i) {
        canon_codes[0].second.push_back(false);
    }
    for (size_t i = 1; i < huffman_codes.size(); ++i) {
        size_t pos_of_last_zero = canon_codes[i - 1].second.size();
        for (size_t reversed_j = 0; reversed_j < canon_codes[i - 1].second.size(); ++reversed_j) {
            size_t j = canon_codes[i - 1].second.size() - 1 - reversed_j;
            if (!canon_codes[i - 1].second[j]) {
                pos_of_last_zero = j;
                break;
            }
        }
        bit_io::BinaryCode new_canon_code;
        if (pos_of_last_zero == canon_codes[i - 1].second.size()) {
            new_canon_code.push_back(true);
            for (size_t j = 0; j < canon_codes[i - 1].second.size(); ++j) {
                new_canon_code.push_back(false);
            }
        } else {
            for (size_t j = 0; j < canon_codes[i - 1].second.size(); ++j) {
                if (j == pos_of_last_zero) {
                    new_canon_code.push_back(true);
                } else if (j > pos_of_last_zero) {
                    new_canon_code.push_back(false);
                } else {
                    new_canon_code.push_back(canon_codes[i - 1].second[j]);
                }
            }
        }
        while (huffman_codes[i].code.size() > new_canon_code.size()) {
            new_canon_code.push_back(false);
        }
        canon_codes[i] = {huffman_codes[i].letter, new_canon_code};
    }
    return canon_codes;
}

void huffman::Encoder::PrintTableOfHuffmanCoding(
    const std::vector<std::pair<huffman::Letter, bit_io::BinaryCode>>& canon_huffman_codes) {
    size_t symbol_size = 1;
    size_t current_symbol_size = 0;
    for (size_t i = 0; i < canon_huffman_codes.size(); ++i) {
        if (canon_huffman_codes[i].second.size() == symbol_size) {
            ++current_symbol_size;
        } else {
            this->writer_->WriteNineBitNumber(current_symbol_size);
            current_symbol_size = 0;
            ++symbol_size;
            while (canon_huffman_codes[i].second.size() != symbol_size) {
                ++symbol_size;
                this->writer_->WriteNineBitNumber(current_symbol_size);
            }
            ++current_symbol_size;
        }
    }
    this->writer_->WriteNineBitNumber(current_symbol_size);
}

void huffman::Encoder::Archive() {
    for (size_t id_of_file = 0; id_of_file < this->filenames_.size(); ++id_of_file) {
        std::ifstream* input_file_stream = new std::ifstream(filenames_[id_of_file], std::ios::binary);
        bit_io::BitReader* reader = new bit_io::BitReader(*input_file_stream);
        std::unordered_map<huffman::Letter, size_t> counter = this->CountOccurence(
            reader, this->filenames_[id_of_file]);
        std::vector<huffman::HuffmanTree::HuffmanCode> huffman_codes = this->BuildHuffmanCodes(counter);
        std::vector<std::pair<huffman::Letter, bit_io::BinaryCode>> canon_huffman_codes =
            this->MakeCanonHuffmanCodes(huffman_codes);
        std::unordered_map<huffman::Letter, size_t> ids_of_codes;
        for (size_t i = 0; i < canon_huffman_codes.size(); ++i) {
            ids_of_codes[canon_huffman_codes[i].first] = i;
        }
        this->writer_->WriteNineBitNumber(counter.size());
        for (const auto& [letter, binary_code] : canon_huffman_codes) {
            this->writer_->Write(letter);
        }
        this->PrintTableOfHuffmanCoding(canon_huffman_codes);
        for (auto symbol : this->filenames_[id_of_file]) {
            this->writer_->Write(canon_huffman_codes[ids_of_codes[huffman::Letter(symbol)]].second);
        }
        this->writer_->Write(canon_huffman_codes[ids_of_codes[huffman::FILENAME_END]].second);
        delete reader;
        std::ifstream* new_input_file_stream = new std::ifstream(this->filenames_[id_of_file], std::ios::binary);
        reader = new bit_io::BitReader(*new_input_file_stream);
        while (!reader->IsEndOfFile()) {
            huffman::Letter symbol = this->FromBinaryCodeToLetter(
                reader->Get(huffman::BITS_IN_BYTE));
            this->writer_->Write(canon_huffman_codes[ids_of_codes[symbol]].second);
        }
        if (id_of_file != this->filenames_.size() - 1) {
            this->writer_->Write(canon_huffman_codes[ids_of_codes[huffman::ONE_MORE_FILE]].second);
        } else {
            this->writer_->Write(canon_huffman_codes[ids_of_codes[huffman::ARCHIVE_END]].second);
        }
    }
}
