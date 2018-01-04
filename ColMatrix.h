
#ifndef EXAMDIPRO_COLVECTOR_H
#define EXAMDIPRO_COLVECTOR_H

#include "Matrix.h"

template<typename T>
class ColMatrix : public Matrix<T> {
public:
    ColMatrix() {}

    ColMatrix(int n, int m) : Matrix<T>(n, 1) {
        this->setName("Matrice colonna");
    }

    virtual ~ColMatrix() {}
};


#endif //EXAMDIPRO_COLVECTOR_H
