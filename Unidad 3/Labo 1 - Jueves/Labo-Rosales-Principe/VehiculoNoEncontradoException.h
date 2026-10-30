#pragma once
#include "Exception.h"

class VehiculoNoEncontradoException : public Exception {
public:
	VehiculoNoEncontradoException(string placa) {
		this->mensaje = "El vehiculo con placa: " + placa + " no existe en el sistema.";
	}
};