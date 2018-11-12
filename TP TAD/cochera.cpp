#include "pch.h"
#include "cochera.h"
#include "vehiculo.h"


ST_COCHERA inicializarCochera(int id) {
	ST_COCHERA cochera;
	cochera._id = id;
	cochera.fechaIngreso = localTime();
	cochera.vehiculo = inicializarVehiculo();
	cochera.tipo_alquiler = VACIA;
	cochera.precio = 0;
	for (int i = 0; i < CANT_PAGO; i++)
	{
		cochera.pago[i] = 0;

	}

	return cochera;
}

void llenarCocheras(ST_COCHERA vec[], int n) {
	for (int i = 0; i < n; i++)
	{
		vec[i] = inicializarCochera(i);
	}
}
