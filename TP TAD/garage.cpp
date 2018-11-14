#include "pch.h"
#include "garage.h"
#include "funcionesmiscelaneas.h"
#include "fecha.h"
#include <string>
#include <iostream>

float calcularPrecio(ST_VEHICULO vehiculo, tipoAlquiler tipo) {
	float precio = 0.0f;
	if (tipo == MES)
	{
		if (vehiculo.tipo == AUTO)
			precio = 2500.0f;
		else
			precio = 4000.0f;
	}
	else if (tipo == DIA) {
		if (vehiculo.tipo == AUTO)
			precio = 300.0f;
		else
			precio = 400.0f;
	}
	else
	{
		if (vehiculo.tipo == AUTO)
			precio = 50.0f;
		else
			precio = 75.0f;
	}
	//vehiculo.tipo == AUTO ? precio = 2500 : precio = 4000;
	return precio;
}

float cantDeuda(ST_COCHERA cochera, int mes) {
	float deuda = 0;
	for (int i = 0; i < mes; i++)
	{
		deuda += cochera.pago[i];
	}
	return deuda;
}

ST_ERROR calcularPago(ST_COCHERA cochera, float &pago) {
	ST_ERROR error;
	ST_FECHA fechaActual = localTime();
	if (cochera.tipo_alquiler == MES && cochera.pago[fechaActual.mes - 1] != 0.0f) {
		pago = cantDeuda(cochera, localTime().mes);//cochera.pago[fechaActual.mes - 1];
		error = createError(ERR_OK, "");
		return error;
	}
	if (cochera.tipo_alquiler == DIA) {
		if (cochera.fechaIngreso.mes < fechaActual.mes)
			pago = cochera.precio * (getDiasDelMes(cochera.fechaIngreso.mes) - cochera.fechaIngreso.dia + 1 + fechaActual.dia);
		else
			pago = cochera.precio * (fechaActual.dia - cochera.fechaIngreso.dia);
		error = createError(ERR_OK, "");
		return error;
	}
	if (cochera.tipo_alquiler == HORA) {
		pago = cochera.precio * (fechaActual.hora - cochera.fechaIngreso.hora);
		error = createError(ERR_OK, "");
		return error;
	}
	error = createError(ERR_COCHERA_A_EGRESAR_VACIA, "La cochera a egresar esta vacia.");
	return error;
}

void llenarCocheras(int n) {
	for (int i = 0; i < n; i++)
	{
		_cocheras[i] = inicializarCochera(i);
	}
}

ST_ERROR ingresarVehiculo(ST_VEHICULO vehiculo, tipoAlquiler tipo, ST_FECHA fechaIngreso, ST_COCHERA &cochera) {
	ST_ERROR error;
	for (int i = 0; i < CANT_COCHERAS; i++)
	{
		if (_cocheras[i].tipo_alquiler == VACIA) {
			std::cout << _cocheras[i]._id << std::endl;
			cochera._id = _cocheras[i]._id;
			cochera.vehiculo = vehiculo;
			cochera.tipo_alquiler = tipo;
			cochera.fechaIngreso = fechaIngreso;
			cochera.precio = calcularPrecio(vehiculo, tipo);
			for (int i = 0; i < CANT_PAGO; i++)
			{
				if (i < fechaIngreso.mes)
					cochera.pago[i] = 0.0f;
				else
					cochera.pago[i] = cochera.precio;
			}
			_cocheras[i] = cochera;
			error = createError(ERR_OK, "Vehiculo ingresado correctamente a la cochera ID: " + std::to_string(cochera._id) + ".");
			return error;
		}
	}
	// Si no hay cochera disponible, crear y returnear el error.
	error = createError(ERR_NO_HAY_COCHERA_DISPONIBLE, "No hay cochera disponible.");
	return error;
}

ST_ERROR buscarCocheraPorPatente(std::string patente, int &cochera) {
	ST_ERROR error;
	for (int i = 0; i < CANT_COCHERAS; i++)
	{
		if (_cocheras[i].vehiculo.patente._Equal(patente)) {
			cochera = i;
			error = createError(ERR_OK, "Cochera encontrada con exito");
			return error;
		}
	}
	error = createError(ERR_NO_HAY_VEHICULO_CON_TAL_PATENTE, "No se ha encontrado un vehiculo con esa patente.");
	return error;
}

ST_ERROR egresarVehiculo(std::string patente, float &valorAPagar) {
	int posCochera;
	ST_ERROR error = buscarCocheraPorPatente(patente, posCochera);
	if (error.tipoDeError != ERR_OK) {
		return error;
	}
	error = calcularPago(_cocheras[posCochera], valorAPagar);
	if (error.tipoDeError != ERR_OK) {
		return error;
	}
	error = createError(ERR_OK, "Vehiculo egresado con exito.");
	_cocheras[posCochera] = inicializarCochera(_cocheras[posCochera]._id);
	return error;
}

ST_ERROR buscarCocheraPorId(int id, ST_COCHERA &cochera) {
	ST_ERROR error;
	for (int i = 0; i < CANT_COCHERAS; i++) {
		if (_cocheras[i]._id == id && _cocheras[i].tipo_alquiler != VACIA) {
			cochera = _cocheras[i];
			error = createError(ERR_OK, "");
			return error;
		}
	}
	error = createError(ERR_NO_HAY_COCHERA_CON_TAL_ID, "No se ha encontrado una cochera con ese ID.");
	return error;
}

ST_ERROR moverVehiculo(int idOrigen, ST_COCHERA &destino) {
	ST_COCHERA cocheraOrigen;
	ST_ERROR error = buscarCocheraPorId(idOrigen, cocheraOrigen);
	if (error.tipoDeError != ERR_OK)
		return error;
	for (int i = 0; i < CANT_COCHERAS; i++)
	{
		if(_cocheras[i].tipo_alquiler == VACIA){
			cocheraOrigen._id = i;
			_cocheras[i] = cocheraOrigen;
			destino = _cocheras[i];
			_cocheras[idOrigen] = inicializarCochera(idOrigen); 
			error = createError(ERR_OK, "Cochera movida con exito.");
			return error;
		}		
	}
	error = createError(ERR_NO_HAY_COCHERA_DISPONIBLE, "No hay cocheras disponibles.");
	return error;
}

void listarDeudores(int mes) {
	std::cout << std::endl;
	std::string meses[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
	float totalDeuda;
	for (int i = 0; i < CANT_COCHERAS; i++)
	{
		totalDeuda = cantDeuda(_cocheras[i], mes);
		if (_cocheras[i].tipo_alquiler == MES && totalDeuda != 0.0f) {
			std::cout << "Cochera: " << _cocheras[i]._id << std::endl << "Propietario Automovil: " << _cocheras[i].vehiculo.duenio.nombre << " " << _cocheras[i].vehiculo.duenio.apellido << std::endl;
			std::cout << "Alquila desde: " << _cocheras[i].fechaIngreso.fechaCompleta << std::endl;
			std::cout << "Meses que adeuda: ";
			for (int j = 0; j < mes; j++)
			{
				if (_cocheras[i].pago[j] != 0) {
					std::cout << meses[j] << ((j < mes - 1) ? ", " : ".");
				}
			}
			std::cout << std::endl << "Total Deuda: $" << totalDeuda << std::endl;
			std::cout << std::endl;
		}
	}
}

void ordenarCocherasPorPago(ST_COCHERA cochera[CANT_COCHERAS]) {
	ST_COCHERA aux;
	for (int i = 0; i < CANT_COCHERAS; i++)
	{
		for (int j = 0; j < CANT_COCHERAS; j++)
		{
			if (cochera[j].pago[localTime().mes] < cochera[i].pago[localTime().mes]) {
				aux = cochera[j];
				cochera[j] = cochera[i];
				cochera[i] = aux;
			}
		}
	}
}
void ordenarCocherasPorApellido(ST_COCHERA cochera[CANT_COCHERAS]) {
	ST_COCHERA aux;
	for (int i = 0; i < CANT_COCHERAS; i++)
	{
		for (int j = 0; j < CANT_COCHERAS; j++)
		{
			if (cochera[j].vehiculo.duenio.apellido[0] > cochera[i].vehiculo.duenio.apellido[0]) {
				aux = cochera[j];
				cochera[j] = cochera[i];
				cochera[i] = aux;
			}
		}
	}
}
void listarCobranzasMensuales() {
	float pagoActual = 0.0f;
	ST_COCHERA cocherasOrdenadasPorPago[CANT_COCHERAS];
	ST_COCHERA cocherasOrdenadasPorApellido[CANT_COCHERAS];
	for (int i = 0; i < CANT_COCHERAS; i++) {
		cocherasOrdenadasPorPago[i] = _cocheras[i];
		cocherasOrdenadasPorApellido[i] = _cocheras[i];
	}

	ordenarCocherasPorPago(cocherasOrdenadasPorPago);
	ordenarCocherasPorApellido(cocherasOrdenadasPorApellido);

	float lastPago = cocherasOrdenadasPorPago[0].pago[localTime().mes];
	int i = 0;
	bool flag = false;
	std::cout << "Importe a cobrar: " << cocherasOrdenadasPorPago[i].pago[localTime().mes] << std::endl;
	while ((i < CANT_COCHERAS || cocherasOrdenadasPorPago[i].pago[localTime().mes] == lastPago) && cocherasOrdenadasPorPago[i].pago[localTime().mes] != 0.0f)
	{
		for (int j = 0; j < CANT_COCHERAS && flag == false; j++)
		{
			if (cocherasOrdenadasPorApellido[j].pago[localTime().mes] == lastPago) {
				std::cout << "		" << cocherasOrdenadasPorApellido[j].vehiculo.duenio.apellido << " " << cocherasOrdenadasPorApellido[j].vehiculo.duenio.nombre << std::endl;
			}
		}
		flag = true;
		if (cocherasOrdenadasPorPago[i].pago[localTime().mes] < lastPago) {
			lastPago = cocherasOrdenadasPorPago[i].pago[localTime().mes];
			std::cout << std::endl << "Importe a cobrar: " << cocherasOrdenadasPorPago[i].pago[localTime().mes] << std::endl;
			flag = false;
		}
		i++;
	}
}
