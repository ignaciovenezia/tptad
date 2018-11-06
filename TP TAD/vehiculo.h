#pragma once
#include <string>
#include "duenio.h"
enum tipoVehiculo {
	AUTO,
	CAMIONETA,
};

typedef struct vehiculo {
	int tipo; //tipo_vehiculo
	std::string patente;
	ST_DUENIO duenio;
}ST_VEHICULO;

ST_VEHICULO crearVehiculo();