#include "imghash_c.h"

unsigned long long imghash_c(char *buffer, unsigned int size)
{
    imghash::Source source(buffer, size);
    imghash::Hasher *hasher = new imghash::SimpleHasher();
    imghash::Hash hash = hasher->hash(source);
    delete hasher;
    return hash.toLongLong();
}
