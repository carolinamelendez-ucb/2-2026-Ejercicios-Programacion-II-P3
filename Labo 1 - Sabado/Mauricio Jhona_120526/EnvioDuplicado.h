#pragma once
#include "Exception.h"
class EnvioDuplicado : public Exception
{
public:
	EnvioDuplicado() {
		this->mensaje = "Codigo de envio duplicado";
	}
};