#include "gtest/gtest.h"
#include "defs.h"
#include "arrayadjustment.h"
#include "valuecropper.h"
#include "valuenormalizer.h"
#include "valuestretcher.h"
#include "exception.h"

using namespace LatticeLib;

TEST(ValueCropper,valuecroppertest) {

    int size = 10;
    int intTestArray[10] = {0,1,2,3,4,5,6,7,8,9};
    double doubleTestArray[10] = {0.0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};

    ValueCropper cropper;

    // T = int
    EXPECT_THROW(cropper.apply(intTestArray, size,5,4), incompatibleException);
    EXPECT_EQ(0, intTestArray[0]);
    EXPECT_EQ(1, intTestArray[1]);
    EXPECT_EQ(2, intTestArray[2]);
    EXPECT_EQ(3, intTestArray[3]);
    EXPECT_EQ(4, intTestArray[4]);
    EXPECT_EQ(5, intTestArray[5]);
    EXPECT_EQ(6, intTestArray[6]);
    EXPECT_EQ(7, intTestArray[7]);
    EXPECT_EQ(8, intTestArray[8]);
    EXPECT_EQ(9, intTestArray[9]);
    cropper.apply(intTestArray, size,-1,10);
    EXPECT_EQ(0,intTestArray[0]);
    EXPECT_EQ(1, intTestArray[1]);
    EXPECT_EQ(2, intTestArray[2]);
    EXPECT_EQ(3, intTestArray[3]);
    EXPECT_EQ(4, intTestArray[4]);
    EXPECT_EQ(5, intTestArray[5]);
    EXPECT_EQ(6, intTestArray[6]);
    EXPECT_EQ(7, intTestArray[7]);
    EXPECT_EQ(8, intTestArray[8]);
    EXPECT_EQ(9, intTestArray[9]);
    cropper.apply(intTestArray, size, 0, 9);
    EXPECT_EQ(0, intTestArray[0]);
    EXPECT_EQ(1, intTestArray[1]);
    EXPECT_EQ(2, intTestArray[2]);
    EXPECT_EQ(3, intTestArray[3]);
    EXPECT_EQ(4, intTestArray[4]);
    EXPECT_EQ(5, intTestArray[5]);
    EXPECT_EQ(6, intTestArray[6]);
    EXPECT_EQ(7, intTestArray[7]);
    EXPECT_EQ(8, intTestArray[8]);
    EXPECT_EQ(9, intTestArray[9]);
    cropper.apply(intTestArray, size, 2, 7);
    EXPECT_EQ(2, intTestArray[0]);
    EXPECT_EQ(2, intTestArray[1]);
    EXPECT_EQ(2, intTestArray[2]);
    EXPECT_EQ(3, intTestArray[3]);
    EXPECT_EQ(4, intTestArray[4]);
    EXPECT_EQ(5, intTestArray[5]);
    EXPECT_EQ(6, intTestArray[6]);
    EXPECT_EQ(7, intTestArray[7]);
    EXPECT_EQ(7, intTestArray[8]);
    EXPECT_EQ(7, intTestArray[9]);
    cropper.apply(intTestArray, size, 5, 5);
    EXPECT_EQ(5, intTestArray[0]);
    EXPECT_EQ(5, intTestArray[1]);
    EXPECT_EQ(5, intTestArray[2]);
    EXPECT_EQ(5, intTestArray[3]);
    EXPECT_EQ(5, intTestArray[4]);
    EXPECT_EQ(5, intTestArray[5]);
    EXPECT_EQ(5, intTestArray[6]);
    EXPECT_EQ(5, intTestArray[7]);
    EXPECT_EQ(5, intTestArray[8]);
    EXPECT_EQ(5, intTestArray[9]);
    cropper.apply(intTestArray, size, 9, 10);
    EXPECT_EQ(9, intTestArray[0]);
    EXPECT_EQ(9, intTestArray[1]);
    EXPECT_EQ(9, intTestArray[2]);
    EXPECT_EQ(9, intTestArray[3]);
    EXPECT_EQ(9, intTestArray[4]);
    EXPECT_EQ(9, intTestArray[5]);
    EXPECT_EQ(9, intTestArray[6]);
    EXPECT_EQ(9, intTestArray[7]);
    EXPECT_EQ(9, intTestArray[8]);
    EXPECT_EQ(9, intTestArray[9]);
    cropper.apply(intTestArray, size, 1, 2);
    EXPECT_EQ(2, intTestArray[0]);
    EXPECT_EQ(2, intTestArray[1]);
    EXPECT_EQ(2, intTestArray[2]);
    EXPECT_EQ(2, intTestArray[3]);
    EXPECT_EQ(2, intTestArray[4]);
    EXPECT_EQ(2, intTestArray[5]);
    EXPECT_EQ(2, intTestArray[6]);
    EXPECT_EQ(2, intTestArray[7]);
    EXPECT_EQ(2, intTestArray[8]);
    EXPECT_EQ(2, intTestArray[9]);

    // T = double
    EXPECT_THROW(cropper.apply(doubleTestArray, size, 5.0, 4.0), incompatibleException);
    EXPECT_NEAR(0.0, doubleTestArray[0], EPSILONT);
    EXPECT_NEAR(1.1, doubleTestArray[1], EPSILONT);
    EXPECT_NEAR(2.2, doubleTestArray[2], EPSILONT);
    EXPECT_NEAR(3.3, doubleTestArray[3], EPSILONT);
    EXPECT_NEAR(4.4, doubleTestArray[4], EPSILONT);
    EXPECT_NEAR(5.5, doubleTestArray[5], EPSILONT);
    EXPECT_NEAR(6.6, doubleTestArray[6], EPSILONT);
    EXPECT_NEAR(7.7, doubleTestArray[7], EPSILONT);
    EXPECT_NEAR(8.8, doubleTestArray[8], EPSILONT);
    EXPECT_NEAR(9.9, doubleTestArray[9], EPSILONT);
    cropper.apply(doubleTestArray, size, -1.1, 10.1);
    EXPECT_NEAR(0.0, doubleTestArray[0], EPSILONT);
    EXPECT_NEAR(1.1, doubleTestArray[1], EPSILONT);
    EXPECT_NEAR(2.2, doubleTestArray[2], EPSILONT);
    EXPECT_NEAR(3.3, doubleTestArray[3], EPSILONT);
    EXPECT_NEAR(4.4, doubleTestArray[4], EPSILONT);
    EXPECT_NEAR(5.5, doubleTestArray[5], EPSILONT);
    EXPECT_NEAR(6.6, doubleTestArray[6], EPSILONT);
    EXPECT_NEAR(7.7, doubleTestArray[7], EPSILONT);
    EXPECT_NEAR(8.8, doubleTestArray[8], EPSILONT);
    EXPECT_NEAR(9.9, doubleTestArray[9], EPSILONT);
    cropper.apply(doubleTestArray, size, 0.0 - 0.5*EPSILONT, 9.9 + 0.5 *EPSILONT);
    EXPECT_NEAR(0.0, doubleTestArray[0], EPSILONT);
    EXPECT_NEAR(1.1, doubleTestArray[1], EPSILONT);
    EXPECT_NEAR(2.2, doubleTestArray[2], EPSILONT);
    EXPECT_NEAR(3.3, doubleTestArray[3], EPSILONT);
    EXPECT_NEAR(4.4, doubleTestArray[4], EPSILONT);
    EXPECT_NEAR(5.5, doubleTestArray[5], EPSILONT);
    EXPECT_NEAR(6.6, doubleTestArray[6], EPSILONT);
    EXPECT_NEAR(7.7, doubleTestArray[7], EPSILONT);
    EXPECT_NEAR(8.8, doubleTestArray[8], EPSILONT);
    EXPECT_NEAR(9.9, doubleTestArray[9], EPSILONT);
    cropper.apply(doubleTestArray, size, 2.1, 7.8);
    EXPECT_NEAR(2.1, doubleTestArray[0], EPSILONT);
    EXPECT_NEAR(2.1, doubleTestArray[1], EPSILONT);
    EXPECT_NEAR(2.2, doubleTestArray[2], EPSILONT);
    EXPECT_NEAR(3.3, doubleTestArray[3], EPSILONT);
    EXPECT_NEAR(4.4, doubleTestArray[4], EPSILONT);
    EXPECT_NEAR(5.5, doubleTestArray[5], EPSILONT);
    EXPECT_NEAR(6.6, doubleTestArray[6], EPSILONT);
    EXPECT_NEAR(7.7, doubleTestArray[7], EPSILONT);
    EXPECT_NEAR(7.8, doubleTestArray[8], EPSILONT);
    EXPECT_NEAR(7.8, doubleTestArray[9], EPSILONT);
    cropper.apply(doubleTestArray, size, 5.5, 5.5 + 0.5*EPSILONT);
    EXPECT_NEAR(5.5, doubleTestArray[0], EPSILONT);
    EXPECT_NEAR(5.5, doubleTestArray[1], EPSILONT);
    EXPECT_NEAR(5.5, doubleTestArray[2], EPSILONT);
    EXPECT_NEAR(5.5, doubleTestArray[3], EPSILONT);
    EXPECT_NEAR(5.5, doubleTestArray[4], EPSILONT);
    EXPECT_NEAR(5.5, doubleTestArray[5], EPSILONT);
    EXPECT_NEAR(5.5, doubleTestArray[6], EPSILONT);
    EXPECT_NEAR(5.5, doubleTestArray[7], EPSILONT);
    EXPECT_NEAR(5.5, doubleTestArray[8], EPSILONT);
    EXPECT_NEAR(5.5, doubleTestArray[9], EPSILONT);
    cropper.apply(doubleTestArray, size, 9.9, 10.1);
    EXPECT_NEAR(9.9, doubleTestArray[0], EPSILONT);
    EXPECT_NEAR(9.9, doubleTestArray[1], EPSILONT);
    EXPECT_NEAR(9.9, doubleTestArray[2], EPSILONT);
    EXPECT_NEAR(9.9, doubleTestArray[3], EPSILONT);
    EXPECT_NEAR(9.9, doubleTestArray[4], EPSILONT);
    EXPECT_NEAR(9.9, doubleTestArray[5], EPSILONT);
    EXPECT_NEAR(9.9, doubleTestArray[6], EPSILONT);
    EXPECT_NEAR(9.9, doubleTestArray[7], EPSILONT);
    EXPECT_NEAR(9.9, doubleTestArray[8], EPSILONT);
    EXPECT_NEAR(9.9, doubleTestArray[9], EPSILONT);
    cropper.apply(doubleTestArray, size, 1.1, 2.2);
    EXPECT_NEAR(2.2, doubleTestArray[0], EPSILONT);
    EXPECT_NEAR(2.2, doubleTestArray[1], EPSILONT);
    EXPECT_NEAR(2.2, doubleTestArray[2], EPSILONT);
    EXPECT_NEAR(2.2, doubleTestArray[3], EPSILONT);
    EXPECT_NEAR(2.2, doubleTestArray[4], EPSILONT);
    EXPECT_NEAR(2.2, doubleTestArray[5], EPSILONT);
    EXPECT_NEAR(2.2, doubleTestArray[6], EPSILONT);
    EXPECT_NEAR(2.2, doubleTestArray[7], EPSILONT);
    EXPECT_NEAR(2.2, doubleTestArray[8], EPSILONT);
    EXPECT_NEAR(2.2, doubleTestArray[9], EPSILONT);
}

TEST(ValueNormalizer, valuenormalizertest) {

    int size = 10;
    int intTestArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double doubleTestArray1[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    double doubleTestArray2[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    double doubleTestArray3[10] = {-10.0, -9.0, -8.0, -7.0, -6.0, -5.0, -4.0, -3.0, -2.0, -1.0};
    double doubleTestArray4[10] = {1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5};
    float floatTestArray1[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    float floatTestArray2[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    float floatTestArray3[10] = {-10.0, -9.0, -8.0, -7.0, -6.0, -5.0, -4.0, -3.0, -2.0, -1.0};
    float floatTestArray4[10] = {1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5};

    ValueNormalizer normalizer;

    // T = int
    EXPECT_THROW(normalizer.apply(intTestArray, size, 10, 1), incompatibleException);
    EXPECT_EQ(1, intTestArray[0]);
    EXPECT_EQ(2, intTestArray[1]);
    EXPECT_EQ(3, intTestArray[2]);
    EXPECT_EQ(4, intTestArray[3]);
    EXPECT_EQ(5, intTestArray[4]);
    EXPECT_EQ(6, intTestArray[5]);
    EXPECT_EQ(7, intTestArray[6]);
    EXPECT_EQ(8, intTestArray[7]);
    EXPECT_EQ(9, intTestArray[8]);
    EXPECT_EQ(10, intTestArray[9]);
    normalizer.apply(intTestArray, size, 0, 10);
    EXPECT_EQ(0, intTestArray[0]);
    EXPECT_EQ(0, intTestArray[1]);
    EXPECT_EQ(0, intTestArray[2]);
    EXPECT_EQ(0, intTestArray[3]);
    EXPECT_EQ(0, intTestArray[4]);
    EXPECT_EQ(0, intTestArray[5]);
    EXPECT_EQ(0, intTestArray[6]);
    EXPECT_EQ(0, intTestArray[7]);
    EXPECT_EQ(0, intTestArray[8]);
    EXPECT_EQ(1, intTestArray[9]);

    // T = double
    EXPECT_THROW(normalizer.apply(doubleTestArray1, size, 10.0, 1.0), incompatibleException);
    EXPECT_NEAR(1.0, doubleTestArray1[0], EPSILONT);
    EXPECT_NEAR(2.0, doubleTestArray1[1], EPSILONT);
    EXPECT_NEAR(3.0, doubleTestArray1[2], EPSILONT);
    EXPECT_NEAR(4.0, doubleTestArray1[3], EPSILONT);
    EXPECT_NEAR(5.0, doubleTestArray1[4], EPSILONT);
    EXPECT_NEAR(6.0, doubleTestArray1[5], EPSILONT);
    EXPECT_NEAR(7.0, doubleTestArray1[6], EPSILONT);
    EXPECT_NEAR(8.0, doubleTestArray1[7], EPSILONT);
    EXPECT_NEAR(9.0, doubleTestArray1[8], EPSILONT);
    EXPECT_NEAR(10.0, doubleTestArray1[9], EPSILONT);
    normalizer.apply(doubleTestArray1, size, 0.0, 10.0);
    EXPECT_NEAR(0.1, doubleTestArray1[0], EPSILONT);
    EXPECT_NEAR(0.2, doubleTestArray1[1], EPSILONT);
    EXPECT_NEAR(0.3, doubleTestArray1[2], EPSILONT);
    EXPECT_NEAR(0.4, doubleTestArray1[3], EPSILONT);
    EXPECT_NEAR(0.5, doubleTestArray1[4], EPSILONT);
    EXPECT_NEAR(0.6, doubleTestArray1[5], EPSILONT);
    EXPECT_NEAR(0.7, doubleTestArray1[6], EPSILONT);
    EXPECT_NEAR(0.8, doubleTestArray1[7], EPSILONT);
    EXPECT_NEAR(0.9, doubleTestArray1[8], EPSILONT);
    EXPECT_NEAR(1.0, doubleTestArray1[9], EPSILONT);
    normalizer.apply(doubleTestArray2, size, 1.0, 15.0);
    EXPECT_NEAR(0.0, doubleTestArray2[0], EPSILONT);
    EXPECT_GE(doubleTestArray2[1], doubleTestArray2[0]);
    EXPECT_GE(doubleTestArray2[2], doubleTestArray2[1]);
    EXPECT_GE(doubleTestArray2[3], doubleTestArray2[2]);
    EXPECT_GE(doubleTestArray2[4], doubleTestArray2[3]);
    EXPECT_GE(doubleTestArray2[5], doubleTestArray2[4]);
    EXPECT_GE(doubleTestArray2[6], doubleTestArray2[5]);
    EXPECT_GE(doubleTestArray2[7], doubleTestArray2[6]);
    EXPECT_GE(doubleTestArray2[8], doubleTestArray2[7]);
    EXPECT_GE(doubleTestArray2[9], doubleTestArray2[8]);
    EXPECT_GE(1, doubleTestArray2[9]);
    normalizer.apply(doubleTestArray3, size, -10.0, 0.0);
    EXPECT_NEAR(0.0, doubleTestArray3[0], EPSILONT);
    EXPECT_NEAR(0.1, doubleTestArray3[1], EPSILONT);
    EXPECT_NEAR(0.2, doubleTestArray3[2], EPSILONT);
    EXPECT_NEAR(0.3, doubleTestArray3[3], EPSILONT);
    EXPECT_NEAR(0.4, doubleTestArray3[4], EPSILONT);
    EXPECT_NEAR(0.5, doubleTestArray3[5], EPSILONT);
    EXPECT_NEAR(0.6, doubleTestArray3[6], EPSILONT);
    EXPECT_NEAR(0.7, doubleTestArray3[7], EPSILONT);
    EXPECT_NEAR(0.8, doubleTestArray3[8], EPSILONT);
    EXPECT_NEAR(0.9, doubleTestArray3[9], EPSILONT);
    normalizer.apply(doubleTestArray4, size, 0.0, 10.0);
    EXPECT_GE(doubleTestArray4[0], 0.0);
    EXPECT_GE(doubleTestArray4[1], doubleTestArray4[0]);
    EXPECT_GE(doubleTestArray4[2], doubleTestArray4[1]);
    EXPECT_GE(doubleTestArray4[3], doubleTestArray4[2]);
    EXPECT_GE(doubleTestArray4[4], doubleTestArray4[3]);
    EXPECT_GE(doubleTestArray4[5], doubleTestArray4[4]);
    EXPECT_GE(doubleTestArray4[6], doubleTestArray4[5]);
    EXPECT_GE(doubleTestArray4[7], doubleTestArray4[6]);
    EXPECT_GE(doubleTestArray4[8], doubleTestArray4[7]);
    EXPECT_GE(doubleTestArray4[9], doubleTestArray4[8]);
    EXPECT_GE(1, doubleTestArray4[9]);

    // T = float
    EXPECT_THROW(normalizer.apply(floatTestArray1, size, float(10.0), float(1.0)), incompatibleException);
    EXPECT_NEAR(1.0, floatTestArray1[0], EPSILONT);
    EXPECT_NEAR(2.0, floatTestArray1[1], EPSILONT);
    EXPECT_NEAR(3.0, floatTestArray1[2], EPSILONT);
    EXPECT_NEAR(4.0, floatTestArray1[3], EPSILONT);
    EXPECT_NEAR(5.0, floatTestArray1[4], EPSILONT);
    EXPECT_NEAR(6.0, floatTestArray1[5], EPSILONT);
    EXPECT_NEAR(7.0, floatTestArray1[6], EPSILONT);
    EXPECT_NEAR(8.0, floatTestArray1[7], EPSILONT);
    EXPECT_NEAR(9.0, floatTestArray1[8], EPSILONT);
    EXPECT_NEAR(10.0, floatTestArray1[9], EPSILONT);
    normalizer.apply(floatTestArray1, size, float(0.0), float(10.0));
    EXPECT_NEAR(0.1, floatTestArray1[0], EPSILONT);
    EXPECT_NEAR(0.2, floatTestArray1[1], EPSILONT);
    EXPECT_NEAR(0.3, floatTestArray1[2], EPSILONT);
    EXPECT_NEAR(0.4, floatTestArray1[3], EPSILONT);
    EXPECT_NEAR(0.5, floatTestArray1[4], EPSILONT);
    EXPECT_NEAR(0.6, floatTestArray1[5], EPSILONT);
    EXPECT_NEAR(0.7, floatTestArray1[6], EPSILONT);
    EXPECT_NEAR(0.8, floatTestArray1[7], EPSILONT);
    EXPECT_NEAR(0.9, floatTestArray1[8], EPSILONT);
    EXPECT_NEAR(1.0, floatTestArray1[9], EPSILONT);
    normalizer.apply(floatTestArray2, size, float(1.0), float(15.0));
    EXPECT_NEAR(0.0, floatTestArray2[0], EPSILONT);
    EXPECT_GE(floatTestArray2[1], floatTestArray2[0]);
    EXPECT_GE(floatTestArray2[2], floatTestArray2[1]);
    EXPECT_GE(floatTestArray2[3], floatTestArray2[2]);
    EXPECT_GE(floatTestArray2[4], floatTestArray2[3]);
    EXPECT_GE(floatTestArray2[5], floatTestArray2[4]);
    EXPECT_GE(floatTestArray2[6], floatTestArray2[5]);
    EXPECT_GE(floatTestArray2[7], floatTestArray2[6]);
    EXPECT_GE(floatTestArray2[8], floatTestArray2[7]);
    EXPECT_GE(floatTestArray2[9], floatTestArray2[8]);
    EXPECT_GE(1, floatTestArray2[9]);
    normalizer.apply(floatTestArray3, size, float(-10.0), float(0.0));
    EXPECT_NEAR(0.0, floatTestArray3[0], EPSILONT);
    EXPECT_NEAR(0.1, floatTestArray3[1], EPSILONT);
    EXPECT_NEAR(0.2, floatTestArray3[2], EPSILONT);
    EXPECT_NEAR(0.3, floatTestArray3[3], EPSILONT);
    EXPECT_NEAR(0.4, floatTestArray3[4], EPSILONT);
    EXPECT_NEAR(0.5, floatTestArray3[5], EPSILONT);
    EXPECT_NEAR(0.6, floatTestArray3[6], EPSILONT);
    EXPECT_NEAR(0.7, floatTestArray3[7], EPSILONT);
    EXPECT_NEAR(0.8, floatTestArray3[8], EPSILONT);
    EXPECT_NEAR(0.9, floatTestArray3[9], EPSILONT);
    normalizer.apply(floatTestArray4, size, float(0.0), float(10.0));
    EXPECT_GE(floatTestArray4[0], 0.0);
    EXPECT_GE(floatTestArray4[1], floatTestArray4[0]);
    EXPECT_GE(floatTestArray4[2], floatTestArray4[1]);
    EXPECT_GE(floatTestArray4[3], floatTestArray4[2]);
    EXPECT_GE(floatTestArray4[4], floatTestArray4[3]);
    EXPECT_GE(floatTestArray4[5], floatTestArray4[4]);
    EXPECT_GE(floatTestArray4[6], floatTestArray4[5]);
    EXPECT_GE(floatTestArray4[7], floatTestArray4[6]);
    EXPECT_GE(floatTestArray4[8], floatTestArray4[7]);
    EXPECT_GE(floatTestArray4[9], floatTestArray4[8]);
    EXPECT_GE(1, floatTestArray4[9]);

}

TEST(ValueStretcher, valuestretchertest) {

}