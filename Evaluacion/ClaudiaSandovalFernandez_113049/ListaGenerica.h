
#pragma once
#include <iostream>
#include <string>
#include "Exception.h"

using namespace std;

template <class T>

class ListaGenerica
{
private:
	ListaGenerica <T>* listaElementos;
	int capacidad;
	int indice;

public:
	ListaGenerica(int capacidad) {
		this->capacidad = capacidad;
		this->indice = 0;
		this->listaElementos = new  T* [capacidad];
	}

	~ListaGenerica() {
		for (int i = 0; i < capacidad;i++) {
			delete listaElementos;
		}
		delete[]listaElementos
	}

	int getCapacidad() {
		return capacidad;
	}
	int getIndice() {
		return indice;
	}

	void mostrar() {
		for (int i = 0; i < capacidad;i++) {
			cout << listaElementos;
		}
	}

	void agregarElementos(T* nuevoElemento) {
		for (int i = 0; i < capacidad;i++) {
			listaElementos[capacidad] = listaElementos[nuevoElemento];
			capacidad++;
		}
	}

	bool verificarElemento() {
		if (listaElementos->verificarElemento() == nullptr) {
			return false;
		}
		return true;
	}

	T* buscar(string valorBuscado, string(*funtionGetter)(T*)) {
		for (int i = 0; i < capacidad;i++) {
			string valorActual = funtionGetter(listaElementos[i]);
			if (valorActual == valorBuscado) {
				return this->listaElementos[i];
			}
		}
		return nullptr;
	}
};
