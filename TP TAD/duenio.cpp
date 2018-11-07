#include "pch.h"
#include "duenio.h"

ST_DUENIO inicializarDuenio() {
	ST_DUENIO duenio;
	duenio.nombre = "";
	duenio.apellido = "";
	duenio.dni = "";
	duenio.telefono = "";
	duenio.email = ""; 

	return duenio;
}

ST_DUENIO crearDuenio(std::string nombre, std::string apellido, std::string dni, std::string telefono, std::string email) {
	ST_DUENIO duenio;
	duenio.nombre = nombre;
	duenio.apellido = apellido;
	duenio.dni = dni;
	duenio.telefono = telefono;
	duenio.email = email;

	return duenio;
}