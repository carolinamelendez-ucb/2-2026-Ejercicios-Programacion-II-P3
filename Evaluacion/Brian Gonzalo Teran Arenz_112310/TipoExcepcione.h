#pragma once
#include"Excepciones.h"
class PerroDuplicadoException : public Excepciones {
public:
	PerroDuplicadoException(string codigo) {
		this->mensaje = "El codigo: "+ codigo +" del Perro esta duplicado ";
	}
};
class ServicioDuplicadoException : public Excepciones {
public:
	ServicioDuplicadoException(string codigo) 
	{
		this->mensaje = "El codigo: " + codigo + " del Servicio esta duplicado ";
	}
};
class AtencionDuplicadoException : public Excepciones {
public:
	AtencionDuplicadoException(string codigo)
	{
		this->mensaje = "El codigo: " + codigo + " del Atencion esta duplicado ";
	}
};
class PerroNoEncontradoException : public Excepciones {
public:
	PerroNoEncontradoException() {
		this->mensaje = "El codigo para identificar al  perro no se a encontrado";
	}
};
class ServicioNoEncontradoException : public Excepciones {
public:
	ServicioNoEncontradoException() {
		this->mensaje = "El codigo para identificar al  Servicio no se a encontrado";
	}
};