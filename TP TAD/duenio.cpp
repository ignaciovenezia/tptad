#include "pch.h"
#include "duenio.h"

ST_DUENIO inicializarDuenio() {
	ST_DUENIO duenio;
	duenio.nombre = "";
	duenio.apellido = "";
	duenio.dni = -1;
	duenio.telefono = -1;
	duenio.email = ""; 

	return duenio;
}

ST_DUENIO crearDuenio(std::string nombre, std::string apellido, int dni, int telefono, std::string email) {
	ST_DUENIO duenio;
	duenio.nombre = nombre;
	duenio.apellido = apellido;
	duenio.dni = dni;
	duenio.telefono = telefono;
	duenio.email = email;

	return duenio;
}