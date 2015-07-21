#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include "image.h"
#include "intensityworkset.h"
#include "lattice.h"
#include "vectoroperators.h"
#include <cmath>
#include <stdio.h>

namespace LatticeLib {

    /**
     * Class for segmenting Image data based on the result of a SeededDistanceTransform.
     */
    class Segmentation {
    public:
        /**
         * Crisp segmentation, based on a distance transform. Each modality band in the output image corresponds to a label.
         * Each spel belongs to exactly one layer, in which its value is 'true'.
         *
         * Parameter            | in/out    | Comment
         * :---------           | :-----    |:-------
         * distanceTransform    | INPUT     | Distance transform on which to base the segmentation.
         * segmentation         | OUTPUT    | Resulting segmentation. Must have the same lattice and number of modality bands as distanceTransform.
         */
        void crisp(Image<double> distanceTransform, Image<bool> segmentation) {
            if (distanceTransform.getLattice() != segmentation.getLattice()) {
                // throw error
            }
            if (distanceTransform.getNBands() != segmentation.getNBands()) {
                // throw error
            }

            int nElements = distanceTransform.getNElements();
            int nBands = distanceTransform.getNBands();
            for (int elementIndex = 0; elementIndex < nElements; elementIndex++) {
                vector<double> distances = distanceTransform[elementIndex];
                vector<bool> labels(nBands, false);
                labels.at(getIndexOfMinimumValue(distances)) = true;
                segmentation.setElement(elementIndex,labels);
            }
        }

        /**
         * Fuzzy segmentation, based on a distance transform. Each modality band in the output image corresponds to a
         * label. The sum of the intensities of each spatial element is segmentation.maxIntensity. The intensity of a
         * spatial element in a band corresponds to its degree of membership, in the range [minIntensity,maxIntensity]
         * to that label.
         *
         * Some simplifications are made; The shape of the spatial elements is approximated by a sphere, and the
         * competing seed points are assumed to be evenly distributed around each spatial element. The accumulated
         * round-off error is added in favour of the lowest label, to make the labels sum up correctly. This behavior
         * is most prominent for, for example, integer types, for which the round-off error may be relatively large.
         *
         * Parameter            | in/out    | Comment
         * :---------           | :-----    |:-------
         * distanceTransform    | INPUT     | Distance transform on which to base the segmentation.
         * segmentation         | OUTPUT    | Resulting segmentation. Must have the same lattice and number of modality bands as distanceTransform.
         */
        template <class T>
        void fuzzy(Image<double> distanceTransform, IntensityWorkset<T> segmentation) {
            if (distanceTransform.getLattice() != segmentation.getImage().getLattice()) {
                // TODO: throw error
            }
            if (distanceTransform.getNBands() != segmentation.getImage().getNBands()) {
                // TODO: throw error
            }

            int nElements = distanceTransform.getNElements();
            int nLabels = distanceTransform.getNBands();
            T minCoverage = segmentation.getMinIntensity();
            T maxCoverage = segmentation.getMaxIntensity();
            T coverageRange = maxCoverage - minCoverage;
            double scaleFactor = cbrt(1 / segmentation.getImage().getLattice().getDensity());
            double radius = cbrt(3/(4 * PI)) * scaleFactor; // approximate the spel by a sphere
            for (int elementIndex = 0; elementIndex < nElements; elementIndex++) {
                vector<double> distances = distanceTransform[elementIndex];
                int nearestLabel = getIndexOfMinimumValue(distances);
                double smallestDistance = distances[nearestLabel];
                vector<int> competingLabels;
                int nCompetingLabels = 0;
                vector<double> competingClaims;
                double sumOfClaims = 0.0;
                for (int labelIndex = 0; labelIndex < nLabels; labelIndex++) {
                    segmentation.getImage().setElement(elementIndex, labelIndex, minCoverage); // setup to no label
                    double claim = radius - (distances[labelIndex] - smallestDistance);
                    if (claim > 0.0) { // part of the spel is closer to labelIndex than to nearestLabel
                        competingLabels.push_back(labelIndex);
                        competingClaims.push_back(claim);
                        sumOfClaims += claim;
                        nCompetingLabels++;
                    }
                }
                double normalizationFactor = 1/sumOfClaims;
                T accumulatedCoverage = 0;
                for (int labelIndex = 1; labelIndex < (nCompetingLabels); labelIndex++) { // First element gets special treatment, see below.
                    T coverage = T(minCoverage + coverageRange * normalizationFactor * competingClaims[labelIndex]);
                    segmentation.getImage().setElement(elementIndex,competingLabels[labelIndex],coverage);
                    accumulatedCoverage += (coverage - minCoverage);
                }
                // This favours the first, and lowest, label, as the accumulated round-off error, which may be as much as nBands, is added to its coverage value, but it's the only idea I've got right now. The practise of favouring the lowest element was inspired by F. Malmberg, who uses this method to make the segmentations deterministic.
                segmentation.getImage().setElement(elementIndex, competingLabels[0], maxCoverage - accumulatedCoverage);
            }
        }
    };
}

#endif //SEGMENTATION_H
