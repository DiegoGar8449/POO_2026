/* Cajero automatico 
Garcia Rodriguez Diego
POO - 3NV31 */

#include <iostream>
#include "Cuenta.h"
using namespace std;


//DEFINICION DE METODOS

//CUENTA
Cuenta::Cuenta(){ //constructor
	saldo = 0.0; //dato miembro
}

void Cuenta::solicitar_datos(){
	cout<< "Ingrese su numero de cuenta: ";
	cin>> cuenta;
}

float Cuenta::consultar(){
	cout<< "\nEl saldo de su cuenta ";
	cout<<cuenta;
	cout<< " es de:  $";
	return saldo;
}

float Cuenta::depositar(){
	cout<< "\n¿Cuanto dinero desea depositar?: ";
	cin>>deposito;
	return saldo + deposito;
}

float Cuenta::retirar(){
	cout<< "\n¿Cuanto dinero desea retirar?: ";
	cin>>retiro;
	return saldo - retiro;
}

int main (){
	cout<< "¡Bienvenido a su nuevo cajero automatico! Cree su cuenta y elija la operacion que desee realizar: \n";

		Cuenta cuenta1; //se construye un objeto llamado cuenta1 de la clase Cuenta
			cuenta1.solicitar_datos();//mensaje
		
		int opcion; //sub-menu para las opciones
			cout<<"1. Consulta.\n" <<"2. Deposito.\n" <<"3. Retiro.\n";
			cout<<"Elige el numero de la opcion que deseas calcular: ";
			cin >>opcion;
		
		if (opcion == 1){
			cout<<cuenta1.consultar(); //mensaje
		}
		else 
				
				if (opcion == 2){
						cout<<cuenta1.depositar(); //mensaje
				}
				else 
				
				if (opcion == 3){
							cout<<cuenta1.retirar();
				}
				else{
					cout<<"Opcion no valida.\n";
				}
	
	return 0;
}
