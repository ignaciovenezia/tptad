#include "pch.h"
#include "garage.h"
#include "funcionesmiscelaneas.h"

float calcularPrecio(ST_VEHICULO vehiculo, tipoAlquiler tipo) {
	float precio = 0.0f;
	if (tipo == MES)
	{
		if (vehiculo.tipo == AUTO)
			precio = 2500.0f;
		else
			precio = 4000.0f;
	}
	else if (tipo == DIA) {
		if (vehiculo.tipo == AUTO)
			precio = 300.0f;
		else
			precio = 400.0f;
	}
	else
	{
		if (vehiculo.tipo == AUTO)
			precio = 50.0f;
		else
			precio = 75.0f;
	}

	//vehiculo.tipo == AUTO ? precio = 2500 : precio = 4000;
	return precio;
}

ST_ERROR ingresarVehiculo(ST_VEHICULO vehiculo, tipoAlquiler tipo, std::string fechaIngreso, ST_COCHERA &cochera) {
	ST_ERROR error;
	for (int i = 0; i < CANT_COCHERAS; i++)
	{
		if (cocheras[i].tipo_alquiler == VACIA) {
			cochera._id = cocheras[i]._id;
			cochera.vehiculo = vehiculo;
			cochera.tipo_alquiler = tipo;
			cochera.fechaIngreso = fechaIngreso; //localTime;
			cochera.precio = calcularPrecio(vehiculo, tipo);
			for (int i = mesActual(); i < CANT_PAGO; i++)
			{
				cochera.pago[i] = cochera.precio;
			}
			cocheras[i] = cochera;
			error = createError(ERR_OK, "Vehiculo ingresado correctamente a la cochera " + cochera._id);
			return error;
		}
	}
	// Si no hay cochera disponible, crear y returnear el error.
	error = createError(ERR_NO_HAY_COCHERA_DISPONIBLE, "No hay cochera disponible.");
	return error;
}

ST_ERROR buscarCocheraPorPatente(std::string patente, ST_COCHERA &cochera) {
	ST_ERROR error;
	for (int i = 0; i < CANT_COCHERAS; i++)
	{
		if (cocheras[i].vehiculo.patente._Equal(patente)) {
			cochera = cocheras[i];
			error = createError(ERR_OK, "Cochera encontrada con exito");
			return error;
		}
	}
	error = createError(ERR_NO_HAY_VEHICULO_CON_TAL_PATENTE, "No se ha encontrado un vehiculo con esa patente.");
	return error;
}

ST_ERROR egresarVehiculo(std::string patente, std::string fechaEgreso) {
	ST_COCHERA cochera;
	ST_ERROR error = buscarCocheraPorPatente(patente, cochera);
	if (error.tipoDeError != ERR_OK) {
		return error;
	}
	
}

ST_ERROR moverVehiculo(ST_COCHERA origen);

void listarDeudores(int mes);

void listarCobranzasMensuales();
