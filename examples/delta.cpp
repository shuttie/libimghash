#include "simplehasher.h"

int main(int argc, char* argv[]) {
    if (argc == 3) {
        imghash::Source data1;
        data1.loadFile(argv[1]);
        imghash::Source data2;
        data2.loadFile(argv[2]);
        // hashing
        imghash::Hasher *hasher = new imghash::SimpleHasher(8);
        imghash::Hash hash1 = hasher->hash(data1);
        imghash::Hash hash2 = hasher->hash(data2);
        std::cout << "hash1: " << hash1.toHex() << "\nhash2: " << hash2.toHex() << "\nRMSE: " << hash1.getRMSE(hash2) << "\n";
        delete hasher;
    }
}
