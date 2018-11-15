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
* @param(in) int anio
* @param(in) int mes 
* @param(in) int dia 
* @param(in) int hora 
* @param(in) int minutos
* @param(out) ST_FECHA fecha.completa con la funcion oss.str().
*/
ST_FECHA crearFecha(int anio, int mes, int dia, int hora, int minutos);


/** @brief desgloza el valor de la fecha obteniendo los dias del mes.
* @return int: los dias del mes indicado.
* @param(in) mes: el mes a saber los dias
*/
int getDiasDelMes(int mes);