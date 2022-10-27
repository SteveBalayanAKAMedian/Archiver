project(archiver)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra -std=c++17")

add_executable(archiver
    main.cpp BitIO.h BitIO.cpp Decoder.cpp Decoder.h Encoder.cpp Encoder.h HuffmanTree.cpp HuffmanTree.h PriorityQueue.cpp PriorityQueue.h "huffman consts and usings.h")