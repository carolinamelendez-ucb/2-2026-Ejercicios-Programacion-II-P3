#pragma once
#include "Exception.h";
class ServicioNoEncontradoException :public Exception {
public:
	ServicioNoEncontradoException() :Exception(" ") {
		this->mensaje = " el codigo No esta registrado   en el servicio ";
	}
};