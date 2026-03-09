//se crea la clase Cuenta con metodos
class Cuenta {
	private:
	//datos miembro
	float saldo;
	float retiro;
	float deposito;
	int operacion;
	int cuenta;
	
	public:
	Cuenta(); //constructor
	//funciones miembro
	void solicitar_datos(); 
	float consultar();
	float depositar();
	float retirar(); 
};

