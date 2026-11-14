#pragma once
#include "Exception.h"
class PerroDuplicadoException : public Exception
{
public:
	PerroDuplicadoException() {
		this->mensaje = "codigo del perro duplicado";
	}
};