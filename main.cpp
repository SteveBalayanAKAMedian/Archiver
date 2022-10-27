#include "BitIO.h"
#include "Encoder.h"
#include "Decoder.h"
#include <iostream>
#include <vector>
#include <string>

int main(int argc, const char* const argv[]) {
    if (std::string(argv[1]) == "-c" && argc >= 4) {
        std::string archive_name = std::string(argv[2]);
        std::vector<std::string> filenames(argc - 3);
        for (size_t i = 3; i < static_cast<size_t>(argc); ++i) {
            filenames[i - 3] = std::string(argv[i]);
        }
        if (huffman::Encoder::CanCreate(filenames)) {
            huffman::Encoder* encoder = new huffman::Encoder(archive_name, filenames);
            try {
                encoder->Archive();
            } catch (std::exception& exception) {
                std::cout << "Cannot archive, something went wrong:\n" << exception.what() << std::endl;
            }
            delete encoder;
        } else {
            std::cout << "Invalid filenames" << std::endl;
        }
    } else if (std::string(argv[1]) == "-d" && argc == 3) {
        std::string archive_name = std::string(argv[2]);
        std::ifstream tmp_ifstream(archive_name);
        if (!tmp_ifstream.good()) {
            std::cout << "invalid archive name" << std::endl;
        }  else {
            huffman::Decoder* decoder = new huffman::Decoder(archive_name);
            try {
                decoder->Decode();
            } catch (std::exception& exception) {
                std::cout << "Cannot decompress, something went wrong:\n" << exception.what() << std::endl;
            }
            delete decoder;
        }
    } else if (std::string(argv[1]) == "-h" && argc == 2) {
        std::cout << "====================================================\n";
        std::cout << "Hello, you are using Huffman Archiver.\nIf you want to archive some files, use command:\n";
        std::cout << "archiver -c archive_name file1 [file2 ...]\n";
        std::cout << "Files file1, file2, ... will be archived into archive archive_name.\n";
        std::cout << "For decompression use command:\n";
        std::cout << "archiver -d archive_name\n";
        std::cout << "Files from archive archive_name will be decompressed in the current directory.\n";
        std::cout << "====================================================\n" << std::endl;
    } else {
        std::cout << "Invalid arguments, use command archiver -h if you need documentation." << std::endl;
    }
    return 0;
}