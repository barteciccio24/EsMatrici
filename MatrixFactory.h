

#ifndef EXAMDIPRO_MATRIXDESIGNER_H
#define EXAMDIPRO_MATRIXDESIGNER_H

#include "Matrix.h"

template<typename T>
class MatrixFactory {
public:
    virtual ~MatrixFactory() {}

    Matrix<T> *choiceMatrixType(int n, int m) {
        Matrix<T> *mtx;
        mtx = createMatrix(n, m);
        return mtx;
    }

    virtual Matrix<T> *createMatrix(int n, int m)  = 0;

protected:
    MatrixFactory() {}
};

#endif //EXAMDIPRO_MATRIXDESIGNER_H