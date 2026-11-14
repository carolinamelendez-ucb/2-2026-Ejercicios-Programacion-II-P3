#pragma once
#pragma once
#include "Exception.h";
class ServicioDuplicadoException :public Exception {
public:
	ServicioDuplicadoException() :Exception(" ") {
		this->mensaje = " el codigo esta duplicado del servicio ";
	}
};