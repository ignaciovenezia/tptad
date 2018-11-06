#include "pch.h"
#include "error.h"
#include <string.h>
#include "funcionesmiscelaneas.h"



ST_ERROR createError(ERROR_TYPE errorNumber, char description[ERROR_LENGTH + 1]) {
	ST_ERROR error;
	error.err_no = errorNumber;
	strcpy_s(error.err_desc, description);

	return error;
}

void logError(ST_ERROR error) {
	char timeString[TIME_STRING_LENGTH + 1];
	getTimeAsString(timeString);
	printf("%s: %s\n", timeString, error.err_desc);
}

void printError(ST_ERROR error, char *text) {
	printf("%s", error.err_desc);

	if (text != NULL) {
		printf(". %s\n", text);
	}
}