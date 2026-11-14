#pragma once
#include "Exception.h"
class PerroNoEncontradoException : public Exception
{
public:
	PerroNoEncontradoException() {
		this->mensaje = "Perro no existe";
	}
};