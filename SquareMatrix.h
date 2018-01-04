
#ifndef EXAMDIPRO_VALOMATRIX_H
#define EXAMDIPRO_VALOMATRIX_H



#include "Matrix.h"

template<typename T>
class SquareMatrix : public Matrix<T> {
public:
    SquareMatrix() {}

    SquareMatrix(int n) : Matrix<T>(n, n) {
        this->setName("Matrice quadrata");
    }

    virtual ~SquareMatrix() {}
};


#endif //EXAMDIPRO_VALOMATRIX_H