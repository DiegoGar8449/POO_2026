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
	cout<<"\nApellido paterno: ";
	getline(cin>> ws, apellido_paterno);
	cout<<"\nApellido materno: ";
	getline(cin>> ws, apellido_materno);
	cout<<"\nEdad: ";
	//ciclo de control: si no es un número entero o es menor/igual a cero, se queda aquí
	while (!(cin>>edad) || edad <= 0){
		cout<<"¡Error! Por favor ingresa una edad valida (digito): ";
		cin.clear(); // reestablece el estado de cin y elimina un bucle infinito
		cin.ignore(1000, '\n'); //limpia caracteres basura del buffer hasta el salto de linea
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
		cout<<"\n\nDigite el numero de la opcion: ";
		while (!(cin>>opcion_cuenta)){
			cin.clear();
			cin.ignore(10000, '\n');
			cout<<"\n¡Error! Ingrese unicamente digitos.";
			cout<<"\n\nDigite el numero de la opcion: ";
		}
		
		switch(opcion_cuenta){
			case 1:{
				cout<<"\n\n*************** CREAR CUENTA ***************";
				string id_ingresado;
				
				//capturar y validar el id ingresado
				cout<<"\nIngrese su id (5 dígitos): ";
				cin>>id_ingresado;
				
				//verificar si el id ya existe en la bd
				bool id_existe = false;
				ifstream archivo_leer("archivo_jefes.txt");
				
				if(archivo_leer.is_open()){
					string linea;
					while(getline(archivo_leer, linea)){
						stringstream separador(linea);
						string id_leido;
						
						//se extrae el id para corroborar.
						getline(separador, id_leido, ','); 
						
						if(id_leido == id_ingresado){
							id_existe = true;
							break; //si el id existe, se rompe el ciclo.
						}
					}
					archivo_leer.close();
				}
				
				//ciclo de decision para rechazar o continuar
				if(id_existe){
					cout<<"\n¡Error! El ID '" << id_ingresado << "' ya se encuentra registrado. Intente con uno distinto.\n";
				} else {
					
					//si es nuevo, se asigna al objeto
					id = id_ingresado;
					
					//capturar y validar contraseña
					cout<<"\nIngrese su contraseña (5 digitos): ";
					cin>>contrasenia;
					
					//insertar en la bd
					ofstream archivo_jefes("archivo_jefes.txt",ios::app);
					
					if(archivo_jefes.is_open()){
						archivo_jefes <<id<<","<<contrasenia<<","<<nombre<<","<<apellido_paterno<<","
						<<apellido_materno<<","<<edad<<"\n";
						archivo_jefes.close();
						cout<<"\n¡Cuenta registrada en archivo_jefes.txt!";
					} else {
						cout<<"\n¡Error! No se pudo abrir o crear la base de datos.";
					}
				}
			} break;
			
			case 2:{
				cout<<"\n*************** MODIFICAR CONTRASEÑA ***************";
				string id_buscar;
				cout<<"\nIngrese el Id de su cuenta: "; cin>>id_buscar;
				ifstream archivo_leer("archivo_jefes.txt"); //se abre el archivo original para leer.
				if(archivo_leer.is_open()){
					
					ofstream archivo_temp("temp.txt"); //se crea un archivo temporal para escribir.
				
					bool encontrado = false;
				
					if(archivo_leer.is_open() && archivo_temp.is_open()){
						string linea;
					
						//se lee linea por linea el archivo original
						while(getline(archivo_leer, linea)){
							stringstream separador(linea);
							string id_leido, contrasenia_leida, nombre_leido, apPaterno_leido, apMaterno_leido, edad_leido;
						
							//se extraen los datos separados por comas
							getline(separador, id_leido, ',');
							getline(separador, contrasenia_leida, ',');
							getline(separador, nombre_leido, ',');
							getline(separador, apPaterno_leido, ',');
							getline(separador, apMaterno_leido, ',');
							getline(separador, edad_leido, ',');
						
							//se compara el id de la linea actual con el que se busca
							if(id_leido == id_buscar){
								encontrado = true;
								cout<<"\n¡Cuenta encontrada! Ingrese su nueva contraseña.";
								//el id no se modifica por ser nuestra "llave primaria" en esta bd
								cout<<"\nNueva contraseña (5 digitos): ";cin>>contrasenia;
							
								//se escriben los datos nuevos en el archivo temporal
								archivo_temp << id_leido << "," << contrasenia << "," <<nombre_leido << "," <<
								apPaterno_leido << "," << apMaterno_leido << "," << edad_leido << "\n";
							} else { //si no es el id que buscamos, se mantiene la linea intacta en el txt original.
								archivo_temp << linea << "\n";
							}
						}
					
						archivo_leer.close();
						archivo_temp.close();
					
						if(encontrado){
							//se reemplaza el archivo viejo con el nuevo.
							remove("archivo_jefes.txt");
							rename("temp.txt","archivo_jefes.txt");
							cout<<"\n¡Datos actualizados correctamente en la base de datos!";
						} else { //si el id no existía, se borra la basura temporal.
							remove("temp.txt");
							cout<<"\nNo se encontró ninguna cuenta con el id ingresado: "<< id_buscar;
						}
					}
					
				} else {
				cout<<"\nNo se pudo abrir la base de datos. Quiza no hay cuentas registradas.";
				}
				
			}	break;
				
			case 3:
				cout<<"\nRegresando al menu principal...\n";
				break;
			default:
				cout<<"\nOpcion no valida.";
		}
		
	}while (opcion_cuenta != 3);
}
