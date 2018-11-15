#pragma once
#include <string>
#include "vehiculo.h"
#include "fecha.h"

#define CANT_PAGO 12

/** @brief tipo de alquiler de una cochera.
*/
enum tipoAlquiler {
	VACIA,
	HORA,
	DIA,
	MES
};

typedef struct cochera {
	int _id;
	ST_VEHICULO vehiculo;
	ST_FECHA fechaIngreso;
	float precio;
	tipoAlquiler tipo_alquiler;
	float pago[CANT_PAGO];
}ST_COCHERA;


/** @brief inicializa una cochera default
* @return ST_COSCHERA: cochera default.
*/
ST_COCHERA inicializarCochera(int);