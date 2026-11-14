#pragma once
#include "Exception.h"
class ServicioNoEncontradoException : public Exception {
public:
	ServicioNoEncontradoException(string codigo) {
		this->mensaje = "El servicio con codigo: " + codigo + " no existe en el sistema.";
	}
};