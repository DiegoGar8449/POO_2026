/* PFigura Programa para calculo area y perimetro de figuras con CFigura
 * García Rodríguez Diego / 3NV31 */
#include <iostream>
using namespace std;
#include "CFigura.h"
#define PI 3.1416 //constante
#define CUADRADO(x) (x*x)//macro

/**************** 1. ESTRUCTURA MAIN **********************/
int main(){
	int continuar;
	cout<<"************** Area y perimetro de figuras *****************\n";
	do{
		#ifdef _WIN32  //limpieza de terminal en windows y linux
		system("cls");
		#else
		system("clear");
		#endif //fin limpieza
		
		int num;
		cout<< "\nFiguras disponibles: ";
		cout<< "1) Circulo. 2) Cuadrado. 3) Rectangulo. 4) Triangulo equilatero.";
		cout<< "\n\nElija el numero de la figura: ";
		cin>>num;
		switch(num){ //switch para las 4 opciones de figuras a calcular
	
			case 1:{ // 1) objeto CCirculo
				CFigura* figura;  // puntero a CFigura
				figura = new CCirculo();
				figura->solicitar_datos();  // mensaje a solicitar datos de la clase padre CFigura
				cout << "\nPerímetro: " << figura->calcular_perimetro() <<"\n";  // mensaje a calcular_perimetro
				cout << "Área: " << figura->calcular_area() <<"\n";  // msj a calcular_area
				delete figura;
			}break;
			
			case 2:{ // 2) objeto CCuadrado
				CFigura* figura;  // puntero a CFigura
				figura = new CCuadrado(); 
				figura->solicitar_datos();  // mensaje a solicitar datos de la clase padre CFigura
				cout << "\nPerímetro: " << figura->calcular_perimetro() <<"\n";  // mensaje a calcular_perimetro
				cout << "Área: " << figura->calcular_area() <<"\n";  // msj a calcular_area
				delete figura;
			}break;
			
			case 3:{ // 2) objeto CRectangulo
				CFigura* figura;  // puntero a CFigura
				figura = new CRectangulo(); 
				figura->solicitar_datos();  // mensaje a solicitar datos de la clase padre CFigura
				cout << "\nPerímetro: " << figura->calcular_perimetro() <<"\n";  // mensaje a calcular_perimetro
				cout << "Área: " << figura->calcular_area() <<"\n";  // msj a calcular_area
				delete figura;
			}break;
			
			case 4:{ // 2) objeto CTriangulo
				CFigura* figura;  // puntero a CFigura
				figura = new CTriangulo_equi(); 
				figura->solicitar_datos();  // mensaje a solicitar datos de la clase padre CFigura
				cout << "\nPerímetro: " << figura->calcular_perimetro() <<"\n";  // mensaje a calcular_perimetro
				cout << "Área: " << figura->calcular_area() <<"\n";  // msj a calcular_area
				delete figura;
			}break;
			
			default: cout<< "\nOpcion no valida.";
		}
		cout<<"\n***********************************************";
		cout<< "\n¿Realizar el calculo de otra figura? 1 = Si. 0 = Salir: ";
		cin>>continuar;
		
	}while(continuar == 1);
	
return 0;
}

/*************** 2. FUNCIONES DEL PROGRAMADOR *****************/
// CONSTRUCTORES
CFigura::CFigura(){ // CFigura
	color = "";
}

CFigura::~CFigura() { }// Destructor CFigura

CCirculo::CCirculo() : CFigura() { // CCirculo
    radio = 0.0;
}

CCuadrado::CCuadrado() : CFigura() { //CCuadrado
    lado = 0.0;
}

CRectangulo::CRectangulo() : CFigura() { //CRectangulo
	base = 0.0;
	altura = 0.0;
}

CTriangulo_equi::CTriangulo_equi() : CFigura(){
	base = 0.0;
	altura = 0.0;
}

// MÉTODOS CFigura
void CFigura::solicitar_datos(){
	cout<<"\n*********************************************";
	cout<<"\nDatos de la figura...\n";
	cout<<"\nColor: ";
	cin>>color;
}

double CFigura::calcular_perimetro() {
    return 0.0;
}

double CFigura::calcular_area() {
    return 0.0;
}

//METODOS CCirculo
void CCirculo::solicitar_datos() { 
	CFigura::solicitar_datos(); //llamada al metodo padre
    cout << "Radio: ";
    cin >> radio;
}

double CCirculo::calcular_perimetro() {
    return 2 * PI * radio;
}

double CCirculo::calcular_area() {
    return PI * CUADRADO(radio);
}

// MÉTODOS CCuadrado
void CCuadrado::solicitar_datos() {
	CFigura::solicitar_datos(); //llamada al metodo padre
    cout << "Lado: ";
    cin >> lado;
}

double CCuadrado::calcular_perimetro() {
    return lado + lado + lado + lado;
}

double CCuadrado::calcular_area() {
    return CUADRADO(lado);
}

// MÉTODOS CRectangulo
void CRectangulo::solicitar_datos() {
	CFigura::solicitar_datos(); //llamada al metodo padre
    cout << "Base: ";
    cin >> base;
    cout<< "Altura: ";
    cin>> altura;
}

double CRectangulo::calcular_perimetro() {
    return base*2 + altura*2;
}

double CRectangulo::calcular_area() {
    return base*altura;
}

// MÉTODOS CTriangulo equilatero
void CTriangulo_equi::solicitar_datos() {
	CFigura::solicitar_datos(); //llamada al metodo padre
    cout << "Base: ";
    cin >> base;
    cout<< "Lado: ";
    cin>> lado;
    cout<< "Altura: ";
    cin>> altura;
}

double CTriangulo_equi::calcular_perimetro() {
    return base + lado*2;
}

double CTriangulo_equi::calcular_area() {
    return (base*altura)/2;
}
