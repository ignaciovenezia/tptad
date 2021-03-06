#include <iostream>
#include "pch.h"
#include "garage.h"
#include "vehiculo.h"
#include "fecha.h"

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
	llenarCocheras(CANT_COCHERAS);
	cout << CANT_COCHERAS << " cocheras creadas." << endl;
	cout << endl;
	ST_ERROR error;
	ST_DUENIO duenio;
	ST_VEHICULO vehiculo;
	float valorAPagar = 0.0f;
	cout << "Creamos un dueño ingresando los siguientes datos: " << endl;
	cout << "Nombre: 1234, Apellido: Favero, DNI: 38929292, Tel: 1133232323, Email: sdfas@gmail.com" << endl;
	error = crearDuenio("1234", "Favero", "38929239", "113232323", "asdas@gmail.com", duenio);
	logError(error);
	cout << endl;
	cout << "Creamos otro dueño ingresando los siguientes datos: " << endl;
	cout << "Nombre: Tobias, Apellido: Favero, DNI: 38aa8321, Tel: 1133232323, Email: pkmsn@gmail.com" << endl;
	error = crearDuenio("Tobias", "Favero", "38aa2932", "113232323", "asdas@gmail.com", duenio);
	logError(error);
	cout << endl;
	cout << "Creamos un dueño ingresando los siguientes datos: " << endl;
	cout << "Nombre: Ignacio Julian, Apellido: Venezia, DNI: 38176142, Tel:1130367785, Email: nacho_kpo@hotmail.com" << endl;
	error = crearDuenio("Ignacio Julian", "Venezia", "38176142", "1130367785", "nacho_kpo@hotmail.com", duenio);
	logError(error);
	cout << endl;
	cout << endl;
	cout << "Creamos el vehiculo de Ignacio Julian con los siguientes datos: " << endl;
	cout << "Vehiculo: Camioneta, Patente: AF891KK" << endl;
	error = crearVehiculo(CAMIONETA, "AF891KK", duenio, vehiculo);
	logError(error);
	cout << endl;
	cout << endl;
	cout << "Ingresamos el vehiculo de Ignacio con un tipo de alquiler mensual con la fecha 12/05/2018 12:12. " << endl;

	ST_COCHERA cochera;
	error = ingresarVehiculo(vehiculo, MES, crearFecha(2018, 5, 12, 12, 12), cochera);
	logError(error);
	cout << endl;

	valorAPagar = 0.0f;
	cout << "Creamos un dueño ingresando los siguientes datos: " << endl;
	cout << "Nombre: Horacio, Apellido: Signori, DNI: 5323565, Tel:1123984623, Email: horacio_cobolero@hotmail.com" << endl;
	error = crearDuenio("Horacio", "Signori", "5323565", "1123984623", "horacio_cobolero@hotmail.com", duenio);
	logError(error);
	cout << endl;
	cout << "Creamos el vehiculo de Horacio, con los siguientes datos: " << endl;
	cout << "Vehiculo: Auto, Patente: AF891JK" << endl;
	error = crearVehiculo(AUTO, "AF891JK", duenio, vehiculo);
	logError(error);
	cout << endl;
	cout << "Ingresamos el vehiculo de Horacio con un tipo de alquiler hora. Con fecha 15/11/2018 a las 12:12" << endl;

	ST_COCHERA cochera2;
	error = ingresarVehiculo(vehiculo, HORA, crearFecha(2018, 11, 15, 12, 12), cochera2);
	logError(error);
	cout << endl;
	cout << endl;
	valorAPagar = 0.0f;
	cout << "Creamos un dueño ingresando los siguientes datos: " << endl;
	cout << "Nombre: Marco, Apellido: Rusticcini, DNI: 55423145, Tel:1125465485, Email: marco_comunista@hotmail.com" << endl;
	error = crearDuenio("Marco", "Rusticcini", "55423145", "1125465485", "marco_comunista@hotmail.com", duenio);
	logError(error);
	cout << endl;
	cout << "Creamos el vehiculo de Marco, con los siguientes datos: " << endl;
	cout << "Vehiculo: Auto, Patente: AF89AVK" << endl;
	error = crearVehiculo(AUTO, "AF89AVK", duenio, vehiculo);
	logError(error);
	cout << endl;
	cout << "Tras el error, volvemos a crear el vehiculo de Marco, con los siguientes datos: " << endl;
	cout << "Vehiculo: Auto, Patente: AF899VK" << endl;
	error = crearVehiculo(AUTO, "AF899VK", duenio, vehiculo);
	logError(error);
	cout << endl;
	cout << "Ingresamos el vehiculo de Marco con un tipo de alquiler mensual con la fecha 5/10/2018 5:10" << endl;

	ST_COCHERA cochera3;
	error = ingresarVehiculo(vehiculo, MES, crearFecha(2018, 10, 5, 5, 10), cochera3);
	logError(error);

	valorAPagar = 0.0f;
	cout << endl;
	cout << endl;
	cout << "Creamos un dueño ingresando los siguientes datos: " << endl;
	cout << "Nombre: Tobias, Apellido: Favero, DNI: 38176142, Tel:1130367785, Email: tobias_hadouken@gmail.com" << endl;
	error = crearDuenio("Tobias", "Favero", "38176142", "1130367785", "tobias_hadouken@gmail.com", duenio);
	logError(error);
	cout << endl;
	cout << "Creamos el vehiculo de Tobias, con los siguientes datos: " << endl;
	cout << "Vehiculo: Auto, Patente: AF891GK" << endl;
	error = crearVehiculo(AUTO, "AF891GK", duenio, vehiculo);
	logError(error);
	cout << endl;	
	cout << "Ingresamos el vehiculo de Tobias con un tipo de alquiler dia con la fecha 6/11/2018 00:12" << endl;

	ST_COCHERA cochera4;
	error = ingresarVehiculo(vehiculo, DIA, crearFecha(2018, 11, 6, 00, 12), cochera4);
	logError(error);
	cout << endl;
	cout << endl;
	valorAPagar = 0.0f;
	cout << "Creamos un dueño ingresando los siguientes datos: " << endl;
	cout << "Nombre: Nicolas, Apellido: Senra, DNI: 35231252, Tel:1165984512, Email: nico_morganfreeman@gmail.com" << endl;
	error = crearDuenio("Nicolas", "Senra", "35231252", "1165984512", "nico_morganfreeman@gmail.com", duenio);
	logError(error);
	cout << endl;
	cout << "Creamos el vehiculo de Nicolas, con los siguientes datos: " << endl;
	cout << "Vehiculo: Auto, Patente: AF891MF" << endl;
	error = crearVehiculo(AUTO, "AF891MF", duenio, vehiculo);
	logError(error);
	cout << endl;

	ST_COCHERA cochera5;
	cout << "Ingresamos el vehiculo de Nicolas con un tipo de alquiler dia con la fecha 13/1/2018 00:12 " << endl;
	error = ingresarVehiculo(vehiculo, DIA, crearFecha(2018, 1, 13, 00, 12), cochera5);
	logError(error);

	cout << endl << "===============================================" << endl << endl;

	cout << "Movemos un vehiculo de cochera con cochera origen ID: 107" << endl;
	error = moverVehiculo(107, cochera);
	logError(error);

	cout << endl;

	cout << "Movemos un vehiculo de cochera con cochera origen ID: 0, pero al no haber cocheras vacias nos va a dar el siguiente error: " << endl;
	error = moverVehiculo(0, cochera);
	logError(error);
	
	cout << endl << "===============================================" << endl << endl;
	
	cout << "Egresamos el vehiculo de Horacio que tiene como patente AF891JK." << endl;
	error = egresarVehiculo("AF891JK", valorAPagar = 0.0f);
	logError(error);
	if (error.tipoDeError == ERR_OK)
		cout << "Valor a pagar: $" << valorAPagar;

	cout << endl << endl << "Egresamos un vehiculo con patente inexistente AA999AA: " << endl;
	error = egresarVehiculo("AA999AA", valorAPagar = 0.0f);
	logError(error);
	if (error.tipoDeError == ERR_OK)
		cout << "Valor a pagar: $" << valorAPagar;
	cout << endl << "===============================================" << endl << endl;

	cout << "Ahora que existe una cochera vacante, movemos el vehiculo de cochera origen ID: 0" << endl;
	error = moverVehiculo(0, cochera);
	logError(error);

	cout << endl << "===============================================" << endl << endl;
	cout << "Generamos la lista de deudores hasta el mes 10" << endl << endl;
	listarDeudores(10);

	cout << endl << "===============================================" << endl << endl;
	cout << "Por ultimo generamos la lista de cobranzas del mes actual:" << endl << endl;
	listarCobranzasMensuales();


}