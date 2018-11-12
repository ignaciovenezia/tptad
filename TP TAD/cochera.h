#pragma once
#include <string>
#include "vehiculo.h"
#include "fecha.h"

#define CANT_PAGO 12

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
	int tipo_alquiler;
	float pago[CANT_PAGO];
}ST_COCHERA;

void llenarCocheras(ST_COCHERA vec[], int n);

ST_COCHERA inicializarCochera(int);