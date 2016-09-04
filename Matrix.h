#ifndef MATX_H
#define MATX_H

#include <vector>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

template<class T>
class Matrix {

	private:
		int n, m;
		vector<vector<T>> mat;

	public:
		Matrix(int = 1);
		Matrix(int, int);
		Matrix(vector<vector<T>>);
		void setMat(vector<vector<T>>);
		void printM(void);
		int sizeN(void);
		int sizeM(void);
		Matrix transpose();

		Matrix operator+(const Matrix m);
		Matrix operator-(const Matrix m);
		Matrix operator*(const T A);
		Matrix operator*(const Matrix m);
		vector<T> &operator[](int i);

};

#endif
