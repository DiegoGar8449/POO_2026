/*CFigura.h
 * Cabecera con todas las clases para el cpp PFigura
 * Garcia Rodriguez Diego / 3NV31*/
#pragma once
#include <string>
 
//*************Clase Padre ***********/
 class CFigura{
	 protected:
	 std::string color;
	 public:
	 CFigura(); //constructor
	 virtual void solicitar_datos(); //funcion miembro o prototipo
	 virtual double calcular_perimetro(); //virtual para polimorfismo
	 virtual double calcular_area();
	 virtual ~CFigura(); //destructor
};
 
//************* Clases hija *************
class CCirculo : public CFigura{
	private:
	float radio; //datos miembro o atributos
	public:
	CCirculo(); //constructor
	virtual void solicitar_datos();
	virtual double calcular_perimetro(); //se repiten los metodos en las clases hijas por polimorfismo
	virtual double calcular_area();	
};

class CCuadrado : public CFigura{
	private:
	float lado; //datos miembro o atributos
	public:
	CCuadrado(); //constructor
	virtual void solicitar_datos();
	virtual double calcular_perimetro();
	virtual double calcular_area();	
};

class CRectangulo : public CFigura{
	private:
	float base; //datos miembro o atributos
	float altura;
	public:
	CRectangulo(); //constructor
	virtual void solicitar_datos();
	virtual double calcular_perimetro();
	virtual double calcular_area();	
};

class CTriangulo_equi : public CFigura{
	private:
	float base; //datos miembro o atributos
	float lado;
	float altura;
	public:
	CTriangulo_equi(); //constructor
	virtual void solicitar_datos();
	virtual double calcular_perimetro();
	virtual double calcular_area();	
};
