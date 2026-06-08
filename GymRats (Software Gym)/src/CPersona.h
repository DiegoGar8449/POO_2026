#pragma once //para que la clase se compile una sola vez.
#include <string>

//***********Clase abstracta o Superclase****************
class CPersona{
	protected:
	std::string nombre;
	std::string apellido_paterno;
	std::string apellido_materno;
	int edad;
	std::string telefono_celular;
	std:string calle;
	std::string calle_num;
	std_string colonia;
	
	public:
	CPersona();//constructor
	virtual void solicitar_datos();
	virtual void mostrar_datos();
	virtual ~CPersona();//destructor
};

//***********clases hijas****************
class CCliente : public CPersona{
	private:
	std::string id;
	std::string constrasenia;
	float mensualidad;
	
	public:
	CCliente();//constructor
	virtual void elegir_area();
	virtual float pagar_mensualidad();
	virtual void entrenar();
	virtual void modificar_datos();
	virtual void elegir_entrenador();
};

class CEntrenador{
	private:
	std::string id;
	std::string constrasenia;
	std::string tipo_deporte;
	std::string turno;
	float sueldo;
	
	public:
	CEntrenador()//constructor
	virtual void enseniar();
};
