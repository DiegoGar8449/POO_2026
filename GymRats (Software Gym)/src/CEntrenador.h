#pragma once
#include "CPersona.h"
#include <string>

class CEntrenador : public CPersona {
    private:
        std::string tipo_deporte;
        float sueldo;
        std::string jornada_laboral;

    public:
        CEntrenador();
        bool iniciar_sesion();
        void menu_principal_entrenador();
        void gestionar_cuenta();
        void ver_solicitudes();
        void enseniar_deporte();
        void cobrar_cliente();
};
