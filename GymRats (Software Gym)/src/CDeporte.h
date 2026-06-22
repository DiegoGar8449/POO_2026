#pragma once
#include <string>

class CDeporte {
    protected:
        std::string id;
        std::string nombre_deporte;
        int duracion_sesion;
        std::string accesorios_deportivos[5];

    public:
        CDeporte();
        virtual void solicitar_datos_deporte();
        virtual void realizar_deporte(const std::string &id_cliente, const std::string &nombre_cliente);
        virtual ~CDeporte();
};

class CZumba : public CDeporte {
    private:
        std::string nivel_intensidad;
    public:
        CZumba();
        void solicitar_datos_deporte() override;
        void realizar_deporte(const std::string &id_cliente, const std::string &nombre_cliente) override;
};

class CCardio : public CDeporte {
    private:
        float velocidad;
    public:
        CCardio();
        void solicitar_datos_deporte() override;
        void realizar_deporte(const std::string &id_cliente, const std::string &nombre_cliente) override;
};

class CPesas : public CDeporte {
    private:
        int peso;
        int sets;
        int repeticiones;
    public:
        CPesas();
        void solicitar_datos_deporte() override;
        void realizar_deporte(const std::string &id_cliente, const std::string &nombre_cliente) override;
};
