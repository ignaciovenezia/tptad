#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

#define ERROR_LENGTH 40

#include <stdio.h>

enum ERROR_TYPE {
	ERR_OK,
	ERR_NO_GARAGE

};

typedef struct error {
	int err_no;
	char err_desc[ERROR_LENGTH + 1];
} ST_ERROR;


/**
 * Crea un error y lo devuelve.
 *
 * @param[in] {ERROR_TYPE} errorNumber n�mero de error.
 * @param[in] {char *} description descripci�n del error.
 * @return {ERROR_ST} error creado
 */
ST_ERROR createError(ERROR_TYPE error, char description[ERROR_LENGTH + 1]);

/**
 * Imprime la descripci�n del error por pantalla. Agrega fecha y hora.
 *
 * @param[in] {ERROR_ST} error a imprimir
 */
void logError(ST_ERROR error);

/**
 * Imprime la descripci�n del error por pantalla.
 *
 * @param[in] {ERROR_ST} error a imprimir
 * @param[in] {char *} texto extra. En caso de ser distinto de null se imprime.
 */
void printError(ST_ERROR error, char *text = NULL);



#endif // ERROR_H_INCLUDED