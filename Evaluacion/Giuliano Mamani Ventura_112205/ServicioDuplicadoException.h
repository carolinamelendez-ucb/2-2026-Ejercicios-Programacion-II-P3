#pragma once
#include "Exception.h"

class ServicioDuplicadoException : public Exception {
public:
	ServicioDuplicadoException() : Exception() {
		mensaje = "codigo del servicio ya existe";
	}
};