#pragma once
#include "Exception.h"

class ServicioNoEncontradoException : public Exception {
public:
	ServicioNoEncontradoException() : Exception() {
		mensaje = "el servicio no existe";
	}
};