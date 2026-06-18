#pragma once
#include "CPersona.h"
#include <string>

/*************** Clase hija CEmpleado ***************/
class CEmpleado : public CPersona { 
	//clase amiga para mantener encapsulamiento y permitir la asociación entre CJefe y CEmpleado
	friend class CJefe;
	private://atributos miembro
	std::string id;
	std::string contrasenia;
	std::string turno;
	float salario_base;
	int horas_trabajadas;
	float bono;
	
	public:
	CEmpleado();//constructor
	void menu_principal_empleado();
	void gestionar_cuenta();
	void gestionar_cliente();
	void llamar_emergencias();
};
