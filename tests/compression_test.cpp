#include "simplehasher.h"
#include "test.h"

class CompressionTest: public Test {
public:
    CompressionTest(std::string fileName) {
        source.loadFile(fileName);
        for (int i=1; i<99; ++i) {
            Magick::Image image = source.getImage();
            image.magick("JPEG");
            image.quality(i);
            Magick::Blob blob;
            image.write(&blob);
            imghash::Source target((char*)blob.data(), blob.length());
            images.push_back(target);
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc == 2) {
        CompressionTest test(argv[1]);
        test.run();
    }
}

