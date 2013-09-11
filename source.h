#ifndef SOURCE_H
#define SOURCE_H

#include <string>
#include <vector>
#include <Magick++.h>
#include <iostream>

namespace imghash {

class Source {
private:
    Magick::Image image;
public:
    Source(std::string data);
    Source(char* buffer, int size);
    Magick::PixelPacket* getPixels();
    Magick::Image getImage();
};

}

#endif
