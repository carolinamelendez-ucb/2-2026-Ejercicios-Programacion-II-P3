#pragma once
#include <iostream>
#include <string>
#include "Atencion.h"
#include "Exception.h"
#include "ListaGenerica.h"
#include "Perro.h"
#include "ServicioBano.h"
#include "SistemaPeluqueria.h"
using namespace std;

class SistemaPeluqueria
{
private:
	string nombre;

public:
	SistemaPeluqueria(string nombre);
	~SistemaPeluqueria();
	void RegistrarPerro();
	void RegistrarServicio();
	void RegistarAtencion();
	void MostrarAtenciones();
};