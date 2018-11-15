#pragma once
#include "error.h"
#include "cochera.h"
#include "vehiculo.h"
#include <string>

#define CANT_COCHERAS 4 // numero de cocheras

static ST_COCHERA _cocheras[CANT_COCHERAS]; 
/*
* @brief Ingresa un vehiculo a una cochera.
* @return ST_ERROR: un error indicando el resultado del ingreso.
* @param(in) ST_VEHICULO vehiculo: el vehiculo a ingresar.
* @param(in) tipoAlquiler tipo: tipo de alquiler del vehiculo en cuestion.
* @param(in) ST_FECHA fechaIngreso: la fecha de ingreso del vehiculo.
* @param(out) ST_COCHERA &cochera: la cochera en cuestion a la que se le ingresa un vehiculo.
*/
ST_ERROR ingresarVehiculo(ST_VEHICULO vehiculo, tipoAlquiler tipo, ST_FECHA fechaIngreso, ST_COCHERA &cochera);

/** @brief Egresa un vehiculo de una cochera.
* @return ST_ERROR: un error indicando el resultado del egreso
* @param(in) string patente: la patente del vehiculo a egresar. 
* @param(out) float valorAPagar: valor a pagar al egresar el vehiculo.
*/
ST_ERROR egresarVehiculo(std::string patente, float &valorAPagar);

/** @brief Mueve un vehiculo de una cochera a otra.
* @return ST_ERROR: un error indicando el resultado de la movida.
* @param(in) int idOrigen: el id de la cochera origen.
* @param(out) ST_COCHERA &cocheraDestino la cochera destino.
*/
ST_ERROR moverVehiculo(int idOrigen, ST_COCHERA &cocheraDestino);


/** @brief Printea un listado de todos los deudores de las cocheras mensuales hasta un mes especifico.
* @param(in) int mes: el mes limite.
*/
void listarDeudores(int mes);

/** @brief Printea un listado formateado de las cobranzas a realizar en el mes actual.
*/
void listarCobranzasMensuales();

/** @brief Llena las cocheras con el default.
*/
void llenarCocheras(int n);
