#include "pch.h"
#include "error.h"
#include <string.h>
#include "funcionesmiscelaneas.h"
#include <iostream>



ST_ERROR createError(ERROR_TYPE errorNumber, std::string description) {
	ST_ERROR error;
	error.tipoDeError = errorNumber;
	error.err_desc = description;

	return error;
}

void logError(ST_ERROR error) {
	char timeString[TIME_STRING_LENGTH + 1];
	getTimeAsString(timeString);
	std::cout << timeString << ": " << error.err_desc << std::endl;
	//printf("%s: %s\n", timeString, error.err_desc);
}

void printError(ST_ERROR error, char *text) {
	std::cout << error.err_desc << std::endl;
	//printf("%s", error.err_desc);

	if (text != NULL) {
		std::cout << text << std::endl;
		//printf(". %s\n", text);
	}
}