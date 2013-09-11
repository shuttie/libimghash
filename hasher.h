#ifndef HASHER_H
#define HASHER_H

#include "source.h"
#include "hash.h"

namespace imghash {

class Hasher {
public:
    virtual Hash hash(char* buffer, unsigned int length);
    virtual Hash hash(std::string& data);
    virtual Hash hash(Source image) = 0;
};

}

#endif
