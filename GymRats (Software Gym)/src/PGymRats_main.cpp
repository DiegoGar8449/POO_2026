/* Programa "GymRats". main.cpp del proyecto final.
 * Cabeceras utilizadas: CPersona.h, 
 * Autores:
 * - Contreras Galicia Jesús Yizán,
 * - García Rodríguez Diego.
 * Secuencia: 3NV31
 * U. A.: Programación Orientada a Objetos.
 * Profa.: Dra. Claudia Azorín Vega.
 */
#include <iostream>
#include "CPersona.h"
using namespace std;

//PROTOTIPOS (declaraciones de funciones dentro del main)
void limpiar_pantalla(); // limpia pantalla en linux y windows.

/*************** 1. MAIN ***************/
int main(){
	cout<<"*************** GymRats ****************";
	cout<<"\nPrograma para gestionar tu Gym.";
	
	int continuar;
	do{
		limpiar_pantalla();
		
		int opcion;
		cout<<"\n*************** PERFILES GIMNASIO ***************";
		cout<<"\n 1) Jefe. 2) Empleado. 3) Entrenador. 4) Cliente.";
		cout<<"\nIngrese el numero de perfil al que quiera acceder: ";
		cin>>opcion;
		switch(opcion){
			
			case 1:
			CPersona jefe; //objeto
			jefe.solicitar_datos(); //mensaje
			break;
		} 
		
		cout<<"\n¿Seleccionar otro perfil? 1 = Si. 2 = No: ";
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
