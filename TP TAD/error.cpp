#include "pch.h"
#include "error.h"
#include <string.h>
#include "funcionesmiscelaneas.h"
#include <iostream>
#include <time.h>


ST_ERROR createError(ERROR_TYPE errorNumber, std::string description) {
	ST_ERROR error;
	error.tipoDeError = errorNumber;
	error.err_desc = description;

	return error;
}

/**
 * Devuelve el tiempo formateado como DD/MM/AAAA - HH:mm
 *
 * @param[out] {char *} timeString tiempo formateado.
 */
void getTimeAsString(char timeString[TIME_STRING_LENGTH + 1]) {
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	int day = aTime->tm_mday;
	int month = aTime->tm_mon + 1; // Month is 0 – 11, add 1 to get a jan-dec 1-12 concept
	int year = aTime->tm_year + 1900; // Year is # years since 1900
	int hour = aTime->tm_hour;
	int min = aTime->tm_min;

	// DD/MM/AAAA - HH:mm
	snprintf(timeString, TIME_STRING_LENGTH + 1, "%d/%d/%d - %d:%d", day, month, year, hour, min);
	return;
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