#include <iostream>
#include "CCliente.h"
#include <fstream>
#include <sstream>

void limpiar_pantalla(); 
using namespace std;

// Constructor
CCliente::CCliente() : CPersona() {
    id = "";
    contrasenia = "";
    tipo_membresia = "Basica";
    deporte_inscrito = "Ninguno";
    estado_membresia = "Inactiva";
}

bool CCliente::iniciar_sesion() {
    limpiar_pantalla();
    cout << "\n*************** INICIO DE SESIÓN CLIENTE ***************";
    string id_ingresado, pass_ingresada;
    cout << "\nIngrese su Id (5 dígitos): ";
    cin >> id_ingresado;

    ifstream archivo("archivo_clientes.txt");
    if (!archivo.is_open()) {
        cout << "\n¡Error! No hay clientes registrados aún o la base de datos no existe.\n";
        cout << "Presione ENTER para continuar...";
        cin.ignore(10000, '\n');
        cin.get();
        return false;
    }

    string linea;
    bool encontrado = false;
    while (getline(archivo, linea)) {
        stringstream separador(linea);
        string id_leido, pass_leida, nombre_leido;
        
        getline(separador, id_leido, ',');
        getline(separador, pass_leida, ',');
        getline(separador, nombre_leido, ',');

        if (id_leido == id_ingresado) {
            encontrado = true;
            cout << "Ingrese su contraseña: ";
            cin >> pass_ingresada;
            
            if (pass_ingresada == pass_leida) {
                this->id = id_leido;
                this->nombre = nombre_leido;
                cout << "\n¡Bienvenido, " << nombre << "!\n";
                archivo.close();
                return true;
            } else {
                cout << "\nContraseña incorrecta.\n";
                archivo.close();
                return false;
            }
        }
    }
    archivo.close();
    if (!encontrado) {
		cout << "\n¡Error! El Id ingresado no coincide con ningún cliente registrado.\n";
        cout << "Presione ENTER para continuar...";
        cin.ignore(10000, '\n');
        cin.get(); //
        return false;
	}
	
	return false;
}

void CCliente::menu_principal_cliente() {
    int opcion;
    do {
        limpiar_pantalla();
        cout << "\n\n*************** MENÚ CLIENTE ***************";
        cout << "\n1) Gestionar mi cuenta (Crear perfil).";
        cout << "\n2) Iniciar sesión para hacer Deporte.";
        cout << "\n3) Contratar Entrenador.";
        cout << "\n4) Regresar al menú principal.";
        cout << "\n********************************************";
        cout << "\nIngrese una opción: ";
        
        while (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ingrese solo números: ";
        }

        switch (opcion) {
            case 1:{
				 gestionar_cuenta();
			} break;
            
            case 2:{ 
                if(iniciar_sesion()) {
                    gestionar_deporte(); 
				}
                
            } break;
                
            case 3:{
				 contratar_entrenador();
			} break;
			
            case 4:{
				cout << "\nSaliendo del menú cliente...\n";
			}break;
			
            default: cout << "\nOpción no válida.\n"; break;
        }
    } while (opcion != 4);
}

void CCliente::gestionar_cuenta() {
    cout << "\n\n*************** REGISTRO DE CLIENTE ***************\n";
    if (solicitar_datos()) { //para llenar todos los datos personales del cliente
        cout << "\nIngrese un Id para su cuenta (5 dígitos): ";
        cin >> id;
        cout << "Cree una contraseña (5 dígitos): ";
        cin >> contrasenia;
        cout << "Tipo de membresia (Basica/Premium): ";
        cin >> tipo_membresia;
        estado_membresia = "Activa";

        ofstream archivo("archivo_clientes.txt", ios::app);
        if (archivo.is_open()) {
            archivo << id << "," 
                    << contrasenia << "," 
                    << nombre << "," 
                    << apellido_paterno << "," 
                    << apellido_materno << "," 
                    << edad << "," 
                    << telefono_celular << "," 
                    << calle << "," 
                    << calle_num << "," 
                    << colonia << ","
                    << tipo_membresia << "," 
                    << estado_membresia << "\n";
            archivo.close();
            cout << "\n¡Cuenta de cliente creada exitosamente! Ya puedes pasar a caja con el Empleado.\n";
        } else {
            cout << "\nError al guardar la base de datos de clientes.\n";
        }
    }
    cout << "Presione ENTER para continuar...";
    cin.ignore(10000, '\n');
    cin.get();
}

void CCliente::gestionar_deporte() {
    cout << "\n*************** AREA DEPORTIVA ***************\n";
    CDeporte mi_rutina; 
    mi_rutina.solicitar_datos_deporte();
    mi_rutina.realizar_deporte(id, nombre); //se registra qué cliente realizó la actividad
    
    cout << "Presione ENTER para continuar...";
    cin.ignore(10000, '\n');
    cin.get();
}

void CCliente::contratar_entrenador() {
    cout << "\n*************** CONTRATAR ENTRENADOR ***************\n";
    cout << "Modulo en construcción. ¡Pronto tendremos entrenadores disponibles!\n";
    cout << "Presione ENTER para regresar...";
    cin.ignore(10000, '\n');
    cin.get();
}
