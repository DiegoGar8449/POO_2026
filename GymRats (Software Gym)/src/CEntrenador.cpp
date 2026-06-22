#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <vector>
#include "CPersona.h"
#include "CEntrenador.h"
using namespace std;

void limpiar_pantalla();

/*************** CONSTRUCTOR ***************/
CEntrenador::CEntrenador() : CPersona() {
    tipo_deporte = "";
    sueldo = 0.0;
    jornada_laboral = "";
}

/*************** INICIO DE SESION ***************/
bool CEntrenador::iniciar_sesion() {
    limpiar_pantalla();
    cout << "\n*************** INICIO DE SESION ENTRENADOR ***************";
    string id_ing, pass_ing;
    cout << "\nIngrese su Id: ";
    cin >> id_ing;

    ifstream archivo("archivo_entrenadores.txt");
    if (!archivo.is_open()) {
        cout << "\n¡Error! No hay entrenadores registrados.\n";
        cout << "Presione ENTER para continuar...";
        cin.ignore(10000, '\n'); cin.get();
        return false;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream sep(linea);
        string id_l, pass_l, nom_l, apPat_l, apMat_l, dep_l, sueldo_l, jorn_l;
        getline(sep, id_l, ',');
        getline(sep, pass_l, ',');
        getline(sep, nom_l, ',');
        getline(sep, apPat_l, ',');
        getline(sep, apMat_l, ',');
        getline(sep, dep_l, ',');
        getline(sep, sueldo_l, ',');
        getline(sep, jorn_l, '\n');

        if (id_l == id_ing) {
            cout << "Ingrese su contrasenia: ";
            cin >> pass_ing;
            if (pass_ing == pass_l) {
                id              = id_l;
                contrasenia     = pass_l;
                nombre          = nom_l;
                apellido_paterno = apPat_l;
                apellido_materno = apMat_l;
                tipo_deporte    = dep_l;
                sueldo          = stof(sueldo_l);
                jornada_laboral = jorn_l;
                archivo.close();
                cout << "\n¡Bienvenido, " << nombre << "!\n";
                return true;
            } else {
                cout << "\nContrasenia incorrecta.\n";
                archivo.close();
                return false;
            }
        }
    }
    archivo.close();
    cout << "\n¡Error! Id no encontrado.\n";
    cout << "Presione ENTER para continuar...";
    cin.ignore(10000, '\n'); cin.get();
    return false;
}

/*************** MENU PRINCIPAL ***************/
void CEntrenador::menu_principal_entrenador() {
    int opcion;
    do {
        limpiar_pantalla();
        cout << "\n\n*************** MENU ENTRENADOR ***************";
        cout << "\n1) Gestionar mi cuenta (Crear cuenta).";
        cout << "\n2) Iniciar sesion y ver solicitudes de clientes.";
        cout << "\n3) Cobrar a mis clientes (generar lista de cobros).";
        cout << "\n4) Regresar al menu principal.";
        cout << "\n***********************************************";
        cout << "\nIngrese una opcion: ";

        while (!(cin >> opcion)) {
            cin.clear(); cin.ignore(10000, '\n');
            cout << "Ingrese solo digitos: ";
        }

        switch (opcion) {
            case 1: gestionar_cuenta(); break;
            case 2:
                if (iniciar_sesion()) {
                    ver_solicitudes();
                    enseniar_deporte();
                }
                break;
            case 3:
                if (id.empty()) {
                    cout << "\nDebe iniciar sesion primero (opcion 2).\n";
                    cout << "Presione ENTER..."; cin.ignore(10000, '\n'); cin.get();
                } else {
                    cobrar_cliente();
                }
                break;
            case 4: cout << "\nSaliendo del menu de entrenador...\n"; break;
            default: cout << "\nOpcion no valida.\n"; break;
        }
    } while (opcion != 4);
}

/*************** GESTIONAR CUENTA ***************/
void CEntrenador::gestionar_cuenta() {
    cout << "\n\n*************** CREAR CUENTA ENTRENADOR ***************";



    //datos personales heredados de CPersona.
    if (!solicitar_datos()) {
        cout << "Presione ENTER..."; cin.ignore(10000, '\n'); cin.get();
        return;
    }
    
        //id con verificacion para evitar repetidos
    string id_ing;
    bool id_existe = true;
    while (id_existe) {
        cout << "\nIngrese un Id para su cuenta (5 digitos): ";
        cin >> id_ing;

        id_existe = false;
        ifstream leer("archivo_entrenadores.txt");
        if (leer.is_open()) {
            string linea;
            while (getline(leer, linea)) {
                stringstream sep(linea);
                string id_l;
                getline(sep, id_l, ',');
                if (id_l == id_ing) { id_existe = true; break; }
            }
            leer.close();
        }
        if (id_existe) {
            cout << "\n¡Error! El Id '" << id_ing << "' ya existe. Intente con uno diferente.\n";
        }
    }
    id = id_ing;

    //credenciales juntas al final de los datos personales).
    cout << "\nCree una contrasenia (5 digitos): ";
    cin >> contrasenia;

    //datos laborales propios de CEntrenador.
    cout << "Deporte que entrena [ZUMBA/CARDIO/PESAS] (Solo mayusculas): ";
    cin >> tipo_deporte;

    cout << "Sueldo por hora: $";
    while (!(cin >> sueldo) || sueldo <= 0) {
        cin.clear(); cin.ignore(10000, '\n');
        cout << "Ingrese un sueldo valido: $";
    }

    cout << "Jornada laboral (MATUTINA/MIXTA/NOCTURNA): ";
    cin >> jornada_laboral;

    //guardar id, contrasenia, nombre, ap_pat, ap_mat, deporte, sueldo, jornada.
    ofstream archivo("archivo_entrenadores.txt", ios::app);
    if (archivo.is_open()) {
        archivo << id << "," << contrasenia << "," << nombre << ","
                << apellido_paterno << "," << apellido_materno << ","
                << tipo_deporte << "," << sueldo << "," << jornada_laboral << "\n";
        archivo.close();
        cout << "\n¡Cuenta de entrenador creada exitosamente!\n";
    } else {
        cout << "\nError al guardar la cuenta.\n";
    }
    cout << "Presione ENTER..."; cin.ignore(10000, '\n'); cin.get();
}

/*************** VER Y ACEPTAR SOLICITUDES ***************/
void CEntrenador::ver_solicitudes() {
    cout << "\n\n*************** SOLICITUDES DE CLIENTES ***************\n";

    ifstream archivo("solicitudes_entrenador.txt");
    if (!archivo.is_open()) {
        cout << "No hay solicitudes pendientes.\n";
        cout << "Presione ENTER..."; cin.ignore(10000, '\n'); cin.get();
        return;
    }

    vector<string> lineas;
    string linea;
    while (getline(archivo, linea)) lineas.push_back(linea);
    archivo.close();

    bool hay_pendientes = false;
    for (int i = 0; i < (int)lineas.size(); i++) {
        stringstream sep(lineas[i]);
        string id_c, nom_c, dep_c, estado_c;
        getline(sep, id_c, ',');
        getline(sep, nom_c, ',');
        getline(sep, dep_c, ',');
        getline(sep, estado_c, '\n');

        if (dep_c == tipo_deporte && estado_c == "Pendiente") {
            hay_pendientes = true;
            cout << "\n[" << i << "] Id: " << id_c << " | Nombre: " << nom_c
                 << " | Deporte: " << dep_c;
        }
    }

    if (!hay_pendientes) {
        cout << "No hay solicitudes pendientes para tu deporte (" << tipo_deporte << ").\n";
        cout << "Presione ENTER..."; cin.ignore(10000, '\n'); cin.get();
        return;
    }

    cout << "\n\nIngrese el numero de la solicitud que desea ACEPTAR (o -1 para salir): ";
    int sel;
    cin >> sel;

    if (sel == -1 || sel < 0 || sel >= (int)lineas.size()) {
        cout << "\nSin cambios.\n";
        cout << "Presione ENTER..."; cin.ignore(10000, '\n'); cin.get();
        return;
    }

    stringstream sep2(lineas[sel]);
    string id_c, nom_c, dep_c, estado_c;
    getline(sep2, id_c, ',');
    getline(sep2, nom_c, ',');
    getline(sep2, dep_c, ',');
    getline(sep2, estado_c, '\n');

    lineas[sel] = id_c + "," + nom_c + "," + dep_c + ",Aceptada";
    ofstream actualizar("solicitudes_entrenador.txt");
    for (const string &l : lineas) actualizar << l << "\n";
    actualizar.close();

    ofstream lista("clientes_entrenador.txt", ios::app);
    if (lista.is_open()) {
        lista << id << "," << nombre << "," << id_c << "," << nom_c << "," << dep_c << "\n";
        lista.close();
        cout << "\n¡Cliente " << nom_c << " aceptado y agregado a tu lista!\n";
    }
    cout << "Presione ENTER..."; cin.ignore(10000, '\n'); cin.get();
}

/*************** ENSENIAR DEPORTE ***************/
void CEntrenador::enseniar_deporte() {
    cout << "\n\n*************** HORARIO DE ENTRENAMIENTO ***************";
    cout << "\nEntrenador: " << nombre << " " << apellido_paterno;
    cout << "\nDeporte: " << tipo_deporte;
    cout << "\nJornada: " << jornada_laboral;
    cout << "\n\nEl entrenador le ensenara a sus clientes " << tipo_deporte;
    cout << "\nLos clientes deben presentarse en el area de " << tipo_deporte
         << " con ropa deportiva adecuada.\n";
    cout << "Presione ENTER..."; cin.ignore(10000, '\n'); cin.get();
}

/*************** COBRAR CLIENTES ***************/
void CEntrenador::cobrar_cliente() {
    cout << "\n*************** GENERANDO LISTA DE COBROS ***************\n";

    float monto = 0.0;
    if (tipo_deporte == "Zumba")       monto = sueldo;
    else if (tipo_deporte == "Cardio") monto = sueldo;
    else if (tipo_deporte == "Pesas")  monto = sueldo;

    ifstream lista("clientes_entrenador.txt");
    if (!lista.is_open()) {
        cout << "No tienes clientes registrados aun.\n";
        cout << "Presione ENTER..."; cin.ignore(10000, '\n'); cin.get();
        return;
    }

    string nombre_archivo = "cobros_entrenador_" + id + ".txt";
    ofstream cobros(nombre_archivo);
    if (!cobros.is_open()) {
        cout << "Error al generar el archivo de cobros.\n";
        lista.close();
        cout << "Presione ENTER..."; cin.ignore(10000, '\n'); cin.get();
        return;
    }

    cobros << "****************************************\n";
    cobros << "GYMRATS - LISTA DE COBROS\n";
    cobros << "****************************************\n";
    cobros << "Entrenador: " << nombre << " " << apellido_paterno << "\n";
    cobros << "Deporte: " << tipo_deporte << "\n";
    cobros << "----------------------------------------\n";

    float total = 0.0;
    int num_cliente = 1;
    string linea;
    bool tiene_clientes = false;

    while (getline(lista, linea)) {
        stringstream sep(linea);
        string id_ent, nom_ent, id_c, nom_c, dep_c;
        getline(sep, id_ent, ',');
        getline(sep, nom_ent, ',');
        getline(sep, id_c, ',');
        getline(sep, nom_c, ',');
        getline(sep, dep_c, '\n');

        if (id_ent == id) {
            tiene_clientes = true;
            cobros << num_cliente++ << ") Id: " << id_c
                   << " | Nombre: " << nom_c
                   << " | Deporte: " << dep_c
                   << " | Monto: $" << monto << "\n";
            total += monto;
        }
    }
    lista.close();

    if (!tiene_clientes) cobros << "(Sin clientes registrados aun)\n";

    cobros << "----------------------------------------\n";
    cobros << "TOTAL A RECAUDAR: $" << total << "\n";
    cobros << "****************************************\n";
    cobros.close();

    cout << "¡Lista de cobros generada en " << nombre_archivo << "!\n";
    cout << "Presione ENTER..."; cin.ignore(10000, '\n'); cin.get();
}
