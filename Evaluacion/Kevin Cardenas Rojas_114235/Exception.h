#pragma once
#include<iostream>
#include<string>

using namespace std;

class Exception {
protected:
	string mensaje;
public:
	Exception() {
		this->mensaje = "";

	}
	virtual ~Exception(){}

	string getMensaje() {
		return this->mensaje;
	}

};

class PerroDuplicadoException :public Exception {
public:
	PerroDuplicadoException()
	{
		this->mensaje = "Perro Duplicado";
}
};

class ServicioDuplicadoException : public Exception {
public:
	ServicioDuplicadoException(){
		this->mensaje = "Servicio Duplicado";
	}
};



class ServicioNoEncontradoException : public Exception {
public:
	ServicioNoEncontradoException() {
		this->mensaje = "Servicio no enontrado";
	}



};

class PerroNoEncontradoException:public Exception {
public:
	PerroNoEncontradoException()
	{
		this->mensaje = "Perro no encontrado";
	}
};


