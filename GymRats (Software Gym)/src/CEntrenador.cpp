#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "CEntrenador.h"

int main(){
	
}

CEntrenador::CEntrenador(string id, string contra, string deporte, float sueldo, string jornada) {

    id = id;
    contrasenia = contra;
    tipo_deporte = deporte;
    sueldo = sueldo;
    jornada_laboral = jornada;
}

void CEntrenador::cobrar_cliente(CCliente cliente) {

    float monto;
	
	if (cliente.getDeporte() == "Pesas")
        monto = 500;
    else if (cliente.getDeporte() == "Cardio")
        monto = 400;
    else if (cliente.getDeporte() == "Zumba")
        monto = 450;
    else
        monto = 300;

    ofstream archivo("archivo_clientes.txt", ios::app);

    if (archivo.is_open()) {
	
 		archivo << "ID Cliente: " << cliente.getId() << endl;
        archivo << "Nombre: " << cliente.getNombre() << endl;
        archivo << "Deporte: " << cliente.getDeporte() << endl;
        archivo << "Monto a cobrar: $" << monto << endl;
        archivo << "------------------------" << endl;

        archivo.close();

        cout << "Datos guardados en archivo_clientes.txt" << endl;
    }
}

