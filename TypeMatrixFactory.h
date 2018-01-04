

#ifndef EXAMDIPRO_MATRIXSTYLE_H
#define EXAMDIPRO_MATRIXSTYLE_H


#include "SquareMatrix.h"
#include "RowMatrix.h"
#include "ColMatrix.h"
#include "RectangleMatrix.h"
#include "MatrixFactory.h"

template<typename T>
class TypeMatrixFactory : public MatrixFactory<T> {
public:
    Matrix<T> *createMatrix(int n, int m) {
        if (n == m && n > 0)
            return new SquareMatrix<T>(n);
        else if (n == 1 && m > 0)
            return new RowMatrix<T>(1, m);
        else if (n > 0 && m == 1)
            return new ColMatrix<T>(n, 1);
        else if (n > 0 && m > 0 && n != m)
                return new RectangleMatrix<T>(n,m);
        else return 0;
    }
};


#endif //EXAMDIPRO_MATRIXSTYLE_H
