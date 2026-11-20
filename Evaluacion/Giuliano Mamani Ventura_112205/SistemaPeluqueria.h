#pragma once
#include"Atencion.h"
#include"ServicioBano.h"
#include"ServicioCorte.h"
#include"ListaGenerica.h"

#include"PerroDuplicadoException.h"
#include"ServicioDuplicadoException.h"
#include"PerroNoEncontradoException.h"
#include"ServicioNoEncontradoException.h"


class SistemaPeluqueria {
private:
	string nombre;
	ListaGenerica<Perro>* listaPerros;
	ListaGenerica<Servicio>* listaServicios;
	ListaGenerica<Atencion>* listaAtenciones;
public:
	SistemaPeluqueria(string nombre) {
		this->nombre = nombre;
		this->listaPerros = new ListaGenerica<Perro>(20);
		this->listaServicios = new ListaGenerica<Servicio>(10);
		this->listaAtenciones = new ListaGenerica<Atencion>(10);
	}
	~SistemaPeluqueria() {
		delete listaPerros;
		delete listaServicios;
		delete listaAtenciones;
	}

	void agregarPerro(Perro* nuevoPerro) {
		try {
			string codigo = nuevoPerro->getCodigo();
			Perro* perroDuplicado = listaPerros->buscar(codigo, Perro::comparar);

			if (perroDuplicado != nullptr) {
				throw PerroDuplicadoException();
			}
			listaPerros->agregar(nuevoPerro);
		}
		catch(Exception error){
			cout << error.getMensaje() << endl;
		}
	}
	void agregarServicio(Servicio* nuevoServicio) {
		try {
			string codigo = nuevoServicio->getCodigo();
			Servicio* servicioDuplicado = listaServicios->buscar(codigo, Servicio::comparar);

			if (servicioDuplicado != nullptr) {
				throw ServicioDuplicadoException();
			}
			listaServicios->agregar(nuevoServicio);
		}
		catch (Exception error) {
			cout << error.getMensaje() << endl;
		}
	}
	void agregarAtencion(string codigoPerro, string codigoServicio, Atencion* nuevaAtencion) {
		try {
			Perro* perroExiste = listaPerros->buscar(codigoPerro, Perro::comparar);
			Servicio* servicioExiste = listaServicios->buscar(codigoServicio, Servicio::comparar);

			if (perroExiste == nullptr) {
				throw PerroNoEncontradoException();
			}
			if (servicioExiste == nullptr) {
				throw ServicioNoEncontradoException();
			}
			if (perroExiste != nullptr && servicioExiste != nullptr) {
				listaAtenciones->agregar(nuevaAtencion);
				nuevaAtencion->asignarPerro(perroExiste);
				nuevaAtencion->asignarServicio(servicioExiste);
			}
		}
		catch (Exception error) {
			cout << error.getMensaje() << endl;
		}
	}

	void mostrarPerro(string codigoPerro) {
		try {
			Perro* perroEncontrado = listaPerros->buscar(codigoPerro, Perro::comparar);

			if (perroEncontrado == nullptr) {
				throw PerroNoEncontradoException();
			}

			perroEncontrado->mostrar();
		}
		catch (Exception error) {
			cout << error.getMensaje() << endl;
		}
	}
	void mostrarTodosPerros() {
		cout << "==========lista de Perros===========" << endl;
		listaPerros->mostrar();
	}
};