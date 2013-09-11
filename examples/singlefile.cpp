#include <iostream>
#include <fstream>
#include <ios>
#include "simplehasher.h"
#include <sys/stat.h>

int main(int argc, char* argv[]) {
    if (argc == 2) {
        imghash::Source data;
        data.loadFile(argv[1]);
        // hashing
        imghash::Hasher *hasher = new imghash::SimpleHasher(8);
        imghash::Hash hash = hasher->hash(data);
        std::cout << "hash: " << hash.toHex() << "\n";
        delete hasher;
    }
}
