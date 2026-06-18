#include <iostream>
#include <fstream>//para manejo de archivos de texto y simular bd.
#include <sstream>//para separar por comas
#include <cstdio>//para las funciones remove() y rename()
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
	cout<<"\nApellido paterno: "; cin>>apellido_paterno;
	cout<<"\nApellido materno: "; cin>>apellido_materno;
	cout<<"\nEdad: "; cin>>edad;
	cout<<"\nTelefono celular: "; cin>>telefono_celular;
	cout<<"\nCalle: "; cin>>calle;
	cout<<"\nNumero de domicilio: "; cin>>calle_num;
	cout<<"\nColonia: ";
	getline(cin >> ws, colonia);
	cout<<"****************************************";
}

//CONSTRUCTOR CJefe
CJefe::CJefe() : CPersona(){
	id = "";
	contrasenia = "";
}

//DEFINICION METODOS CJefe
void CJefe::gestionar_cuenta(){
	int opcion_cuenta;
	do {
		cout<<"\n\n*************** GESTION CUENTA JEFE ***************";
		cout<<"\n1) Crear cuenta.";
		cout<<"\n2) Modificar datos.";
		cout<<"\n3) Salir.";
		cout<<"\n****************************************";
		cout<<"\n\nDigite el numero de la opcion: "; cin>>opcion_cuenta;
		
		switch(opcion_cuenta){
			case 1:{
				cout<<"\n\n*************** CREAR CUENTA ***************";
				cout<<"\nIngrese su id (5 dígitos): "; cin>>id;
				cout<<"\nIngrese su contraseña (5 digitos): ";
				cin>>contrasenia;
				// std::ios::app significa "Append" (Añadir). 
				// Evita que el archivo se borre si ya existen otros jefes registrados.
				ofstream archivo_jefes("archivo_jefes.txt",ios::app);
				if(archivo_jefes.is_open()){
				//escribimos los datos separados por comas. 
				//también puede guardar los datos heredados de CPersona que indiquemos.
				archivo_jefes <<id<<","<<contrasenia<<","<<nombre<<","<<apellido_paterno<<","
				<<apellido_materno<<","<<edad<<"\n";
				archivo_jefes.close();
				cout<<"\n¡Cuenta registrada en archivo_jefes.txt!";
				} else {cout<<"\n¡Error! No se pudo abrir o crear la base de datos.";}
			} break;
			
			case 2:
				cout<<"\n*************** MODIFICAR DATOS ***************";
				// Aquí en el futuro leeremos el .txt, buscaremos el ID y reemplazaremos la línea.
				break;
				
			case 3:
				cout<<"\nRegresando al menu principal...\n";
				break;
			default:
				cout<<"\nOpcion no valida.";
		}
		
	}while (opcion_cuenta != 3);
}
