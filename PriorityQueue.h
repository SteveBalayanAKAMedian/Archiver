#ifndef CPP_PILOT_HSE_PRIORITYQUEUE_H
#define CPP_PILOT_HSE_PRIORITYQUEUE_H
#include "HuffmanTree.h"
#include <vector>

class PriorityQueue {
public:
    PriorityQueue();

    PriorityQueue(const std::vector<std::pair<size_t, huffman::HuffmanTree*>>& elements);

    std::pair<size_t, huffman::HuffmanTree*> ExtractRoot();

    size_t Size();

    void Insert(std::pair<size_t, huffman::HuffmanTree*>);

private:
    std::vector<std::pair<size_t, huffman::HuffmanTree*>> heap_;

    void SiftUp(size_t id);

    void SiftDown(size_t id);
};

#endif  // CPP_PILOT_HSE_PRIORITYQUEUE_H
