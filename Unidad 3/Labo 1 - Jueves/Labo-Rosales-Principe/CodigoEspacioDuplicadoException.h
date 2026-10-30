#pragma once
#include "Exception.h"

class CodigoEspacioDuplicadoException : public Exception {
public:
	CodigoEspacioDuplicadoException(string codigo) {
		this->mensaje = "El codigo de espacio: " + codigo + " esta duplicado.";
	}
};
