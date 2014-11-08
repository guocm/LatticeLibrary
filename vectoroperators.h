#ifndef VECTOROPERATORS_H
#define VECTOROPERATORS_H

#include <vector>
#include "exception.h"
#include "defs.h"

namespace CImage {

    template<class T>
    vector <T> operator+(const vector <T> &v1, const vector <T> &v2) {
        int length = v1.size();
        if (length != v2.size()) {
            throw dimensionMismatchException();
        }
        vector <T> result;
        for (int i = 0; i < length; i++) {
            result.push_back(v1[i] + v2[i]);
        }
        return result;
    }

    template<class T>
    vector <T> operator-(const vector <T> &v1, const vector <T> &v2) {
        int length = v1.size();
        if (length != v2.size()) {
            throw dimensionMismatchException();
        }
        vector <T> result;
        for (int i = 0; i < length; i++) {
            result.push_back(v1[i] - v2[i]);
        }
        return result;
    }

    template<class T>
    vector <T> operator-(const vector <T> &v) {
        vector <T> result;
        int length = v.size();
        for (int i = 0; i < length; i++) {
            result.push_back(-v[i]);
        }
        return result;
    }

    template<class T>
    vector<double> operator*(double d, const vector <T> &v) {
        vector<double> result;
        int length = v.size();
        for (int i = 0; i < length; i++) {
            result.push_back(d * v[i]);
        }
        return result;
    }

    template<class T>
    vector <T> minElements(vector <T> v1, vector <T> v2) {
        int length = v1.size();
        if (length != v2.size()) {
            throw dimensionMismatchException();
        }
        vector <T> result;
        for (int i = 0; i < length; i++) {
            result.push_back(MIN(v1[i], v2[i]));
        }
        return result;
    }

    template<class T>
    vector <T> maxElements(vector <T> v1, vector <T> v2) {
        int length = v1.size();
        if (length != v2.size()) {
            throw dimensionMismatchException();
        }
        vector <T> result;
        for (int i = 0; i < length; i++) {
            result.push_back(MAX(v1[i], v2[i]));
        }
        return result;
    }
}
#endif