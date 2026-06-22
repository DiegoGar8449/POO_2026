#pragma once
#include <string>

class CEmergencia {
    private:
        int tipo_emergencia;
        std::string id_empleado;

    public:
        CEmergencia();
        void enviar_ayuda(const std::string &id_emp);
};
