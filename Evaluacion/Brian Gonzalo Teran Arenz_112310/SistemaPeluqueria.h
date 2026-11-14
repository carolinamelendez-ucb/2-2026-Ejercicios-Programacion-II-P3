#pragma once
#include"Atencion.h"
#include"ListaGenerica.h"
#include"TipoExcepcione.h"
class SistemaPeluqueria {
private:
	string nombre;
	ListaGenerica<Perro>* ListaP;
	ListaGenerica<Servicio>* ListaS;
	ListaGenerica<Atencion>* ListaA;
public:
	SistemaPeluqueria(const string& nombre)
	{
		this->nombre = nombre;
		this->ListaP = new ListaGenerica<Perro>(25);
		this->ListaS = new ListaGenerica<Servicio>(25);
		this->ListaA = new ListaGenerica<Atencion>(10);
	}
	void AgregarPerro(Perro* nuevoPerro) {
		try {
			string codigoP = nuevoPerro->getCodigo();
			Perro* PerroDuplicado = ListaP->Buscar(codigoP, Perro::Comparar);
			if (PerroDuplicado != nullptr) {
				throw PerroDuplicadoException(codigoP);
			}
			ListaP->Agregar(nuevoPerro);
		}
		catch (Excepciones* err) {
			err->getMensaje();
		}
	}
	void AgregarServicio(Servicio* nuevoServicio) {
		try {
			string codigoS = nuevoServicio->getCodigo();
			Servicio* ServicioDuplicado = ListaS->Buscar(codigoS, Servicio::Comparar);
			if (ServicioDuplicado != nullptr) {
				throw ServicioDuplicadoException(codigoS);
			}
			ListaS->Agregar(nuevoServicio);
		}
		catch (Excepciones err) {
			err.getMensaje();
		}
	}
	void AsignarServicioyPerroaAtencion(string codigoS,string codigoP,string codigoA) {
		try {
			Servicio* ServicioEncontrado = ListaS->Buscar(codigoS, Servicio::Comparar);
			Perro* PerroEncontrado = ListaP->Buscar(codigoP, Perro::Comparar);
			Atencion* Atencion = ListaA->Buscar(codigoA, Atencion::Comparar);
			if (ServicioEncontrado == nullptr) {
				throw ServicioNoEncontradoException();
			}
			if (PerroEncontrado == nullptr) {
				throw PerroNoEncontradoException();
			}
			Atencion->AgregarServicioyPerroaAtencion(ServicioEncontrado, PerroEncontrado);
		}
		catch (Excepciones* err) {
			err->getMensaje();
		}
		

	}
	void BuscarInformacionDeUnSoloPerro(string codigo) {
		try {
			Perro* PerroEncontrado = ListaP->Buscar(codigo, Perro::Comparar);
			if (PerroEncontrado == nullptr) {
				throw ServicioNoEncontradoException();
			}
			PerroEncontrado->Mostrar();

		}
		catch (Excepciones* err) {
			err->getMensaje();
		}
		
	}
	void AgregarAtencion(Atencion* nuevaAtencion) {
		try {
			string codigoA = nuevaAtencion->getCodigo();
			Atencion* AntencionDuplicada = ListaA->Buscar(codigoA, Atencion::Comparar);
			if (AntencionDuplicada != nullptr) {
				throw AtencionDuplicadoException(codigoA);
			}
			ListaA->Agregar(nuevaAtencion);
		}
		catch (Excepciones* err) {
			err->getMensaje();
		};
	}
	void MostrarAtencion() {
		ListaA->Mostrar();
	}
	void Mostar() {
		ListaP->Mostrar();
		ListaS->Mostrar();
	}
};