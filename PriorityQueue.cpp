#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() {
    heap_ = std::vector<std::pair<size_t, huffman::HuffmanTree*>>(1);
}

PriorityQueue::PriorityQueue(const std::vector<std::pair<size_t, huffman::HuffmanTree*>>& elements) {
    heap_ = std::vector<std::pair<size_t, huffman::HuffmanTree*>>(1);
    for (const auto& element : elements) {
        heap_.push_back(element);
        this->SiftUp(heap_.size() - 1);
    }
}

void PriorityQueue::SiftUp(size_t id) {
    while (id > 1 && heap_[id].first < heap_[id / 2].first) {
        swap(heap_[id], heap_[id / 2]);
        id /= 2;
    }
}

void PriorityQueue::SiftDown(size_t id) {
    while (2 * id < heap_.size()) {
        size_t left = 2 * id;
        size_t right = 2 * id + 1;
        size_t j = left;
        if (right < heap_.size() && heap_[right].first < heap_[left].first) {
            j = right;
        }
        if (heap_[id].first <= heap_[j].first) {
            break;
        }
        swap(heap_[id], heap_[j]);
        id = j;
    }
}

void PriorityQueue::Insert(std::pair<size_t, huffman::HuffmanTree*> element) {
    heap_.push_back(element);
    this->SiftUp(heap_.size() - 1);
}

std::pair<size_t, huffman::HuffmanTree*> PriorityQueue::ExtractRoot() {
    auto root = heap_[1];
    swap(heap_[1], heap_.back());
    heap_.pop_back();
    this->SiftDown(1);
    return root;
}

size_t PriorityQueue::Size() {
    return heap_.size() - 1;
}

