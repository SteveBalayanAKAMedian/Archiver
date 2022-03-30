#ifndef CPP_PILOT_HSE_BYTECONSTS_H
#define CPP_PILOT_HSE_BYTECONSTS_H
#include <bitset>
#include <vector>

namespace huffman {
const size_t LETTER_SIZE = 9;
using Letter = std::bitset<LETTER_SIZE>;
const size_t BITS_IN_BYTE = 8;
const Letter FILENAME_END = 256;
const Letter ONE_MORE_FILE = 257;
const Letter ARCHIVE_END = 258;
}  // namespace huffman

#endif  // CPP_PILOT_HSE_BYTECONSTS_H
