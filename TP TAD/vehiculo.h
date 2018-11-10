#pragma once
#include <string>
#include "duenio.h"
enum tipoVehiculo {
	AUTO,
	CAMIONETA,
};

typedef struct vehiculo {
	tipoVehiculo tipo;
	std::string patente;
	ST_DUENIO duenio;
}ST_VEHICULO;

ST_VEHICULO inicializarVehiculo();

ST_ERROR crearVehiculo(tipoVehiculo tipo, std::string patente, ST_DUENIO duenio, ST_VEHICULO &vehiculo);

