#pragma once
#pragma once
#include "Exception.h"
class  PesomaxException : public Exception
{
public:
	PesomaxException() {
		this->mensaje = "peso excedido permitido en el envio";
	}
};