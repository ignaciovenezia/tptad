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
	cout << "Ingresamos el vehiculo de Ignacio con un tipo de alquiler mensual. " << endl;

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
	cout << "Ingresamos el vehiculo con un tipo de alquiler hora. " << endl;

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
	cout << "Ingresamos el vehiculo con un tipo de alquiler mensual." << endl;

	ST_COCHERA cochera3;
	error = ingresarVehiculo(vehiculo, MES, crearFecha(2018, 10, 5, 5, 10), cochera3);
	logError(error);

	valorAPagar = 0.0f;
	cout << endl;
	cout << endl;
	cout << "Creamos un dueño ingresando los siguientes datos: " << endl;
	cout << "Nombre: Tobias, Apellido: Favero, DNI: 38176142, Tel:1130367785, Email: tobaristo16@gmail.com" << endl;
	error = crearDuenio("Tobias", "Favero", "38176142", "1130367785", "tobaristo16@gmail.com", duenio);
	logError(error);
	cout << endl;
	cout << "Creamos el vehiculo de Marco, con los siguientes datos: " << endl;
	cout << "Vehiculo: Auto, Patente: AF891GK" << endl;
	error = crearVehiculo(AUTO, "AF891GK", duenio, vehiculo);
	logError(error);
	cout << endl;	
	cout << "Ingresamos el vehiculo con un tipo de alquiler dia. " << endl;

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
	cout << "Ingresamos el vehiculo con un tipo de alquiler dia. " << endl;
	error = ingresarVehiculo(vehiculo, DIA, crearFecha(2018, 1, 13, 00, 12), cochera5);
	logError(error);
	cout << endl;



	/*
	error = egresarVehiculo("AF891KK", valorAPagar);
	logError(error);
	if(error.tipoDeError == ERR_OK)
		cout << valorAPagar << endl;
	//
	ST_COCHERA cocheraDestino;
	error = moverVehiculo(0, cocheraDestino);
	logError(error);
	if (error.tipoDeError == ERR_OK)
		cout << "La nueva cochera es la ID: " << cocheraDestino._id << "." << endl;;


	error = egresarVehiculo("AF891KK", valorAPagar);
	logError(error);
	if (error.tipoDeError == ERR_OK)
		cout << valorAPagar << endl;
	*/
	listarDeudores(10);
	listarCobranzasMensuales();

	/*
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

	// ingresar vehiculo al garage
	cout << "Se procedera a ingresar el vehiculo a una cochera vacia teniendo en cuenta los siguientes datos:" << endl;
	cout << endl;
	ST_COCHERA cochera;
/*	cout << "1) Tipo de Alquiler - MENSUAL " << endl;
	error = ingresarVehiculo(vehiculo, MES, localTime(), cochera);
	logError(error);
	cout << "1) Tipo de Alquiler - HORA" << endl;
	error = ingresarVehiculo(vehiculo, HORA, crearFecha(2018, 11, 13, 1, 20), cochera);
	cout << "Precio de la cochera: " << cochera.precio << " por hora.";
	cout << "Ingresa en la fecha: 2018-11-13 1:20" << endl;
	logError(error);
	cout << endl;
	// egresar vehiculo del garage
	cout << "Se procede a egresar un vehiculo de una cochera teniendo en cuenta los siguientes datos:" << endl;
	cout << endl;
	float valorAPagar = 0.0f;
	cout << "1) Patente del vehiculo - JK018LP" << endl;
	error = egresarVehiculo("JK018LP", valorAPagar);
	logError(error);
	cout << "1) Patente del vehiculo - AA000AA" << endl;
	error = egresarVehiculo("AA000AA", valorAPagar);
	logError(error);
	if (error.tipoDeError == ERR_OK)
		cout << "Valor A pagar: " << valorAPagar << endl;
	cout << "Ingresamos otro vehiculo con los siguientes datos: " << endl;
	cout << "1) Tipo de Alquiler - MES" << endl;
	crearDuenio("Ignacio", "Venezia", "123123", "123123", "123123", duenio);
	crearVehiculo(CAMIONETA, "AF203KK", duenio, vehiculo);
	error = ingresarVehiculo(vehiculo, MES, crearFecha(2018, 5, 13, 1, 20), cochera);
	cout << "Precio de la cochera: " << cochera.precio << " por mes.";
	cout << "Ingresa en la fecha: 2018-05-13 1:20" << endl;
	logError(error);
	cout << endl;
	error = egresarVehiculo("AA000AA", valorAPagar);
	logError(error);
	if (error.tipoDeError == ERR_OK)
		cout << "Valor A pagar: " << valorAPagar << endl;
	// mover vehiculo de cochera
	*/
	// lista de deudores
	// cobranza del mes9*/

}