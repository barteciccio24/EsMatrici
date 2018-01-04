
#ifndef EXAMDIPRO_ROWVECTOR_H
#define EXAMDIPRO_ROWVECTOR_H

#include "Matrix.h"

template<typename T>
class RowMatrix : public Matrix<T> {
public:
    RowMatrix() {}

    RowMatrix(int x, int y) : Matrix<T>(1, y) {
        this->setName("Matrice riga");
    }

    virtual ~RowMatrix() {}
};


#endif //EXAMDIPRO_ROWVECTOR_H