#include "pch.h"
#include "consola.h"
#include "funcionesmiscelaneas.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>



using namespace std;

ST_DUENIO ingresarDatosDelDuenio() {

	string nombre = "";
	string apellido = "";
	string dni = "";
	string telefono = "";
	string email = "";

	cout << "Ingresar nombre: ";
	getline(cin, nombre);
	while (!esNombreCorrecto(nombre)) {
		cout << "Nombre incorrecto. Solo se pueden usar letras y espacios." << endl;
		cout << "Ingresar nombre: ";
		getline(cin, nombre);
	}
	cout << "Ingresar apellido: ";
	getline(cin, apellido);
	while (!esNombreCorrecto(apellido)) {
		cout << "Apellido incorrecto. Solo se pueden usar letras y espacios." << endl;
		cout << "Ingresar Apellido: ";
		getline(cin, apellido);
	}
	cout << "Ingresar DNI: ";
	getline(cin, dni);
	while (!esNumeroCorrecto(dni)) {
		cout << "DNI incorrecto. Solo se pueden usar numeros." << endl;
		cout << "Ingresar DNI: ";
		getline(cin, dni);
	}
	cout << "Ingresar telefono: ";
	getline(cin, telefono);
	while (!esNumeroCorrecto(telefono)) {
		cout << "Telefono incorrecto. Solo se pueden usar numeros." << endl;
		cout << "Ingresar Telefono: ";
		getline(cin, telefono);
	}
	cout << "Ingresar email: ";
	getline(cin, email);
	while (!esEmailCorrecto(email)) {
		cout << "Email incorrecto. Solo se pueden usar letras, numeros, arroba, guion, guion bajo y punto." << endl;
		cout << "Ingresar Email: ";
		getline(cin, email);
	}
	cout << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Apellido: " << apellido << endl;
	cout << "DNI: " << dni << endl;
	cout << "Telefono: " << telefono << endl;
	cout << "Email: " << email << endl << endl;
	cout << "Datos correctos? (y/n)" << endl;

	char p;
	bool isYN = false;
	while (!isYN) {
		cin >> p;
		p = tolower(p);
		cin.ignore();
		switch (p) {
		case 'y':
			isYN = true;
			return crearDuenio(nombre, apellido, dni, telefono, email);
			break;
		case 'n':
			isYN = true;
			system("cls");
			return ingresarDatosDelDuenio();
			break;
		default:
			cout << "Datos correctos? (y/n)";
		}
	}
}

ST_VEHICULO ingresarDatosDelVehiculo(ST_DUENIO duenio) {
	
	string patente = "";
	string tipo = "";
	tipoVehiculo tipoV = AUTO;
	tipoVehiculo vehiculo = AUTO;
	cout << "Ingresar patente (AA999AA): ";
	getline(cin, patente);
	while (!esPatenteCorrecta(patente)) {
		cout << "Patente incorrecta. Utilizar formato AA999AA" << endl;
		cout << "Ingresar patente: ";
		getline(cin, patente);
	}
	cout << "Ingresar tipo de vehiculo (auto/camioneta): ";
	getline(cin, tipo);
	while (!esTipoCorrecto(tipo)) {
		cout << "Tipo incorrecto. Solo puede ser ´auto´ o ´camioneta´" << endl;
		cout << "Ingresar tipo de vehiculo (auto/camioneta): ";
		getline(cin, tipo);
	}
	if (tipo._Equal("camioneta"))
	{
		tipoV = CAMIONETA;
	}

	return crearVehiculo(tipoV, patente, duenio);
}


void ingresarUnVehiculoAlGarage() {

	cout << "Para ingresar un nuevo vehiculo precisamos los datos del amigo duenio, ingresar los siguientes datos: " << endl;
	ST_DUENIO duenio = ingresarDatosDelDuenio();
	cout << "Luego precisamos los datos del vehiculo, ingresar los siguientes datos: " << endl;
	ST_VEHICULO vehiculo = ingresarDatosDelVehiculo(duenio);
	std::cout << vehiculo.tipo << endl;
	


}
	

void prenderConsola() {
	system("cls");
	int n;
	cout << "###########################" << endl,
	cout << "1. Ingresar un vehiculo" << endl;
	cout << "Ingrese la oppcion que quieras migo: ";
	cin >> n;
	cin.ignore();
	switch (n){
	case 1:
		ingresarUnVehiculoAlGarage();
		break;
	}
}