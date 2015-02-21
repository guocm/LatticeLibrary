#include "gtest/gtest.h"
#include "cclattice.h"
#include "bcclattice.h"
#include "fcclattice.h"
#include "cimage.h"
#include "exception.h"

using namespace CImage;

TEST(CImage, neighbors) {

    int nRows = 5;
    int nColumns = 6;
    int nLayers = 7;
    int nElements = nRows * nColumns * nLayers;
    double scaleFactor = 1.0;
    CCLattice *latticeCC = new CCLattice(nRows, nColumns, nLayers, scaleFactor);
    BCCLattice *latticeBCC = new BCCLattice(nRows, nColumns, nLayers, scaleFactor);
    FCCLattice *latticeFCC = new FCCLattice(nRows, nColumns, nLayers, scaleFactor);
    int nBands = 1;
    uint8 data[nElements];
    for (int i = 0; i < nElements; i++) {
        data[i] = 0;
    }
    CImage<uint8> *imageCC = new CImage<uint8>(data, *latticeCC, nBands);
    CImage<uint8> *imageBCC = new CImage<uint8>(data, *latticeBCC, nBands);
    CImage<uint8> *imageFCC = new CImage<uint8>(data, *latticeFCC, nBands);

    //{r,l,bo,t,f,ba,   bor,tr,bar,fr,bol,tl,bal,fl,boba,bof,tba,tf,   bofr,tfr,tbar,bobar,bofl,tfl,tbal,bobal}
    int CC6[6] = {171, 169, 176, 164, 140, 200};
    int CC18[18] = {171, 169, 176, 164, 140, 200, 177, 165, 201, 141, 175, 163, 199, 139, 206, 146, 194, 134};
    int CC26[26] = {171, 169, 176, 164, 140, 200, 177, 165, 201, 141, 175, 163, 199, 139, 206, 146, 194, 134, 147, 135, 195, 207, 145, 133, 193, 205};
    // {tlf,trf,bolf,borf,tlba,trba,bolba,borba,   t,f,l,ba,r,bo}
    int BCC8EL[8] = {45, 46, 51, 52, 105, 106, 111, 112};
    int BCC8OL[8] = {82, 83, 88, 89, 142, 143, 148, 149};
    int BCC14EL[14] = {45, 46, 51, 52, 105, 106, 111, 112, 76, 22, 81, 142, 83, 88};
    int BCC14OL[14] = {82, 83, 88, 89, 142, 143, 148, 149, 106, 52, 111, 172, 113, 118};
    // {tf,tl,tba,tr,fl,bal,bar,fr,bof,bol,boba,bor,   t,f,l,ba,r,bo}
    int FCC12ELER[12] = {99, 128, 159, 129, 104, 164, 165, 105, 111, 140, 171, 141};
    int FCC12ELOR[12] = {44, 74, 104, 75, 50, 110, 111, 51, 56, 86, 116, 87};
    int FCC12OLER[12] = {69, 99, 129, 100, 75, 135, 136, 76, 81, 111, 141, 112};
    int FCC12OLOR[12] = {74, 103, 134, 104, 79, 139, 140, 80, 86, 115, 146, 116};
    int FCC18ELER[18] = {99, 128, 159, 129, 104, 164, 165, 105, 111, 140, 171, 141, 123, 75, 134, 195, 136, 147};
    int FCC18ELOR[18] = {44, 74, 104, 75, 50, 110, 111, 51, 56, 86, 116, 87, 68, 20, 79, 140, 81}; // bottom missing
    int FCC18OLER[18] = {69, 99, 129, 100, 75, 135, 136, 76, 81, 111, 141, 112, 93, 45, 104, 165, 106, 117};
    int FCC18OLOR[18] = {74, 103, 134, 104, 79, 139, 140, 80, 86, 115, 146, 116, 98, 50, 109, 170, 111}; // bottom missing

    vector<Neighbor> neighbors;
    int neighborhoodSize, correctNNeighbors;

    // CC 26-neighborhood
    neighborhoodSize = 26;
    correctNNeighbors = 26;
    imageCC->getNeighbors(3, 2, 5, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    EXPECT_EQ(neighbors[0].getIndex(), CC26[0]);
    EXPECT_EQ(neighbors[1].getIndex(), CC26[1]);
    EXPECT_EQ(neighbors[2].getIndex(), CC26[2]);
    EXPECT_EQ(neighbors[3].getIndex(), CC26[3]);
    EXPECT_EQ(neighbors[4].getIndex(), CC26[4]);
    EXPECT_EQ(neighbors[5].getIndex(), CC26[5]);
    EXPECT_EQ(neighbors[6].getIndex(), CC26[6]);
    EXPECT_EQ(neighbors[7].getIndex(), CC26[7]);
    EXPECT_EQ(neighbors[8].getIndex(), CC26[8]);
    EXPECT_EQ(neighbors[9].getIndex(), CC26[9]);
    EXPECT_EQ(neighbors[10].getIndex(), CC26[10]);
    EXPECT_EQ(neighbors[11].getIndex(), CC26[11]);
    EXPECT_EQ(neighbors[12].getIndex(), CC26[12]);
    EXPECT_EQ(neighbors[13].getIndex(), CC26[13]);
    EXPECT_EQ(neighbors[14].getIndex(), CC26[14]);
    EXPECT_EQ(neighbors[15].getIndex(), CC26[15]);
    EXPECT_EQ(neighbors[16].getIndex(), CC26[16]);
    EXPECT_EQ(neighbors[17].getIndex(), CC26[17]);
    EXPECT_EQ(neighbors[18].getIndex(), CC26[18]);
    EXPECT_EQ(neighbors[19].getIndex(), CC26[19]);
    EXPECT_EQ(neighbors[20].getIndex(), CC26[20]);
    EXPECT_EQ(neighbors[21].getIndex(), CC26[21]);
    EXPECT_EQ(neighbors[22].getIndex(), CC26[22]);
    EXPECT_EQ(neighbors[23].getIndex(), CC26[23]);
    EXPECT_EQ(neighbors[24].getIndex(), CC26[24]);
    EXPECT_EQ(neighbors[25].getIndex(), CC26[25]);
    correctNNeighbors = 7;
    imageCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(nRows - 1, nColumns - 1, nLayers - 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(nRows - 1, 0, 0, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(0, nColumns - 1, 0, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(0, 0, nLayers - 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(0, nColumns - 1, nLayers - 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(nRows - 1, 0, nLayers - 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(nRows - 1, nColumns - 1, 0, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    correctNNeighbors = 11;
    imageCC->getNeighbors(1, 0, 0, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(0, 1, 0, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(0, 0, 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(1, nColumns - 1, nLayers - 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(nRows - 1, 1, nLayers - 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(nRows - 1, nColumns - 1, 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(0, nColumns - 1, 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(0, 1, nLayers - 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(0, nColumns - 1, 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(1, nColumns - 1, 0, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(nRows - 1, 1, 0, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(1, nColumns - 1, 0, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    correctNNeighbors = 17;
    imageCC->getNeighbors(0, 1, 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(1, 0, 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(1, 1, 0, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(nRows - 1, nColumns - 2, nLayers - 2, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(nRows - 2, nColumns - 1, nLayers - 2, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageCC->getNeighbors(nRows - 2, nColumns - 2, nLayers - 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    neighborhoodSize = 6;
    EXPECT_THROW(imageCC->getNeighbors(nRows, 0, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageCC->getNeighbors(-1, 0, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageCC->getNeighbors(0, nColumns, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageCC->getNeighbors(0, -1, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageCC->getNeighbors(0, 0, nLayers, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageCC->getNeighbors(0, 0, -1, neighborhoodSize, neighbors), outsideRangeException);
    neighborhoodSize = 18;
    EXPECT_THROW(imageCC->getNeighbors(nRows, 0, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageCC->getNeighbors(-1, 0, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageCC->getNeighbors(0, nColumns, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageCC->getNeighbors(0, -1, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageCC->getNeighbors(0, 0, nLayers, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageCC->getNeighbors(0, 0, -1, neighborhoodSize, neighbors), outsideRangeException);
    neighborhoodSize = 26;
    EXPECT_THROW(imageCC->getNeighbors(nRows, 0, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageCC->getNeighbors(-1, 0, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageCC->getNeighbors(0, nColumns, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageCC->getNeighbors(0, -1, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageCC->getNeighbors(0, 0, nLayers, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageCC->getNeighbors(0, 0, -1, neighborhoodSize, neighbors), outsideRangeException);
    neighborhoodSize = 8;
    EXPECT_THROW(imageCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = 12;
    EXPECT_THROW(imageCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = 14;
    EXPECT_THROW(imageCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    // neighborhoodSize = 18 is valid for both CC and FCC.
    neighborhoodSize = -6;
    EXPECT_THROW(imageCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = 0;
    EXPECT_THROW(imageCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = 100;
    EXPECT_THROW(imageCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);

    // BCC 14 neighbors
    neighborhoodSize = 14;
    correctNNeighbors = 14;
    imageBCC->getNeighbors(3, 4, 2, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    EXPECT_EQ(neighbors[0].getIndex(), BCC14EL[0]);
    EXPECT_EQ(neighbors[1].getIndex(), BCC14EL[1]);
    EXPECT_EQ(neighbors[2].getIndex(), BCC14EL[2]);
    EXPECT_EQ(neighbors[3].getIndex(), BCC14EL[3]);
    EXPECT_EQ(neighbors[4].getIndex(), BCC14EL[4]);
    EXPECT_EQ(neighbors[5].getIndex(), BCC14EL[5]);
    EXPECT_EQ(neighbors[6].getIndex(), BCC14EL[6]);
    EXPECT_EQ(neighbors[7].getIndex(), BCC14EL[7]);
    EXPECT_EQ(neighbors[8].getIndex(), BCC14EL[8]);
    EXPECT_EQ(neighbors[9].getIndex(), BCC14EL[9]);
    EXPECT_EQ(neighbors[10].getIndex(), BCC14EL[10]);
    EXPECT_EQ(neighbors[11].getIndex(), BCC14EL[11]);
    EXPECT_EQ(neighbors[12].getIndex(), BCC14EL[12]);
    EXPECT_EQ(neighbors[13].getIndex(), BCC14EL[13]);
    imageBCC->getNeighbors(3, 4, 3, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    EXPECT_EQ(neighbors[0].getIndex(), BCC14OL[0]);
    EXPECT_EQ(neighbors[1].getIndex(), BCC14OL[1]);
    EXPECT_EQ(neighbors[2].getIndex(), BCC14OL[2]);
    EXPECT_EQ(neighbors[3].getIndex(), BCC14OL[3]);
    EXPECT_EQ(neighbors[4].getIndex(), BCC14OL[4]);
    EXPECT_EQ(neighbors[5].getIndex(), BCC14OL[5]);
    EXPECT_EQ(neighbors[6].getIndex(), BCC14OL[6]);
    EXPECT_EQ(neighbors[7].getIndex(), BCC14OL[7]);
    EXPECT_EQ(neighbors[8].getIndex(), BCC14OL[8]);
    EXPECT_EQ(neighbors[9].getIndex(), BCC14OL[9]);
    EXPECT_EQ(neighbors[10].getIndex(), BCC14OL[10]);
    EXPECT_EQ(neighbors[11].getIndex(), BCC14OL[11]);
    EXPECT_EQ(neighbors[12].getIndex(), BCC14OL[12]);
    EXPECT_EQ(neighbors[13].getIndex(), BCC14OL[13]);
    correctNNeighbors = 4;
    imageBCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    correctNNeighbors = 5;
    imageBCC->getNeighbors(4, 0, 6, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    correctNNeighbors = 7;
    imageBCC->getNeighbors(nRows - 1, nColumns - 1, nLayers - 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageBCC->getNeighbors(0, 5, 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageBCC->getNeighbors(4, 0, 5, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    neighborhoodSize = 8;
    EXPECT_THROW(imageBCC->getNeighbors(nRows, 0, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageBCC->getNeighbors(-1, 0, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageBCC->getNeighbors(0, nColumns, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageBCC->getNeighbors(0, -1, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageBCC->getNeighbors(0, 0, nLayers, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageBCC->getNeighbors(0, 0, -1, neighborhoodSize, neighbors), outsideRangeException);
    neighborhoodSize = 14;
    EXPECT_THROW(imageBCC->getNeighbors(nRows, 0, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageBCC->getNeighbors(-1, 0, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageBCC->getNeighbors(0, nColumns, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageBCC->getNeighbors(0, -1, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageBCC->getNeighbors(0, 0, nLayers, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageBCC->getNeighbors(0, 0, -1, neighborhoodSize, neighbors), outsideRangeException);
    neighborhoodSize = 6;
    EXPECT_THROW(imageBCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = 12;
    EXPECT_THROW(imageBCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = 18;
    EXPECT_THROW(imageBCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = 26;
    EXPECT_THROW(imageBCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = -8;
    EXPECT_THROW(imageBCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = 0;
    EXPECT_THROW(imageBCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = 100;
    EXPECT_THROW(imageBCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);

    // FCC 18 neighbors
    neighborhoodSize = 18;
    correctNNeighbors = 17;
    imageFCC->getNeighbors(3, 2, 2, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    EXPECT_EQ(neighbors[0].getIndex(), FCC18ELOR[0]);
    EXPECT_EQ(neighbors[1].getIndex(), FCC18ELOR[1]);
    EXPECT_EQ(neighbors[2].getIndex(), FCC18ELOR[2]);
    EXPECT_EQ(neighbors[3].getIndex(), FCC18ELOR[3]);
    EXPECT_EQ(neighbors[4].getIndex(), FCC18ELOR[4]);
    EXPECT_EQ(neighbors[5].getIndex(), FCC18ELOR[5]);
    EXPECT_EQ(neighbors[6].getIndex(), FCC18ELOR[6]);
    EXPECT_EQ(neighbors[7].getIndex(), FCC18ELOR[7]);
    EXPECT_EQ(neighbors[8].getIndex(), FCC18ELOR[8]);
    EXPECT_EQ(neighbors[9].getIndex(), FCC18ELOR[9]);
    EXPECT_EQ(neighbors[10].getIndex(), FCC18ELOR[10]);
    EXPECT_EQ(neighbors[11].getIndex(), FCC18ELOR[11]);
    EXPECT_EQ(neighbors[12].getIndex(), FCC18ELOR[12]);
    EXPECT_EQ(neighbors[13].getIndex(), FCC18ELOR[13]);
    EXPECT_EQ(neighbors[14].getIndex(), FCC18ELOR[14]);
    EXPECT_EQ(neighbors[15].getIndex(), FCC18ELOR[15]);
    EXPECT_EQ(neighbors[16].getIndex(), FCC18ELOR[16]);
    imageFCC->getNeighbors(3, 2, 3, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    EXPECT_EQ(neighbors[0].getIndex(), FCC18OLOR[0]);
    EXPECT_EQ(neighbors[1].getIndex(), FCC18OLOR[1]);
    EXPECT_EQ(neighbors[2].getIndex(), FCC18OLOR[2]);
    EXPECT_EQ(neighbors[3].getIndex(), FCC18OLOR[3]);
    EXPECT_EQ(neighbors[4].getIndex(), FCC18OLOR[4]);
    EXPECT_EQ(neighbors[5].getIndex(), FCC18OLOR[5]);
    EXPECT_EQ(neighbors[6].getIndex(), FCC18OLOR[6]);
    EXPECT_EQ(neighbors[7].getIndex(), FCC18OLOR[7]);
    EXPECT_EQ(neighbors[8].getIndex(), FCC18OLOR[8]);
    EXPECT_EQ(neighbors[9].getIndex(), FCC18OLOR[9]);
    EXPECT_EQ(neighbors[10].getIndex(), FCC18OLOR[10]);
    EXPECT_EQ(neighbors[11].getIndex(), FCC18OLOR[11]);
    EXPECT_EQ(neighbors[12].getIndex(), FCC18OLOR[12]);
    EXPECT_EQ(neighbors[13].getIndex(), FCC18OLOR[13]);
    EXPECT_EQ(neighbors[14].getIndex(), FCC18OLOR[14]);
    EXPECT_EQ(neighbors[15].getIndex(), FCC18OLOR[15]);
    EXPECT_EQ(neighbors[16].getIndex(), FCC18OLOR[16]);
    correctNNeighbors = 18;
    imageFCC->getNeighbors(2, 3, 4, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    EXPECT_EQ(neighbors[0].getIndex(), FCC18ELER[0]);
    EXPECT_EQ(neighbors[1].getIndex(), FCC18ELER[1]);
    EXPECT_EQ(neighbors[2].getIndex(), FCC18ELER[2]);
    EXPECT_EQ(neighbors[3].getIndex(), FCC18ELER[3]);
    EXPECT_EQ(neighbors[4].getIndex(), FCC18ELER[4]);
    EXPECT_EQ(neighbors[5].getIndex(), FCC18ELER[5]);
    EXPECT_EQ(neighbors[6].getIndex(), FCC18ELER[6]);
    EXPECT_EQ(neighbors[7].getIndex(), FCC18ELER[7]);
    EXPECT_EQ(neighbors[8].getIndex(), FCC18ELER[8]);
    EXPECT_EQ(neighbors[9].getIndex(), FCC18ELER[9]);
    EXPECT_EQ(neighbors[10].getIndex(), FCC18ELER[10]);
    EXPECT_EQ(neighbors[11].getIndex(), FCC18ELER[11]);
    EXPECT_EQ(neighbors[12].getIndex(), FCC18ELER[12]);
    EXPECT_EQ(neighbors[13].getIndex(), FCC18ELER[13]);
    EXPECT_EQ(neighbors[14].getIndex(), FCC18ELER[14]);
    EXPECT_EQ(neighbors[15].getIndex(), FCC18ELER[15]);
    EXPECT_EQ(neighbors[16].getIndex(), FCC18ELER[16]);
    EXPECT_EQ(neighbors[17].getIndex(), FCC18ELER[17]);
    imageFCC->getNeighbors(2, 3, 3, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    EXPECT_EQ(neighbors[0].getIndex(), FCC18OLER[0]);
    EXPECT_EQ(neighbors[1].getIndex(), FCC18OLER[1]);
    EXPECT_EQ(neighbors[2].getIndex(), FCC18OLER[2]);
    EXPECT_EQ(neighbors[3].getIndex(), FCC18OLER[3]);
    EXPECT_EQ(neighbors[4].getIndex(), FCC18OLER[4]);
    EXPECT_EQ(neighbors[5].getIndex(), FCC18OLER[5]);
    EXPECT_EQ(neighbors[6].getIndex(), FCC18OLER[6]);
    EXPECT_EQ(neighbors[7].getIndex(), FCC18OLER[7]);
    EXPECT_EQ(neighbors[8].getIndex(), FCC18OLER[8]);
    EXPECT_EQ(neighbors[9].getIndex(), FCC18OLER[9]);
    EXPECT_EQ(neighbors[10].getIndex(), FCC18OLER[10]);
    EXPECT_EQ(neighbors[11].getIndex(), FCC18OLER[11]);
    EXPECT_EQ(neighbors[12].getIndex(), FCC18OLER[12]);
    EXPECT_EQ(neighbors[13].getIndex(), FCC18OLER[13]);
    EXPECT_EQ(neighbors[14].getIndex(), FCC18OLER[14]);
    EXPECT_EQ(neighbors[15].getIndex(), FCC18OLER[15]);
    EXPECT_EQ(neighbors[16].getIndex(), FCC18OLER[16]);
    EXPECT_EQ(neighbors[17].getIndex(), FCC18OLER[17]);
    correctNNeighbors = 6;
    imageFCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    correctNNeighbors = 8;
    imageFCC->getNeighbors(4, 5, 6, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageFCC->getNeighbors(3, 5, 6, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageFCC->getNeighbors(4, 5, 5, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    correctNNeighbors = 11;
    imageFCC->getNeighbors(1, 0, 0, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageFCC->getNeighbors(0, 0, 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    imageFCC->getNeighbors(1, 0, 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    correctNNeighbors = 15;
    imageFCC->getNeighbors(3, 5, 5, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    neighborhoodSize = 12;
    EXPECT_THROW(imageFCC->getNeighbors(nRows, 0, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageFCC->getNeighbors(-1, 0, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageFCC->getNeighbors(0, nColumns, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageFCC->getNeighbors(0, -1, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageFCC->getNeighbors(0, 0, nLayers, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageFCC->getNeighbors(0, 0, -1, neighborhoodSize, neighbors), outsideRangeException);
    neighborhoodSize = 18;
    EXPECT_THROW(imageFCC->getNeighbors(nRows, 0, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageFCC->getNeighbors(-1, 0, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageFCC->getNeighbors(0, nColumns, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageFCC->getNeighbors(0, -1, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageFCC->getNeighbors(0, 0, nLayers, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(imageFCC->getNeighbors(0, 0, -1, neighborhoodSize, neighbors), outsideRangeException);
    neighborhoodSize = 6;
    EXPECT_THROW(imageFCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = 8;
    EXPECT_THROW(imageFCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = 14;
    EXPECT_THROW(imageFCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = 26;
    EXPECT_THROW(imageFCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = -12;
    EXPECT_THROW(imageFCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = 0;
    EXPECT_THROW(imageFCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = 100;
    EXPECT_THROW(imageFCC->getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);

    delete latticeCC;
    delete latticeBCC;
    delete latticeFCC;
    delete imageCC;
    delete imageBCC;
    delete imageFCC;
}