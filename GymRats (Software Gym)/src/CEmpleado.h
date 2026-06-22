#pragma once
#include "CPersona.h"
#include <string>

/*************** Clase hija CEmpleado ***************/
class CEmpleado : public CPersona {
    friend class CJefe;
    private:
        std::string turno;
        float salario_base;
        int horas_trabajadas;
        float bono;

    public:
        CEmpleado();
        bool iniciar_sesion();
        void menu_principal_empleado();
        void gestionar_cuenta();
        void cobrar_cliente();
        void gestionar_cliente();
        void llamar_emergencias();
};
