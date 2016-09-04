#include "Matrix.h"

template<class T>
Matrix<T>::Matrix(int _n) {
	n = m = _n;
	vector<T> tmp(m, 0);
	for (int i = 0; i < n; i++)
		mat.push_back(tmp);
}

template<class T>
Matrix<T>::Matrix(int _n, int _m) {
	n = _n;
	m = _m;
	vector<T> tmp(m, 0);
	for (int i = 0; i < n; i++)
		mat.push_back(tmp);
}

template<class T>
Matrix<T>::Matrix(vector<vector<T>> vec) {
	mat = vec;
	n = vec.size();
	m = vec[0].size();
}

template<>
void Matrix<double>::printM(void) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%.2lf ", mat[i][j]);
		}
		puts("");
	}
	puts("");
}

template<>
void Matrix<int>::printM(void) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", mat[i][j]);
		}
		puts("");
	}
	puts("");
}

template<class T>
int Matrix<T>::sizeN(void) { return n; }

template<class T>
int Matrix<T>::sizeM(void) { return m; }

template<class T>
void Matrix<T>::setMat(vector<vector<T>> vec) {
	mat = vec;
	n = vec.size();
	m = vec[0].size();
}

template<class T>
Matrix<T> Matrix<T>::transpose() {
	Matrix B(m, n);
	for (int i = 0; i < sizeN(); i++)
		for (int j = 0; j < sizeM(); j++)
			B.mat[j][i] = mat[i][j];

	return B;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> matrix) {
	Matrix ans(matrix.n);
	if (n == matrix.n and m == matrix.m) {
		Matrix sum(matrix.n, matrix.m);
		for (int i = 0; i < matrix.n; i++) {
			for (int j = 0; j < matrix.m; j++) {
				sum.mat[i][j] = matrix.mat[i][j] + mat[i][j];
			}
		}
		return sum;
	}
	else return ans;
}

template<class T>
vector<T> &Matrix<T>::operator[](int i) {
	if (i > sizeN()) return mat[0];
	else return mat[i];
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> matrix) {
	Matrix err(matrix.n);
	if (n == matrix.n && m == matrix.m) {
		Matrix res(matrix.n, matrix.m);
		for (int i = 0; i < matrix.n; i++) {
			for (int j = 0; j < matrix.m; j++) {
				res.mat[i][j] = matrix.mat[i][j] - mat[i][j];
			}
		}
		return res;
	}
	else return err;
}	

template<class T>
Matrix<T> Matrix<T>::operator*(const T A) {
	Matrix B(sizeN(), sizeM());
	for (int i = 0; i < B.sizeN(); i++)
		for (int j = 0; j < B.sizeM(); j++)
			B.mat[i][j] = mat[i][j] * A;
	return B;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> matrix) {
	Matrix C(n, matrix.m);
	if (n == matrix.m && m == matrix.n) {
		for (int i = 0; i < sizeN(); i++) {
			for (int j = 0; j < matrix.m; j++) {
				for (int k = 0; k < m; k++) {
					C.mat[i][j] += mat[i][k] * matrix.mat[k][j];
				}
			}
		}
	}
	return C;
}

template class Matrix<double>;
template class Matrix<int>;
