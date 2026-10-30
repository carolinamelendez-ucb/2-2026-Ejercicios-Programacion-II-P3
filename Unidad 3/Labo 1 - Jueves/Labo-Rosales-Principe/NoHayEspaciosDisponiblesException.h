#pragma once
#include "Exception.h"

class NoHayEspaciosDisponiblesException : public Exception {
public:
	NoHayEspaciosDisponiblesException() {
		this->mensaje = "No existen espacios disponibles en el parqueo.";
	}
};
