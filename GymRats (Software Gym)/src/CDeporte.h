#pragma once
#include <string>

class CDeporte{
	protected:
    std::string id;
	std::string nombre_deporte;
	int duracion_sesion;
	std::string accesorios_deportivos[5];
	
	
	public:
	CDeporte(); //constructor
	void realizar_deporte(const std::string &id_cliente, const std::string &nombre_cliente);
	void solicitar_datos_deporte();
    ~CDeporte(); //destructor
};

class CZumba : public CDeporte{
    private:
    std::string nivel_intensidad;
    
    public:
	CZumba();//constructor
};

class CCardio : public CDeporte{
	private:
	float velocidad;
	
	public:
	CCardio();//constructor
	
};

class CPesas : public CDeporte{
	private:
	int peso;
	int sets;
	int repeticiones;
	
	public:
	CPesas();//constructor
};
