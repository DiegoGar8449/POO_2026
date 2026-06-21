#include <string>
#include <CEntrenador>
class CEntrenador{
	protected:
		string id;
		string contrasenia;
		string tipo_deporte;
		float sueldo;
		string jornada_laboral;
		
	public:
		CEntrenador();
		void cobro_client(CCliente cliente);
		void ens_pesas();
		void ens_zumba();
		void ens_cardio();
};
