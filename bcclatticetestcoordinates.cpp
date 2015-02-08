#include "gtest/gtest.h"
#include "defs.h"
#include "bcclattice.h"
#include <cmath>

using namespace CImage;

TEST(BCCLattice,coordinates) {

    int nRows = 5;
    int nColumns = 6;
    int nLayers = 7;
    int nElements = nRows * nColumns * nLayers;
    double scaleFactor1 = 1.0;
    double scaleFactor2 = 2.5;
    BCCLattice *lattice1 = new BCCLattice(nRows, nColumns, nLayers, scaleFactor1);
    BCCLattice *lattice2 = new BCCLattice(nRows, nColumns, nLayers, scaleFactor2);

    // "1D" lattices
    BCCLattice *lattice1Column1Layer = new BCCLattice(nElements, 1, 1, scaleFactor1);
    BCCLattice *lattice1Row1Layer = new BCCLattice(1, nElements, 1, scaleFactor1);
    BCCLattice *lattice1Row1Column = new BCCLattice(1, 1, nElements, scaleFactor1);

    // "2D" lattices
    int n1 = 15;
    int n2 = 14;
    BCCLattice *lattice1Layer = new BCCLattice(n1, n2, 1, scaleFactor1);
    BCCLattice *lattice1Column = new BCCLattice(n1, 1, n2, scaleFactor1);
    BCCLattice *lattice1Row = new BCCLattice(1, n1, n2, scaleFactor1);

    vector<double> coordinates;

    // spel coordinates
    EXPECT_NEAR(lattice1->indexToX(0), BCCOFFSET, EPSILONT);
    EXPECT_NEAR(lattice1->indexToY(0), BCCOFFSET, EPSILONT);
    EXPECT_NEAR(lattice1->indexToZ(0), BCCOFFSET, EPSILONT);
    EXPECT_NEAR(lattice1->indexToX(82), BCCOFFSET + 4 * BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1->indexToY(82), BCCOFFSET + 3 * BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1->indexToZ(82), BCCOFFSET + BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1->indexToX(112), BCCOFFSET + 9 * BCCOFFSET, EPSILONT);
    EXPECT_NEAR(lattice1->indexToY(112), BCCOFFSET + 7 * BCCOFFSET, EPSILONT);
    EXPECT_NEAR(lattice1->indexToZ(112), BCCOFFSET + 3 * BCCOFFSET, EPSILONT);
    EXPECT_NEAR(lattice1->indexToX(209), BCCOFFSET + 5 * BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1->indexToY(209), BCCOFFSET + 4 * BCCSQFACEDISTANCE, EPSILONT); // !!!!!!
    EXPECT_NEAR(lattice1->indexToZ(209), BCCOFFSET + 3 * BCCSQFACEDISTANCE, EPSILONT);

    lattice1->getCoordinates(0, coordinates);
    EXPECT_NEAR(coordinates[0], BCCOFFSET, EPSILONT);
    EXPECT_NEAR(coordinates[1], BCCOFFSET, EPSILONT);
    EXPECT_NEAR(coordinates[2], BCCOFFSET, EPSILONT);
    lattice1->getCoordinates(82, coordinates);
    EXPECT_NEAR(coordinates[0], BCCOFFSET + 4 * BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(coordinates[1], BCCOFFSET + 3 * BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(coordinates[2], BCCOFFSET + BCCSQFACEDISTANCE, EPSILONT);
    lattice1->getCoordinates(112, coordinates);
    EXPECT_NEAR(coordinates[0], BCCOFFSET + 9 * BCCOFFSET, EPSILONT);
    EXPECT_NEAR(coordinates[1], BCCOFFSET + 7 * BCCOFFSET, EPSILONT);
    EXPECT_NEAR(coordinates[2], BCCOFFSET + 3 * BCCOFFSET, EPSILONT);
    lattice1->getCoordinates(209, coordinates);
    EXPECT_NEAR(coordinates[0], BCCOFFSET + 5 * BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(coordinates[1], BCCOFFSET + 4 * BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(coordinates[2], BCCOFFSET + 3 * BCCSQFACEDISTANCE, EPSILONT);


    EXPECT_NEAR(lattice2->indexToX(0), scaleFactor2 * (BCCOFFSET), EPSILONT);
    EXPECT_NEAR(lattice2->indexToY(0), scaleFactor2 * (BCCOFFSET), EPSILONT);
    EXPECT_NEAR(lattice2->indexToZ(0), scaleFactor2 * (BCCOFFSET), EPSILONT);
    EXPECT_NEAR(lattice2->indexToX(82), scaleFactor2 * (BCCOFFSET + 4 * BCCSQFACEDISTANCE), EPSILONT);
    EXPECT_NEAR(lattice2->indexToY(82), scaleFactor2 * (BCCOFFSET + 3 * BCCSQFACEDISTANCE), EPSILONT);
    EXPECT_NEAR(lattice2->indexToZ(82), scaleFactor2 * (BCCOFFSET + BCCSQFACEDISTANCE), EPSILONT);
    EXPECT_NEAR(lattice2->indexToX(112), scaleFactor2 * (BCCOFFSET + 9 * BCCOFFSET), EPSILONT);
    EXPECT_NEAR(lattice2->indexToY(112), scaleFactor2 * (BCCOFFSET + 7 * BCCOFFSET), EPSILONT);
    EXPECT_NEAR(lattice2->indexToZ(112), scaleFactor2 * (BCCOFFSET + 3 * BCCOFFSET), EPSILONT);
    EXPECT_NEAR(lattice2->indexToX(209), scaleFactor2 * (BCCOFFSET + 5 * BCCSQFACEDISTANCE), EPSILONT);
    EXPECT_NEAR(lattice2->indexToY(209), scaleFactor2 * (BCCOFFSET + 4 * BCCSQFACEDISTANCE), EPSILONT); // !!!!!!
    EXPECT_NEAR(lattice2->indexToZ(209), scaleFactor2 * (BCCOFFSET + 3 * BCCSQFACEDISTANCE), EPSILONT);

    EXPECT_GT(lattice2->indexToX(170) - lattice1->indexToX(170), EPSILONT);
    EXPECT_GT(lattice2->indexToY(170) - lattice1->indexToY(170), EPSILONT);
    EXPECT_GT(lattice2->indexToZ(170) - lattice1->indexToZ(170), EPSILONT);
    EXPECT_GT(lattice2->indexToX(209) - lattice1->indexToX(209), EPSILONT);
    EXPECT_GT(lattice2->indexToY(209) - lattice1->indexToY(209), EPSILONT);
    EXPECT_GT(lattice2->indexToZ(209) - lattice1->indexToZ(209), EPSILONT);
    EXPECT_GT(lattice2->indexToX(nElements - 1) - lattice1->indexToX(nElements - 1), EPSILONT);
    EXPECT_GT(lattice2->indexToY(nElements - 1) - lattice1->indexToY(nElements - 1), EPSILONT);
    EXPECT_GT(lattice2->indexToZ(nElements - 1) - lattice1->indexToZ(nElements - 1), EPSILONT);

    // width, height and depth
    EXPECT_NEAR(lattice1->getWidth(), 6.5 * BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1->getHeight(), 5.5 * BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1->getDepth(), 4 * BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice2->getWidth(), scaleFactor2 * 6.5 * BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice2->getHeight(), scaleFactor2 * 5.5 * BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice2->getDepth(), scaleFactor2 * 4 * BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1Column1Layer->getWidth(), BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1Column1Layer->getHeight(), nElements* BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1Column1Layer->getDepth(), BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1Row1Layer->getWidth(), nElements* BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1Row1Layer->getHeight(), BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1Row1Layer->getDepth(), BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1Row1Column->getWidth(), BCCSQFACEDISTANCE + BCCOFFSET, EPSILONT);
    EXPECT_NEAR(lattice1Row1Column->getHeight(), BCCSQFACEDISTANCE + BCCOFFSET, EPSILONT);
    EXPECT_NEAR(lattice1Row1Column->getDepth(), (nElements+ 1) * BCCOFFSET, EPSILONT);

    EXPECT_NEAR(lattice1Layer->getWidth(), n2 * BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1Layer->getHeight(), n1 * BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1Layer->getDepth(), BCCSQFACEDISTANCE, EPSILONT);

    EXPECT_NEAR(lattice1Column->getWidth(), BCCSQFACEDISTANCE + BCCOFFSET, EPSILONT);
    EXPECT_NEAR(lattice1Column->getHeight(), n1 * BCCSQFACEDISTANCE + BCCOFFSET, EPSILONT);
    EXPECT_NEAR(lattice1Column->getDepth(), (n2 + 1) * BCCOFFSET, EPSILONT);

    EXPECT_NEAR(lattice1Row->getWidth(), n1 * BCCSQFACEDISTANCE + BCCOFFSET, EPSILONT);
    EXPECT_NEAR(lattice1Row->getHeight(), BCCSQFACEDISTANCE + BCCOFFSET, EPSILONT);
    EXPECT_NEAR(lattice1Row->getDepth(), (n2 + 1) * BCCOFFSET, EPSILONT);

    delete lattice1;
    delete lattice2;
    delete lattice1Column1Layer;
    delete lattice1Row1Layer;
    delete lattice1Row1Column;
    delete lattice1Layer;
    delete lattice1Column;
    delete lattice1Row;

}

TEST(BCCLattice,distances) {

    // set up image
    int nRows = 5;
    int nColumns = 6;
    int nLayers = 7;
    int nElements = nRows * nColumns * nLayers;
    double scaleFactor1 = 1.0;
    double scaleFactor2 = cbrt(2.5);
    BCCLattice *lattice1 = new BCCLattice(nRows, nColumns, nLayers, scaleFactor1);
    BCCLattice *lattice2 = new BCCLattice(nRows, nColumns, nLayers, scaleFactor2);

    // distance between spels
    EXPECT_NEAR(lattice1->euclideanDistance(0, 0), 0, EPSILONT);
    EXPECT_NEAR(lattice1->euclideanDistance(170, 170), 0, EPSILONT);
    EXPECT_NEAR(lattice1->euclideanDistance(nElements - 1, nElements - 1), 0, EPSILONT);
    EXPECT_NEAR(lattice1->euclideanDistance(82, 45), BCCHEXFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1->euclideanDistance(82, 45), lattice1->euclideanDistance(45, 82), EPSILONT);
    EXPECT_NEAR(lattice1->euclideanDistance(82, 46), BCCHEXFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1->euclideanDistance(82, 46), lattice1->euclideanDistance(46, 82), EPSILONT);
    EXPECT_NEAR(lattice1->euclideanDistance(82, 51), BCCHEXFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1->euclideanDistance(82, 51), lattice1->euclideanDistance(51, 82), EPSILONT);
    EXPECT_NEAR(lattice1->euclideanDistance(82, 52), BCCHEXFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1->euclideanDistance(82, 52), lattice1->euclideanDistance(52, 82), EPSILONT);
    EXPECT_NEAR(lattice1->euclideanDistance(82, 22), BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1->euclideanDistance(82, 22), lattice1->euclideanDistance(22, 82), EPSILONT);
    EXPECT_NEAR(lattice1->euclideanDistance(82, 76), BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1->euclideanDistance(82, 76), lattice1->euclideanDistance(76, 82), EPSILONT);
    EXPECT_NEAR(lattice1->euclideanDistance(82, 83), BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice1->euclideanDistance(82, 83), lattice1->euclideanDistance(83, 82), EPSILONT);

    EXPECT_NEAR(lattice2->euclideanDistance(0, 0), 0, EPSILONT);
    EXPECT_NEAR(lattice2->euclideanDistance(170, 170), 0, EPSILONT);
    EXPECT_NEAR(lattice2->euclideanDistance(nElements - 1, nElements - 1), 0, EPSILONT);
    EXPECT_NEAR(lattice2->euclideanDistance(82, 45), scaleFactor2 * BCCHEXFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice2->euclideanDistance(82, 45), lattice2->euclideanDistance(45, 82), EPSILONT);
    EXPECT_NEAR(lattice2->euclideanDistance(82, 46), scaleFactor2 * BCCHEXFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice2->euclideanDistance(82, 46), lattice2->euclideanDistance(46, 82), EPSILONT);
    EXPECT_NEAR(lattice2->euclideanDistance(82, 51), scaleFactor2 * BCCHEXFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice2->euclideanDistance(82, 51), lattice2->euclideanDistance(51, 82), EPSILONT);
    EXPECT_NEAR(lattice2->euclideanDistance(82, 52), scaleFactor2 * BCCHEXFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice2->euclideanDistance(82, 52), lattice2->euclideanDistance(52, 82), EPSILONT);
    EXPECT_NEAR(lattice2->euclideanDistance(82, 22), scaleFactor2 * BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice2->euclideanDistance(82, 22), lattice2->euclideanDistance(22, 82), EPSILONT);
    EXPECT_NEAR(lattice2->euclideanDistance(82, 76), scaleFactor2 * BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice2->euclideanDistance(82, 76), lattice2->euclideanDistance(76, 82), EPSILONT);
    EXPECT_NEAR(lattice2->euclideanDistance(82, 83), scaleFactor2 * BCCSQFACEDISTANCE, EPSILONT);
    EXPECT_NEAR(lattice2->euclideanDistance(82, 83), lattice2->euclideanDistance(83, 82), EPSILONT);

    vector<double> distanceVector;
    double right[3] = {BCCSQFACEDISTANCE, 0, 0};
    double bottom[3] = {0, BCCSQFACEDISTANCE, 0};
    double back[3] = {0, 0, BCCSQFACEDISTANCE};
    double left[3] = {-BCCSQFACEDISTANCE, 0, 0};
    double top[3] = {0, -BCCSQFACEDISTANCE, 0};
    double front[3] = {0, 0, -BCCSQFACEDISTANCE};
    double ftl[3] = {-BCCOFFSET, -BCCOFFSET, -BCCOFFSET};
    double ftr[3] = {BCCOFFSET, -BCCOFFSET, -BCCOFFSET};
    double fbl[3] = {-BCCOFFSET, BCCOFFSET, -BCCOFFSET};
    double fbr[3] = {BCCOFFSET, BCCOFFSET, -BCCOFFSET};
    double btl[3] = {-BCCOFFSET, -BCCOFFSET, BCCOFFSET};
    double btr[3] = {BCCOFFSET, -BCCOFFSET, BCCOFFSET};
    double bbl[3] = {-BCCOFFSET, BCCOFFSET, BCCOFFSET};
    double bbr[3] = {BCCOFFSET, BCCOFFSET, BCCOFFSET};
    lattice1->euclideanDistanceVector(82, 82, distanceVector);
    EXPECT_TRUE(fabs(distanceVector[0]) < EPSILONT);
    EXPECT_TRUE(fabs(distanceVector[1]) < EPSILONT);
    EXPECT_TRUE(fabs(distanceVector[2]) < EPSILONT);
    lattice1->euclideanDistanceVector(82, 83, distanceVector);
    EXPECT_NEAR(distanceVector[0], right[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], right[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], right[2], EPSILONT);
    lattice1->euclideanDistanceVector(82, 88, distanceVector);
    EXPECT_NEAR(distanceVector[0], bottom[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], bottom[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], bottom[2], EPSILONT);
    lattice1->euclideanDistanceVector(22, 82, distanceVector);
    EXPECT_NEAR(distanceVector[0], back[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], back[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], back[2], EPSILONT);
    lattice1->euclideanDistanceVector(83, 82, distanceVector);
    EXPECT_NEAR(distanceVector[0], left[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], left[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], left[2], EPSILONT);
    lattice1->euclideanDistanceVector(88, 82, distanceVector);
    EXPECT_NEAR(distanceVector[0], top[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], top[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], top[2], EPSILONT);
    lattice1->euclideanDistanceVector(82, 22, distanceVector);
    EXPECT_NEAR(distanceVector[0], front[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], front[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], front[2], EPSILONT);
    lattice1->euclideanDistanceVector(82, 45, distanceVector);
    EXPECT_NEAR(distanceVector[0], ftl[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], ftl[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], ftl[2], EPSILONT);
    lattice1->euclideanDistanceVector(82, 46, distanceVector);
    EXPECT_NEAR(distanceVector[0], ftr[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], ftr[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], ftr[2], EPSILONT);
    lattice1->euclideanDistanceVector(82, 51, distanceVector);
    EXPECT_NEAR(distanceVector[0], fbl[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], fbl[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], fbl[2], EPSILONT);
    lattice1->euclideanDistanceVector(82, 52, distanceVector);
    EXPECT_NEAR(distanceVector[0], fbr[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], fbr[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], fbr[2], EPSILONT);
    lattice1->euclideanDistanceVector(82, 105, distanceVector);
    EXPECT_NEAR(distanceVector[0], btl[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], btl[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], btl[2], EPSILONT);
    lattice1->euclideanDistanceVector(82, 106, distanceVector);
    EXPECT_NEAR(distanceVector[0], btr[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], btr[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], btr[2], EPSILONT);
    lattice1->euclideanDistanceVector(82, 111, distanceVector);
    EXPECT_NEAR(distanceVector[0], bbl[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], bbl[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], bbl[2], EPSILONT);
    lattice1->euclideanDistanceVector(82, 112, distanceVector);
    EXPECT_NEAR(distanceVector[0], bbr[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], bbr[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], bbr[2], EPSILONT);

    double right2[3] = {scaleFactor2 * BCCSQFACEDISTANCE, 0, 0};
    double bottom2[3] = {0, scaleFactor2 * BCCSQFACEDISTANCE, 0};
    double back2[3] = {0, 0, scaleFactor2 * BCCSQFACEDISTANCE};
    double left2[3] = {-scaleFactor2 * BCCSQFACEDISTANCE, 0, 0};
    double top2[3] = {0, -scaleFactor2 * BCCSQFACEDISTANCE, 0};
    double front2[3] = {0, 0, -scaleFactor2 * BCCSQFACEDISTANCE};
    double ftl2[3] = {-scaleFactor2 * BCCOFFSET, -scaleFactor2 * BCCOFFSET, -scaleFactor2 * BCCOFFSET};
    double ftr2[3] = {scaleFactor2 * BCCOFFSET, -scaleFactor2 * BCCOFFSET, -scaleFactor2 * BCCOFFSET};
    double fbl2[3] = {-scaleFactor2 * BCCOFFSET, scaleFactor2 * BCCOFFSET, -scaleFactor2 * BCCOFFSET};
    double fbr2[3] = {scaleFactor2 * BCCOFFSET, scaleFactor2 * BCCOFFSET, -scaleFactor2 * BCCOFFSET};
    double btl2[3] = {-scaleFactor2 * BCCOFFSET, -scaleFactor2 * BCCOFFSET, scaleFactor2 * BCCOFFSET};
    double btr2[3] = {scaleFactor2 * BCCOFFSET, -scaleFactor2 * BCCOFFSET, scaleFactor2 * BCCOFFSET};
    double bbl2[3] = {-scaleFactor2 * BCCOFFSET, scaleFactor2 * BCCOFFSET, scaleFactor2 * BCCOFFSET};
    double bbr2[3] = {scaleFactor2 * BCCOFFSET, scaleFactor2 * BCCOFFSET, scaleFactor2 * BCCOFFSET};
    lattice2->euclideanDistanceVector(82, 82, distanceVector);
    EXPECT_TRUE(fabs(distanceVector[0]) < EPSILONT);
    EXPECT_TRUE(fabs(distanceVector[1]) < EPSILONT);
    EXPECT_TRUE(fabs(distanceVector[2]) < EPSILONT);
    lattice2->euclideanDistanceVector(82, 83, distanceVector);
    EXPECT_NEAR(distanceVector[0], right2[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], right2[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], right2[2], EPSILONT);
    lattice2->euclideanDistanceVector(82, 88, distanceVector);
    EXPECT_NEAR(distanceVector[0], bottom2[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], bottom2[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], bottom2[2], EPSILONT);
    lattice2->euclideanDistanceVector(22, 82, distanceVector);
    EXPECT_NEAR(distanceVector[0], back2[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], back2[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], back2[2], EPSILONT);
    lattice2->euclideanDistanceVector(83, 82, distanceVector);
    EXPECT_NEAR(distanceVector[0], left2[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], left2[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], left2[2], EPSILONT);
    lattice2->euclideanDistanceVector(88, 82, distanceVector);
    EXPECT_NEAR(distanceVector[0], top2[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], top2[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], top2[2], EPSILONT);
    lattice2->euclideanDistanceVector(82, 22, distanceVector);
    EXPECT_NEAR(distanceVector[0], front2[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], front2[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], front2[2], EPSILONT);
    lattice2->euclideanDistanceVector(82, 45, distanceVector);
    EXPECT_NEAR(distanceVector[0], ftl2[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], ftl2[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], ftl2[2], EPSILONT);
    lattice2->euclideanDistanceVector(82, 46, distanceVector);
    EXPECT_NEAR(distanceVector[0], ftr2[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], ftr2[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], ftr2[2], EPSILONT);
    lattice2->euclideanDistanceVector(82, 51, distanceVector);
    EXPECT_NEAR(distanceVector[0], fbl2[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], fbl2[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], fbl2[2], EPSILONT);
    lattice2->euclideanDistanceVector(82, 52, distanceVector);
    EXPECT_NEAR(distanceVector[0], fbr2[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], fbr2[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], fbr2[2], EPSILONT);
    lattice2->euclideanDistanceVector(82, 105, distanceVector);
    EXPECT_NEAR(distanceVector[0], btl2[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], btl2[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], btl2[2], EPSILONT);
    lattice2->euclideanDistanceVector(82, 106, distanceVector);
    EXPECT_NEAR(distanceVector[0], btr2[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], btr2[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], btr2[2], EPSILONT);
    lattice2->euclideanDistanceVector(82, 111, distanceVector);
    EXPECT_NEAR(distanceVector[0], bbl2[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], bbl2[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], bbl2[2], EPSILONT);
    lattice2->euclideanDistanceVector(82, 112, distanceVector);
    EXPECT_NEAR(distanceVector[0], bbr2[0], EPSILONT);
    EXPECT_NEAR(distanceVector[1], bbr2[1], EPSILONT);
    EXPECT_NEAR(distanceVector[2], bbr2[2], EPSILONT);

    delete lattice1;
    delete lattice2;

}