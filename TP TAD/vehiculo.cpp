#include "pch.h"
#include "vehiculo.h"

ST_VEHICULO crearVehiculo() {
	ST_VEHICULO vehiculo;
	vehiculo.tipo = -1;
	vehiculo.patente = "";
	vehiculo.duenio = inicializarDuenio();

	return vehiculo;
}