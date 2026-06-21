#include <string>
class CEmergencia{
	protected:
		int tipo_emergencia;
		string id_empleado;
	public:
		CEmergencia();
		void enviar_ayuda();
};
