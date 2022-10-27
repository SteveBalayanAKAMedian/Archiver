#include "BitIO.h"

bit_io::BitReader::BitReader(std::istream& input_stream) {
    this->input_stream_ = std::move(&input_stream);
    this->buffer_ = bit_io::BinaryCode(bit_io::BUFFER_SIZE);
    this->buffer_it_ = this->buffer_.end();
}

bool bit_io::BitReader::GetOneBit() {
    if (this->buffer_it_ == this->buffer_.end()) {
        char read_byte;
        this->input_stream_->get(read_byte);
        for (size_t i = 0; i < bit_io::BUFFER_SIZE; ++i) {
            this->buffer_[i] = (read_byte >> i) & 1;
        }
        this->buffer_it_ = this->buffer_.begin();
    }
    ++this->buffer_it_;
    return *(this->buffer_it_ - 1);
}

bit_io::BinaryCode bit_io::BitReader::Get(size_t count) {
    bit_io::BinaryCode read_byte(count);
    for (size_t i = 0; i < read_byte.size(); ++i) {
        read_byte[i] = this->GetOneBit();
    }
    return read_byte;
}

bool bit_io::BitReader::IsEndOfFile() {
    if (this->input_stream_->peek() == EOF) {
        if (this->input_stream_->eof()) {
            return true;
        }
        throw std::runtime_error("Error while reading file");
    }
    return false;
}

bit_io::BitWriter::BitWriter(std::ostream& output_stream) {
    this->output_stream_ = std::move(&output_stream);
    this->buffer_ = bit_io::BinaryCode(bit_io::BUFFER_SIZE);
    this->buffer_it_ = this->buffer_.begin();
}

void bit_io::BitWriter::ClearBuffer() {
    char byte = 0;
    for (size_t i = 0; i < this->buffer_.size(); ++i) {
        if (this->buffer_[i]) {
            byte |= (this->buffer_[i] << i);
        }
    }
    this->output_stream_->put(byte);
    this->buffer_it_ = this->buffer_.begin();
}

void bit_io::BitWriter::WriteOneBit(bool bit) {
    if (this->buffer_it_ == this->buffer_.end()) {
        this->ClearBuffer();
    }
    *this->buffer_it_ = bit;
    ++this->buffer_it_;
}

void bit_io::BitWriter::Write(const bit_io::BinaryCode& bits) {
    for (const auto& bit : bits) {
        this->WriteOneBit(bit);
    }
}

template<size_t BITSET_SIZE>
void bit_io::BitWriter::Write(const std::bitset<BITSET_SIZE>& letter) {
    for (size_t i = 0; i < BITSET_SIZE; ++i) {
        this->WriteOneBit(letter[i]);
    }
}

void bit_io::BitWriter::WriteNineBitNumber(size_t number) {
    huffman::Letter letter = number;
    this->Write(letter);
}

bit_io::BitWriter::~BitWriter() {
    if (buffer_it_ != buffer_.begin()) {
        this->ClearBuffer();
    }
    delete this->output_stream_;
}