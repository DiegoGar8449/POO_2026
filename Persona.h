#include <string> //directiva del procesador necesaria para compilar la cabecera usando string.

//creacion clase Persona
class Persona{
	
	private:
	//datos miembro
	std::string nombre;
	std::string apellido1;
	std::string apellido2;
	float estatura;
	float peso;
	std::string hobby;
	
	public:
	Persona(); //constructor
	//funcion miembro
	void solicitar_datos();
	void mostrar_datos();
	float imc();
	std::string estado_salud();
};
