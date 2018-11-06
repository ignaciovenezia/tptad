#pragma once
#include <string>
#include "vehiculo.h"

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
	std::string fechaIngreso;
	float precio;
	int tipo_alquiler;
	int pago[CANT_PAGO];
}ST_COCHERA;

void llenarCocheras(ST_COCHERA vec[], int n);

ST_COCHERA crearCochera(int);