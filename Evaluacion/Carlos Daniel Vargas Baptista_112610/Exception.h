#pragma once
#include<iostream>
#include<string>
using namespace std;

class Exception{
protected:
	string mensaje;
public:
	Exception() {
		this->mensaje = "";
	}
	string getMensaje() {
		return this->mensaje;
	}
};
class PerroDuplicadoException :public Exception{
public:
	PerroDuplicadoException(string codigo) {
		this->mensaje = "El perro con codigo " + codigo + " ya esta registrado (duplicado)";
	}
};
class ServicioDuplicadoException : public Exception {
public:
	ServicioDuplicadoException(string codigoServicio) {
		this->mensaje = "El servicio con el codigo " + codigoServicio + " ya esta registrado (duplicado)";

	}
};
class ServicioNoEncontradoException : public Exception {
public:
	ServicioNoEncontradoException(string codigoServicio) {
		this->mensaje = "El servicio con el codigo " + codigoServicio + " no esta registrado";
	}
};
class PerroNoEncontradoException :public Exception {
public:
	PerroNoEncontradoException(string codigo) {
		this->mensaje = "El perro con el codigo " + codigo + " No esta registrado";
	}
};