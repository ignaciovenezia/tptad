#pragma once
#include <string>

typedef struct duenio {
	std::string nombre;
	std::string apellido;
	int dni;
	int telefono;
	std::string email;
}ST_DUENIO;

ST_DUENIO inicializarDuenio();

ST_DUENIO crearDuenio(std::string nombre, std::string apellido, int dni, int telefono, std::string email);
