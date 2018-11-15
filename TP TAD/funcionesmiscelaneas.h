#pragma once
#include <string>
#include "vehiculo.h"
#define TIME_STRING_LENGTH 18

/** @brief chequea si el nombre (o apellido) ingresao para el duenio es correcto. 
* @return bool: true si es nombre (o apellido) correcto, false si no lo es.
* @param(in) string str: el nombre (o apellido) a chequear.
*/
bool esNombreCorrecto(std::string str);

/** @brief chequea si el dni (y telefono) ingresado para el duenio es correcto.
* @return bool: true si es dni (y telefono) correcto, false si no lo es.
* @param(in) string str: el dni (y telefono) a chequear.
*/
bool esNumeroCorrecto(std::string str);

/** @brief chequea si el Email ingresado para el duenio es correcto.
* @return bool: true si es email correcto, false si no lo es.
* @param(in) string str: el email a chequear.
*/
bool esEmailCorrecto(std::string str);

/** @brief chequea si la patente ingresado para el vehiculo es correcta.
* @return bool: true si es patente correcto, false si no lo es.
* @param(in) string str: la patente a chequear (formato = AA999AA).
*/
bool esPatenteCorrecta(std::string str);

/** @brief chequea si el tipo de vehiculo es correcto.
* @return bool: si es correcto.
* @param(in) string str: el tipo a chequear ("AUTO" o "CAMIONETA").
*/
bool esTipoCorrecto(tipoVehiculo tipo);