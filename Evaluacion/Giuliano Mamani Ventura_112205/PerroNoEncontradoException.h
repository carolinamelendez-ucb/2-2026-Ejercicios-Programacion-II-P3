#pragma once
#include "Exception.h"

class PerroNoEncontradoException : public Exception {
public:
	PerroNoEncontradoException() : Exception() {
		mensaje = "el perro no existe";
	}
};