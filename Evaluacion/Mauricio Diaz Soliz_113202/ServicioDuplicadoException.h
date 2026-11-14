#pragma once
#include "Exception.h"
class ServicioDuplicadoException :public Exception
{
public:
	ServicioDuplicadoException() {
		this->mensaje = "Codigo del servicio duplicado";
	}
};