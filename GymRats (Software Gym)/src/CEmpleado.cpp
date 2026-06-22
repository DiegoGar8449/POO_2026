#include <iostream>
#include "CPersona.h"
#include "CEmpleado.h"
#include "CEmergencia.h"
#include <fstream>
#include <sstream>
#include <cstdio>
using namespace std;

void limpiar_pantalla();

//CONSTRUCTOR
CEmpleado::CEmpleado() : CPersona(){
    id = "";
    contrasenia = "";
    turno = "";
    salario_base = 0.00;
    horas_trabajadas = 0;
    bono = 0.00;
}

//METODO INICIAR SESION
bool CEmpleado::iniciar_sesion(){
    limpiar_pantalla();
    cout << "\n*************** INICIO DE SESION EMPLEADO ***************";
    
    string id_ingresado;
    cout << "\nIngrese su Id (5 dígitos): ";
    cin >> id_ingresado;
    
    //verificar si existe la bd.
    ifstream archivo_leer("archivo_empleados.txt");
    if (!archivo_leer.is_open()){
        cout << "\n¡Error! No se encontró el id en la base de datos de empleados. Quiza no se ha creado una cuenta.";
        cout << "\nPresione ENTER para continuar...";
        cin.ignore(10000, '\n');
        cin.get();
        return false;
    }
    
    string linea;
    bool id_encontrado = false;
    string pass_correcta;
    
    //variables temporales para guardar los datos si encontramos el Id
    string t_id, t_pass, t_nombre, t_apPat, t_apMat, t_edad, t_tel, t_calle, t_num, t_col;
    string t_turno, t_salario, t_horas, t_bono;
    
    //buscar el id en el archivo
    while (getline(archivo_leer, linea)){
        stringstream separador(linea);
        
        getline(separador, t_id, ',');
        getline(separador, t_pass, ',');
        getline(separador, t_nombre, ',');
        getline(separador, t_apPat, ',');
        getline(separador, t_apMat, ',');
        getline(separador, t_edad, ',');
        getline(separador, t_tel, ',');
        getline(separador, t_calle, ',');
        getline(separador, t_num, ',');
        getline(separador, t_col, ',');
        getline(separador, t_turno, ',');
        getline(separador, t_salario, ',');
        getline(separador, t_horas, ',');
        getline(separador, t_bono, '\n');
        
        if (t_id == id_ingresado){
            id_encontrado = true;
            pass_correcta = t_pass; //se guarda la contraseña real para validarla después.
            break;//se detiene la busqueda.
        }
    }
    archivo_leer.close();
    
    //si el Id no existe, cancelamos el inicio de sesión.
    if (!id_encontrado){
        cout << "\n¡Error! El Id ingresado no existe en el sistema.";
        cout << "\nPresione ENTER para continuar...";
        cin.ignore(10000, '\n');
        cin.get();
        return false;
    }
    
    //si el Id sí existe, solicitamos la contraseña.
    string pass_ingresada;
    cout << "Ingrese su contraseña (5 dígitos): ";
    cin >> pass_ingresada;
    
    if (pass_ingresada == pass_correcta){
        //se asignan todas las variables temporales al objeto de la clase.
        id = t_id;
        contrasenia = t_pass;
        nombre = t_nombre;
        apellido_paterno = t_apPat;
        apellido_materno = t_apMat;
        edad = stoi(t_edad);
        telefono_celular = t_tel;
        calle = t_calle;
        calle_num = t_num;
        colonia = t_col;
        turno = t_turno;
        salario_base = stof(t_salario);
        horas_trabajadas = stoi(t_horas);
        bono = stof(t_bono);
        
        cout << "\nBienvenido, " << nombre << "!";
        cout << "\nHoras trabajadas actuales: " << horas_trabajadas;
        cout << "\nBono acumulado: $" << bono;
        cout << "\nPresione ENTER para continuar...";
        cin.ignore(10000, '\n');
        cin.get();
        return true;
    } else {
        //si la contraseña no coincide.
        cout << "\n¡Error! Contraseña incorrecta.";
        cout << "\nPresione ENTER para continuar...";
        cin.ignore(10000, '\n');
        cin.get();
        return false;
    }
}

//MENU PRINCIPAL EMPLEADO
void CEmpleado::menu_principal_empleado(){
    int opcion_empleado;
    do {
        limpiar_pantalla();
        cout << "\n\n*************** MENU EMPLEADO ***************";
        cout << "\n1) Gestionar mi cuenta (Crear perfil o Modificar contraseña).";
        cout << "\n2) Iniciar Sesion para Cobrar a un cliente.";
        cout << "\n3) Reportar Emergencia (Ambulancia / Bomberos / Policia).";
        cout << "\n4) Regresar al menu principal.";
        cout << "\n**********************************************************";
        cout << "\nIngrese el digito de la opcion que desee realizar: ";

        while (!(cin >> opcion_empleado)){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nIngrese unicamente digitos.";
            cout << "\nSeleccione la accion que desee realizar: ";
        }

        switch(opcion_empleado) {
            case 1: gestionar_cuenta(); break;
            case 2:
                if(iniciar_sesion()) {
                    cobrar_cliente();
                }
                break;
            case 3: llamar_emergencias(); break;
            case 4: cout << "\nSaliendo del menu del empleado..."; break;
            default: cout << "\nOpcion no valida."; break;
        }
    } while (opcion_empleado != 4);
}

//METODO GESTIONAR CUENTA
void CEmpleado::gestionar_cuenta(){
    int opcion_cuenta;
    do {
        cout << "\n*************** GESTION CUENTA EMPLEADO ***************";
        cout << "\n1) Crear cuenta.";
        cout << "\n2) Modificar Contraseña.";
        cout << "\n3) Salir.";
        cout << "\n****************************************";
        cout << "\nDigite el numero de la opcion: ";
        
        while (!(cin >> opcion_cuenta)){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\n¡Error! Ingrese unicamente digitos.";
            cout << "\nDigite el numero de la opcion: ";
        }
        
        switch(opcion_cuenta){
            case 1: {
				cout << "\n\n*************** CREAR CUENTA EMPLEADO ***************\n\n";
    
				// 1) Primero los datos personales.
				if (solicitar_datos()) {
        
					// 2) Id con bucle hasta que sea único.
					string id_ingresado;
					bool id_valido = false;
        
					while (!id_valido) {
						cout << "\nIngrese el ID asignado para este empleado (5 dígitos): ";
						cin >> id_ingresado;
            
						bool id_existe = false;
						ifstream archivo_leer("archivo_empleados.txt");
            
						if (archivo_leer.is_open()) {
							string linea;
							while (getline(archivo_leer, linea)) {
								stringstream separador(linea);
								string id_leido;
								getline(separador, id_leido, ',');
								if (id_leido == id_ingresado) {
									id_existe = true;
									break;
								}
							}
							archivo_leer.close();
						}
            
						if (id_existe) {
							cout << "¡Error! El ID '" << id_ingresado << "' ya existe. Intente con uno distinto.\n";
						} else {
							id_valido = true;
							id = id_ingresado;
						}
					}
        
					// 3) Contraseña justo después del ID (credenciales juntas).
					cout << "Ingrese su contraseña (5 dígitos): ";
					cin >> contrasenia;
        
					// 4) Datos laborales al final.
					cout << "\nIngrese el turno asignado (Ej. Matutino, Vespertino, Mixto): ";
					cin >> turno;
            
					cout << "Ingrese el salario base por hora: $";
					while (!(cin >> salario_base) || salario_base <= 0) {
						cout << "¡Error! Ingrese un salario válido mayor a 0: $";
						cin.clear();
						cin.ignore(10000, '\n');
					}
					horas_trabajadas = 0;
					bono = 0.00;
        
					// Guardar en la base de datos.
					ofstream archivo_empleados("archivo_empleados.txt", ios::app);
        
					if (archivo_empleados.is_open()) {
						archivo_empleados << id << "," << contrasenia << "," << nombre << ","
                        << apellido_paterno << "," << apellido_materno << ","
                        << edad << "," << telefono_celular << ","
                        << calle << "," << calle_num << "," << colonia << ","
                        << turno << "," << salario_base << ","
                        << horas_trabajadas << "," << bono << "\n";
            
						archivo_empleados.close();
						cout << "\n¡Cuenta registrada en archivo_empleados.txt exitosamente!";
					} else {
						cout << "\n¡Error! No se pudo abrir o crear la base de datos.";
					}
				}
    
				break;
			}
            
            case 2: {
				cout << "\n*************** MODIFICAR CONTRASEÑA EMPLEADO ***************";
				string id_buscar;
				cout << "\nIngrese su ID (5 dígitos): ";
				cin >> id_buscar;

				ifstream archivo_leer("archivo_empleados.txt");

				//verifica que la bd original exista, para abrirla
				if (archivo_leer.is_open()) {
        
					//si se pudo abrir la bd, se crea el archivo temporal.
					ofstream archivo_temp("tempEmpleado.txt");

					if (archivo_temp.is_open()) {
						string linea;
						bool encontrado = false;

						while (getline(archivo_leer, linea)) {
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

							if (id_leido == id_buscar) {
								encontrado = true;
								cout << "\n¡Cuenta encontrada! Ingrese su nueva contraseña.";
								cout << "\nNueva contraseña (5 dígitos): ";
								cin >> pass_leida;

								archivo_temp << id_leido << "," << pass_leida << "," 
                                << nombre_leido << "," << apPaterno_leido << "," 
                                << apMaterno_leido << "," << edad_leida << ","
                                << tel_leido << "," << calle_leida << ","
                                << num_leido << "," << colonia_leida << ","
                                << turno_leido << "," << salario_str << "," 
                                << horas_str << "," << bono_str << "\n";
							} else {
								archivo_temp << linea << "\n";
							}
						}
						archivo_leer.close();
						archivo_temp.close();

						if (encontrado) {
							remove("archivo_empleados.txt");
							rename("tempEmpleado.txt", "archivo_empleados.txt");
							cout << "\n¡Contraseña actualizada correctamente!";
						} else {
						remove("tempEmpleado.txt");//se borra el archivo temporal si el id no existe.
						cout << "\nNo se encontró ninguna cuenta con el ID: " << id_buscar;
						}
					}
				} else {
				//nunca se crea el archivo temporal para evitar generar archivos fantasma.
					cout << "\nNo se pudo abrir la base de datos de empleados. Quiza no se ha creado una cuenta.";
				}
				break;
			}
            
            case 3:{
                cout << "\nRegresando al menu principal...";
            }break;
            
            default:
                cout << "\nOpcion no valida.";
        }
    } while (opcion_cuenta != 3);
}

//METODO COBRAR CLIENTE
void CEmpleado::cobrar_cliente(){
    limpiar_pantalla();
	cout << "\n*************** COBRAR A CLIENTE ***************";
	
	string id_cliente;
	cout << "\nIngrese el ID del cliente (5 dígitos): ";
	cin >> id_cliente;
    
    ifstream archivo_clientes("archivo_clientes.txt");
		if (!archivo_clientes.is_open()){
			cout << "\n¡Error! No se pudo abrir la bd de clientes. Quiza no hay ningun cliente registrado.";
        return;
		}
		
		string linea;
		bool encontrado = false;
		string nombre_cliente, apPaterno_cliente, apMaterno_cliente, membresia_cliente, estado_membresia_cliente;
    
		while (getline(archivo_clientes, linea)){
			stringstream separador(linea);
			string id_leido, pass_leida, nombre_leido, apPat_leido, apMat_leido, edad_leida, tel_leido;
			string calle_leida, num_leido, colonia_leida, membresia_leida, estado_leido;
			getline(separador, id_leido, ',');
			getline(separador, pass_leida, ',');
			getline(separador, nombre_leido, ',');
			getline(separador, apPat_leido, ',');
			getline(separador, apMat_leido, ',');
			getline(separador, edad_leida, ',');
			getline(separador, tel_leido, ',');
			getline(separador, calle_leida, ',');
			getline(separador, num_leido, ',');
			getline(separador, colonia_leida, ',');
			getline(separador, membresia_leida, ',');
			getline(separador, estado_leido, '\n');
        
			if (id_leido == id_cliente){
				encontrado = true;
				nombre_cliente = nombre_leido;
				apPaterno_cliente = apPat_leido;
				apMaterno_cliente = apMat_leido;
				membresia_cliente = membresia_leida;
				estado_membresia_cliente = estado_leido;
				break;
			}	
		}
		archivo_clientes.close();
    
		if (!encontrado){
			cout << "\n¡Error! No se encontró ningún cliente con el ID: " << id_cliente;
			cout << "\nPresione ENTER para continuar...";
			cin.ignore(10000, '\n');
			cin.get();
			return;
		}
    
		cout << "\nCliente encontrado: " << nombre_cliente;
    
		float monto;
		cout << "\nIngrese el monto a cobrar: $";
		while (!(cin >> monto) || monto <= 0){
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "\n¡Error! Ingrese un monto válido (mayor a 0): $";
		}
    
		cout << "\n**************************************************";
		cout << "\nCobro de $" << monto << " realizado a " << nombre_cliente;
		cout << "\n**************************************************";
    
		//generar el ticket de cobro del cliente, igual que se hace con el pago a empleados.
		string nombre_ticket_cliente = "ticket_cobro_" + id_cliente + ".txt";
		ofstream ticket_cliente(nombre_ticket_cliente);

		if (ticket_cliente.is_open()) {
			ticket_cliente << "\n****************************************";
			ticket_cliente << "\nGYMRATS - RECIBO DE COBRO";
			ticket_cliente << "\n****************************************";
			ticket_cliente << "\nId Cliente: " << id_cliente;
			ticket_cliente << "\nNombre: " << nombre_cliente << " " << apPaterno_cliente << " " << apMaterno_cliente;
			ticket_cliente << "\nTipo de membresia: " << membresia_cliente;
			ticket_cliente << "\nEstado de membresia: " << estado_membresia_cliente;
			ticket_cliente << "\nAtendido por (Id empleado): " << id;
			ticket_cliente << "\n----------------------------------------";
			ticket_cliente << "\nMONTO COBRADO: $" << monto;
			ticket_cliente << "\n****************************************\n";
			ticket_cliente.close();
			cout << "\n¡Ticket de cobro generado con exito (" << nombre_ticket_cliente << ")!";
		} else {
			cout << "\n¡Error! No se pudo generar el ticket de cobro del cliente.";
		}
    
		//para actualizar las métricas del empleado acorde a sus actividades realizadas.
		horas_trabajadas += 1;
		bono += (monto * 0.10);

		//permite que los cambios en el archivo se mantengan.
		ifstream archivo_leer("archivo_empleados.txt");

		//verifica que se pueda abrir el archivo de empleados
		if (archivo_leer.is_open()) {
        
			//crear el archivo temporal
			ofstream archivo_temp("tempEmpleado.txt");

			if (archivo_temp.is_open()) {
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

					if (id_leido == id){
						// Al coincidir con el empleado activo, se guardan los datos actualizados
						archivo_temp << id_leido << "," << pass_leida << "," 
                        << nombre_leido << "," << apPaterno_leido << "," 
                        << apMaterno_leido << "," << edad << "," 
                        << telefono_celular << "," << calle << "," 
                        << calle_num << "," << colonia << ","
                        << turno_leido << "," << salario_str << "," 
                        << horas_trabajadas << "," << bono << "\n";
					} else {	
						archivo_temp << linea << "\n";
					}
				}
				archivo_leer.close();
				archivo_temp.close();

				remove("archivo_empleados.txt");
				rename("tempEmpleado.txt", "archivo_empleados.txt");
			}
		} else {
			cout << "\n¡Error! No se pudo actualizar el registro del empleado en la base de datos.";
		}

		cout << "\nHoras trabajadas acumuladas: " << horas_trabajadas;
		cout << "\nBono acumulado: $" << bono;
		cout << "\n**************************************************";
		cout << "\nPresione ENTER para continuar...";
		cin.ignore(10000, '\n');
		cin.get();
}

//METODO LLAMAR EMERGENCIAS
void CEmpleado::llamar_emergencias() {
    //se verifica que el empleado haya iniciado sesion (id no vacío).
    if (id.empty()) {
        cout << "\n¡Error! Debe iniciar sesion primero para reportar una emergencia.";
        cout << "\nPresione ENTER para continuar...";
        cin.ignore(10000, '\n');
        cin.get();
        return;
    }

    //asociacion con CEmergencia: se crea el objeto y se le pasa el id del empleado.
    CEmergencia emergencia;
    emergencia.enviar_ayuda(id);

    cout << "Presione ENTER para continuar...";
    cin.ignore(10000, '\n');
    cin.get();
}
