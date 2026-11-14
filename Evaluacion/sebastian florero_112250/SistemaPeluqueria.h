#pragma once
#include <iostream>
#include <string>
#include "ListaGenerica.h"
#include "Perro.h"
#include "Servicio.h"
#include "ServicioBano.h"
#include "ServicioCorte.h"
using namespace std;
class SistemaPeluqueria {
private:
	string nombre;
	ListaGenerica<Perro>* listaPerros;
	ListaGenerica<Servicio>* listaServicios;
public:
	SistemaPeluqueria(string nombre) {
		this->nombre = nombre;
		this->listaPerros = new ListaGenerica<Perro>(2);
		this->listaServicios = new ListaGenerica<Servicio>(2);
	}

	//void registrarPerro(Perro* perro) {
		//string codigo = perro->getCodigo();
		//this->listaPerros->agregar(perro);
	//}
};