/* Proyecto final: GymRats.
 * PGymRats_main.cpp.
 * Autores:
 * - Contreras Galicia Jesús Yizán.
 * - García Rodríguez Diego.
 * Secuencia: 3NV31
 * U. A.: Programación Orientada a Objetos.
 * Profa.: Dra. Claudia Azorín Vega.
 */
#include <iostream>
#include "CPersona.h"
#include "CJefe.h"
#include "CEmpleado.h"
using namespace std;

//PROTOTIPOS (declaraciones de funciones dentro del main)
void limpiar_pantalla(); // limpia pantalla en linux y windows.

/*************** 1. MAIN ***************/
int main(){
	cout<<"\n*************** GYMRATS - Software para gestionar tu gym ****************";
	
	int continuar;
	do{
		limpiar_pantalla();
		
		int opcion;
		cout<<"\n\n*************** PERFILES GIMNASIO ***************";
		cout<<"\n1) Jefe." << "\n2) Empleado." << "\n3) Entrenador." << "\n4) Cliente.";
		cout<<"\n****************************************";
		cout<<"\n\nIngrese el numero del perfil que desee crear o escriba 0 para salir: ";
		while (!(cin>>opcion)){
			cin.clear();
			cin.ignore(10000, '\n');
			cout<<"\n¡Error! Ingrese solo dígitos.";
			cout<<"\n\nIngrese el número del perfil que desee usar o escriba 0 para salir: ";
		}
		
		if (opcion == 0){break;}
		
		switch(opcion){
			
			case 1:{
				CJefe jefe; //objeto
				jefe.menu_principal_jefe();
			} break;
			
			case 2:{
				CEmpleado empleado; //objeto
				empleado.menu_principal_empleado();
			} break;
			
			default:
			cout<<"\n¡Error! Opción no valida en el menu de perfiles.";
			break;
		} 
		
		cout<<"\n¿Seleccionar otro perfil para crear? 1 = Si. 0 = No: ";
		while (!(cin>> continuar) ||  (continuar != 1 && continuar != 0)){
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "\n¡Error! Seleccione una opcion valida (1 para Si, 0 para No).";
			cout<<"\n\n¿Desea seleccionar otro perfil? (1 = Si, 0 = No).";
		}
	} while (continuar==1);
	
	cout<<"\n¡Gracias por usar el programa!\n\n";
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
