#pragma once
#include "Exception.h"

class PerroDuplicadoException : public Exception{
public:
	PerroDuplicadoException() : Exception(){
		mensaje = "codigo del perro ya existe";
	}
};