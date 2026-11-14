#pragma once
#include "Exception.h";
class PerroDuplicadoException :public Exception {
public:
	PerroDuplicadoException():Exception(" ") {
		this->mensaje = " el codigo esta duplicado ";
	}
};