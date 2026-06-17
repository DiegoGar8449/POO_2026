/* Programa "GymRats". main.cpp del proyecto final.
 * Cabeceras utilizadas: CPersona.h, 
 * Autores:
 * - Contreras Galicia Jesús Yizán.
 * - García Rodríguez Diego.
 * Secuencia: 3NV31
 * U. A.: Programación Orientada a Objetos.
 * Profa.: Dra. Claudia Azorín Vega.
 */
#include <iostream>
#include <fstream> //para manejo de archivos de texto y simular bd.
#include "CPersona.h"
using namespace std;

//PROTOTIPOS (declaraciones de funciones dentro del main)
void limpiar_pantalla(); // limpia pantalla en linux y windows.

/*************** 1. MAIN ***************/
int main(){
	cout<<"\n*************** GymRats (software para gestionar tu gym) ****************";
	
	int continuar;
	do{
		limpiar_pantalla();
		
		int opcion;
		cout<<"\n\n PERFILES GIMNASIO ***************";
		cout<<"\n 1) Jefe. 2) Empleado. 3) Entrenador. 4) Cliente.";
		cout<<"\nIngrese el numero de perfil al que quiera acceder: ";
		cin>>opcion;
		switch(opcion){
			
			case 1:
			CJefe jefe; //objeto
			jefe.solicitar_datos(); //mensaje
			jefe.gestionar_cuenta();
			break;
		} 
		
		cout<<"\n¿Seleccionar otro perfil? 1 = Si. 0 = No: ";
		cin>> continuar;
	} while (continuar==1);
	
	cout<<"\n¡Gracias por usar el programa!";
	return 0;
}

/*************** DEFINICION PROTOTIPOS ***************/
//limpieza de pantalla.
void limpiar_pantalla(){
	#ifdef _WIN32
		system("cls");//comando para windows.
	#else
			system("clear");//comando para linux.
	#endif		
}
/*************** 2. FUNCIONES DEL PROGRAMADOR ***************/

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
	std::getline(std::cin >> std::ws, nombre);
	cout<<"\nApellido paterno: "; cin>>apellido_paterno;
	cout<<"\nApellido materno: "; cin>>apellido_materno;
	cout<<"\nEdad: "; cin>>edad;
	cout<<"\nTelefono celular: "; cin>>telefono_celular;
	cout<<"\nCalle: "; cin>>calle;
	cout<<"\nNumero de domicilio: "; cin>>calle_num;
	cout<<"\nColonia: ";
	std::getline(std::cin >> std::ws, colonia);
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
		cout<<"\nDigite el numero de la opcion: "; cin>>opcion_cuenta;
		
		switch(opcion_cuenta){
			case 1:{
				cout<<"\n\n*************** CREAR CUENTA ***************";
				cout<<"\nIngrese su id (5 dígitos): "; cin>>id;
				cout<<"\nIngrese su contraseña (10 caracteres. Sin acento): ";
				cin>>contrasenia;
				// std::ios::app significa "Append" (Añadir). 
				// Evita que el archivo se borre si ya existen otros jefes registrados.
				ofstream archivo_jefes("archivo_jefes.txt",ios::app);
				if(archivo_jefes.is_open()){
				//escribimos los datos separados por comas. 
				//también guarda los datos heredados de CPersona.
				archivo_jefes <<id << ","<<contrasenia << "," <<nombre << "," <<apellido_paterno << "," <<edad <<"\n";
				archivo_jefes.close();
				cout<<"\n¡Cuenta registrada en archivo_jefes.txt!";
				} else {cout<<"\n¡Error! No se pudo abrir o crear la base de datos.";}
			} break;
			
			case 2:
				cout<<"\n(El modulo de modificar datos esta en construccion...)";
				// Aquí en el futuro leeremos el .txt, buscaremos el ID y reemplazaremos la línea.
				break;
				
			case 3:
				cout<<"\nRegresando al menu principal...";
				break;
			default:
				cout<<"\nOpcion no valida.";
		}
		
	}while (opcion_cuenta != 3);
}
