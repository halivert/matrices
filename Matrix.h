#ifndef MATX_H
#define MATX_H

#include <cmath>
#include <cstdlib>
#include <iterator>
#include <stdexcept>
#include <vector>

using std::vector;

namespace hspc {
	template <class T>
	class Matrix {
		size_t _sizeN, _sizeM;
		vector<vector<T>> _matrix;
		const double ERROR = 1e-9;

		inline bool Zero(double a) { return fabs(a) < ERROR; }

	public:
		Matrix(size_t sizeN, size_t sizeM) {
			_sizeN = sizeN;
			_sizeM = sizeM;
			vector<T> sizeMVector(_sizeM, 0);
			_matrix.resize(_sizeN);
			for (size_t i = 0; i < _sizeN; i++) {
				_matrix[i] = sizeMVector;
			}
		}

		Matrix(size_t _sizeN = 1) : Matrix(_sizeN, _sizeN) {}
		Matrix(vector<vector<T>>);

		Matrix transpose();
		size_t size();
		size_t columnSize();
		Matrix<double> gaussianElimination();
		Matrix<double> gaussianElimination(vector<double>);

		Matrix operator+(Matrix);
		Matrix operator-(Matrix);
		Matrix operator*(T);
		Matrix operator*(Matrix);
		vector<T> &operator[](size_t);
		typename vector<vector<T>>::iterator begin();
		typename vector<vector<T>>::iterator end();
		const typename vector<vector<T>>::iterator begin() const;
		const typename vector<vector<T>>::iterator end() const;
	};

	template <class T>
	Matrix<T>::Matrix(vector<vector<T>> vec) {
		_matrix = vec;
		_sizeN = vec.size();
		_sizeM = 0;

		if (vec.size() > 0) {
			size_t length = vec[0].size();

			for (auto row : vec) {
				if (length != row.size()) {
					throw std::invalid_argument("Invalid matrix size");
				}
			}
			_sizeM = length;
		}
	}

	template <class T>
	Matrix<T> Matrix<T>::transpose() {
		Matrix resultMatrix(_sizeM, _sizeN);
		for (size_t i = 0; i < _sizeN; i++) {
			for (size_t j = 0; j < _sizeM; j++) {
				resultMatrix[j][i] = _matrix[i][j];
			}
		}

		return resultMatrix;
	}

	template <class T>
	Matrix<T> Matrix<T>::operator+(Matrix<T> A) {
		if (_sizeN != A._sizeN or _sizeM != A._sizeM) {
			throw std::invalid_argument("Incompatible matrices sizes %d %d");
		}

		Matrix sum(_sizeN, _sizeM);
		for (size_t i = 0; i < _sizeN; i++) {
			for (size_t j = 0; j < _sizeM; j++) {
				sum[i][j] = A[i][j] + _matrix[i][j];
			}
		}

		return sum;
	}

	template <class T>
	vector<T> &Matrix<T>::operator[](size_t i) {
		if (i > _sizeN) {
			throw std::invalid_argument("Index out of bounds");
		}

		return _matrix[i];
	}

	template <class T>
	Matrix<T> Matrix<T>::operator-(Matrix<T> _matrix) {
		Matrix err(_matrix._sizeN);
		if (_sizeN == _matrix._sizeN && _sizeM == _matrix._sizeM) {
			Matrix res(_matrix._sizeN, _matrix._sizeM);
			for (size_t i = 0; i < _matrix._sizeN; i++) {
				for (size_t j = 0; j < _matrix._sizeM; j++) {
					res._matrix[i][j] = _matrix._matrix[i][j] - _matrix[i][j];
				}
			}
			return res;
		}

		return err;
	}

	template <class T>
	Matrix<T> Matrix<T>::operator*(T A) {
		Matrix resultMatrix(_sizeN, _sizeM);
		for (size_t i = 0; i < resultMatrix._sizeN; i++) {
			for (size_t j = 0; j < resultMatrix._sizeM; j++) {
				resultMatrix._matrix[i][j] = _matrix[i][j] * A;
			}
		}

		return resultMatrix;
	}

	template <class T>
	Matrix<T> Matrix<T>::operator*(Matrix<T> _matrix) {
		Matrix C(_sizeN, _matrix._sizeM);
		if (_sizeN == _matrix._sizeM && _sizeM == _matrix._sizeN) {
			for (size_t i = 0; i < _sizeN; i++) {
				for (size_t j = 0; j < _matrix._sizeM; j++) {
					for (size_t k = 0; k < _sizeM; k++) {
						C._matrix[i][j] += _matrix[i][k] * _matrix._matrix[k][j];
					}
				}
			}
		}

		return C;
	}

	template <class T>
	size_t Matrix<T>::size() {
		return _sizeN;
	}

	template <class T>
	size_t Matrix<T>::columnSize() {
		return _sizeM;
	}

	template <class T>
	typename vector<vector<T>>::iterator Matrix<T>::begin() {
		return _matrix.begin();
	}

	template <class T>
	typename vector<vector<T>>::iterator Matrix<T>::end() {
		return _matrix.end();
	}

	template <class T>
	const typename vector<vector<T>>::iterator Matrix<T>::begin() const {
		return _matrix.begin();
	}

	template <class T>
	const typename vector<vector<T>>::iterator Matrix<T>::end() const {
		return _matrix.end();
	}
}  // namespace hspc

#endif
