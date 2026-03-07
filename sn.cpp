//Garcia Rodriguez Diego / 3NV31

#include <iostream>
using namespace std;
#include "Circulo.h" //archivo cabecera que contiene la definicion de la clase Circulo
#include "Cuadrado.h"//archivo cabecera que contiene la definicion de la clase Cuadrado
#include "Tria_equi.h"//archivo cabecera que contiene la definicion de la clase Triangulo
//#include "Rectangulo.h"//archivo cabecera que contiene la definicion de la clase Rectangulo
#define PI 4.1516 //constante
#define CUADRADO(x) (x*x)//macro

//DEFINICION DE METODOS

//CIRCULO
Circulo::Circulo(){//constructor
	radio=0.0; //dato miembro o atributo
}
				void Circulo::solicitar_datos(){
					cout<< "Escriba el radio del circulo: ";
					cin>>radio;
				}

				float Circulo::perimetro_circulo(){
					cout<<"\nEl perimetro del circulo de radio " <<radio<< " es: ";
					return 2*PI*radio;
				}
				
				float Circulo::area_circulo(){
					cout<<"\nEl area del circulo de radio " <<radio<< " es: ";
					return PI*CUADRADO(radio);
				}
				
//CUADRADO
Cuadrado::Cuadrado(){ //constructor
	lado = 0.0; //dato miembro o atributo
}
				void Cuadrado::solicitar_datos(){
					cout<< "Escriba el lado del cuadrado: ";
					cin>> lado;
				}
				
				float Cuadrado::perimetro_cuadrado(){
					cout<< "\nEl perimetro del cuadrado de lado " <<lado<< " es: ";
					return lado + lado + lado + lado;
				}
				
				float Cuadrado::area_cuadrado(){
					cout<< "\nEl area del cuadrado de lado " <<lado<< " es: ";
					return CUADRADO(lado); //utilizando la macro porque es igual a lado por lado
				}

//TRIANGULO_EQUILATERO

Tria_equi::Tria_equi(){ //constructor
	base = 0.0; // dato miembro
	altura = 0.0; // dato miembro
}
				void Tria_equi::solicitar_datos(){
					cout<< "Escriba la base del triangulo equilatero: ";
					cin>> base;
					cout<< "\nEscriba la altura del triangulo equilatero: ";
					cin>> altura;
				}
		
				float Tria_equi::perimetro_tria_equi(){
					cout<< "\nEl perimetro del triangulo de base "<<base<< " y altura "<<altura<< " es: ";
					return base*3;
				}
		
				float Tria_equi::area_tria_equi(){
					cout<< "\nEl area del triangulo de base "<<base<< " y altura "<<altura<< " es: ";
					return (base*altura)/2;
				}

//En main implemento Switch Case para el menu de opciones y construyo los objetos de las figuras

int main(){
	int numero;
	cout<< "¡Bienvenido! Con este programa puede calcular el area, perimetro, o ambas, de cualquiera de las figuras siguientes: \n"
	<< "1. Circulo.\n" << "2. Cuadrado.\n" << "3. Triangulo equilatero.\n" << "4. Rectangulo.\n"
	<< "Digite el numero de la figura que desea utilizar: ";
	cin>> numero;
	
	switch (numero){
		case 1: {
				cout<<"***********************************************************************************************\n";
				cout<<"Eligio el Circulo\n";
				cout<<"***********************************************************************************************\n";
				
				Circulo circulo1; //se construye un objeto llamado circle de la clase Circulo
				circulo1.solicitar_datos();//mensaje
		
				int opcion; //sub-menu para las opciones
				cout<<"1. Area.\n" <<"2. Perimetro.\n" <<"3. Ambas.\n";
				cout<<"Elige el numero de la opcion que deseas calcular: ";
				cin >>opcion;
		
				if (opcion == 1){
					cout<<circulo1.area_circulo(); //mensaje
				}
				else 
				
				if (opcion == 2){
						cout<<circulo1.perimetro_circulo(); //mensaje
				}
				else 
				
				if (opcion == 3){
							cout<<circulo1.area_circulo();
							cout<<circulo1.perimetro_circulo();
				}
				else{
					cout<<"Opcion no valida.\n";
				}
		}	
		break;
		
		case 2: {
				cout<<"***********************************************************************************************\n";
				cout<<"Eligio el Cuadrado\n";
				cout<<"***********************************************************************************************\n";
				
				Cuadrado cuadrado1; //se crea el objeto cuadrado1
				cuadrado1.solicitar_datos(); //mensaje
				
				int opcion;
				cout<< "1. Area.\n" << "2. Perimetro.\n" << "3. Ambas.\n";
				cout<< "Elige el numero de la opcion que deseas calcular: ";
				cin>> opcion;
				
				if (opcion == 1){ //calcula area cuadrado
					cout << cuadrado1.area_cuadrado(); //mensaje
				}
				else
				
				if (opcion == 2){ //calcula perimetro cuadrado
					cout << cuadrado1.perimetro_cuadrado(); //mensaje
				}
				else
				
				if (opcion == 3){ //calcula ambas
					cout << cuadrado1.area_cuadrado();
					cout << cuadrado1.perimetro_cuadrado();
				}
				
				else{
					cout<< "Opcion no valida.\n";
				}
		}
		break;
		
		case 3: {
				cout<<"***********************************************************************************************\n";
				cout<<"Eligio el Triangulo equilatero\n";
				cout<<"***********************************************************************************************\n";
				
				Tria_equi tria_equi1; //se crea el objeto tria_equi1
				tria_equi1.solicitar_datos(); //mensaje
				
				int opcion;
				cout<< "1. Area.\n" << "2. Perimetro.\n" << "3. Ambas.\n";
				cout<< "Elige el numero de la opcion que deseas calcular: ";
				cin>> opcion;
				
				if (opcion == 1){ //area triangulo equilatero
					cout<<tria_equi1.area_tria_equi(); //mensaje
				}
				else
				
				if (opcion == 2){ //perimetro triangulo equilatero
					cout << tria_equi1.perimetro_tria_equi(); //mensaje
				}
				else
				
				if (opcion == 3){ //calcula ambas
					cout << tria_equi1.area_tria_equi();
					cout << tria_equi1.perimetro_tria_equi();
				}
				
				else{
					cout<< "Opcion no valida.\n";
				}
		}
		break;
				
		
		default: cout<<"Respuesta no valida."; 
	}
	
	return 0;
}
