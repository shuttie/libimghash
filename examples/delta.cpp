#include <iostream>
#include <fstream>
#include <ios>
#include "simplehasher.h"
#include <sys/stat.h>

std::string loadFile(std::string fileName) {
    std::string result;
    std::ifstream input;
    input.open(fileName.c_str(), std::ios::in | std::ios::binary);
    if (input.is_open()) {
        // getting file size
        struct stat stat_buf;
        int rc = stat(fileName.c_str(), &stat_buf);
        int size = stat_buf.st_size;
        // reading data
        char* buffer = new char[size];
        input.read(buffer,size);
        result = std::string(buffer,size);
        delete buffer;
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc == 3) {
        std::string data1 = loadFile(argv[1]);
        std::string data2 = loadFile(argv[2]);
        // hashing
        imghash::Hasher *hasher = new imghash::SimpleHasher(8);
        imghash::Hash hash1 = hasher->hash(data1);
        imghash::Hash hash2 = hasher->hash(data2);
        std::cout << "hash1: " << hash1.toHex() << "\nhash2: " << hash2.toHex() << "\nRMSE: " << hash1.getRMSE(hash2) << "\n";
        delete hasher;
    }
}
