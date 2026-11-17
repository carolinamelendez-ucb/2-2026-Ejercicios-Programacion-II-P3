#pragma once
#include "ListaGenerica.h"
#include "Atencion.h"
#include "CapacidadMaximaException.h"
#include "PerroDuplicadoException.h"
#include "ServicioDuplicadoException.h"

class SistemaPeluqueria
{
private:
	string nombre;
	ListaGenerica<Perro> perros;
	ListaGenerica<Servicio> servicios;
	ListaGenerica<Atencion> atenciones;
public:
	SistemaPeluqueria(string nombre) {
		this->nombre = nombre;
	}

	void agregarPerroAlSistema(Perro* nuevoPerro) {
		try {
			if (perros.getCantidad() >= perros.getCapacidad()) {
				throw CapacidadMaximaException();
				delete nuevoPerro;

			} if (perros.verificarCodigos(nuevoPerro->getCodigo()) == true) {
				throw PerroDuplicadoException();
				delete nuevoPerro;
			}
			else {
				perros.agregar(nuevoPerro);
			}
		}
		catch (Exception& err) {
			cout << err.getMensaje() << endl;
		}
	}

	void agregarServicioAlSistema(Servicio* nuevoServicio) {
		try {
			if (servicios.getCantidad() >= servicios.getCapacidad()) {
				throw CapacidadMaximaException();
				delete nuevoServicio;

			} if (servicios.verificarCodigos(nuevoServicio->getCodigo()) == true) {
				throw ServicioDuplicadoException();
				delete nuevoServicio;
			}
			else {
				servicios.agregar(nuevoServicio);
			}
		}
		catch (Exception& err) {
			cout << err.getMensaje() << endl;
		}
	}

	void agregarAtencionAlSistema(Atencion* nuevaAtencion) {
		try {
			if (atenciones.getCantidad() >= atenciones.getCapacidad()) {
				throw CapacidadMaximaException();
				delete nuevaAtencion;

			} if (atenciones.verificarCodigos(nuevaAtencion->getCodigo()) == true) {
				throw PerroDuplicadoException();
				delete nuevaAtencion;
			}
			else {
				atenciones.agregar(nuevaAtencion);
			}
		}
		catch (Exception& err) {
			cout << err.getMensaje() << endl;
		}
	}

	void mostrarSistema() {
		cout << "PERROS REGISTRADOS" << endl;
		perros.mostrar();
		cout << "SERVICIOS REGISTRADOS" << endl;
		servicios.mostrar();
		cout << "/////////////////ATENCIONES REGISTRADAS////////////////" << endl;
		atenciones.mostrar();
	}
};

