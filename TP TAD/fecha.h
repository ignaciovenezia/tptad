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

ST_FECHA localTime();

ST_FECHA crearFecha(int anio, int mes, int dia, int hora, int minutos);

int getDiasDelMes(int mes);