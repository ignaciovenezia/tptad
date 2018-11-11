#pragma once
#include "error.h"
#include "cochera.h"
#include "vehiculo.h"
#include <string>

#define CANT_COCHERAS 1 // numero de cocheras

static ST_COCHERA cocheras[CANT_COCHERAS];

ST_ERROR ingresarVehiculo(ST_VEHICULO vehiculo, tipoAlquiler tipo, std::string fechaIngreso, ST_COCHERA &cochera);

ST_ERROR egresarVehiculo(std::string patente, std::string fechaEgreso);

ST_ERROR moverVehiculo(ST_COCHERA origen);

void listarDeudores(int mes);

void listarCobranzasMensuales();
