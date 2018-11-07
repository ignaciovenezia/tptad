#pragma once
#include <string>

typedef struct duenio {
	std::string nombre;
	std::string apellido;
	std::string dni;
	std::string telefono;
	std::string email;
}ST_DUENIO;

ST_DUENIO inicializarDuenio();

ST_DUENIO crearDuenio(std::string nombre, std::string apellido, std::string dni, std::string telefono, std::string email);
