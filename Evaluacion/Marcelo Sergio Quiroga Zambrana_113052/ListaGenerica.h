#pragma once
#include <iostream>
#include <string>

using namespace std;


template <class T>
class ListaGenerica
{
private:
	int indice;
	int capacidad;
	T** listaObjetos;
public:
	ListaGenerica(int capacidad) {
		this->indice = 0;
		this->capacidad = capacidad;
		this->listaObjetos = new T * [capacidad];
	}

	void agregarObjeto(T* nuevoObjeto) {
		if (indice < capacidad) {
			listaObjetos[indice] = nuevoObjeto;
			indice++;
		}
		else {
			//exception espacio insuficiente
		}
	}

	bool buscarCodigo(string buscarID) {
		for (int i = 0; i < indice; i++) {
			if (listaObjetos[i]->getCodigo() == buscarID) {
				return true;
			}
		}
		return false;
	}

	void mostrarLista() {
		for (int i = 0; i < indice; i++) {
			listaObjetos[i]->mostrarDatos();
		}
	}

	void mostrarElemento(string id) {
		for (int i = 0; i < indice; i++) {
			if (listaObjetos[i]->getCodigo() == id) {
				listaObjetos[i]->mostrarDatos();
			}
		}
	}

	T* getObjeto(int contador) {
		return listaObjetos[contador];
	}

	int getIndice() {
		return indice;
	}
};

