#pragma once
#include "Exception.h"
class PaqueteDuplicado : public Exception
{
public:
	PaqueteDuplicado() {
		this->mensaje = "Paquete duplicado ";
	}
};