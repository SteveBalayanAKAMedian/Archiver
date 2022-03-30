#ifndef CPP_PILOT_HSE_HUFFMANTREE_H
#define CPP_PILOT_HSE_HUFFMANTREE_H
#include "huffman consts and usings.h"
#include "BitIO.h"
#include <iostream>
#include <vector>


namespace huffman {
class HuffmanTree {
public:
    struct HuffmanCode {
        huffman::Letter letter;
        bit_io::BinaryCode code;
    };

public:
    HuffmanTree();

    HuffmanTree(std::vector<HuffmanCode>& codes);

    HuffmanTree(huffman::Letter letter);

    huffman::Letter DecodeWithTree(bit_io::BitReader* reader);

    static HuffmanTree* Merge(HuffmanTree* left, HuffmanTree* right);

    std::vector<HuffmanCode> MakeCodes();

    void AddLetter(HuffmanCode& huffman_code);

    ~HuffmanTree();

private:
    struct Node {
        Node* left;
        Node* right;
        huffman::Letter letter;

        bool IsTerminal();

        Node();

        Node(huffman::Letter letter);

        ~Node();
    };

    void TreeWalk(Node* root, std::vector<HuffmanCode>& codes, bit_io::BinaryCode& current_code);

    void AddLetterToTree(
        Node* root, huffman::Letter& letter, bit_io::BinaryCode& code, bit_io::BinaryCode::iterator it);

    Node* node_;
};
}  //namespace huffman

#endif
