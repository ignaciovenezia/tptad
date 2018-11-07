#include "pch.h"
#include "vehiculo.h"

ST_VEHICULO inicializarVehiculo() {
	ST_VEHICULO vehiculo;
	vehiculo.tipo = AUTO;
	vehiculo.patente = "";
	vehiculo.duenio = inicializarDuenio();

	return vehiculo;
}

ST_VEHICULO crearVehiculo(tipoVehiculo tipo, std::string patente, ST_DUENIO duenio) {
	ST_VEHICULO vehiculo;
	vehiculo.tipo = tipo;
	vehiculo.patente = patente;
	vehiculo.duenio = duenio;

	return vehiculo;
}