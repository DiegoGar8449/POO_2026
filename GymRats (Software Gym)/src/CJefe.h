#pragma once
#include "CPersona.h"
#include <string>

/*************** Clase hija CJefe ***************/
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
