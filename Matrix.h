
#ifndef EXAMDIPRO_MATRIX_H
#define EXAMDIPRO_MATRIX_H

#include <stdexcept>
#include <iostream>

using namespace std;

template<typename T>
class Matrix {
protected:
    Matrix() {
        nCol = 1;
        nRow = 1;
        value = new T[nCol * nRow];
        value[nCol + nRow * nCol] = 0;
    }

    Matrix(int x, int y) {
        nCol = x;
        nRow = y;
        value = new T[nCol * nRow];
        for (int i = 0; i < nCol; i++)
            for (int j = 0; j < nRow; j++)
                value[i + j * nCol] = 0;
    }

public:
    virtual ~Matrix() {
        if (value)
            delete[] value;
    }

    virtual T const getValue(const int n, const int m) const throw(std::out_of_range) {
        if ((n > 0) && (n <= nCol) && (m > 0) && (m <= nRow))
            return value[(n - 1) + (m - 1) * nCol];
        else
            throw (std::out_of_range(
                    "Out Of Range per la selezione degli indici di riga e/o di colonna, La Matrice ha dimensioni diverse"));
    }

    virtual void setValue(const int x, const int y, const T val) throw(std::out_of_range) {
        if ((x > 0) && (y > 0) && (x <= nCol) && (y <= nRow)) {
            value[(x - 1) + (y - 1) * nCol] = val;
        } else
            throw (std::out_of_range(
                    "Out Of Range per la selezione degli indici di riga e/o di colonna, la Matrice ha dimensioni diverse"));
    }

    virtual void printMatrix() const {
        for (int i = 1; i <= nCol; i++) {
            for (int j = 1; j <= nRow; j++)
                std::cout << this->getValue(i, j) << "\t";
            std::cout << std::endl << std::endl;
        }
    }

    virtual Matrix returnRow(const int n) const throw(std::out_of_range) {
        Matrix temp(1, this->nCol);
        if (n > 0 && n <= this->nCol) {
            for (int i = 1; i <= this->nCol; i++) {
                temp.setValue(1, i, this->getValue(n, i));
            }
            return temp;
        } else throw (std::out_of_range("Out Of Range con il valore n"));
    }

    virtual Matrix returnCol(const int m) const throw(std::out_of_range) {
        Matrix temp(this->nRow, 1);
        if (m > 0 && m <= this->nRow) {
            for (int i = 1; i <= this->nRow; i++) {
                temp.setValue(i, 1, this->getValue(i, m));
            }
            return temp;
        } else throw (std::out_of_range("Out Of Range con il valore m"));
    }

    virtual Matrix &trasp() throw(std::out_of_range) {
        if (this->value) {
            Matrix temp(this->nRow, this->nCol);
            T tempor;
            for (int i = 1; i <= this->nCol; i++)
                for (int j = i; j <= this->nRow; j++) {
                    tempor = this->getValue(i, j);
                    temp.setValue(i, j, this->getValue(j, i));
                    temp.setValue(j, i, tempor);
                }
            *this = temp;
            return *this;
        } else throw (std::out_of_range("La Matrice non contiene valori"));
    }

    virtual Matrix &underScale(const int n, const int m) throw(std::out_of_range) {
        if ((this->nCol > 1) && (this->nRow > 1)) {
            if (n <= this->nCol && m <= this->nRow) {
                this->nCol = n;
                this->nRow = m;
                for (int i = n; i < this->nCol; ++i)
                    for (int j = m; j < this->nRow; ++j)
                        this->setValue(i, j, 0);
                return *this;
            } else
                throw (std::out_of_range(
                        "I valori inseriti vanno oltre la dimensione della Matrice, impossibile genereare Matrice orlata!"));
        } else throw (std::out_of_range("La Matrice e' gia alla dimensione minima! Impossibile scalare di dimensione"));
    }

    void PrintDimensions() const {
        cout << "Matrice di dimensione (" << nCol << " x " << nRow << ") : \n";
    }

    virtual Matrix operator*(const Matrix &rh) const throw(std::out_of_range) {
        Matrix<T> tempMatrix(this->nCol, rh.nRow);
        if (this->nRow == rh.nCol) {
            for (int i = 1; i <= this->nCol; i++) {
                for (int j = 1; j <= rh.nRow; j++) {
                    T tempValue = 0;
                    for (int k = 1; k <= this->nRow; k++) {
                        tempValue += (this->getValue(i, k) * rh.getValue(k, j));
                        tempMatrix.setValue(i, j, tempValue);
                    }
                }
            }
            return tempMatrix;
        } else
            throw (std::out_of_range(
                    "La Matrice non e' conformabile! La dimensione delle righe della prima Matrice e delle colonne della seconda devono essere uguali!!"));
    }

    virtual Matrix operator+(const Matrix &rh) const throw(std::out_of_range) {
        Matrix temp(rh.nCol, rh.nRow);
        if ((this->nCol == rh.nCol) && (this->nRow == rh.nRow)) {
            for (int i = 1; i <= this->nCol; i++)
                for (int j = 1; j <= this->nRow; j++) {
                    temp.setValue(i, j, (this->getValue(i, j) + rh.getValue(i, j)));
                }
            return temp;
        } else
            throw (std::out_of_range(
                    "La Matrice non e' conformabile!! La dimensione delle righe e delle colonne delle due Matrici deve esere uguale!! "));
    }

    virtual Matrix &operator=(const Matrix &rh) {
        if (this != &rh) {
            this->nCol = rh.nCol;
            this->nRow = rh.nRow;
            for (int i = 1; i <= this->nCol; i++)
                for (int j = 1; j <= this->nRow; j++)
                    this->setValue(i, j, rh.getValue(i, j));
            return *this;
        } else return *this;
    }

    virtual int getnCol() const {
        return nCol;
    }

    virtual int getnRow() const {
        return nRow;
    }

    virtual const string &getName() const {
        return name;
    }

    virtual void setNcol(int wh) {
        nCol = wh;
    }

    virtual void setNrow(int ht) {
        nRow = ht;
    }

    virtual void setName(const string &tp) {
        name = tp;
    }

private:
    int nCol, nRow;
    T *value;
    string name;
};


#endif //EXAMDIPRO_MATRIX_H
