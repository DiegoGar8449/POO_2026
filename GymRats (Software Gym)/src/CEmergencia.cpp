#include <iostream>
#include <fstream>
#include <ctime>
#include "CEmergencia.h"
using namespace std;

CEmergencia::CEmergencia() {
    tipo_emergencia = 0;
    id_empleado = "";
}

void CEmergencia::enviar_ayuda(const string &id_emp) {
    id_empleado = id_emp;

    cout << "\n*************** LLAMADA DE EMERGENCIA ***************";
    cout << "\n1) Ambulancia";
    cout << "\n2) Bomberos";
    cout << "\n3) Policia";
    cout << "\nSeleccione el servicio que requiere: ";

    while (!(cin >> tipo_emergencia) || tipo_emergencia < 1 || tipo_emergencia > 3) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Opcion invalida. Ingrese 1, 2 o 3: ";
    }

    string servicio;
    switch (tipo_emergencia) {
        case 1: servicio = "Ambulancia"; break;
        case 2: servicio = "Bomberos";   break;
        case 3: servicio = "Policia";    break;
    }

    cout << "\n¡Servicio de " << servicio << " activado! En breve llegara a la ubicacion.\n";

    //obtener fecha y hora del sistema
    time_t t = time(nullptr);
    char fecha[30];
    strftime(fecha, sizeof(fecha), "%d/%m/%Y %H:%M", localtime(&t));

    //guardar reporte de la emergencia
    ofstream reporte("reporte_emergencias.txt", ios::app);
    if (reporte.is_open()) {
        reporte << "****************************************\n";
        reporte << "GYMRATS - REPORTE DE EMERGENCIA\n";
        reporte << "****************************************\n";
        reporte << "Fecha y hora: " << fecha << "\n";
        reporte << "Id empleado que reporto: " << id_empleado << "\n";
        reporte << "Servicio solicitado: " << servicio << "\n";
        reporte << "----------------------------------------\n";
        reporte.close();
        cout << "Reporte guardado en reporte_emergencias.txt\n";
    } else {
        cout << "No se pudo generar el reporte de emergencia.\n";
    }
}
