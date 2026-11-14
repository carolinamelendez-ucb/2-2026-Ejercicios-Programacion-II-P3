#pragma once
#include "Exception.h"
class PerroNoEncontradoException :public Exception {
public:
	PerroNoEncontradoException() :Exception("") {
	this->mensaje = " el codigo no existe :";
}

};