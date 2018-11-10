#include "pch.h"
#include "duenio.h"
#include "funcionesmiscelaneas.h"

ST_DUENIO inicializarDuenio() {
	ST_DUENIO duenio;
	duenio.nombre = "";
	duenio.apellido = "";
	duenio.dni = "";
	duenio.telefono = "";
	duenio.email = ""; 

	return duenio;
}

/*ST_DUENIO crearDuenio(std::string nombre, std::string apellido, std::string dni, std::string telefono, std::string email) {
	ST_DUENIO duenio;
	duenio.nombre = nombre;
	duenio.apellido = apellido;
	duenio.dni = dni;
	duenio.telefono = telefono;
	duenio.email = email;

	return duenio;
}*/

ST_ERROR crearDuenio(std::string nombre, std::string apellido, std::string dni, std::string telefono, std::string email, ST_DUENIO &duenio) {
	ST_ERROR errorduenio;
	//Asigna al duenio los datos pasados por parametro
	duenio.nombre = nombre;
	duenio.apellido = apellido;
	duenio.dni = dni;
	duenio.telefono = telefono;
	duenio.email = email;
	//Chequear si los datos son correctos
	if (!esNombreCorrecto(nombre)) {
		errorduenio = createError(ERR_NOMBRE_INCORRECTO, "Nombre incorrecto.");
		return errorduenio;
	}
	if (!esNombreCorrecto(apellido)) {
		errorduenio = createError(ERR_APELLIDO_INCORRECTO, "Apellido incorrecto.");
		return errorduenio;
	}
	if (!esNumeroCorrecto(dni)) {
		errorduenio = createError(ERR_DNI_INCORRECTO, "DNI incorrecto.");
		return errorduenio;
	}
	if (!esNumeroCorrecto(telefono)) {
		errorduenio = createError(ERR_TELEFONO_INCORRECTO, "TELEFONO incorrecto.");
		return errorduenio;
	}
	if (!esEmailCorrecto(email)) {
		errorduenio = createError(ERR_EMAIL_INCORRECTO, "EMAIL incorrecto.");
		return errorduenio;
	}

	errorduenio = createError(ERR_OK, "Duenio Ingresado OK");
	return errorduenio;
}