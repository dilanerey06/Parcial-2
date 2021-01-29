#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "nav.h"

using namespace std;

Nav::Nav(){
	numOpt = 0;
}

void Nav::makeNav(int numOpt){
	this-> numOpt = numOpt;
	array = new string [numOpt];
	//array[0] = "Salir.";
}

void Nav::makeOpt(int n, string opt){
	if(n <= 0 || n > numOpt){
		cout<<"Número de opción no válido, ingrese un numero valido";
		cin>>n;
	}
	array[n-1] = opt;
}

int Nav::printNav(){
	int a;
	cout<<"================================================"<<'\n';
	for (int i = 0; i < numOpt; ++i){
		cout<<i+1<<"."<<array[i]<<'\n';
	}
	cout<<"Digite la opción que desea realizar--->";cin>>a;
	cin.ignore();
	return a;
}

Nav::~Nav(){}

