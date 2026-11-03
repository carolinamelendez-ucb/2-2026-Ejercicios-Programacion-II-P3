#pragma once
#include "Exception.h"
class  EnvioNoencontrado : public Exception
{
public:
	EnvioNoencontrado() {
		this->mensaje = "envio no encontrado";
	}
};