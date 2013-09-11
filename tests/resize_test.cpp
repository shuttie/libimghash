#include "simplehasher.h"
#include "test.h"

class ResizeTest: public Test {
public:
    ResizeTest(std::string fileName) {
        source.loadFile(fileName);
        for (int i=1; i<99; ++i) {
            Magick::Image image = source.getImage();
            image.magick("JPEG");
            image.quality(50);
            Magick::Geometry resizeGeometry;
            resizeGeometry.percent(true);
            resizeGeometry.width(i);
            resizeGeometry.height(i);
            image.resize(resizeGeometry);
            Magick::Blob blob;
            image.write(&blob);
            imghash::Source target((char*)blob.data(), blob.length());
            images.push_back(target);
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc == 2) {
        ResizeTest test(argv[1]);
        test.run();
    }
}

