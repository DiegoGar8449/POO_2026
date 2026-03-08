/*GENERACION E IMC
Garcia Rodriguez Diego - 3NV31 POO
10 - 02 - 2026 */

#include <iostream>
#include <string>
using namespace std;

struct Usuario { //Al inicio se me complico definir las variables del struct. Considero que nombre, año, peso y estatura estan bien.
string nombre {};
int anio {};
double peso {}; //Double porque, al hacer su potencia a 2, float no soporta la cantidad.
float estatura {};
};

int main(){
	Usuario Diego {}; //Mi idea con el struct es que se insertan distintos usuarios que comparten las mismas variables.
	Diego.nombre = "Diego";
	Diego.anio = 2003;
	Diego.peso = 84.0;
	Diego.estatura = 1.82;
	
	double imc;
	imc = Diego.peso/(Diego.estatura*Diego.estatura); //Intente usar pow y **2 para estatura pero creo que eso no se puede en c++
	if (imc <18.5)
	cout <<"El peso de Diego es bajo y su imc es: " << imc <<'\n';
	if (imc >= 18.5 && imc <= 24.9)
	cout <<"El peso de Diego es normal y su imc es: " << imc << '\n';
	if (imc >=25 && imc <=29.9)
	cout <<"El peso de Diego es alto y su imc es: " << imc << '\n';
	
	if (Diego.anio >= 1995 && Diego.anio <= 2014)
	cout <<"La generacion de "<< Diego.nombre << " es Z o Centennial. \n";
	if (Diego.anio >= 1946 && Diego.anio <= 1964)
	cout << "La generacion de Diego es Baby Boomer.";
	if (Diego.anio >= 1965 && Diego.anio <= 1984)
	cout << "La generacion de Diego es X.";
	if (Diego.anio>= 1985 && Diego.anio <= 1994)
	cout <<"La generacion de Diego es Millenial o Y.";
	
	return 0;
}
