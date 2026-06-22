#include <iostream>
#include <fstream>
#include "CDeporte.h"
using namespace std;

/*************** CONSTRUCTORES ***************/

CDeporte::CDeporte() {
    id = "";
    nombre_deporte = "";
    duracion_sesion = 0;
    for (int i = 0; i < 5; i++) accesorios_deportivos[i] = "";
}
CDeporte::~CDeporte() {}

CZumba::CZumba() : CDeporte() {
    id = "ZUM-01";
    nombre_deporte = "Zumba";
    nivel_intensidad = "";
}

CCardio::CCardio() : CDeporte() {
    id = "CRD-02";
    nombre_deporte = "Cardio";
    velocidad = 0.0;
}

CPesas::CPesas() : CDeporte() {
    id = "PES-03";
    nombre_deporte = "Pesas";
    peso = 0;
    sets = 0;
    repeticiones = 0;
}

/*************** CLASE PADRE (metodos generales) ***************/

// La clase padre ya no hace la seleccion: gestionar_deporte() en CCliente 
// crea el objeto del subtipo correcto antes de llamar a estos metodos.
void CDeporte::solicitar_datos_deporte() {
    cout << "Ingrese la duracion de la sesion en minutos: ";
    while (!(cin >> duracion_sesion) || duracion_sesion <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ingrese un tiempo valido (mayor a 0): ";
    }
}

void CDeporte::realizar_deporte(const string &id_cliente, const string &nombre_cliente) {
    cout << "\nIniciando sesion de " << nombre_deporte << " por " << duracion_sesion << " minutos...";
    ofstream archivo("registro_deportes.txt", ios::app);
    if (archivo.is_open()) {
        archivo << id_cliente << "," << nombre_cliente << "," << id << "," << nombre_deporte << "," << duracion_sesion << "\n";
        archivo.close();
        cout << "\nRutina guardada en registro_deportes.txt exitosamente!\n";
    } else {
        cout << "\nError al guardar el registro de deportes.\n";
    }
}

/*************** CLASES HIJAS (polimorfismo) ***************/

// --- ZUMBA ---
void CZumba::solicitar_datos_deporte() {
    CDeporte::solicitar_datos_deporte(); // pide duración (método del padre)
    cout << "Nivel de intensidad (Bajo/Medio/Alto): ";
    cin >> nivel_intensidad;
}

void CZumba::realizar_deporte(const string &id_cliente, const string &nombre_cliente) {
    cout << "\nIniciando sesion de Zumba por " << duracion_sesion
         << " minutos (Intensidad: " << nivel_intensidad << ")...";
    ofstream archivo("registro_deportes.txt", ios::app);
    if (archivo.is_open()) {
        archivo << id_cliente << "," << nombre_cliente << ","
                << id << "," << nombre_deporte << ","
                << duracion_sesion << "," << nivel_intensidad << "\n";
        archivo.close();
        cout << "\nRutina de Zumba guardada exitosamente!\n";
    } else {
        cout << "\nError al guardar el registro.\n";
    }
}

// --- CARDIO ---
void CCardio::solicitar_datos_deporte() {
    CDeporte::solicitar_datos_deporte();
    cout << "Velocidad promedio (km/h): ";
    while (!(cin >> velocidad) || velocidad <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ingrese una velocidad valida: ";
    }
}

void CCardio::realizar_deporte(const string &id_cliente, const string &nombre_cliente) {
    cout << "\nIniciando sesion de Cardio por " << duracion_sesion
         << " minutos a " << velocidad << " km/h...";
    ofstream archivo("registro_deportes.txt", ios::app);
    if (archivo.is_open()) {
        archivo << id_cliente << "," << nombre_cliente << ","
                << id << "," << nombre_deporte << ","
                << duracion_sesion << "," << velocidad << "\n";
        archivo.close();
        cout << "\nRutina de Cardio guardada exitosamente!\n";
    } else {
        cout << "\nError al guardar el registro.\n";
    }
}

// --- PESAS ---
void CPesas::solicitar_datos_deporte() {
    CDeporte::solicitar_datos_deporte();
    cout << "Peso por serie (kg): ";
    while (!(cin >> peso) || peso <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ingrese un peso valido: ";
    }
    cout << "Numero de sets: ";
    while (!(cin >> sets) || sets <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ingrese un numero de sets valido: ";
    }
    cout << "Repeticiones por set: ";
    while (!(cin >> repeticiones) || repeticiones <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ingrese un numero de repeticiones valido: ";
    }
}

void CPesas::realizar_deporte(const string &id_cliente, const string &nombre_cliente) {
    cout << "\nIniciando sesion de Pesas por " << duracion_sesion << " minutos ("
         << sets << " sets x " << repeticiones << " reps a " << peso << " kg)...";
    ofstream archivo("registro_deportes.txt", ios::app);
    if (archivo.is_open()) {
        archivo << id_cliente << "," << nombre_cliente << ","
                << id << "," << nombre_deporte << ","
                << duracion_sesion << "," << peso << "," << sets << "," << repeticiones << "\n";
        archivo.close();
        cout << "\nRutina de Pesas guardada exitosamente!\n";
    } else {
        cout << "\nError al guardar el registro.\n";
    }
}
