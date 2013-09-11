#include "test.h"

void Test::run() {
    imghash::Hasher *hasher = new imghash::SimpleHasher(8);
    imghash::Hash sourceHash = hasher->hash(source);
    int fails = 0;
    for (unsigned int i=0; i<images.size(); ++i) {
        imghash::Hash targetHash = hasher->hash(images[i]);
        float rmse = sourceHash.getRMSE(targetHash);
        printf("test %2d: RMSE=%f\n", i, rmse);
        if (rmse >= 0.5)
            fails++;
    }
    printf("Test result: %d fails\n", fails);
}
