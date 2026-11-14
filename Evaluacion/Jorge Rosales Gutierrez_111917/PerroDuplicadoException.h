#pragma once
#include "Exception.h"

class PerroDuplicadoException : public Exception {
public:
	PerroDuplicadoException(string codigo) {
		this->mensaje = "El codigo de perro: " + codigo + " ya existe.";
	}
};