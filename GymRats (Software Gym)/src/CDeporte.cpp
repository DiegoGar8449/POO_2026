#include <iostream>
using namespace std;
#include "CDeporte.h"

/*************** FUNCIONES DEL PROGRAMADOR ***************/
#include <iostream>
#include <fstream>
#include "CDeporte.h"

using namespace std;

/*************** CONSTRUCTORES ***************/

// Constructor clase padre CDeporte
CDeporte::CDeporte() {
    id = "";
    nombre_deporte = "";
    duracion_sesion = 0;
    for(int i = 0; i < 5; i++){
        accesorios_deportivos[i] = "";
    }
}

// Destructor clase padre
CDeporte::~CDeporte() {}

// Constructores clases hijas
CZumba::CZumba() : CDeporte() {
    nivel_intensidad = "";
}

CCardio::CCardio() : CDeporte() {
    velocidad = 0.0;
}

CPesas::CPesas() : CDeporte() {
    peso = 0;
    sets = 0;
    repeticiones = 0;
}

/*************** MÉTODOS DE LA CLASE PADRE ***************/

void CDeporte::solicitar_datos_deporte() {
    int opcion_dep;
    cout << "\n*************** SELECCION DE ACTIVIDAD DEPORTIVA ***************";
    cout << "\n1) Zumba   (ID: ZUM-01)";
    cout << "\n2) Cardio  (ID: CRD-02)";
    cout << "\n3) Pesas   (ID: PES-03)";
    cout << "\nSeleccione la actividad que va a realizar: ";
    
    while (!(cin >> opcion_dep) || opcion_dep < 1 || opcion_dep > 3) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Opción invalida. Ingrese un número entre 1 y 3: ";
    }
    
    if (opcion_dep == 1) {
        id = "ZUM-01";
        nombre_deporte = "Zumba";
    } else if (opcion_dep == 2) {
        id = "CRD-02";
        nombre_deporte = "Cardio";
    } else if (opcion_dep == 3) {
        id = "PES-03";
        nombre_deporte = "Pesas";
    }
    
    cout << "Ingrese la duracion de la sesion en minutos: ";
    while (!(cin >> duracion_sesion) || duracion_sesion <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "¡Error! Ingrese un tiempo valido (mayor a 0): ";
    }
}

void CDeporte::realizar_deporte(const string &id_cliente, const string &nombre_cliente) {
    cout << "\nIniciando sesion de " << nombre_deporte << " por " << duracion_sesion << " minutos...";
    
    //generar el .txt con el registro de la actividad
    ofstream archivo_deportes("registro_deportes.txt", ios::app);
    
    if (archivo_deportes.is_open()) {
        //para guardar los datos separados por comas, como en el resto de bd.
        //se agrega el id y nombre del cliente para saber quien realizo la actividad.
        archivo_deportes << id_cliente << "," << nombre_cliente << "," 
                          << id << "," << nombre_deporte << "," << duracion_sesion << "\n";
        archivo_deportes.close();
        cout << "\nRutina completada y guardada en registro_deportes.txt exitosamente!\n";
    } else {
        cout << "\nError! No se pudo generar el archivo de registro de deportes.\n";
    }
}
