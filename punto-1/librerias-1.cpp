#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "nav.h"
#include "librerias-1.h"

using namespace std;

Persona::Persona(){
	nombre = "";
	apellido = "";
	parentesco = "";
	edad = 0;
}

void Persona::makePerson(string name, string apellido, string parentesco, int years){
 nombre = name;
 this->apellido = apellido;
 this->parentesco = parentesco;
 edad = years;
}

string Persona::getNombre(){
	return nombre;
}

string Persona::getApellido(){
	return apellido;
}

/*string Persona::getParentesco(){
	return parentesco;
}

int Persona::getEdad(){
	return edad;
}*/

void Persona::impData(){
	cout<<"Nombre: "<<nombre<<'\n';
	cout<<"Parentesco: "<<parentesco<<'\n';
	cout<<"Edad: "<<edad<<'\n';
	cout<<"================================================"<<'\n';
}

Familia::Familia(){
}

void Familia::makeFamilia(){
	ptrArray = new Persona [3];
	string name, sName, parent;
	int years;
	cout<<"Apellido de la familia: ";
	getline(cin, sName);
	for (int i = 0; i < 3; ++i){
		cout<<"Nombre del integrante #"<<i+1<<": ";
		getline(cin, name);
		cout<<"Parentesco del integrante #"<<i+1<<": ";
		getline(cin, parent);
		cout<<"Edad del integrante #"<<i+1<<": ";cin>>years;
		ptrArray[i].makePerson(name,sName,parent, years);
		cout<<"================================================"<<'\n';
		if(i < 2){
			cin.ignore();
		}
	}
}

void Familia::impDataF(){
	for (int i = 0; i < 3; ++i){
		cout<<"Datos integrante #"<<i+1<<": "<<'\n';
		ptrArray[i].impData();
	}
}

void Familia::searchMember(string nombre){
	if(ptrArray[0].getNombre() == nombre){
		cout<<"El miembro encontrado es: "<<'\n';
		ptrArray[0].impData();
		cout<<"Los otros miembros son: "<<'\n';
		ptrArray[1].impData();
		ptrArray[2].impData();
	}
	else if(ptrArray[1].getNombre() == nombre){
		cout<<"El miembro encontrado es: "<<'\n';
		ptrArray[1].impData();
		cout<<"Los otros miembros son: "<<'\n';
		ptrArray[0].impData();
		ptrArray[2].impData();
	}
	else if(ptrArray[2].getNombre() == nombre){
		cout<<"El miembro encontrado es: "<<'\n';
		ptrArray[2].impData();
		cout<<"Los otros miembros son: "<<'\n';
		ptrArray[0].impData();
		ptrArray[1].impData();
	}
	else{
		cout<<"No se encontró ningún miembro de la familia "<<ptrArray[0].getApellido()<<" con el nombre "<<nombre<<'\n';
	}
}

int searchFamily(Familia *array, string apellido, int numFamCreadas){
	int pos= 0;
	for (int i = 0; i < numFamCreadas; ++i){
		if (array[i].ptrArray[0].getApellido() == apellido){
			pos = i;
			break;
		}
		else{
			pos = -1;
		}		
	}
	return pos;
}



Persona::~Persona(){}
Familia::~Familia(){}