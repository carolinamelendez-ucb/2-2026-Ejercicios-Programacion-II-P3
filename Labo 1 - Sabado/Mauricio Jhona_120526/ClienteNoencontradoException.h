#pragma once
#include "Exception.h"
class ClienteNoencontradoException : public Exception
{
private:
public:
	ClienteNoencontradoException(){
		this->mensaje = "Ci duplicado";
	}
};