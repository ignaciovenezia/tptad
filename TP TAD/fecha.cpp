#include "pch.h"
#include "fecha.h"
#include <time.h>
#include <sstream>
#include <string.h>
#include "funcionesmiscelaneas.h"
#include <iostream>
#include <stdio.h>


ST_FECHA localTime() {
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	ST_FECHA fecha;

	fecha.dia = aTime->tm_mday;
	fecha.mes = aTime->tm_mon + 1; // Month is 0 – 11, add 1 to get a jan-dec 1-12 concept
	fecha.anio = aTime->tm_year + 1900; // Year is # years since 1900
	fecha.hora = aTime->tm_hour;
	fecha.minutos = aTime->tm_min;

	std::ostringstream oss;
	oss << fecha.anio << fecha.mes << fecha.dia << fecha.hora << fecha.minutos;
	fecha.fechaCompleta = oss.str();

	return fecha;
}

int getDiasDelMes(int mes) {
	switch (mes) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		return 28;
	}
}