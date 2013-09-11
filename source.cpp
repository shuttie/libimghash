#include "source.h"

using namespace imghash;

Source::Source(std::string data)
{
    const char* raw = data.data();
    int len = data.length();
    Magick::Blob blob(data.data(), data.length());
    image.read(blob);
}

Source::Source(char *buffer, int size)
{
    Magick::Blob blob(buffer, size);
    image.magick("JPEG");
    image.read(blob);
}

Magick::PixelPacket* Source::getPixels()
{
    return image.getPixels(0,0,image.geometry().width(), image.geometry().height());
}

Magick::Image Source::getImage() {
    return image;
}
