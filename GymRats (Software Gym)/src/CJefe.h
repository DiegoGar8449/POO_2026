#pragma once
#include "CPersona.h"
#include <string>

/*************** Clase hija CJefe ***************/
class CJefe : public CPersona{
	private:
	
	public:
	CJefe();
	void menu_principal_jefe(); //menú para elegir el método a utilizar.
	void gestionar_cuenta(); //Crear cuenta, Modificar datos personales o Eliminar cuenta.
	void gestionar_empleado(); //Modificar turno empleado o Despedir empleado.
	void pagar_empleado(); //pagar a empleado e imprimir ticket.
};
