#include "HuffmanTree.h"

huffman::HuffmanTree::Node::Node() {
    this->left = nullptr;
    this->right = nullptr;
}

huffman::HuffmanTree::Node::Node(huffman::Letter letter) {
    this->left = nullptr;
    this->right = nullptr;
    this->letter = letter;
}

huffman::HuffmanTree::Node::~Node() {
    if (!this->IsTerminal()) {
        delete this->left;
        delete this->right;
    }
}

void huffman::HuffmanTree::AddLetterToTree(
    Node* root, huffman::Letter& letter, bit_io::BinaryCode& code,
                                           bit_io::BinaryCode::iterator it) {
    if (it == code.end()) {
        root->letter = letter;
    }
    else {
        if (*it) {
            if (root->right == nullptr) {
                root->right = new huffman::HuffmanTree::Node();
            }
            huffman::HuffmanTree::AddLetterToTree(root->right, letter, code, it + 1);
        } else {
            if (root->left == nullptr) {
                root->left = new huffman::HuffmanTree::Node();
            }
            huffman::HuffmanTree::AddLetterToTree(root->left, letter, code, it + 1);
        }
    }
}

huffman::HuffmanTree::HuffmanTree(std::vector<HuffmanCode>& canon_codes) {
    this->node_ = new huffman::HuffmanTree::Node();
    for (auto& canon_code : canon_codes) {
        AddLetterToTree(this->node_, canon_code.letter, canon_code.code, canon_code.code.begin());
    }
}

void huffman::HuffmanTree::AddLetter(huffman::HuffmanTree::HuffmanCode& huffman_code) {
    AddLetterToTree(this->node_, huffman_code.letter, huffman_code.code, huffman_code.code.begin());
}

huffman::HuffmanTree::HuffmanTree(huffman::Letter letter) {
    this->node_ = new huffman::HuffmanTree::Node(letter);
}

huffman::HuffmanTree::HuffmanTree() {
    this->node_ = new huffman::HuffmanTree::Node();
}

huffman::HuffmanTree::~HuffmanTree() {
    delete this->node_;
}

bool huffman::HuffmanTree::Node::IsTerminal() {
    return this->left == nullptr && this->right == nullptr;
}

huffman::Letter huffman::HuffmanTree::DecodeWithTree(bit_io::BitReader* reader) {
    auto cur_node = this->node_;
    while (!cur_node->IsTerminal()) {
        bool bit = reader->GetOneBit();
        if (bit) {
            if (cur_node->right == nullptr) {
                throw std::runtime_error("The archive might have been corrupted.");
            }
            cur_node = cur_node->right;
        } else {
            if (cur_node->left == nullptr) {
                throw std::runtime_error("The archive might have been corrupted.");
            }
            cur_node = cur_node->left;
        }
    }
    return cur_node->letter;
}

huffman::HuffmanTree* huffman::HuffmanTree::Merge(HuffmanTree* left, HuffmanTree* right) {
    auto root = new huffman::HuffmanTree();
    root->node_->left = left->node_;
    root->node_->right = right->node_;
    left->node_ = nullptr;
    right->node_ = nullptr;
    return root;
}

void huffman::HuffmanTree::TreeWalk(Node* root, std::vector<HuffmanCode>& codes, bit_io::BinaryCode& current_code) {
    if (root->IsTerminal()) {
        codes.push_back({root->letter, current_code});
    } else {
        if (root->left != nullptr) {
            current_code.push_back(false);
            TreeWalk(root->left, codes, current_code);
        }
        if (root->right != nullptr) {
            current_code.push_back(true);
            TreeWalk(root->right, codes, current_code);
        }
    }
    current_code.pop_back();
}

std::vector<huffman::HuffmanTree::HuffmanCode> huffman::HuffmanTree::MakeCodes() {
    std::vector<huffman::HuffmanTree::HuffmanCode> codes;
    bit_io::BinaryCode current_code;
    TreeWalk(this->node_, codes, current_code);
    return codes;
}