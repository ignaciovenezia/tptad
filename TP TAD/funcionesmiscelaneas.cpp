#include "pch.h"
#include "funcionesmiscelaneas.h"
#include <stdio.h>
#include <time.h>
#include <sstream>
#include <iostream>
#include <regex>

#define LOCALTIME_LENGTH 12


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

std::string localTime()
{
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	int day = aTime->tm_mday;
	int month = aTime->tm_mon + 1; // Month is 0 – 11, add 1 to get a jan-dec 1-12 concept
	int year = aTime->tm_year + 1900; // Year is # years since 1900
	int hour = aTime->tm_hour;
	int min = aTime->tm_min;

	std::ostringstream oss;
	oss << year << month << day << hour << min;
	return oss.str();
}

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
	// hay que arreglar esto
	/*std::regex r("([a-z][a-z][\d][\d][\d][a-z][a-z])");
	std::smatch match;
	std::regex_search(s, match, r);
	std::cout << match[0] << std::endl;
	bool a = !s.empty();
	bool b = match[0] != NULL;
	bool t =  s.length() == 7;
	return t;*/
	return true;
}

bool esTipoCorrecto(std::string s) {
	return !s.empty() && (s._Equal("auto") || s._Equal("camioneta"));
}