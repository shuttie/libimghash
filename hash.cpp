#include "hash.h"

imghash::Hash::Hash()
{

}

std::string imghash::Hash::toString()
{
    return "";
}

std::string imghash::Hash::toHex()
{
    std::stringstream stream;
    for (unsigned int i=0; i<data.size(); ++i) {
        stream << std::hex << std::setfill('0') << std::setw(8) << data[i];
    }
    return stream.str();
}

unsigned long long imghash::Hash::toLongLong()
{
    if (data.empty())
        return 0;
    else if (data.size() == 1)
        return data[0];
    else {
        unsigned long long int result = data[0];
        result |= ((unsigned long long int)data[1] << sizeof(unsigned int));
        return result;
    }
}

void imghash::Hash::setBit(unsigned int index, bool value)
{
    unsigned int blockNumber = (index - (index % (sizeof(unsigned int)*8))) / (sizeof(unsigned int)*8);
    unsigned int blockOffset = index - (blockNumber * sizeof(unsigned int)*8);
    if (blockNumber >= data.size())
        data.resize(blockNumber+1,0);
    if (value)
        data[blockNumber] |= (1 << blockOffset);
}

bool imghash::Hash::getBit(unsigned int index) const
{
    unsigned int blockNumber = (index - (index % (sizeof(unsigned int)*8))) / (sizeof(unsigned int)*8);
    unsigned int blockOffset = index - (blockNumber * sizeof(unsigned int)*8);
    return data[blockNumber] & (1 << blockOffset);
}

float imghash::Hash::getRMSE(const imghash::Hash &other)
{
    return sqrt(getMSE(other));
}

float imghash::Hash::getMSE(const imghash::Hash &other)
{
    int sum = 0;
    int count = 0;
    for (unsigned int i=0; i<data.size()*8*sizeof(unsigned int); ++i) {
        count++;
        bool sourceBit = getBit(i);
        bool otherBit = other.getBit(i);
        if (sourceBit != otherBit)
            sum += 1;
    }

    return (float)sum/(float)count;
}
