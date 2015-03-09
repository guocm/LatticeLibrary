#include "gtest/gtest.h"
#include "fcclattice.h"
#include "exception.h"

using namespace LatticeLib;

TEST(FCCLattice, neighbors) {

    int nRows = 5;
    int nColumns = 6;
    int nLayers = 7;
    int nElements = nRows * nColumns * nLayers;
    double scaleFactor1 = 1.0;
    double scaleFactor2 = 2.5;
    FCCLattice lattice(nRows, nColumns, nLayers, scaleFactor1);
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

    // 12 neighbors
    neighborhoodSize = 12;
    correctNNeighbors = 3;
    lattice.getNeighbors(0, 0, 0, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    correctNNeighbors = 5;
    lattice.getNeighbors(4, 5, 6, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    lattice.getNeighbors(3, 5, 6, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    lattice.getNeighbors(4, 5, 5, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    correctNNeighbors = 8;
    lattice.getNeighbors(1, 0, 0, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    lattice.getNeighbors(0, 0, 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    lattice.getNeighbors(1, 0, 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);

    correctNNeighbors = 12;
    lattice.getNeighbors(3, 5, 5, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    lattice.getNeighbors(2, 3, 4, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    EXPECT_EQ(neighbors[0].getIndex(), FCC12ELER[0]);
    EXPECT_EQ(neighbors[1].getIndex(), FCC12ELER[1]);
    EXPECT_EQ(neighbors[2].getIndex(), FCC12ELER[2]);
    EXPECT_EQ(neighbors[3].getIndex(), FCC12ELER[3]);
    EXPECT_EQ(neighbors[4].getIndex(), FCC12ELER[4]);
    EXPECT_EQ(neighbors[5].getIndex(), FCC12ELER[5]);
    EXPECT_EQ(neighbors[6].getIndex(), FCC12ELER[6]);
    EXPECT_EQ(neighbors[7].getIndex(), FCC12ELER[7]);
    EXPECT_EQ(neighbors[8].getIndex(), FCC12ELER[8]);
    EXPECT_EQ(neighbors[9].getIndex(), FCC12ELER[9]);
    EXPECT_EQ(neighbors[10].getIndex(), FCC12ELER[10]);
    EXPECT_EQ(neighbors[11].getIndex(), FCC12ELER[11]);
    lattice.getNeighbors(lattice.rclToIndex(2, 3, 4), neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    EXPECT_EQ(neighbors[0].getIndex(), FCC12ELER[0]);
    EXPECT_EQ(neighbors[1].getIndex(), FCC12ELER[1]);
    EXPECT_EQ(neighbors[2].getIndex(), FCC12ELER[2]);
    EXPECT_EQ(neighbors[3].getIndex(), FCC12ELER[3]);
    EXPECT_EQ(neighbors[4].getIndex(), FCC12ELER[4]);
    EXPECT_EQ(neighbors[5].getIndex(), FCC12ELER[5]);
    EXPECT_EQ(neighbors[6].getIndex(), FCC12ELER[6]);
    EXPECT_EQ(neighbors[7].getIndex(), FCC12ELER[7]);
    EXPECT_EQ(neighbors[8].getIndex(), FCC12ELER[8]);
    EXPECT_EQ(neighbors[9].getIndex(), FCC12ELER[9]);
    EXPECT_EQ(neighbors[10].getIndex(), FCC12ELER[10]);
    EXPECT_EQ(neighbors[11].getIndex(), FCC12ELER[11]);

    lattice.getNeighbors(3, 2, 2, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    EXPECT_EQ(neighbors[0].getIndex(), FCC12ELOR[0]);
    EXPECT_EQ(neighbors[1].getIndex(), FCC12ELOR[1]);
    EXPECT_EQ(neighbors[2].getIndex(), FCC12ELOR[2]);
    EXPECT_EQ(neighbors[3].getIndex(), FCC12ELOR[3]);
    EXPECT_EQ(neighbors[4].getIndex(), FCC12ELOR[4]);
    EXPECT_EQ(neighbors[5].getIndex(), FCC12ELOR[5]);
    EXPECT_EQ(neighbors[6].getIndex(), FCC12ELOR[6]);
    EXPECT_EQ(neighbors[7].getIndex(), FCC12ELOR[7]);
    EXPECT_EQ(neighbors[8].getIndex(), FCC12ELOR[8]);
    EXPECT_EQ(neighbors[9].getIndex(), FCC12ELOR[9]);
    EXPECT_EQ(neighbors[10].getIndex(), FCC12ELOR[10]);
    EXPECT_EQ(neighbors[11].getIndex(), FCC12ELOR[11]);
    lattice.getNeighbors(lattice.rclToIndex(3, 2, 2), neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    EXPECT_EQ(neighbors[0].getIndex(), FCC12ELOR[0]);
    EXPECT_EQ(neighbors[1].getIndex(), FCC12ELOR[1]);
    EXPECT_EQ(neighbors[2].getIndex(), FCC12ELOR[2]);
    EXPECT_EQ(neighbors[3].getIndex(), FCC12ELOR[3]);
    EXPECT_EQ(neighbors[4].getIndex(), FCC12ELOR[4]);
    EXPECT_EQ(neighbors[5].getIndex(), FCC12ELOR[5]);
    EXPECT_EQ(neighbors[6].getIndex(), FCC12ELOR[6]);
    EXPECT_EQ(neighbors[7].getIndex(), FCC12ELOR[7]);
    EXPECT_EQ(neighbors[8].getIndex(), FCC12ELOR[8]);
    EXPECT_EQ(neighbors[9].getIndex(), FCC12ELOR[9]);
    EXPECT_EQ(neighbors[10].getIndex(), FCC12ELOR[10]);
    EXPECT_EQ(neighbors[11].getIndex(), FCC12ELOR[11]);

    lattice.getNeighbors(2, 3, 3, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    EXPECT_EQ(neighbors[0].getIndex(), FCC12OLER[0]);
    EXPECT_EQ(neighbors[1].getIndex(), FCC12OLER[1]);
    EXPECT_EQ(neighbors[2].getIndex(), FCC12OLER[2]);
    EXPECT_EQ(neighbors[3].getIndex(), FCC12OLER[3]);
    EXPECT_EQ(neighbors[4].getIndex(), FCC12OLER[4]);
    EXPECT_EQ(neighbors[5].getIndex(), FCC12OLER[5]);
    EXPECT_EQ(neighbors[6].getIndex(), FCC12OLER[6]);
    EXPECT_EQ(neighbors[7].getIndex(), FCC12OLER[7]);
    EXPECT_EQ(neighbors[8].getIndex(), FCC12OLER[8]);
    EXPECT_EQ(neighbors[9].getIndex(), FCC12OLER[9]);
    EXPECT_EQ(neighbors[10].getIndex(), FCC12OLER[10]);
    EXPECT_EQ(neighbors[11].getIndex(), FCC12OLER[11]);
    lattice.getNeighbors(lattice.rclToIndex(2, 3, 3), neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    EXPECT_EQ(neighbors[0].getIndex(), FCC12OLER[0]);
    EXPECT_EQ(neighbors[1].getIndex(), FCC12OLER[1]);
    EXPECT_EQ(neighbors[2].getIndex(), FCC12OLER[2]);
    EXPECT_EQ(neighbors[3].getIndex(), FCC12OLER[3]);
    EXPECT_EQ(neighbors[4].getIndex(), FCC12OLER[4]);
    EXPECT_EQ(neighbors[5].getIndex(), FCC12OLER[5]);
    EXPECT_EQ(neighbors[6].getIndex(), FCC12OLER[6]);
    EXPECT_EQ(neighbors[7].getIndex(), FCC12OLER[7]);
    EXPECT_EQ(neighbors[8].getIndex(), FCC12OLER[8]);
    EXPECT_EQ(neighbors[9].getIndex(), FCC12OLER[9]);
    EXPECT_EQ(neighbors[10].getIndex(), FCC12OLER[10]);
    EXPECT_EQ(neighbors[11].getIndex(), FCC12OLER[11]);

    lattice.getNeighbors(3, 2, 3, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    EXPECT_EQ(neighbors[0].getIndex(), FCC12OLOR[0]);
    EXPECT_EQ(neighbors[1].getIndex(), FCC12OLOR[1]);
    EXPECT_EQ(neighbors[2].getIndex(), FCC12OLOR[2]);
    EXPECT_EQ(neighbors[3].getIndex(), FCC12OLOR[3]);
    EXPECT_EQ(neighbors[4].getIndex(), FCC12OLOR[4]);
    EXPECT_EQ(neighbors[5].getIndex(), FCC12OLOR[5]);
    EXPECT_EQ(neighbors[6].getIndex(), FCC12OLOR[6]);
    EXPECT_EQ(neighbors[7].getIndex(), FCC12OLOR[7]);
    EXPECT_EQ(neighbors[8].getIndex(), FCC12OLOR[8]);
    EXPECT_EQ(neighbors[9].getIndex(), FCC12OLOR[9]);
    EXPECT_EQ(neighbors[10].getIndex(), FCC12OLOR[10]);
    EXPECT_EQ(neighbors[11].getIndex(), FCC12OLOR[11]);
    lattice.getNeighbors(lattice.rclToIndex(3, 2, 3), neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    EXPECT_EQ(neighbors[0].getIndex(), FCC12OLOR[0]);
    EXPECT_EQ(neighbors[1].getIndex(), FCC12OLOR[1]);
    EXPECT_EQ(neighbors[2].getIndex(), FCC12OLOR[2]);
    EXPECT_EQ(neighbors[3].getIndex(), FCC12OLOR[3]);
    EXPECT_EQ(neighbors[4].getIndex(), FCC12OLOR[4]);
    EXPECT_EQ(neighbors[5].getIndex(), FCC12OLOR[5]);
    EXPECT_EQ(neighbors[6].getIndex(), FCC12OLOR[6]);
    EXPECT_EQ(neighbors[7].getIndex(), FCC12OLOR[7]);
    EXPECT_EQ(neighbors[8].getIndex(), FCC12OLOR[8]);
    EXPECT_EQ(neighbors[9].getIndex(), FCC12OLOR[9]);
    EXPECT_EQ(neighbors[10].getIndex(), FCC12OLOR[10]);
    EXPECT_EQ(neighbors[11].getIndex(), FCC12OLOR[11]);

    // 18 neighbors
    neighborhoodSize = 18;
    correctNNeighbors = 6;
    lattice.getNeighbors(0, 0, 0, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    correctNNeighbors = 8;
    lattice.getNeighbors(4, 5, 6, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    lattice.getNeighbors(3, 5, 6, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    lattice.getNeighbors(4, 5, 5, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    correctNNeighbors = 11;
    lattice.getNeighbors(1, 0, 0, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    lattice.getNeighbors(0, 0, 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    lattice.getNeighbors(1, 0, 1, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);
    correctNNeighbors = 15;
    lattice.getNeighbors(3, 5, 5, neighborhoodSize, neighbors);
    EXPECT_EQ(neighbors.size(), correctNNeighbors);

    correctNNeighbors = 17;
    lattice.getNeighbors(3, 2, 2, neighborhoodSize, neighbors);
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
    lattice.getNeighbors(lattice.rclToIndex(3, 2, 2), neighborhoodSize, neighbors);
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

    lattice.getNeighbors(3, 2, 3, neighborhoodSize, neighbors);
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
    lattice.getNeighbors(lattice.rclToIndex(3, 2, 3), neighborhoodSize, neighbors);
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
    lattice.getNeighbors(2, 3, 4, neighborhoodSize, neighbors);
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
    lattice.getNeighbors(lattice.rclToIndex(2, 3, 4), neighborhoodSize, neighbors);
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

    lattice.getNeighbors(2, 3, 3, neighborhoodSize, neighbors);
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
    lattice.getNeighbors(lattice.rclToIndex(2, 3, 3), neighborhoodSize, neighbors);
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

    // Exceptions
    neighborhoodSize = 12;
    EXPECT_THROW(lattice.getNeighbors(nRows, 0, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(lattice.getNeighbors(-1, 0, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(lattice.getNeighbors(0, nColumns, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(lattice.getNeighbors(0, -1, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(lattice.getNeighbors(0, 0, nLayers, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(lattice.getNeighbors(0, 0, -1, neighborhoodSize, neighbors), outsideRangeException);
    neighborhoodSize = 18;
    EXPECT_THROW(lattice.getNeighbors(nRows, 0, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(lattice.getNeighbors(-1, 0, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(lattice.getNeighbors(0, nColumns, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(lattice.getNeighbors(0, -1, 0, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(lattice.getNeighbors(0, 0, nLayers, neighborhoodSize, neighbors), outsideRangeException);
    EXPECT_THROW(lattice.getNeighbors(0, 0, -1, neighborhoodSize, neighbors), outsideRangeException);
    neighborhoodSize = 6;
    EXPECT_THROW(lattice.getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = 8;
    EXPECT_THROW(lattice.getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = 14;
    EXPECT_THROW(lattice.getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = 26;
    EXPECT_THROW(lattice.getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = -12;
    EXPECT_THROW(lattice.getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = 0;
    EXPECT_THROW(lattice.getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
    neighborhoodSize = 100;
    EXPECT_THROW(lattice.getNeighbors(0, 0, 0, neighborhoodSize, neighbors), neighborhoodSizeException);
}