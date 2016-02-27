#include "Matriz.h"

Matriz Matriz::operator+(const Matriz m){
	Matriz err(m.n);
	if(this->n == m.n && this->m == m.m){
		Matriz sum(m.n, m.m);
		for(int i = 0; i < m.n; i++){
			for(int j = 0; j < m.m; j++){
				sum.mat[i][j] = m.mat[i][j] + this->mat[i][j];
			}
		}
		return sum;
	}
	else return err;
}

vector<double> &Matriz::operator[](int i){
	if(i > this->SizeN()) return this->mat[0];
	else return this->mat[i];
}

Matriz Matriz::operator-(const Matriz m){
	Matriz err(m.n);
	if(this->n == m.n && this->m == m.m){
		Matriz res(m.n, m.m);
		for(int i = 0; i < m.n; i++){
			for(int j = 0; j < m.m; j++){
				res.mat[i][j] = m.mat[i][j] - this->mat[i][j];
			}
		}
		return res;
	}
	else return err;
}	

Matriz Matriz::operator*(const double A){
	Matriz B(this->SizeN(), this->SizeM());
	for(int i = 0; i < B.SizeN(); i++)
		for(int j = 0; j < B.SizeM(); j++)
			B.mat[i][j] = this->mat[i][j] * A;
	return B;
}

Matriz Matriz::operator*(const Matriz m){
	Matriz C(this->n, m.m);
	if(this->n == m.m && this->m == m.n){
		for(int i = 0; i < this->SizeN(); i++){
			for(int j = 0; j < m.m; j++){
				for(int k = 0; k < this->m; k++){
					C.mat[i][j] += this->mat[i][k] * m.mat[k][j];
				}
			}
		}
	}
	return C;
}

Matriz::Matriz(int n, int m){
	this->n = n;
	this->m = m;
	vector<double> tmp;
	for(int j = 0; j < m; j++){
		tmp.push_back(0);
	}
	for(int i = 0; i < n; i++){
		mat.push_back(tmp);
	}
}

Matriz::Matriz(int n, int m, char c){
	this->n = n;
	this->m = m;
	vector<double> tmp;
	for(int j = 0; j < m; j++){
		tmp.push_back(c - '0');
	}
	for(int i = 0; i < n; i++){
		mat.push_back(tmp);
	}
}

Matriz::Matriz(vector< vector<double> > vec){
	this->mat = vec;
	this->n = (int)vec.size();
	this->m = (int)vec[0].size();
}

void Matriz::ImprimirM(void){
	for(int i = 0; i < this->n; i++){
		for(int j = 0; j < this->m; j++){
			printf("%.2lf ", this->mat[i][j]);
		}
		puts("");
	}
	puts("");
}

Matriz::Matriz(int n){
	this->n = n;
	this->m = n;
	vector<double> tmp;
	for(int j = 0; j < n; j++){
		tmp.push_back(0);
	}
	for(int i = 0; i < n; i++){
		mat.push_back(tmp);
	}
}

Matriz::Matriz(int n, char c){
	this->n = n;
	this->m = n;
	vector<double> tmp;
	for(int j = 0; j < n; j++){
		tmp.push_back(c - '0');
	}
	for(int i = 0; i < n; i++){
		mat.push_back(tmp);
	}
}

int Matriz::SizeN(void){ return n; }

int Matriz::SizeM(void){ return m; }

void Matriz::SetMat(vector< vector<double> > vec){
	this->mat = vec;
	this->n = (int)vec.size();
	this->m = (int)vec[0].size();
}

Matriz Matriz::Transpuesta(){
	Matriz B(this->m, this->n);
	for(int i = 0; i < (int)this->SizeN(); i++)
		for(int j = 0; j < (int)this->SizeM(); j++)
			B.mat[j][i] = this->mat[i][j];

	return B;
}
