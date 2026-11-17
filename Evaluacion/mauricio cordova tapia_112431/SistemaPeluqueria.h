#pragma once
#include <string>
#include <iostream>
#include "Servicio.h"
#include "Perro.h"
#include "ListaGenerica.h"
#include "Atencion.h"
#include "Exception.h"
#include "ExceptionServicioCodigoDuplicado.h"
#include "ExceptionCodigoPerroDuplicado.h"
#include "ExceptionAtencionCodigoRepetido.h"
#include "ExceptionPerroNoEncontrado.h"
#include "ExceptionServicioNoEncontrado.h"
using namespace std;

class SistemaPeluqueria {
private:
	int tamanio;
	string nombre;
	ListaGenerica<Perro>* listaPerro;
	ListaGenerica<Servicio>* listaServicio;
	ListaGenerica<Atencion>* listaAtencion;
public:
	SistemaPeluqueria(int tamanio) {
		this->tamanio = tamanio;
		this->nombre = "Peluqueria Angelito";
		this->listaPerro = new ListaGenerica<Perro>(tamanio);
		this->listaServicio = new ListaGenerica<Servicio>(tamanio);
		this->listaAtencion = new ListaGenerica<Atencion>(tamanio);
	}

	void agregarPerro(Perro* nuevoPerro) {
		try {
			Perro* perroCodigoDuplicado = this->listaPerro->buscar(nuevoPerro->getCodigo(), Perro::getter);
			if (perroCodigoDuplicado != nullptr) {
				throw CodigoPerroDuplicado(nuevoPerro->getCodigo());
			}
			else {
				listaPerro->agregar(nuevoPerro);
			}
		}
		catch(Exception err){
			cout << "Error: " << err.getMensaje() << endl;
		}
	}
	void agregarServicio(Servicio* nuevoServicio) {
		try {
			Servicio* servicioCodigoDuplicado = this->listaServicio->buscar(nuevoServicio->getCodigo(), Servicio::getter);
			if (servicioCodigoDuplicado != nullptr) {
				throw CodigoServicioDuplicado(nuevoServicio->getCodigo());
			}
			else {
				listaServicio->agregar(nuevoServicio);
			}
		}
		catch (Exception err) {
			cout << "Error: " << err.getMensaje() << endl;
		}
	}
	void registrarAtencion(Atencion* nuevaAtencion,string codigoPerro,string codigoServicio) {
		try {
				Perro* perroCodigo = this->listaPerro->buscar(codigoPerro, Perro::getter);
				if (perroCodigo != nullptr) {
					nuevaAtencion->agregarPerro(perroCodigo);
					Servicio* servicioCodigo = this->listaServicio->buscar(codigoServicio, Servicio::getter);
					if (servicioCodigo != nullptr) {
						nuevaAtencion->agregarServicio(servicioCodigo);
						Atencion* atencionCodigoDuplicado = this->listaAtencion->buscar(nuevaAtencion->getCodigo(), Atencion::getter);
						if (atencionCodigoDuplicado != nullptr) {
							throw AtencionCodigoDuplicado(nuevaAtencion->getCodigo());
						}
						else {
							listaAtencion->agregar(nuevaAtencion);
						}
					}
					else {
						throw ServicioNoEncontrado(codigoServicio);
					}
				}
				else {
					throw PerroNoEncontrado(codigoPerro);
				}
			
		}catch (Exception err) {
			cout << "Error: " << err.getMensaje() << endl;
		}
	}

	void buscarPerro(string codigoPerro) {
		try {
			Perro* perroCodigo = this->listaPerro->buscar(codigoPerro, Perro::getter);
			if (perroCodigo != nullptr) {
				//Atencion* atencionCodigoDuplicado = this->listaAtencion->buscar(codigoPerro,Atencion::getterPerro(perroCodigo,codigoPerro));
			}
			else {
				throw PerroNoEncontrado(codigoPerro);
			}
		}
		catch (Exception err) {
			cout << "Error: " << err.getMensaje() << endl;
		}
	}


	void mostrarPerro() {
		listaPerro->mostrar();
		listaServicio->mostrar();
	}

	void mostrarAtenciones() {
		listaAtencion->mostrar();
	}
};