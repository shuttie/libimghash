#include "simplehasher.h"

imghash::SimpleHasher::SimpleHasher(unsigned int size)
    :size(size)
{

}

imghash::Hash imghash::SimpleHasher::hash(Source image)
{
    Magick::Image target(image.getImage());
    target.type(Magick::TrueColorType);
    target.modifyImage();
    target.colorSpace(Magick::GRAYColorspace);
    Magick::Geometry resizeGeom;
    resizeGeom.aspect(true);
    resizeGeom.width(size);
    resizeGeom.height(size);
    target.resize(resizeGeom);
    Magick::Geometry geom = target.size();
    Magick::PixelPacket* pixels = target.getPixels(0,0,size,size);
    float averageColor = getAverage(pixels);
    Hash result;
    int count=0;
    for (unsigned int i=0; i<size; i++) {
        for (unsigned int j=0; j<size; j++) {
            int color = (*pixels++).green;
            bool bit = (color > averageColor);
            //printf("%3d ", color);
            result.setBit(count, bit );
            count++;
        }
        //printf("\n");
    }
    //printf("\n");
    return result;
}

float imghash::SimpleHasher::getAverage(const Magick::PixelPacket* pixels) const
{
    int sum = 0;
    int count = 0;
    for (unsigned int i=0; i<size; i++) {
        for (unsigned int j=0; j<size; j++) {
            sum += (*pixels++).green;
            count++;
        }
    }
    return (float)sum/(float)count;
}

int imghash::SimpleHasher::getMedian(const Magick::PixelPacket *pixels) const
{
    std::map<unsigned int,unsigned int> hist;
    int max = 0;
    unsigned int max_key = 0;
    for (unsigned int i=0; i<size; i++) {
        for (unsigned int j=0; j<size; j++) {
            unsigned int key = (*pixels++).green;
            unsigned int value = hist[key] + 1;
            if (value > max) {
                max_key = key;
                max = value;
            }
            hist[key]++;
        }
    }
    return max_key;
}
