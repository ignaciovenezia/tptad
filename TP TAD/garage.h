#pragma once
#include "error.h"
#include "cochera.h"
#include "vehiculo.h"
#include <string>

#define CANT_COCHERAS 5 // numero de cocheras

static ST_COCHERA _cocheras[CANT_COCHERAS]; 

ST_ERROR ingresarVehiculo(ST_VEHICULO vehiculo, tipoAlquiler tipo, ST_FECHA fechaIngreso, ST_COCHERA &cochera);

ST_ERROR egresarVehiculo(std::string patente, float &valorAPagar);

ST_ERROR moverVehiculo(int idOrigen, ST_COCHERA &cocheraDestino);

void listarDeudores(int mes);

void listarCobranzasMensuales();

void llenarCocheras(int n);
