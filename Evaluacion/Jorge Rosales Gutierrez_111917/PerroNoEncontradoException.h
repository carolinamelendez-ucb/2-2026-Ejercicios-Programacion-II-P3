#pragma once
#include "Exception.h"
class PerroNoEncontradoException : public Exception {
public:
	PerroNoEncontradoException(string codigo) {
		this->mensaje = "El servicio con codigo: " + codigo + " no existe en el sistema.";
	}
};