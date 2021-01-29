#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "librerias-2.h"
#include "nav.h"

using namespace std;

int figuraGeometrica::numElem = 0;

figuraGeometrica::figuraGeometrica(int lado){
	numElem+=1;
	this->lado = lado;
}

int figuraGeometrica::getLado(){
	return lado;
}

void Rectangulo::print(){
	int base = getLado();
	char matrix[altura][base];
	for (int i = 0; i < altura; ++i){
		for (int j = 0; j < base; ++j){
			matrix[i][j] = '*';
			cout<<matrix[i][j]<<"  ";
		}
		cout<<'\n';
	}
}

void Triangulo::print(){
	int lado = getLado();
	char matrix[lado][lado+(lado-1)];
	for (int i = 0; i < lado; ++i){
		for (int j = 0; j < lado+(lado-1); ++j){
			if (j == lado-1-i && i == 0){
				matrix[i][j] = '*';
			}
			if(i != lado-1){
				if(j == lado-1-i || j == lado-1+i){
					matrix[i][j] = '*';
				}
				else{
					matrix[i][j] = ' ';
				}
			}
			else{
				if(j % 2 == 0){
					matrix[i][j] = '*';
				}
				else{
					matrix[i][j] = ' ';
				}
			}
			cout<<matrix[i][j]<<"  ";
		}
		cout<<'\n';
	}
}

void Circulo::print(){
	int radio = getLado();
	int dim = (radio*2)+1;
	char matrix[dim][dim];
	for (int i = 0; i < dim; ++i){
		for (int j = 0; j < dim; ++j){
			if (radio <= 3){
				if (i == 0 && j == 0 || i == 0 && j == dim-1){
					matrix[i][j] = ' ';
				}
				else if(i == dim-1 && j == 0 || i == dim-1 && j == dim-1){
					matrix[i][j] = ' ';
				}
				else{
					matrix[i][j] = '*';
				}
			}
			else{
				if (i == 0 && j <=1 || i == 0 && j >= (dim-2)){
					matrix[i][j] = ' ';
				}
				else if(i == (dim-1) && j <= 1 || i == (dim-1) && j >= (dim-2)){
					if (j == 0 || j == dim-1){
						matrix[i][j] = ' ';
					}
				}
				else if (i == 1 && j == 0 || i == 1 && j == (dim-1) ){
					matrix[i][j] = ' ';
				}
				else if (i == (dim-2) && j == 0 || i == (dim-2) && j == (dim-1)){
					matrix[i][j] = ' ';
				}
				else{
					matrix[i][j] = '*';
				}
			}
			cout<<matrix[i][j]<<" ";
		}
		cout<<'\n';
	}
}

figuraGeometrica::~figuraGeometrica(){}
Rectangulo::~Rectangulo(){}
Triangulo::~Triangulo(){}
Circulo::~Circulo(){}
