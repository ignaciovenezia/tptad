#include "pch.h"
#include "garage.h"
ST_ERROR ingresarVehiculo(ST_VEHICULO vehiculo, tipoAlquiler tipo, std::string fechaIngreso) {
	char desc[18] = "pelotudo";
	ST_ERROR err = createError(ERR_OK, desc);

	return err;
}

ST_ERROR egresarVehiculo(std::string patente, std::string fechaEgreso);

ST_ERROR moverVehiculo(ST_COCHERA origen);

void listarDeudores(int mes);

void listarCobranzasMensuales();
