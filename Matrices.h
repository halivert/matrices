#include <vector>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

class Matriz{
	int n, m;
	vector< vector<double> >mat;
	public:
		Matriz(void);
		Matriz(int n, int m);
		Matriz(int n, int m, char c);
		Matriz(int n);
		Matriz(int n, char c);
		Matriz(vector< vector<double> > vec);
		void SetMat(vector< vector<double> > vec);
		void ImprimirM(void);
		int SizeN(void);
		int SizeM(void);
		Matriz Transpuesta();
		
	Matriz operator+(const Matriz &m);
	Matriz operator-(const Matriz &m);
	Matriz operator*(const double A);
	Matriz operator*(const Matriz &m);
	vector<double> &operator[](int i);
};
