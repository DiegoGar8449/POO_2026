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
int seleccionar_perfil(); // Jefe, empleado, entrenador, cliente.
void procesar_jefe(); //funcion para crear objeto jefe.
void procesar_empleado(); //funcion para crear objeto empleado.
void procesar_entrenador(); //funcion para crear objeto entrenador.
void procesar_cliente(); //funcion para crear objeto cliente.
void mostrar_datos(); //Mostrar la info. personal del usuario.

/*************** 1. MAIN ***************/
int main(){
	cout<<"*************** GymRats ****************";
	cout<<"\nPrograma para gestionar tu Gym.";
	
	int continuar;
	do{
		limpiar_pantalla();
		int opcion = seleccionar_perfil();
		realizar_accion(opcion);
		
		cout<<"\n****************************************";
		cout<<"\n¿Seleccionar otro perfil? 1 = Si. 2 = No: ";
		cin>> continuar;
	} while (continuar==1);
	
	cout<<"\n¡Gracias por usar el programa!";
	return 0;
}

//DEFINICION PROTOTIPOS DEL MENU

//limpieza de pantalla.
void limpiar_pantalla(){
	#ifdef _WIN32
		system("cls");//comando para windows.
	#else
			system("clear");//comando para linux.
	#endif		
}

//seleccionar_perfil.
int seleccionar_perfil(){
	int num;
	cout<<"\nPerfiles del gimnasio: ";
	cout<<"1) Jefe. 2) Empleado. 3) Entrenador. 4) Cliente.";
	cout<<"\nElija su perfil para entrar al gimnasio: ";
	cin>> num;
	return num;
}
