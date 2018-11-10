#include "pch.h"
#include "vehiculo.h"
#include "funcionesmiscelaneas.h"

ST_VEHICULO inicializarVehiculo() {
	ST_VEHICULO vehiculo;
	vehiculo.tipo = AUTO;
	vehiculo.patente = "";
	vehiculo.duenio = inicializarDuenio();

	return vehiculo;
}

/*ST_VEHICULO crearVehiculo(tipoVehiculo tipo, std::string patente, ST_DUENIO duenio) {
	ST_VEHICULO vehiculo;
	vehiculo.tipo = tipo;
	vehiculo.patente = patente;
	vehiculo.duenio = duenio;

	return vehiculo;
}*/

ST_ERROR crearVehiculo(tipoVehiculo tipo, std::string patente, ST_DUENIO duenio, ST_VEHICULO &vehiculo) {
	ST_ERROR error;
	vehiculo.tipo = tipo;
	vehiculo.patente = patente;
	vehiculo.duenio = duenio;
	if (!esTipoCorrecto(tipo)) {
		error = createError(ERR_TIPO_INCORRECTO, "Tipo incorrecto");
		return error;
	}
	if (!esPatenteCorrecta(patente)) {
		error = createError(ERR_PATENTE_INCORRECTA, "Patente incorrecta");
		return error;
	}
	error = createError(ERR_OK, "Vehiculo creado OK");
	return error;
}
