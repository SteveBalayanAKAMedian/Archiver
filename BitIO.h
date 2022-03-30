#ifndef CPP_PILOT_HSE_BITIO_H
#define CPP_PILOT_HSE_BITIO_H
#include "huffman consts and usings.h"
#include <bitset>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace bit_io {
const size_t BUFFER_SIZE = 8;
using BinaryCode = std::vector<bool>;

class BitReader {
public:
    BitReader(std::istream& input_stream);

    bool GetOneBit();

    bool IsEndOfFile();

    bit_io::BinaryCode Get(size_t count);

private:
    std::istream* input_stream_;
    bit_io::BinaryCode buffer_;
    bit_io::BinaryCode::iterator buffer_it_;
};

class BitWriter {
public:
    BitWriter(std::ostream& output_stream);

    void WriteOneBit(bool bit);

    void Write(const bit_io::BinaryCode& bits);

    template<size_t BITSET_SIZE>
    void Write(const std::bitset<BITSET_SIZE>& letter);

    void WriteNineBitNumber(size_t number);

    ~BitWriter();

private:
    void ClearBuffer();

private:
    std::ostream* output_stream_;
    bit_io::BinaryCode buffer_;
    bit_io::BinaryCode::iterator buffer_it_;
};
}

#endif  // CPP_PILOT_HSE_BITIO_H