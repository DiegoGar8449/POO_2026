#include <iostream>
#include "CPersona.h"
#include "CEmpleado.h"
#include <fstream>//para manejo de archivos de texto y simular bd.
#include <sstream>//para separar por comas
#include <cstdio>//para las funciones remove() y rename()
using namespace std;

/*************** FUNCIONES DEL PROGRAMADOR ***************/
//CONSTRUCTOR CEmpleado
CEmpleado::CEmpleado() : CPersona(){
	id = "";
	contrasenia = "";
	turno = "";
	salario_base = 00.00;
	horas_trabajadas = 0;
	bono = 00.00;
}

//DEFINICION METODOS CEmpleado
void CEmpleado::gestionar_cuenta(){
	int opcion_cuenta;
	do {
		cout<<"\n\n*************** GESTION CUENTA EMPLEADO ***************";
		cout<<"\n1) Crear cuenta.";
		cout<<"\n2) Modificar Contraseña.";
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
				ifstream archivo_leer("archivo_empleados.txt");
				
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
					ofstream archivo_empleados("archivo_empleados.txt",ios::app);
					
					if(archivo_empleados.is_open()){
						archivo_empleados <<id<<","<<contrasenia<<","<<nombre<<","<<apellido_paterno<<","
						<<apellido_materno<<","<<edad<<"\n";
						archivo_empleados.close();
						cout<<"\n¡Cuenta registrada en archivo_empleados.txt!";
					} else {
						cout<<"\n¡Error! No se pudo abrir o crear la base de datos.";
					}
				}
			} break;
			
			case 2: {
                cout << "\n\n*************** MODIFICAR CONTRASEÑA EMPLEADO ***************";
                string id_buscar;
                cout << "\nIngrese su ID (5 dígitos): ";
                cin >> id_buscar;

                ifstream archivo_leer("archivo_empleados.txt");
                ofstream archivo_tempEmpleado("tempEmpleado.txt");

                if (archivo_leer.is_open() && archivo_tempEmpleado.is_open()) {
                    string linea;
                    bool encontrado = false;

                    while (getline(archivo_leer, linea)) {
                        stringstream separador(linea);
                        string id_leido, contrasenia_leida, nombre_leido, apPaterno_leido, apMaterno_leido, edad_leido;

                        // Se extraen los datos separados por comas
                        getline(separador, id_leido, ',');
                        getline(separador, contrasenia_leida, ',');
                        getline(separador, nombre_leido, ',');
                        getline(separador, apPaterno_leido, ',');
                        getline(separador, apMaterno_leido, ',');
                        getline(separador, edad_leido, ',');

                        // Se compara el id de la línea actual con el que se busca
                        if (id_leido == id_buscar) {
                            encontrado = true;
                            cout << "\n¡Cuenta encontrada! Ingrese su nueva contraseña.";
                            cout << "\nNueva contraseña (5 dígitos): ";
                            cin >> contrasenia;

                            // Se escriben los datos nuevos en el archivo temporal del empleado
                            archivo_tempEmpleado << id_leido << "," << contrasenia << "," << nombre_leido << ","
                                                 << apPaterno_leido << "," << apMaterno_leido << "," << edad_leido << "\n";
                        } else { 
                            // Si no coincide, se mantiene la línea original
                            archivo_tempEmpleado << linea << "\n";
                        }
                    }

                    archivo_leer.close();
                    archivo_tempEmpleado.close();

                    if (encontrado) {
                        // Se reemplaza el archivo viejo con el nuevo actualizado
                        remove("archivo_empleados.txt");
                        rename("tempEmpleado.txt", "archivo_empleados.txt");
                        cout << "\n¡Datos actualizados correctamente en la base de datos!";
                    } else { 
                        remove("tempEmpleado.txt");
                        cout << "\nNo se encontró ninguna cuenta con el ID ingresado: " << id_buscar;
                    }
                } else {
                    cout << "\nNo se pudo abrir la base de datos. Quizá no hay cuentas registradas.";
                }
                break;
            }
            	
			case 3:
				cout<<"\nRegresando al menu principal...\n";
				break;
			default:
				cout<<"\nOpcion no valida.";
		}
		
	}while (opcion_cuenta != 3);
}
