/*IMC v1.0 Orientada a objetos
Garcia Rodriguez Diego - 3NV31 - POO
07 - 03 - 2026 */

#include <iostream>
#include <vector>
#include "Persona.h" //archivo cabecera que contiene la clase Persona

#include <string>
using namespace std;
#define CUADRADO(x) (x*x)//macro

//DEFINICION DE METODOS

//CLASE PERSONA
Persona::Persona(){ //constructor
	peso = 0.0; //dato miembro o atributo
	estatura = 0.0;
}
	
void Persona::solicitar_datos(){ //funcion miembro
	cout<<"Ingrese su nombre: ";
		cin>>nombre;
	cout<< "\nIngrese su primer apellido: ";
		cin>>apellido1;
	cout<< "\nIngrese su segundo apellido: ";
		cin>>apellido2;
			
	cout<<"\nIngrese su peso en kilogramos: ";
		cin>>peso;
			
	cout<<"\nIngrese su estatura en metros: ";
		cin>>estatura;
			
	cout<<"\nIngrese su hobby: ";
		cin>>hobby;
}
		
float Persona::imc(){
return peso/CUADRADO(estatura);
}
		
string Persona::estado_salud(){
	float indice = imc();
		if (indice < 18.5)
			return "Bajo peso";
		else if (indice >= 18.5 && indice <= 24.9)
			return "Peso normal";
		else if (indice >= 25 && indice <= 29)
			return "Sobre peso";
		else
			return "Obesidad";
}
			
void Persona::mostrar_datos(){ //funcion miembro
	cout<< "Los datos personales de " <<nombre; 
	cout<< " " <<apellido1;
	cout<< " " <<apellido2;
	cout<< " son: \n";
	cout<< "Peso: "<<peso<<" kg.\n";
	cout<< "Estatura: "<<estatura<<" m.\n";
	cout<< "IMC: "<<imc() << " kg/m2\n";
	cout<< "Su estado de salud es: "<<estado_salud()<< "\n";
	cout<< "Hobby: "<<hobby;
}

int main(){
	int i = 0;
	int n;
	cout<< "Ingrese la cantidad de personas que desee registrar: ";
	cin>>n;
	
	//vector para n objetos persona
	vector<Persona> personas(n);
	
	//pedir datos
	for (int i = 0; i < n; i++){
		cout<<"\n--- Persona " << (i + 1) << " ---"<<endl;
		personas[i].solicitar_datos(); //mensaje
	}
	
	//mostrar resultados
	cout<< "\n\n **** RESULTADOS ****"<<endl;
	for (i = 0; i < n; i++){
		personas[i].mostrar_datos(); //mensaje
		cout << "---------------------" <<endl;
	}
	
	return 0;
}
