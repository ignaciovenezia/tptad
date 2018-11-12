#include "pch.h"
#include "funcionesmiscelaneas.h"
#include <iostream>
#include <regex>

#define LOCALTIME_LENGTH 12

bool esNombreCorrecto(std::string s) {
	return !s.empty() && s.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") == std::string::npos;
}

bool esEmailCorrecto(std::string s) {
	return !s.empty() && s.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@._-") == std::string::npos;
}

bool esNumeroCorrecto(std::string s) { 
	return !s.empty() && s.find_first_not_of("0123456789") == std::string::npos;
}

bool esPatenteCorrecta(std::string s) {
	std::regex r("[a-zA-Z][a-zA-Z][0-9][0-9][0-9][a-zA-Z][a-zA-Z]");
	bool a = !s.empty();
	bool b = std::regex_match(s, r);
	bool t = s.length() == 7;
	return a && b && t;
}

bool esTipoCorrecto(tipoVehiculo tipo) {
	return tipo == AUTO || tipo == CAMIONETA;
}