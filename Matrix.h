#ifndef MATX_H
#define MATX_H

#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>

template<class T>
class Matrix {
  private:
    long long sizeN, sizeM;
    std::vector<std::vector<T>> matrix;
    const double ERROR = 1e-9;

    bool Zero(double a) {
      return fabs(a) < ERROR;
    }

  public:
    Matrix(long long _sizeN, long long _sizeM) {
      sizeN = _sizeN;
      sizeM = _sizeM;
      std::vector<T> sizeMVector(sizeM, 0);
      for (long long i = 0; i < sizeN; i++)
        matrix.push_back(sizeMVector);
    }

    Matrix(long long _sizeN = 1) : Matrix(_sizeN, _sizeN) {}

    Matrix(std::vector<std::vector<T>>);
    void setMatrix(std::vector<std::vector<T>>);
    void printMatrix();
    Matrix transpose();
    void gaussianElimination();
    void gaussianElimination(std::vector<double>);

    Matrix operator+(const Matrix);
    Matrix operator-(const Matrix);
    Matrix operator*(const T);
    Matrix operator*(const Matrix);
    std::vector<T> &operator[](long long);
};

template<class T>
Matrix<T>::Matrix(std::vector<std::vector<T>> vec) {
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
void Matrix<T>::setMatrix(std::vector<std::vector<T>> vec) {
  matrix = vec;
  sizeN = vec.size();
  sizeM = vec[0].size();
}

template<class T>
Matrix<T> Matrix<T>::transpose() {
  Matrix resultMatrix(sizeM, sizeN);
  for (long long i = 0; i < sizeN; i++)
    for (long long j = 0; j < sizeM; j++)
      resultMatrix.matrix[j][i] = matrix[i][j];

  return resultMatrix;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> matrix) {
  Matrix ans(matrix.sizeN);
  if (sizeN == matrix.sizeN and sizeM == matrix.sizeM) {
    Matrix sum(matrix.sizeN, matrix.sizeM);
    for (long long i = 0; i < matrix.sizeN; i++) {
      for (long long j = 0; j < matrix.sizeM; j++) {
        sum.matrix[i][j] = matrix.matrix[i][j] + matrix[i][j];
      }
    }
    return sum;
  }
  else return ans;
}

template<class T>
std::vector<T> &Matrix<T>::operator[](long long i) {
  if (i > sizeN) return matrix[0];
  else return matrix[i];
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> matrix) {
  Matrix err(matrix.sizeN);
  if (sizeN == matrix.sizeN && sizeM == matrix.sizeM) {
    Matrix res(matrix.sizeN, matrix.sizeM);
    for (long long i = 0; i < matrix.sizeN; i++) {
      for (long long j = 0; j < matrix.sizeM; j++) {
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
  for (long long i = 0; i < resultMatrix.sizeN; i++)
    for (long long j = 0; j < resultMatrix.sizeM; j++)
      resultMatrix.matrix[i][j] = matrix[i][j] * A;
  return resultMatrix;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> matrix) {
  Matrix C(sizeN, matrix.sizeM);
  if (sizeN == matrix.sizeM && sizeM == matrix.sizeN) {
    for (long long i = 0; i < sizeN; i++) {
      for (long long j = 0; j < matrix.sizeM; j++) {
        for (long long k = 0; k < sizeM; k++) {
          C.matrix[i][j] += matrix[i][k] * matrix.matrix[k][j];
        }
      }
    }
  }
  return C;
}

template<>
void Matrix<double>::gaussianElimination() {
  long long k, i, j, kMax;
  for (k = 0; k < std::min(sizeN, sizeM); ++k) {

    kMax = k;
    for (i = k + 1; i < sizeN; ++i)
      if (fabs(matrix[kMax][k]) < fabs(matrix[i][k]))
        kMax = i;

    std::swap(matrix[k], matrix[kMax]);

    if (Zero(matrix[k][k])) continue;
    for (i = sizeM - 1; i >= k; --i)
      matrix[k][i] = matrix[k][i] / matrix[k][k] * 1.0;
    for (i = 0; i < sizeN; ++i) {
      if (k == i or Zero(matrix[i][k])) continue;
      for (j = sizeM - 1; j >= k; --j)
        matrix[i][j] = matrix[i][j] - matrix[k][j] * (matrix[i][k] * 1.0);
    }
  }
}

template<>
void Matrix<double>::gaussianElimination(std::vector<double> results) {
  if ((long long)results.size() != sizeN) return;

  for (long long i = 0; i < sizeN; ++i)
    matrix[i].push_back(results[i]);

  sizeM++;
  this->gaussianElimination();
}

#endif
