
#ifndef EXAMDIPRO_RECTANGLEMATRIX_H
#define EXAMDIPRO_RECTANGLEMATRIX_H

#include "Matrix.h"

template<typename T>
class RectangleMatrix : public Matrix<T> {
public:
    RectangleMatrix() {}

    RectangleMatrix(int n, int m) : Matrix<T>(n, m) {
        this->setName("Matrice rettangolare");
    }

    virtual ~RectangleMatrix() {}

};


#endif //EXAMDIPRO_RECTANGLEMATRIX_H
