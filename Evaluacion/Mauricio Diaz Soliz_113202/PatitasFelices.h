#pragma once
#include "ListaGenerica.h"
#include "Perro.h"
#include "PerroDuplicadoException.h"
#include "ServicioDuplicadoException.h"
#include "Servicio.h"
#include "Atencion.h"
#include "ServicioNoEncontradoException.h"
#include "PerroNoEncontradoException.h"
class PatitasFelices
{
private:
	ListaGenerica<Perro>* perros;
	ListaGenerica<Servicio>* servicios;	
	ListaGenerica<Atencion>* atenciones;
public:
	PatitasFelices(int cantMaxperros,int cantMaxservicios,int antMaxatenciones) {
		perros = new ListaGenerica<Perro>(cantMaxperros);
		servicios = new ListaGenerica<Servicio>(cantMaxservicios);
		atenciones = new ListaGenerica<Atencion>(antMaxatenciones);
	}
	~PatitasFelices(){}
	void RegistrarPerros(Perro* nuevoperro) {
		string codperro = nuevoperro->getcodigo();
		try {
			Perro* perro = perros->Buscar(codperro, Perro::getCodigostatico);
			if (perro != nullptr) {
				throw PerroDuplicadoException();
			}
			else {
				perros->Registrar(nuevoperro);
			}
		}
		catch (Exception& err) {
			cout << "Error: " << err.getError();
		}
	}
	void Mostrarperro() {
		perros->Mostrar();
	}
	void Registrarservicios(Servicio* nuevoservicio) {
		string idservicio = nuevoservicio->getcodigo();
			try {
				Servicio* servicio = servicios->Buscar(idservicio, Servicio::getcodigoStatic);
				if (servicio != nullptr) {
					throw ServicioDuplicadoException();
				}
				else {
					servicios->Registrar(nuevoservicio);
				}
			}
			catch (Exception& err) {
				cout << "Error: " << err.getError();
			}
	}
	void MostrarServicios() {
		servicios->Mostrar();
	}
	void RegistraraTENCION(string codperro,string codservicio) {
		float costo = 0;
		try {
			Perro* perro = perros->Buscar(codperro, Perro::getCodigostatico);
			if (perro == nullptr) {
				throw PerroNoEncontradoException();
			}
			Servicio* servicio = servicios->Buscar(codservicio, Servicio::getcodigoStatic);
			
			if (servicio == nullptr) {
				throw ServicioNoEncontradoException();
			}

			costo = costo + servicio->getcosto();
			Atencion* atencion = new Atencion("222", perro, servicio,costo);
			atenciones->Registrar(atencion);
		}
		catch (Exception err) {
			cout << "Error: " << err.getError();
		}
	}
	void MostrarAtencion(){
		atenciones->Mostrar();
	}
	void mostraratencionesDeUnperro(string codperro) {
		try {
			Perro* perro = perros->Buscar(codperro, Perro::getCodigostatico);
			if (perro != nullptr) {
				//perro->Mostrar();
			}
			else {
				throw PerroNoEncontradoException();
			}
			Atencion* atencion = atenciones->MostrarConCondicion(codperro, Atencion::getperroidstatic);
	
		}
		catch (Exception& err) {
			cout << "Error: " << err.getError();
		}
		

	}
};