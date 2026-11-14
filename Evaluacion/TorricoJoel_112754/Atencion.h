#pragma once
#include"Perro.h"
#include"Servicio.h"
class Atencion
{
private:
	string codigo;
	Perro* perro;
	Servicio* servicio;
	float costoFinal;
public:
	Atencion(string codigo) {
		this->codigo = codigo;
		this->perro = nullptr;
		this->servicio = nullptr;
		this->costoFinal = 0;
	}
	void agregarPerro(Perro* nuevoPerro) {
		this->perro = nuevoPerro;
	}
	void agregarServicio(Servicio* nuevoServicio) {
		this->servicio = nuevoServicio;
	}
	void mostrarCostoFinal() {
		this->costoFinal = this->servicio->totalServicio();
		if (this->perro->getTamanio() == "GRANDE") {
			this->costoFinal=this->costoFinal + 15;
		}
		cout << "el costo final es: " << this->costoFinal << endl;
	}
	string getCodigo() {
		return codigo;
	}
	Perro* getPerro() {
		return perro;
	}
	static bool compararCodigoAtencion(Atencion* atencion, string codigo) {
		return atencion->getCodigo() == codigo;
	}
	static bool mostrarAtencionesPerro(Atencion* atencion, string codigo) {
		return atencion->getPerro()->getCodigo() == codigo;
	}
	void mostrar() {
		cout << endl;
		cout << "servicicos del perro con codigo: "<<perro->getCodigo() << endl;
		servicio->mostrar();
		mostrarCostoFinal();
	}
};

