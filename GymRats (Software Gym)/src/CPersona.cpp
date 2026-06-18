#include <iostream>
#include "CPersona.h"
using namespace std;

/*************** FUNCIONES DEL PROGRAMADOR ***************/
//CONSTRUCTOR CPersona
CPersona::CPersona(){
	nombre = "";
	apellido_paterno = "";
	apellido_materno = "";
	edad = 0;
	telefono_celular = "";
	calle = "";
	calle_num = "";
	colonia = "";
}
//DESTRUCTOR CPersona
CPersona::~CPersona(){}

//DEFINICION METODOS CPersona
void CPersona::solicitar_datos(){
	cout<<"\n**************** INGRESE SUS DATOS ***************";
	cout<<"\nNombre(s): ";
	getline(cin >> ws, nombre);
	cout<<"\nApellido paterno: ";
	getline(cin>> ws, apellido_paterno);
	cout<<"\nApellido materno: ";
	getline(cin>> ws, apellido_materno);
	cout<<"\nEdad: ";
	//ciclo de control: si no es un número entero o es menor/igual a cero, se queda aquí
	while (!(cin>>edad) || edad <= 0){
		cout<<"¡Error! Por favor ingresa una edad valida (digito): ";
		cin.clear(); // reestablece el estado de cin y elimina un bucle infinito
		cin.ignore(10000, '\n'); //limpia caracteres basura del buffer hasta el salto de linea
	}
	cout<<"\nTelefono celular: ";
	getline(cin>> ws, telefono_celular);
	cout<<"\nCalle: ";
	getline(cin>> ws, calle);
	cout<<"\nNumero de domicilio: ";
	getline(cin>> ws, calle_num);
	cout<<"\nColonia: ";
	getline(cin >> ws, colonia);
	cout<<"****************************************";
}
