#pragma once
#include "Exception.h"

class VehiculoYaAsignadoException : public Exception {
public:
	VehiculoYaAsignadoException(string placa) {
		this->mensaje = "El vehiculo con placa: " + placa + " ya tiene un espacio asignado.";
	}
};
