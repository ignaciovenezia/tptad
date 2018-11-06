#include "pch.h"
#include "consola.h"
#include "funcionesmiscelaneas.h"
#include <iostream>

using namespace std;


void ingresarDatosVehiculo() {
	std::cout << std::endl << std::endl;
	ST_VEHICULO vehiculo;
	std::string nombre = "";
	std::string apellido = "";
	std::string dni = "";
	std::string telefono = "";
	std::string email = "";

	std::cout << "Para ingresar un nuevo vehiculo precisamos los datos del amigo dueño, ingresar los siguientes datos: " << std::endl;

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Ingresar nombre: ";
	std::getline(cin, nombre);
	std::cout << std::endl;
	while (!esNombreCorrecto(nombre)) {
		std::cout << "Nombre incorrecto. Solo se pueden usar letras y espacios." << std::endl;
		std::cout << "Ingresar nombre: ";
		std::getline(std::cin, nombre);
		std::cout << std::endl;
	}

	std::cout << "Ingresar apellido: ";
	std::getline(cin, apellido);
	std::cout << std::endl;
	while (!esNombreCorrecto(apellido)) {
		std::cout << "Apellido incorrecto. Solo se pueden usar letras y espacios." << std::endl;
		std::cout << "Ingresar Apellido: ";
		std::getline(cin, apellido);
		std::cout << std::endl;
	}
	std::cout << "Ingresar dni: ";
	cin >> dni;
	std::cout << std::endl;
	while (!esNumeroCorrecto(dni)){
		std::cout << "DNI incorrecto. Solo se pueden usar numeros." << std::endl;
		std::cout << "Ingresar DNI: ";
		std::getline(cin, dni);
		std::cout << std::endl;
	}

	std::cout << "Ingresar telefono: ";
	cin >> telefono;
	std::cout << std::endl;
	while (!esNumeroCorrecto(telefono)) {
		std::cout << "Telefono incorrecto. Solo se pueden usar numeros." << std::endl;
		std::cout << "Ingresar DNI: ";
		cin >> telefono;
		std::cout << std::endl;
	}

	std::cout << "Ingresar email: ";
	cin >> email;
	while (!esEmailCorrecto(email)) {
		std::cout << "Email incorrecto. Solo se pueden usar letras, numeros, arroba, guion, gion bajo y punto." << std::endl;
		std::cout << "Ingresar Email: ";
		std::getline(cin, email);
		std::cout << std::endl;
	}
}

void prenderConsola() {
	fflush(stdin);
	int n;
	std::cout << "###########################" << std::endl,
	std::cout << "1. Ingresar un vehiculo" << std::endl;
	std::cout << "Ingrese la oppcion que quieras migo: ";
	cin >> n;

	switch(n) {
	case 1: 
		ingresarDatosVehiculo();
		break;
	}
}