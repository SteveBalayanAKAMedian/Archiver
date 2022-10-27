#ifndef CPP_PILOT_HSE_ENCODER_H
#define CPP_PILOT_HSE_ENCODER_H
#include "BitIO.h"
#include "huffman consts and usings.h"
#include "PriorityQueue.h"
#include "HuffmanTree.h"
#include <algorithm>
#include <unordered_map>
#include <filesystem>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>

namespace huffman {
class Encoder {
public:
    static bool CanCreate(const std::vector<std::string>& filenames);

    Encoder(const std::string& address, const std::vector<std::string>& filenames);

    ~Encoder();

    void Archive();

private:
    std::vector<std::string> filenames_;
    std::string address_;
    bit_io::BitWriter* writer_;

    std::unordered_map<huffman::Letter, size_t> CountOccurence(bit_io::BitReader* reader, const std::string& filename);

    std::vector<huffman::HuffmanTree::HuffmanCode> BuildHuffmanCodes(
        const std::unordered_map<huffman::Letter, size_t>& counter);

    std::vector<std::pair<huffman::Letter, bit_io::BinaryCode>> MakeCanonHuffmanCodes(
        std::vector<huffman::HuffmanTree::HuffmanCode>& huffman_codes);

    void PrintTableOfHuffmanCoding(
        const std::vector<std::pair<huffman::Letter, bit_io::BinaryCode>>& canon_huffman_codes);

    huffman::Letter FromBinaryCodeToLetter(const bit_io::BinaryCode& read_symbol);
};
}

#endif
