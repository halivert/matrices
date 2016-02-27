#include <vector>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

class Matriz{
	private:
		int n, m;
		vector< vector<double> >mat;
	public:
		Matriz(int = 0);
		Matriz(int, int);
		Matriz(int, int, char);
		Matriz(int, char);
		Matriz(vector< vector<double> >);
		void SetMat(vector< vector<double> >);
		void ImprimirM(void);
		int SizeN(void);
		int SizeM(void);
		Matriz Transpuesta();

		Matriz operator+(const Matriz m);
		Matriz operator-(const Matriz m);
		Matriz operator*(const double A);
		Matriz operator*(const Matriz m);
		vector<double> &operator[](int i);
};
