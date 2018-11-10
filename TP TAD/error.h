#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

#define ERROR_LENGTH 40

#include <stdio.h>
#include <string>

enum ERROR_TYPE {
	ERR_OK,
	ERR_NO_GARAGE,
	ERR_NOMBRE_INCORRECTO,
	ERR_APELLIDO_INCORRECTO,
	ERR_DNI_INCORRECTO,
	ERR_TELEFONO_INCORRECTO,
	ERR_EMAIL_INCORRECTO,
	ERR_TIPO_INCORRECTO,
	ERR_PATENTE_INCORRECTA,
};

typedef struct error {
	int tipoDeError;
	std::string err_desc;
} ST_ERROR;


/**
 * Crea un error y lo devuelve.
 *
 * @param[in] {ERROR_TYPE} errorNumber número de error.
 * @param[in] {char *} description descripción del error.
 * @return {ERROR_ST} error creado
 */
ST_ERROR createError(ERROR_TYPE error, std::string);

/**
 * Imprime la descripción del error por pantalla. Agrega fecha y hora.
 *
 * @param[in] {ERROR_ST} error a imprimir
 */
void logError(ST_ERROR error);

/**
 * Imprime la descripción del error por pantalla.
 *
 * @param[in] {ERROR_ST} error a imprimir
 * @param[in] {char *} texto extra. En caso de ser distinto de null se imprime.
 */
void printError(ST_ERROR error, char *text = NULL);



#endif // ERROR_H_INCLUDED