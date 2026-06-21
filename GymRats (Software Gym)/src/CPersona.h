#pragma once //para que la clase se compile una sola vez.
#include <string>

/*********** Clase abstracta o Superclase ****************/
class CPersona{
	protected:
	std::string id;
	std::string contrasenia;
	std::string nombre;//datos miembro
	std::string apellido_paterno;
	std::string apellido_materno;
	int edad;
	std::string telefono_celular;
	std::string calle;
	std::string calle_num;
	std::string colonia;
	
	public:
	CPersona();//constructor
	bool solicitar_datos();//funciones miembro
	~CPersona();//destructor
};
