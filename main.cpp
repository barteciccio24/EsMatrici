#include <iostream>

#include "MatrixFactory.h"
#include "TypeMatrixFactory.h"

using namespace std;

int main() {
    //creazione e stampa di matrice di una certa dimensione vuote
    try {
        cout << "Quadrata" << endl;
        MatrixFactory<int> *mtp1 = new TypeMatrixFactory<int>();
        Matrix<int> *matrix1 = mtp1->choiceMatrixType(5, 5);
        matrix1->PrintDimensions();
        matrix1->printMatrix();


        cout << endl << "Vettore colonna" << endl;
        MatrixFactory<int> *mtp2 = new TypeMatrixFactory<int>();
        Matrix<int> *matrix2 = mtp2->choiceMatrixType(3, 1);
        matrix2->PrintDimensions();
        matrix2->printMatrix();


        cout << endl << "Vettore riga" << endl;
        MatrixFactory<int> *mtp3 = new TypeMatrixFactory<int>();
        Matrix<int> *matrix3 = mtp3->choiceMatrixType(1, 3);
        matrix3->PrintDimensions();
        matrix3->printMatrix();


        cout << endl << "Rettangolare" << endl;
        MatrixFactory<int> *mtp4 = new TypeMatrixFactory<int>();
        Matrix<int> *matrix4 = mtp4->choiceMatrixType(3, 4);
        matrix4->PrintDimensions();
        matrix4->printMatrix();

    // da qui in poi facciamo delle prove con matrici numeriche specifiche
        cout<<"Esempio di Prodotto tra matrici\n";
        cout << "Matrix3:" << endl;
        matrix3->setValue(1, 1, 1);
        matrix3->setValue(1, 2, 2);
        matrix3->setValue(1, 3, 3);
        matrix3->printMatrix();

        cout << "Matrix2:" << endl;
        matrix2->setValue(1, 1, 1);
        matrix2->setValue(2, 1, 2);
        matrix2->setValue(3, 1, 3);
        matrix2->printMatrix();

        cout << "Matrix5 = matrix3 * matrix2" << endl;
        MatrixFactory<int> *mtp5 = new TypeMatrixFactory<int>();
        Matrix<int> *matrix5 = mtp1->choiceMatrixType(1,1);
        *matrix5 = (*matrix3) * (*matrix2);
        matrix5->printMatrix();
    }
    catch (std::out_of_range &e) {
        cerr << e.what() << endl;
        return 2;
    }
    catch (std::logic_error &e) {
        cerr << e.what() << endl;
        return 3;
    }
}