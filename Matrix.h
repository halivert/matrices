#ifndef MATX_H
#define MATX_H

#include <cmath>
#include <cstdlib>
#include <iterator>
#include <stdexcept>
#include <vector>

using std::vector;

template <class T>
class Matrix {
	size_t sizeN, sizeM;
	vector<vector<T>> matrix;
	const double ERROR = 1e-9;

	inline bool Zero(double a) { return fabs(a) < ERROR; }

public:
	Matrix(size_t _sizeN, size_t _sizeM) {
		sizeN = _sizeN;
		sizeM = _sizeM;
		vector<T> sizeMVector(sizeM, 0);
		matrix.resize(sizeN);
		for (size_t i = 0; i < sizeN; i++) {
			matrix[i] = sizeMVector;
		}
	}

	Matrix(size_t _sizeN = 1) : Matrix(_sizeN, _sizeN) {}
	Matrix(vector<vector<T>>);

	void setMatrix(vector<vector<T>>);
	Matrix transpose();
	size_t size();
	size_t columnSize();
	void gaussianElimination();
	void gaussianElimination(vector<double>);

	Matrix operator+(Matrix);
	Matrix operator-(Matrix);
	Matrix operator*(T);
	Matrix operator*(Matrix);
	vector<T> operator[](size_t);
	typename vector<vector<T>>::iterator begin();
	typename vector<vector<T>>::iterator end();
	const typename vector<vector<T>>::iterator begin() const;
	const typename vector<vector<T>>::iterator end() const;
};

template <class T>
Matrix<T>::Matrix(vector<vector<T>> vec) {
	matrix = vec;
	sizeN = vec.size();
	sizeM = 0;

	if (vec.size() > 0) {
		size_t length = vec[0].size();

		for (auto row : vec) {
			if (length != row.size()) {
				throw std::invalid_argument("Invalid matrix size");
			}
		}
		sizeM = vec[0].size();
	}
}

template <class T>
void Matrix<T>::setMatrix(vector<vector<T>> vec) {
	matrix = vec;
	sizeN = vec.size();
	sizeM = vec[0].size();
}

template <class T>
Matrix<T> Matrix<T>::transpose() {
	Matrix resultMatrix(sizeM, sizeN);
	for (size_t i = 0; i < sizeN; i++) {
		for (size_t j = 0; j < sizeM; j++) {
			resultMatrix.matrix[j][i] = matrix[i][j];
		}
	}

	return resultMatrix;
}

template <class T>
Matrix<T> Matrix<T>::operator+(Matrix<T> matrix) {
	Matrix ans(matrix.sizeN);
	if (sizeN == matrix.sizeN and sizeM == matrix.sizeM) {
		Matrix sum(matrix.sizeN, matrix.sizeM);
		for (size_t i = 0; i < matrix.sizeN; i++) {
			for (size_t j = 0; j < matrix.sizeM; j++) {
				sum.matrix[i][j] = matrix.matrix[i][j] + matrix[i][j];
			}
		}
		return sum;
	} else {
		return ans;
	}
}

template <class T>
vector<T> Matrix<T>::operator[](size_t i) {
	if (i > sizeN)
		return matrix[0];
	else
		return matrix[i];
}

template <class T>
Matrix<T> Matrix<T>::operator-(Matrix<T> matrix) {
	Matrix err(matrix.sizeN);
	if (sizeN == matrix.sizeN && sizeM == matrix.sizeM) {
		Matrix res(matrix.sizeN, matrix.sizeM);
		for (size_t i = 0; i < matrix.sizeN; i++) {
			for (size_t j = 0; j < matrix.sizeM; j++) {
				res.matrix[i][j] = matrix.matrix[i][j] - matrix[i][j];
			}
		}
		return res;
	} else
		return err;
}

template <class T>
Matrix<T> Matrix<T>::operator*(T A) {
	Matrix resultMatrix(sizeN, sizeM);
	for (size_t i = 0; i < resultMatrix.sizeN; i++)
		for (size_t j = 0; j < resultMatrix.sizeM; j++)
			resultMatrix.matrix[i][j] = matrix[i][j] * A;
	return resultMatrix;
}

template <class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> matrix) {
	Matrix C(sizeN, matrix.sizeM);
	if (sizeN == matrix.sizeM && sizeM == matrix.sizeN) {
		for (size_t i = 0; i < sizeN; i++) {
			for (size_t j = 0; j < matrix.sizeM; j++) {
				for (size_t k = 0; k < sizeM; k++) {
					C.matrix[i][j] += matrix[i][k] * matrix.matrix[k][j];
				}
			}
		}
	}
	return C;
}

template <class T>
size_t Matrix<T>::size() {
	return sizeN;
}

template <class T>
size_t Matrix<T>::columnSize() {
	return sizeM;
}

template <class T>
typename vector<vector<T>>::iterator Matrix<T>::begin() {
	return matrix.begin();
}

template <class T>
typename vector<vector<T>>::iterator Matrix<T>::end() {
	return matrix.end();
}

template <class T>
const typename vector<vector<T>>::iterator Matrix<T>::begin() const {
	return matrix.begin();
}

template <class T>
const typename vector<vector<T>>::iterator Matrix<T>::end() const {
	return matrix.end();
}

#endif
