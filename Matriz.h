#ifndef MATX_H
#define MATX_H

#include <vector>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

template <class T>
class Matriz{
	private:
		int n, m;
		vector< vector<T> > mat;
	public:
		Matriz(int = 0);
		Matriz(int, int);
		Matriz(vector< vector<T> >);
		void SetMat(vector< vector<T> >);
		void ImprimirM(void);
		int SizeN(void);
		int SizeM(void);
		Matriz Transpuesta();

		Matriz operator+(const Matriz m);
		Matriz operator-(const Matriz m);
		Matriz operator*(const T A);
		Matriz operator*(const Matriz m);
		vector<T> &operator[](int i);
};

#endif
