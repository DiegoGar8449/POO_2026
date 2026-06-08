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
int seleccionar_perfil(); 
void realizar_accion(int opcion);	
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
		limpiar_pantalla(); //limpia pantalla cuando se elige otro perfil.
		int opcion = seleccionar_perfil(); // retorna 1, 2, 3, 4.
		realizar_accion(opcion) // pasamos el return al switch
		
		cout<<"\n****************************************";
		cout<<"\n¿Seleccionar otro perfil? 1 = Si. 2 = No: ";
		cin>> continuar;
	} while (continuar==1);
	
	cout<<"\n¡Gracias por usar el programa!";
	return 0;
}

//DEFINICION PROTOTIPOS DEL MENU Y FUNCIONES AUXILIARES DE PROCESAMIENTO

//limpieza de pantalla.
void limpiar_pantalla(){
	#ifdef _WIN32
		system("cls");//comando para windows.
	#else
			system("clear");//comando para linux.
	#endif		
}

//seleccionar perfil
int seleccionar_perfil(){
	int opcion;
	bool valida = false; //condicion para repetir si la opcion no es valida.
	
	do{
		cout<<"\n*************** PERFILES DE GIMNASIO ***************";
		cout<<"\n 1) Jefe. 2) Empleado. 3) Entrenador. 4) Cliente.";
		cout<<"\n*****************************************";
		cout<<"\nIngrese el numero del para ingresar al gimnasio: ";
		cin>> opcion;
		
		if (opcion >= 1 && opcion <= 4){ //validacion de dato ingresado.
			valido = true;
		}
		
		else {
			cout<<"Opcion invalida. Elija un numero correcto";
		}
		
	} while (¡valido); //repite mientras la opcion sea no valida.
	
	return opcion;
}

void realizar_accion(int_opcion){
	switch (opcion){ //switch para elegir la funcion que construye el objeto.
		case 1: procesar_jefe(); break;
		case 2: procesar_empleado(); break;
		case 3: procesar_entrenador(); break;
		case 4: procesar_cliente(); break;
	}
}

void procesar_jefe(){
	CJefe jefe; //crear objeto jefe
	jefe.solicitar_datos();//metodo heredado de la clase padre CPersona.
	jefe.registrar_cuenta();//metodos del jefe.
	jefe.registrar_empleado();
	jefe.IngresoMensualGimnasio();
	jefe.despedir_empleado();
	jefe.registrar_entrenador();
	jefe.despedir_entrenador();
	jefe.modificar_contrasenia();
	jefe.implementar_deporte();
	jefe.comprar_equipoGimnasio();
	jefe.pagar_trabajador();
}

void procesar_empleado(){
	CEmpleado empleado; //crear objeto empleado
	empleado.solicitar_datos()//metodo heredado de CPersona.
	empleado.registrar_cliente();//metodos del empleado
	empleado.eliminar_cliente();
	empleado.modificar_contrasenia();
	empleado.llamar_emergencias();
}

/*************** 2. FUNCIONES DEL PROGRAMADOR ***************/
