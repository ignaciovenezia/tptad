#include <iostream>
#include "pch.h"
#include "garage.h"
#include "vehiculo.h"
using namespace std;


int main()
{
	cout << "Proceso de Creacion de Garage " << endl;
	cout << "                  Integrantes del Grupo: " << endl;
	cout << "                                         Favero, Tobias " << endl;
	cout << "                                         Rusticcini, Marco " << endl;
	cout << "                                         Senra, Nicolas " << endl;
	cout << "                                         Signori, Horacio " << endl;
	cout << "                                         Venezia, Ignacio " << endl;
	cout << "========================================================== " << endl;
	cout << endl;
	//cout << " " << endl;
	cout << "Se procedera a la carga de Cocheras " << endl;

	llenarCocheras(cocheras, CANT_COCHERAS);
	cout << CANT_COCHERAS << " cocheras creadas." << endl;
	cout << endl;

	//prenderConsola();
	cout << "Se procedera a la carga del Duewo con los siguientes datos" << endl;
	cout << endl;
	ST_ERROR error;
	ST_DUENIO duenio;
	cout << "Nombre: Centro Univesitario  -  Apellido: Vicente Lopez " << endl;
	cout << "DNI: 12345678 - Telefono: 12345678 - E-Mail: CtroUnivVteLopez@mvl.com.ar " << endl;
	cout << endl;
	cout << "-------------------- Verificacion Errores Duewo:" << endl;
	cout << endl;
	cout << "1) Nombre - Centro Univesitario 1234 " << endl;
	error = crearDuenio("Centro Univesitario 1234", "Vicente Lopez 1234", "a2345678", "123a5678", "CtroU***nivVteLopez@mvl.com.ar", duenio);
	logError(error);
	cout << endl;
	cout << "            Centro Univesitario" << endl;
	cout << endl;
	cout << "2) Apellido - Vicente 1234 Lopez " << endl;
	error = crearDuenio("Centro Univesitario", "Vicente Lopez 1234", "a2345678", "123a5678", "CtroU***nivVteLopez@mvl.com.ar", duenio);
	logError(error);
	cout << endl;
	cout << "              Vicente Lopez" << endl;
	cout << endl;
	cout << "3) Documento - 1234aaaa " << endl;
	error = crearDuenio("Centro Univesitario", "Vicente Lopez", "a2345678", "123a5678", "CtroU***nivVteLopez@mvl.com.ar", duenio);
	logError(error);
	cout << endl;
	cout << "               12345678 " << endl;
	cout << endl;
	cout << "4) Telefono - aaaa5678 " << endl;
	error = crearDuenio("Centro Univesitario", "Vicente Lopez", "12345678", "123a5678", "CtroU***nivVteLopez@mvl.com.ar", duenio);
	logError(error);
	cout << endl;
	cout << "               12345678 " << endl;
	cout << endl;
	cout << "5) E-Mail - Ctro*****teLopez@mvl.com.ar " << endl;
	error = crearDuenio("Centro Univesitario", "Vicente Lopez", "12345678", "12345678", "CtroU***nivVteLopez@mvl.com.ar", duenio);
	logError(error);
	cout << endl;
	cout << "            CtroUnivVteLopez@mvl.com.ar " << endl;
	cout << endl;
	error = crearDuenio("Centro Univesitario", "Vicente Lopez", "12345678", "12345678", "CtroUnivVteLopez@mvl.com.ar", duenio);
	logError(error);
	cout << endl; 
	cout << "Se procedera a la carga del Vehiculo con los siguientes datos" << endl;
	cout << endl;
	ST_VEHICULO vehiculo;
	cout << "Tipo: Auto - Patente: AA000AA " << endl;
	cout << endl;
	cout << "-------------------- Verificacion Errores Vehiculo:" << endl;
	cout << endl;
	cout << "1) Tipo - MOTO " << endl;
	error = crearVehiculo(OTRO, "AAA000", duenio, vehiculo);
	logError(error);
	cout << endl;
	cout << "          AUTO" << endl;
	cout << endl;
	cout << "2) Patente - AAA000 " << endl;
	error = crearVehiculo(AUTO, "AAA000", duenio, vehiculo);
	logError(error);
	cout << endl;
	cout << "             AA000AA" << endl;
	cout << endl;
	error = crearVehiculo(AUTO, "AA000AA", duenio, vehiculo);
	logError(error);
	cout << endl;

	// agregar cochera al garage
	cout << "Se procedera a ingresar el vehiculo a una cochera vacia teniendo en cuenta los siguientes datos:" << endl;
	cout << endl;
	ST_COCHERA cochera;
	cout << "1) Tipo de Alquiler - MENSUAL " << endl;
	error = ingresarVehiculo(vehiculo, MES, "201811101818", cochera); //localTime;
	logError(error);
	cout << "1) Tipo de Alquiler - HORA " << endl;
	error = ingresarVehiculo(vehiculo, HORA, "201811101818", cochera); //localTime;
	logError(error);
	// mover cochera de garage

	// lista de deudores
	// cobranza del mes

	int n;
	cin >> n;
	return 0;
}