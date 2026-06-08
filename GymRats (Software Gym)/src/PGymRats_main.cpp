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
int seleccionar_perfil(); // Jefe, empleado, entrenador, cte.
void calcular_sueldo(int opcion); //para empleado y entrenador.
void mostrar_sueldo(CPersona* empleado); 
void calcular_membresia(int opcion); //para cliente
void mostrar_TotalMembresia(CPersona* cliente);

/*************** 1. MAIN ***************/
int main(){
	cout<<"*************** GymRats ****************";
	cout<<"\nPrograma para gestionar tu Gym.";
	
	int continuar;
	do{
		limpiar_pantalla();
		int opcion = seleccionar_perfil();
		calcular_sueldo(opcion);
		calcular_membresia(opcion);
		
		cout<<"\n****************************************";
		cout<<"\n¿Seleccionar otro perfil?";
		cin>> continuar;
	} while (continuar==1);
	
	cout<<"\n¡Gracias por usar el programa!";
	return 0;
}

//DEFINICION PROTOTIPOS

//limpieza de pantalla en el menu.
void limpiar_pantalla(){
	#ifdef _WIN32
		system("cls");//comando para windows.
	#else
			system("clear");//comando para linux.
	#endif		
}
