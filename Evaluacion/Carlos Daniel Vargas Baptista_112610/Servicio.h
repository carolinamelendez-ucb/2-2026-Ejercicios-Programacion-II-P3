#pragma once
#include<iostream>
#include<string>
using namespace std;

class Servicio{
protected:
	string codigoServicio;
	string nombre;
	string tipo;
public:
	Servicio(string codigoServicio, string nombre, string tipo) {
		this->codigoServicio = codigoServicio;
		this->nombre = nombre;
		this->tipo = tipo;
	}
	string getCodigoServicio() {
		return this->codigoServicio;
	}
	string getNombre() {
		return this->nombre;
	}
	static string getterCodigoServicio(Servicio* s) {
		return s->codigoServicio;
	}
};
class ServicioBano:public Servicio {
private:
	float costoProductos;
public:
	ServicioBano(string codigo, string nombre, float costoProductos)
		:Servicio(codigo, nombre, "Banio") {
		this->costoProductos = costoProductos;
	}
};
class ServicioCorte : public Servicio {
private:
	float costoCorte;
public:
	ServicioCorte(string codigo, string nombre, float costoCorte)
		:Servicio(codigo, nombre, "Corte") {
		this->costoCorte = costoCorte;
	}
};