#include <iostream>
#include "pch.h"
#include "consola.h"

#define CANT_COCHERAS 100 // numero de cocheras


int main()
{
	ST_COCHERA cocheras[CANT_COCHERAS];
	llenarCocheras(cocheras, CANT_COCHERAS);
	//prenderConsola();
	ST_ERROR error;
	ST_DUENIO duenio;
	error = crearDuenio("ASSDASDA", "Linux", "27980841", "1160504141", "aguantelinux@hotmail.com", duenio);
	logError(error);
	error = crearDuenio("ASSDASDA", "Linux", "27980841", "1160504141", "aguantelinux@hotmail.com", duenio);
	logError(error);
}