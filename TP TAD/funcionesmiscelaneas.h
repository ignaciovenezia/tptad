#pragma once
#include <string>
#include "vehiculo.h"
#define TIME_STRING_LENGTH 18

void getTimeAsString(char[TIME_STRING_LENGTH + 1]);

std::string localTime();

int mesActual();

bool esNombreCorrecto(std::string str);

bool esNumeroCorrecto(std::string str);

bool esEmailCorrecto(std::string str);

bool esPatenteCorrecta(std::string str);

bool esTipoCorrecto(tipoVehiculo tipo);