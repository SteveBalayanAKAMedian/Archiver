#ifndef CPP_PILOT_HSE_DECODER_H
#define CPP_PILOT_HSE_DECODER_H
#include "BitIO.h"
#include "huffman consts and usings.h"
#include "HuffmanTree.h"
#include <string>
#include <fstream>

namespace huffman {
class Decoder {
public:
    Decoder(const std::string&);

    ~Decoder();

    void Decode();

private:
    bit_io::BitReader* input_stream_;

    size_t FromBinaryCodeToSizeT(const bit_io::BinaryCode& read_symbol);

    std::vector<huffman::HuffmanTree::HuffmanCode> MakeCanonHuffmanCodes(
        const std::vector<std::pair<huffman::Letter, size_t>>& huffman_codes);
};
}


#endif  // CPP_PILOT_HSE_DECODER_H
