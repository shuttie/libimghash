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
    if (argc == 2) {
        std::string data = loadFile(argv[1]);
        // hashing
        imghash::Hasher *hasher = new imghash::SimpleHasher(8);
        imghash::Hash hash = hasher->hash(data);
        std::cout << "hash: " << hash.toHex() << "\n";
        delete hasher;
    }
}
