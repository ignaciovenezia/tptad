#pragma once
#include <string>
#include "error.h"

typedef struct duenio {
	std::string nombre;
	std::string apellido;
	std::string dni;
	std::string telefono;
	std::string email;
}ST_DUENIO;


/** @brief inicializa un dueño default
* @return ST_DUENIO el duenio inicializado.
*/
ST_DUENIO inicializarDuenio();

//ST_DUENIO crearDuenio(std::string nombre, std::string apellido, std::string dni, std::string telefono, std::string email);

/** @brief crea un ST_DUENIO
* @return ST_ERROR: un error indicando el resultado de la creacion del duenio
* @param(in) string nombre: el nombre del duenio. Solo se pueden usar letras y espacios.
* @param(in) string apellido: el apellido del duenio. Solo se pueden usar letras y espacios.
* @param(in) string dni: el dni del duenio. Solo se pueden usar numeros.
* @param(in) string telefono: el telefono del duenio. Solo se pueden usar numeros.
* @param(in) string email: el email del duenio. Solo se pueden usar letras, numeros, guion, guion bajo y punto.
* @param(out) ST_DUENIO duenio: el duenio creado con los anteriores parametros.
*/
ST_ERROR crearDuenio(std::string nombre, std::string apellido, std::string dni, std::string telefono, std::string email, ST_DUENIO &duenio);
