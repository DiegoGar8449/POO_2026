#include <iostream>
#include <cstring>

using namespace std;

#include "CEmergencia.h"

int main(){
	CEmergencia emer;
	
	emer.enviar_ayuda();
}

CEmergencia::CEmergencia(){
	id_empleado;
	tipo_emergencia;
}

void CEmergencia::enviar_ayuda(){
	
	cout<<"Servicios de emergencia\n";
	cout<<"1 = Hambulancia\n";
	cout<<"2 = Bomberos.\n";
	cout<<"3 = Policia.\n";
	cout<<"Teclee el servicio de emergencia que requiere.\n";
	cin>>tipo_emergencia;
	
	switch (tipo_emergencia){
		case 1:
			cout<<"Servicio de hambulancia.\n";
			cout<<"El servicio ha sido activado, en breve llegara a la locacion.";
			break;
		case 2:
			cout<<"Servicio de Bomberos.\n";
			cout<<"El servicio ha sido activado, en breve llegaran a la locacion.";
			break;
		case 3:
			cout<<"Servicio de Policia.\n";
			cout<<"El servicio ha sido activado, en breve llegaran a la locacion.";
			break;
	}
}
