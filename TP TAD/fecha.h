#pragma once
#include <string>


typedef struct fecha {
	int anio;
	int mes;
	int dia;
	int hora;
	int minutos;
	std::string fechaCompleta;
}ST_FECHA;

/** @brief Obtener el tiempo de sistema local en ST_ERROR.
* @return ST_FECHA fecha local actual.
*/
ST_FECHA localTime();


/** @brief
* @return ST_ERROR: un error indicando el resultado del
* @param(in)
* @param(in)
* @param(in)
* @param(out)
*/
ST_FECHA crearFecha(int anio, int mes, int dia, int hora, int minutos);

int getDiasDelMes(int mes);