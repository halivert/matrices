#ifndef MATX_H
#define MATX_H

#include <vector>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

template<class T>
class Matrix {
  public:
    int sizeN, sizeM;
    vector<vector<T>> matrix;

    Matrix(int _sizeN = 1) {
      sizeN = sizeM = _sizeN;
      vector<T> sizeMVector(sizeM, 0);
      for (int i = 0; i < sizeN; i++)
        matrix.push_back(sizeMVector);
    }

    Matrix(int _sizeN, int _sizeM) {
      sizeN = _sizeN;
      sizeM = _sizeM;
      vector<T> sizeMVector(sizeM, 0);
      for (int i = 0; i < sizeN; i++)
        matrix.push_back(sizeMVector);
    }

    Matrix(vector<vector<T>>);
    void setMat(vector<vector<T>>);
    void printMatrix(void);
    Matrix transpose();

    Matrix operator+(const Matrix m);
    Matrix operator-(const Matrix m);
    Matrix operator*(const T A);
    Matrix operator*(const Matrix m);
    vector<T> &operator[](int i);
};

template<class T>
Matrix<T>::Matrix(vector<vector<T>> vec) {
  matrix = vec;
  sizeN = vec.size();
  sizeM = vec[0].size();
}

template<>
void Matrix<double>::printMatrix(void) {
  for (int i = 0; i < sizeN; i++) {
    for (int j = 0; j < sizeM; j++) {
      printf("%.2lf ", matrix[i][j]);
    }
    puts("");
  }
  puts("");
}

template<>
void Matrix<int>::printMatrix(void) {
  for (int i = 0; i < sizeN; i++) {
    for (int j = 0; j < sizeM; j++) {
      printf("%d ", matrix[i][j]);
    }
    puts("");
  }
  puts("");
}

template<class T>
void Matrix<T>::setMat(vector<vector<T>> vec) {
  matrix = vec;
  sizeN = vec.size();
  sizeM = vec[0].size();
}

template<class T>
Matrix<T> Matrix<T>::transpose() {
  Matrix resultMatrix(sizeM, sizeN);
  for (int i = 0; i < sizeN; i++)
    for (int j = 0; j < sizeM; j++)
      resultMatrix.matrix[j][i] = matrix[i][j];

  return resultMatrix;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> matrix) {
  Matrix ans(matrix.sizeN);
  if (sizeN == matrix.sizeN and sizeM == matrix.sizeM) {
    Matrix sum(matrix.sizeN, matrix.sizeM);
    for (int i = 0; i < matrix.sizeN; i++) {
      for (int j = 0; j < matrix.sizeM; j++) {
        sum.matrix[i][j] = matrix.matrix[i][j] + matrix[i][j];
      }
    }
    return sum;
  }
  else return ans;
}

template<class T>
vector<T> &Matrix<T>::operator[](int i) {
  if (i > sizeN) return matrix[0];
  else return matrix[i];
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> matrix) {
  Matrix err(matrix.sizeN);
  if (sizeN == matrix.sizeN && sizeM == matrix.sizeM) {
    Matrix res(matrix.sizeN, matrix.sizeM);
    for (int i = 0; i < matrix.sizeN; i++) {
      for (int j = 0; j < matrix.sizeM; j++) {
        res.matrix[i][j] = matrix.matrix[i][j] - matrix[i][j];
      }
    }
    return res;
  }
  else return err;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const T A) {
  Matrix resultMatrix(sizeN, sizeM);
  for (int i = 0; i < resultMatrix.sizeN; i++)
    for (int j = 0; j < resultMatrix.sizeM; j++)
      resultMatrix.matrix[i][j] = matrix[i][j] * A;
  return resultMatrix;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> matrix) {
  Matrix C(sizeN, matrix.sizeM);
  if (sizeN == matrix.sizeM && sizeM == matrix.sizeN) {
    for (int i = 0; i < sizeN; i++) {
      for (int j = 0; j < matrix.sizeM; j++) {
        for (int k = 0; k < sizeM; k++) {
          C.matrix[i][j] += matrix[i][k] * matrix.matrix[k][j];
        }
      }
    }
  }
  return C;
}

#endif
