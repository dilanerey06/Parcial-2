#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "librerias-2.h"
#include "nav.h"

using namespace std;

void construirMenu(Nav &nav1,Nav &nav2);

int main(){
	Nav nav1, nav2;
	construirMenu(nav1, nav2);
	int mainOpt = 0, secondOpt;
	int b, a;
	do{
		if(figuraGeometrica::numElem < 3){
			secondOpt = 0;
			mainOpt = nav1.printNav();
			switch(mainOpt){
				case 1:{
					cout<<"Base: ";cin>>b;
					cout<<"ALtura: ";cin>>a;
					Rectangulo rec1(b,a);
					cout<<"Se ha creado un rectangulo de base: "<<b<<" y altura "<<a<<'\n';
					cout<<"Que acción desea realizar? "<<'\n';
					do{
						secondOpt = nav2.printNav();
						if (secondOpt == 1){
							rec1.print();
						}
						else{
							rec1.~Rectangulo();
						}	
					} while (secondOpt == 1);
					break;
				}
				case 2:{
					cout<<"Radio: ";cin>>b;
					Circulo cir1(b);
					cout<<"Se ha creado un circulo de radio: "<<b<<'\n';
					cout<<"Que acción desea realizar? "<<'\n';
					do{
						secondOpt = nav2.printNav();
						if (secondOpt == 1){
							cir1.print();
						}
						else{
							cir1.~Circulo();
						}	
					} while (secondOpt == 1);
					break;
				}
				case 3:{
					cout<<"Medida de los lados: ";cin>>b;
					Triangulo tr1(b);
					cout<<"Se ha creado un triangulo equilatero de medida: "<<b<<'\n';
					cout<<"Que acción desea realizar? "<<'\n';
					do{
						secondOpt = nav2.printNav();
						if (secondOpt == 1){
							tr1.print();
						}
						else{
							tr1.~Triangulo();
						}	
					} while (secondOpt == 1);
					break;
				}
			}
		}
		else{
			cout<<"Ya se han creado 3 figuras y este es el numero máximo que se permite"<<'\n';
			exit(1);
		}
		cout<<"Figuras creadas: "<<figuraGeometrica::numElem<<'\n';
	} while (mainOpt != 4);
	return 0;
}

void construirMenu(Nav &nav1,Nav &nav2){
	nav1.makeNav(4);
	nav1.makeOpt(1, "Crear Rectangulo.");
	nav1.makeOpt(2, "Crear Circulo.");
	nav1.makeOpt(3, "Crear Triangulo.");
	nav1.makeOpt(4, "Salir.");
	nav2.makeNav(2);
	nav2.makeOpt(1, "Dibujar figura creada.");
	nav2.makeOpt(2, "Eliminar figura creada.");
}