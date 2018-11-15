#pragma once
#include <string>
#include "duenio.h"

enum tipoVehiculo {
	AUTO,
	CAMIONETA,
	OTRO,
};

typedef struct vehiculo {
	tipoVehiculo tipo;
	std::string patente;
	ST_DUENIO duenio;
}ST_VEHICULO;

/** @brief inicializa las variables ST_VEHICULO tipo, ST_VEHICULO patente y ST_DUENIO duenio.
* @return ST_VEHICULO: vehiculo
*/
ST_VEHICULO inicializarVehiculo();

/** @brief crea un ST_VEHICULO
* @return ST_ERROR error: un error indicando el resultado de la creacion del vehiculo.
* @param(in) tipoVehiculo tipo: el tipo de vehiculo. Solo puede recibir "AUTO" o "CAMIONETA".
* @param(in) str string patente: la patente del vehiculo. Solo recibe letras y numeros en formato "AA999AA".
* @param(in) ST_DUENIO duenio: el duenio creado con sus respectivas variables.
* @param(in) ST_VEHICULO vehiculo: el vehiculo creado con los anteriores parametros.
*/
ST_ERROR crearVehiculo(tipoVehiculo tipo, std::string patente, ST_DUENIO duenio, ST_VEHICULO &vehiculo);

