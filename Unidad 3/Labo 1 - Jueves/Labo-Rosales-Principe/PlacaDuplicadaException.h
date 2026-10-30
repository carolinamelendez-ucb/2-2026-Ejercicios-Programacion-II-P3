#pragma once
#include "Exception.h"

class PlacaDuplicadaException : public Exception {
public:
	PlacaDuplicadaException(string placa) {
		this->mensaje = "La placa: " + placa + " ya se encuentra registrada.";
	}
};
