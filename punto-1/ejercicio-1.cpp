#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "nav.h"
#include "librerias-1.h"

using namespace std;

void crearMenu(Nav &nav1);

int numFam;

int main(){
	Nav nav1;
	crearMenu(nav1);
	cout<<"¿Cuantas familias desea ingresar?:"; cin>>numFam;
	Familia *array;
	array = new Familia [numFam];
	int opt=0, conta=0;
	do{
		opt = nav1.printNav();
		switch(opt){
			case 1:
			{
				if (conta < numFam){
					cout<<"Familia #"<<conta+1<<": "<<'\n';
					array[conta].makeFamilia();
					conta++;	
				}
				else{
					cout<<"Excedio el número de familias que iba a ingresar"<<'\n';
				}
				
				break;
			}
			case 2:
			{
				string sName;
				int pos;
				cout<<"Apellido de la familia que desea buscar: ";
				getline(cin, sName);
				cout<<"================================================"<<'\n';
				pos = searchFamily(array, sName, numFam);
				if(pos >= 0){
					cout<<"Los datos de la familia "<<sName<<" son: "<<'\n';
					array[pos].impDataF();
				}
				else{
					cout<<"No se ha encontrado ninguna familia con el apellido "<<sName<<"."<<'\n';
				}	
				break;
			}
			case 3:
			{
				int pos;
				string name, sName;
				cout<<"Apellido de la familia a la que pertenece el integrante que desea buscar: ";
				getline(cin, sName);
				pos = searchFamily(array, sName, numFam);
				if(pos >= 0){
					cout<<"Nombre del integrante que desea buscar: ";
					getline(cin, name);
					array[pos].searchMember(name);
				}
				else{
					cout<<"No se ha encontrado ninguna familia con el apellido "<<sName<<"."<<'\n';
				}	
				break;
			}
		}	
	}while(opt != 4);	
		
	return 0;
}

void crearMenu(Nav &nav1){
	nav1.makeNav(4);
	nav1.makeOpt(1, "Ingresar una nueva familia.");
	nav1.makeOpt(2, "Buscar familia.");
	nav1.makeOpt(3, "Consultar integrante de familia.");
	nav1.makeOpt(4, "Salir.");
}