#pragma once
#include "Exception.h"
class ServicioNoEncontradoException : public Exception
{
public:
	ServicioNoEncontradoException() {
		this->mensaje = "Servicio No encontrado";
	}
};