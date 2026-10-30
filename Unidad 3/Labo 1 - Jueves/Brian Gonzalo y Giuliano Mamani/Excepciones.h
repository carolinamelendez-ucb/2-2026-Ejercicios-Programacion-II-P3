#pragma once
#include<string>
#include <iostream>
using namespace std;
class Excepciones {
protected:
	string mensaje;
public:
	Excepciones() {
		this->mensaje = "";
	}
	string getMensaje() {
		return	this->mensaje;
	}
};
class CapacidadMaximaEspaciosException : public Excepciones {
public:
	CapacidadMaximaEspaciosException() {
		mensaje = "si se superó la capacidad máxima de espacios permitidos.";
	}
};
class CodigoEspacioDuplicadoException : public Excepciones {
public:
	CodigoEspacioDuplicadoException() {
		mensaje = "si el nuevo espacio tiene un código duplicado con un espacio existente.";
	}
};
class CapacidadMaximaVehiculosException : public Excepciones {
public:
	CapacidadMaximaVehiculosException() {
		mensaje = "si se superó la capacidad máxima de espacios permitidos.";
	}
};
class PlacaDuplicadaException : public Excepciones {
public:
	PlacaDuplicadaException() {
		mensaje = "si el nuevo vehículo tiene una placa duplicada con un vehículo existente.";
	}
};
class VehiculoNoEncontradoException : public Excepciones {
public:
	VehiculoNoEncontradoException() {
		mensaje = "si intenta asignar un vehículo que no existe.";
	}
};
class NoHayEspaciosDisponiblesException : public Excepciones {
public:
	NoHayEspaciosDisponiblesException() {
		mensaje = "si no existen espacios disponibles.";
	}
};
class VehiculoYaAsignadoException : public Excepciones {
public:
	VehiculoYaAsignadoException() {
		mensaje = "si el vehículo ya tiene un espacio asignado.";
	}
};