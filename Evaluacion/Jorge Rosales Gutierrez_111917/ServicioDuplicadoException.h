#pragma once
#include "Exception.h"

class ServicioDuplicadoException : public Exception {
public:
	ServicioDuplicadoException(string codigo) {
		this->mensaje = "El codigo de servicio: " + codigo + " ya existe.";
	}
};