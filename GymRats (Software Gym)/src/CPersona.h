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

//***********clases hijas****************
class CJefe : public CPersona{
	private:
	std::string id;//datos miembro
	std::string contrasenia;
	float ingresosGimnasio;
	
	public:
	CJefe();//constructor
	void registrar_cuenta();
	void IngresoMensualGimnasio();//funciones miembro
	void contratar_empleado();
	void despedir_empleado();
	void contratar_entrenador();
	void despedir_entrenador();
	void modificar_contrasenia();
	void implementar_deporte();
	float comprar_equipoGimnasio;
	float pagar_trabajador;
};

class CCliente : public CPersona{
	private:
	std::string id;//datos miembro
	std::string constrasenia;
	float mensualidad;
	
	public:
	CCliente();//constructor
	void elegir_area();//funciones miembro
	float pagar_mensualidad();
	void entrenar();
	void modificar_contrasenia();
	void elegir_entrenador();
};

class CEmpleado : public CPersona{
	private:
	std::string id;
	std::string constrasenia;
	std::string turno;
	float sueldo;
	
	public:
	CEmpleado();// constructor
	void registrar_cuenta();//funciones miembro
	void registrar_cliente();
	void eliminar_cliente();
	void modificar_contrasenia();
	void llamar_emergencias();
};

class CEntrenador : public CPersona{
	private:
	std::string id;
	std::string constrasenia;
	std::string tipo_deporte;
	std::string turno;
	std::string cartera_clientes[3];
	float sueldo;
	
	public:
	CEntrenador();//constructor
	void enseniar();
	void mostrar_CarteraDeClientes();
};
