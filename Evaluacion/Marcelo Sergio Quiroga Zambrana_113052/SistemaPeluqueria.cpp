#include "SistemaPeluqueria.h"
#include "Exception.h"
#include "PerroNoEncontradoException.h"
#include "PerroRepetidoException.h"
#include "ServicioNoEncontradoException.h"
#include "ServicioRepetidoException.h"

SistemaPeluqueria::SistemaPeluqueria(string nombre) {
	this->nombre = nombre;
	this->listaPerros = new ListaGenerica<Perro>(10);
	this->listaServicios = new ListaGenerica<Servicio>(10);
	this->listaAtenciones = new ListaGenerica<Atencion>(10);
}

void SistemaPeluqueria::registrarPerro(Perro* nuevoPerro) {
	if (listaPerros->buscarCodigo(nuevoPerro->getCodigo()) == true ) {
		PerroRepetidoException();
	}
	else {
		listaPerros->agregarObjeto(nuevoPerro);
	}
}

void SistemaPeluqueria::registrarServicio(Servicio* nuevoServicio) {
	if (listaServicios->buscarCodigo(nuevoServicio->getCodigo()) == true ) {
		ServicioRepetidoException();
	}
	else {
		listaServicios->agregarObjeto(nuevoServicio);
	}
}

void SistemaPeluqueria::registrarAtencion(string codigoPerro,string codigoServicio) {
	if (listaPerros->buscarCodigo(codigoPerro) == false) {
		PerroNoEncontradoException();
	}
	else if (listaServicios->buscarCodigo(codigoServicio) == false) {
		ServicioNoEncontradoException();
	}

	Perro* nuevoPerro = nullptr;
	Servicio* nuevoServicio = nullptr;

	for (int i = 0; i < listaPerros->getIndice(); i++) {
		if (listaPerros->buscarCodigo(codigoPerro) == true ) {
			nuevoPerro = listaPerros->getObjeto(i);
		}
	}

	for (int j = 0; j < listaServicios->getIndice(); j++) {
		if (listaServicios->buscarCodigo(codigoServicio) == true) {
			nuevoServicio = listaServicios->getObjeto(j);
		}
	}

	Atencion* nuevaAtencion = new Atencion(nuevoPerro, nuevoServicio);
	listaAtenciones->agregarObjeto(nuevaAtencion);
	nuevaAtencion->getCodigo() = nuevaAtencion->getCodigo() + "1";
}

void SistemaPeluqueria::mostrarRegistroPerros() {
	listaPerros->mostrarLista();
}

void SistemaPeluqueria::mostrarRegistroServicios() {
	listaServicios->mostrarLista();
}

void SistemaPeluqueria::mostrarRegistroAtenciones() {
	listaAtenciones->mostrarLista();
}

void SistemaPeluqueria::mostrarAtencionesPerro(string id) {
	listaPerros->mostrarElemento(id);
}
