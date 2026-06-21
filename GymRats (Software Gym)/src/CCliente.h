#pragma once
#include "CPersona.h"
#include "CDeporte.h"
#include <string>

class CCliente : public CPersona {
private:
    std::string tipo_membresia;
    std::string deporte_inscrito;
    std::string estado_membresia;

public:
    CCliente(); // Constructor
    bool iniciar_sesion();
    void menu_principal_cliente();
    void gestionar_cuenta();
    void gestionar_deporte();
    void contratar_entrenador();
};
