#pragma once
#include <iostream>
#include <string>
#include "Perro.h"
#include "Servicio.h"
#include "ListaGenerica.h"
#include "Atencion.h"

using namespace std;

class SistemaPeluqueria
{
private:
	string nombre;
	ListaGenerica<Perro>* elementosPerro;
	ListaGenerica<Servicio>* elementosServicio;
	ListaGenerica<Atencion>* elementosAtencion;
public:
	SistemaPeluqueria(string nombre) {
		this->nombre = nombre;
		this->elementosPerro = new ListaGenerica<Perro>(10);
		this->elementosServicio = new  ListaGenerica<Servicio>(10);
		this->elementosAtencion = new  ListaGenerica<Atencion>(10);
	}
	~SistemaPeluqueria() {

	}

	void registrarPerro(Perro* nuevoPerro) {
		try {
			if (elementosPerro->agregarElementos(nuevoPerro) =! nullptr) {
				
			}
		}
	}

	void registrarServicio(Servicio* nuevoServicio) {
		try {
			if (elementosServicio->agregarElementos()== true) {

			}
		}
	}

	void registrarAtencion(Atencion* nuevaAtencion) {
		try {
			if (elementosAtencion->agregarElementos() == true) {

			}
		}
	}

};

