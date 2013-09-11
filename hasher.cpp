#include "hasher.h"

imghash::Hash imghash::Hasher::hash(char *buffer, unsigned int length)
{
    return hash(Source(buffer, length));
}

imghash::Hash imghash::Hasher::hash(std::string &data)
{
    return hash(Source(data));
}
