#pragma once
#include "Perro.h"
#include "Servicio.h"
#include "ServicioBanio.h"
#include "ServicioCorte.h"
#include "Atencion.h"
#include "ListaGenerica.h"

class SistemaPeluqueria
{
private:
	string nombre;
	ListaGenerica<Perro>* listaPerros;
	ListaGenerica<Servicio>* listaServicios;
	ListaGenerica<Atencion>* listaAtenciones;
public:
	SistemaPeluqueria(string nombre);
	void registrarPerro(Perro* nuevoPerro);
	void registrarServicio(Servicio* nuevoServicio);
	void registrarAtencion(string codigoPerro,string codigoServicio);
	void mostrarRegistroPerros();
	void mostrarRegistroServicios();
	void mostrarRegistroAtenciones();
	void mostrarAtencionesPerro(string id);
};

