#include "source.h"

using namespace imghash;

Source::Source()
{

}

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

bool Source::loadFile(std::string fileName)
{
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
        Magick::Blob blob(buffer, size);
        image.read(blob);
        delete buffer;
        return true;
    }
    return false;
}
