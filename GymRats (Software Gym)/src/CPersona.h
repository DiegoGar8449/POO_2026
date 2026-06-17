#pragma once //para que la clase se compile una sola vez.
#include <string>

//***********Clase abstracta o Superclase****************
class CPersona{
	protected:
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
	void solicitar_datos();//funciones miembro
	void mostrar_datos();
	~CPersona();//destructor
};

class CJefe : public CPersona{
	private:
	std::string id;
	std::string contrasenia;
	public:
	CJefe();
	void gestionar_cuenta(); //Crear cuenta, Modificar datos personales o Eliminar cuenta.
	void gestionar_empleado(); //Contratar empleado, Modificar o Despedir.
	void pagar_empleado(); //pago quincenal a empleado e imprime ticket.
};
