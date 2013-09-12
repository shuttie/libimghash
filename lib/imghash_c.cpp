#include "imghash_c.h"

unsigned long long imghash_buffer(char *buffer, unsigned int size)
{
    imghash::Source source(buffer, size);
    imghash::Hasher *hasher = new imghash::SimpleHasher();
    imghash::Hash hash = hasher->hash(source);
    delete hasher;
    return hash.toLongLong();
}


unsigned long long imghash_file(char *fileName)
{
    imghash::Source source;
    source.loadFile(fileName);
    imghash::Hasher *hasher = new imghash::SimpleHasher();
    imghash::Hash hash = hasher->hash(source);
    delete hasher;
    return hash.toLongLong();
}


const char *imghash_file_hex(char *fileName)
{
    imghash::Source source;
    source.loadFile(fileName);
    imghash::Hasher *hasher = new imghash::SimpleHasher();
    imghash::Hash hash = hasher->hash(source);
    delete hasher;
    return hash.toHex().c_str();
}
