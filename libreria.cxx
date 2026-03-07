/*Examen diagnostico.
 * Martes 10 de febrero de 2026
 * Secuencia: Programacion Orientada a Objetos
 * Pregunta 8: Sistema de librería utilizando la variable Struct
Garcia Rodriguez Diego - 3NV31.
*/

#include <iostream>
#include <string>

struct Libro{ //Es la primera vez que trabajo bien con una variable tipo struct. Espero trabajarla bien.
	
	long int isbr {}; //Entendi que struct se usa cuando insertaremos variables que se relacionan con otras variables.
	std::string autor {}; //Como trabajamos con libros, la variable tipo struct "Libro" 'tiene en comun otras 6 variables'.
	std::string titulo {}; //El proposito de struct es evitarnos tener que hacer más variables (mismas variables) para cada libro. 
	std::string editorial {};
	int anio {};
	float precio {};
};

int main(){ //Puse cuatro libros que me han gustado mucho, aunque aun no termino El mito de Sisifo
	
	Libro sisifo {};
	sisifo.isbr = 9788439738121;
	sisifo.autor = "Albert Camus.";
	sisifo.titulo = "El mito de Sisifo.";
	sisifo.editorial = "Literatura Random House.";
	sisifo.anio = 1984;
	sisifo.precio = 200;
	
	Libro cartas {};
	cartas.isbr = 9712345738121;
	cartas.autor = "Franz Kafka.";
	cartas.titulo = "Cartas al padre.";
	cartas.editorial = "N/A.";
	cartas.anio = 1956;
	cartas.precio = 150;
	
	Libro batallas {};
	batallas.isbr = 9732145765121;
	batallas.autor = "Jose Emilio Pacheco.";
	batallas.titulo = "Las batallas en el desierto.";
	batallas.editorial = "N/A.";
	batallas.anio = 1982;
	batallas.precio = 200;
	
	Libro cafe {};
	cafe.isbr = 9713122004121;
	cafe.autor = "Toshikazu Kawaguchi.";
	cafe.titulo = "Antes de que se enfrie el cafe.";
	cafe.editorial = "Plaza & Janes.";
	cafe.anio = 2021;
	cafe.precio = 399;
	
	std::string x;
	
	std::cout << "Bienvenido a 'Libreria Mia'. ¿Desea comprar un libro? \n"; 
	std::cout << "Escriba 'Si' o 'No'\n";
	
	std::cin >> x;
	if (x == "Si")
	//std::cout << "Estos son los libros disponibles: \n"; No logro hacer que aparezca ese texto.
	std::cout << sisifo.titulo <<'\n'; 
	std::cout << cartas.titulo  <<'\n';
	std::cout << batallas.titulo <<'\n';
	std::cout <<cafe.titulo <<'\n';
	if (x == "No")
	std::cout <<"Saldra del sistema." ;
	//if (x != "Si" && x != "No")
	//std::cout << "La opcion ingresada no es valida. "; Tampoco logre que estas opciones funcionaran.
	
	std::string y;
	std::cout <<"¿Que libro desea comprar? \n";
	if (y == "El mito de Sisifo")
	std::cout << "Los datos de su compra son: \n";
	std::cout << sisifo.isbr << '\n';
	std::cout << sisifo.autor << '\n';
	std::cout << sisifo.titulo << '\n';
	std::cout << sisifo.editorial << '\n';
	std::cout << sisifo.anio << '\n';
	std::cout << sisifo.precio << '\n';
	std::cout << "¡Gracias por su compra!";
	
	
	return 0;
}
