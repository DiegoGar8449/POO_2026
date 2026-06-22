#include <iostream>
#include "CPersona.h"
#include "CJefe.h"
#include "CEmpleado.h"
#include <fstream>//para manejo de archivos de texto y simular bd.
#include <sstream>//para separar por comas
#include <cstdio>//para las funciones remove() y rename()
using namespace std;

//PROTOTIPOS (declaro la función global de limpiar pantalla que hice en main.cpp).
void limpiar_pantalla(); // limpia pantalla en linux y windows.

/*************** FUNCIONES DEL PROGRAMADOR ***************/
//CONSTRUCTOR CJefe
CJefe::CJefe() : CPersona(){
	id = "";
	contrasenia = "";
}

//DEFINICION METODOS CJefe
//MENU FUNCIONES JEFE
void CJefe::menu_principal_jefe(){
	int opcion_jefe;
	do {
		limpiar_pantalla();
		cout<<"\n\n*************** MENU JEFE ***************";
		cout<<"\n1) Gestionar mi cuenta (O crear nueva cuenta).";
		cout<<"\n2) Pagar a un empleado.";
		cout<<"\n3) Regresar al menú principal.";
		cout<<"\n****************************************";
		cout<<"\n\nIngrese el digito de la opción que desee realizar: ";
		
		while(!(cin >> opcion_jefe)){
			cin.clear();
			cin.ignore(10000, '\n');
			cout<<"\nIngrese unicamente digitos.";
			cout<<"\n\nSeleccione la accion que desee realizar: ";
		}
		
		switch(opcion_jefe) {
			case 1:
			gestionar_cuenta(); break;
			
			case 2:
			pagar_empleado(); break;
			
			case 3:
			cout<<"\nSaliendo del menu del jefe..."; break;
			
			default:
			cout<<"\nOpcion no valida."; break;
		}
	} while (opcion_jefe != 3);
}

//GESTIONAR CUENTA
void CJefe::gestionar_cuenta(){
	int opcion_cuenta;
	do {
		cout<<"\n\n*************** GESTION CUENTA JEFE ***************";
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
				
				// 1) Primero se llenan los datos personales.
				if(solicitar_datos()){
					
					// 2) Luego se pide el ID, con bucle hasta que sea único.
					string id_ingresado;
					bool id_existe = true;
					
					while(id_existe){
						cout<<"\nIngrese un Id para su cuenta (5 dígitos): ";
						cin>>id_ingresado;
						
						id_existe = false;
						ifstream archivo_leer("archivo_jefes.txt");
						if(archivo_leer.is_open()){
							string linea;
							while(getline(archivo_leer, linea)){
								stringstream separador(linea);
								string id_leido;
								getline(separador, id_leido, ',');
								if(id_leido == id_ingresado){
									id_existe = true;
									break;
								}
							}
							archivo_leer.close();
						}
						
						if(id_existe){
							cout<<"\n¡Error! El Id '" << id_ingresado << "' ya existe. Intente con otro.\n";
						}
					}
					id = id_ingresado;
					
					// 3) Por último la contraseña (credenciales juntas al final).
					cout<<"\nCree una contraseña (5 dígitos): ";
					cin>>contrasenia;
					
					// Guardar en la base de datos.
					ofstream archivo_jefes("archivo_jefes.txt", ios::app);
					if(archivo_jefes.is_open()){
						archivo_jefes << id << "," << contrasenia << "," << nombre << ","
						<< apellido_paterno << "," << apellido_materno << ","
						<< edad << "," << telefono_celular << "," 
						<< calle << "," << calle_num << "," << colonia << "\n";
						archivo_jefes.close();
						cout<<"\n¡Cuenta registrada exitosamente en archivo_jefes.txt!";
					} else {
						cout<<"\n¡Error! No se pudo abrir o crear la base de datos.";
					}
				}
			} break;
			
			case 2: {
				cout << "\n\n*************** MODIFICAR CONTRASEÑA JEFE ***************";
				string id_buscar;
				cout << "\nIngrese su ID (5 dígitos): ";
				cin >> id_buscar;

				ifstream archivo_leer("archivo_jefes.txt");

				//verificacion para comprobar que la bd original se pueda abrir.
				if (archivo_leer.is_open()) {
        
					//si la bd se pudo abrir, se crea un archivo temporal.
					ofstream archivo_tempJefe("tempJefe.txt");

					if (archivo_tempJefe.is_open()) {
						string linea;
						bool encontrado = false;

						while (getline(archivo_leer, linea)) {
							stringstream separador(linea);
							string id_leido, contrasenia_leida, nombre_leido, apPaterno_leido, apMaterno_leido;
							string edad_leida, tel_leido, calle_leida, num_leido, colonia_leida;

							getline(separador, id_leido, ',');
							getline(separador, contrasenia_leida, ',');
							getline(separador, nombre_leido, ',');
							getline(separador, apPaterno_leido, ',');
							getline(separador, apMaterno_leido, ',');
							getline(separador, edad_leida, ',');
							getline(separador, tel_leido, ',');
							getline(separador, calle_leida, ',');
							getline(separador, num_leido, ',');
							getline(separador, colonia_leida, '\n');

							if (id_leido == id_buscar) {
								encontrado = true;
								cout << "\n¡Cuenta encontrada! Ingrese su nueva contraseña.";
								cout << "\nNueva contraseña (5 dígitos): ";
								cin >> contrasenia;

								archivo_tempJefe << id_leido << "," << contrasenia << "," << nombre_leido << ","
                                << apPaterno_leido << "," << apMaterno_leido << "," << edad_leida << ","
                                << tel_leido << "," << calle_leida << "," << num_leido << "," << colonia_leida << "\n";
							} else { 
								archivo_tempJefe << linea << "\n";
							}
						}

						archivo_leer.close();
						archivo_tempJefe.close();

						if (encontrado) {
							remove("archivo_jefes.txt");
							rename("tempJefe.txt", "archivo_jefes.txt");
							cout << "\n¡Datos actualizados correctamente en la base de datos!";
						} else { 
							remove("tempJefe.txt"); // Borramos el temporal si no se encontró el ID
							cout << "\nNo se encontró ninguna cuenta con el ID ingresado: " << id_buscar;
						}
					}
				} else {
					cout << "\nNo se pudo abrir la base de datos o quizá no existe ninguna cuenta creada.";
				}
			} break;
		
			case 3:{
				cout<<"\nRegresando al menu principal...\n";
			
			}break;
			
			default:
			cout<<"\nOpcion no valida.";
		}
		
	}while (opcion_cuenta != 3);
}

//METODO PAGAR EMPLEADO
void CJefe::pagar_empleado(){
    cout << "\n*************** PAGAR EMPLEADO ***************";
    string id_buscar;
    cout << "\nIngrese el Id del empleado a pagar: ";
    cin >> id_buscar;
    
    ifstream leer_empleados("archivo_empleados.txt");
    if (leer_empleados.is_open()){
        string linea;
        bool encontrado = false;
        CEmpleado emp;
        
        while (getline(leer_empleados, linea)) {
            stringstream separador(linea);
            string id_leido, pass_leida, nombre_leido, apPaterno_leido, apMaterno_leido;
            string edad_leida, tel_leido, calle_leida, num_leido, colonia_leida;
            string turno_leido, salario_str, horas_str, bono_str;
            
            //se leen las 14 columnas
            getline(separador, id_leido, ',');
            getline(separador, pass_leida, ',');
            getline(separador, nombre_leido, ',');
            getline(separador, apPaterno_leido, ',');
            getline(separador, apMaterno_leido, ',');
            getline(separador, edad_leida, ',');
            getline(separador, tel_leido, ',');
            getline(separador, calle_leida, ',');
            getline(separador, num_leido, ',');
            getline(separador, colonia_leida, ',');
            getline(separador, turno_leido, ',');
            getline(separador, salario_str, ',');
            getline(separador, horas_str, ',');
            getline(separador, bono_str, '\n');
            
            if (id_leido == id_buscar){
                encontrado = true;
                emp.id = id_leido;
                emp.nombre = nombre_leido;
                emp.apellido_paterno = apPaterno_leido;
                emp.apellido_materno = apMaterno_leido;
                emp.edad = stoi(edad_leida);
                emp.telefono_celular = tel_leido;
                emp.calle = calle_leida;
                emp.calle_num = num_leido;
                emp.colonia = colonia_leida;
                emp.turno = turno_leido;
                emp.salario_base = stof(salario_str);
                emp.horas_trabajadas = stoi(horas_str);
                emp.bono = stof(bono_str);
                break;
            }
        }
        leer_empleados.close();
        
        if (encontrado){
            float pago_total = (emp.salario_base * emp.horas_trabajadas) + emp.bono;
            
            cout << "\nGenerando recibo de pago para: " << emp.nombre;
            cout << "\nTotal a pagar: $" << pago_total;
            
            string nombre_ticket = "ticket_pago_" + emp.id + ".txt";
            ofstream ticket(nombre_ticket);
            
            if (ticket.is_open()) {
                ticket << "\n****************************************";
                ticket << "\nGYMRATS - RECIBO DE PAGO";
                ticket << "\n****************************************";
                ticket << "\nId Empleado: " << emp.id;
                ticket << "\nNombre: " << emp.nombre << " " << emp.apellido_paterno << " " << emp.apellido_materno;
                ticket << "\nPago por hora: $" << emp.salario_base;
                ticket << "\nHoras laboradas: " << emp.horas_trabajadas;
                ticket << "\nBono: $" << emp.bono;
                ticket << "\n----------------------------------------";
                ticket << "\nTOTAL NETO RECIBIDO: $" << pago_total;
                ticket.close();
                
                cout << "\n¡Ticket de pago generado con exito (" << nombre_ticket << ")!";
                
                //segundo bloque de lectura para reiniciar horas y bonos
                ifstream archivo_leer("archivo_empleados.txt");
                ofstream archivo_temp("tempEmpleado.txt");
                
                if (archivo_leer.is_open() && archivo_temp.is_open()){
                    string linea;
                    while (getline(archivo_leer, linea)){
                        stringstream separador(linea);
                        string id_leido, pass_leida, nombre_leido, apPaterno_leido, apMaterno_leido;
                        string edad_leida, tel_leido, calle_leida, num_leido, colonia_leida;
                        string turno_leido, salario_str, horas_str, bono_str;
                        
                        getline(separador, id_leido, ',');
                        getline(separador, pass_leida, ',');
                        getline(separador, nombre_leido, ',');
                        getline(separador, apPaterno_leido, ',');
                        getline(separador, apMaterno_leido, ',');
                        getline(separador, edad_leida, ',');
                        getline(separador, tel_leido, ',');
                        getline(separador, calle_leida, ',');
                        getline(separador, num_leido, ',');
                        getline(separador, colonia_leida, ',');
                        getline(separador, turno_leido, ',');
                        getline(separador, salario_str, ',');
                        getline(separador, horas_str, ',');
                        getline(separador, bono_str, '\n');
                        
                        if (id_leido == emp.id){
                            //las metricas se reinician a 0.
                            archivo_temp << id_leido << "," << pass_leida << "," 
                                         << nombre_leido << "," << apPaterno_leido << "," 
                                         << apMaterno_leido << "," << edad_leida << ","
                                         << tel_leido << "," << calle_leida << ","
                                         << num_leido << "," << colonia_leida << ","
                                         << turno_leido << "," << salario_str << "," 
                                         << "0" << "," 
                                         << "0.00" << "\n";
                        } else {
                            archivo_temp << linea << "\n";
                        }
                    }
                    archivo_leer.close();
                    archivo_temp.close();
                    
                    remove("archivo_empleados.txt");
                    rename("tempEmpleado.txt", "archivo_empleados.txt");
                    
                    cout << "\nHoras y bonos del empleado reseteados para el próximo periodo.";
                }
            }
        } else {
            cout << "\n¡Error! No se encontró ningun empleado con el Id: " << id_buscar;
        }
    } else {
        cout << "\n¡Error! No se pudo abrir la base de datos de empleados. Quiza no hay ningun empleado registrado.";
    }
    
    cout << "\nPresione ENTER para continuar...";
    cin.ignore(10000, '\n');
    cin.get();
}
