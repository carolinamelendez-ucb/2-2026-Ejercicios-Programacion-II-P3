#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class ListaGenerica {
private:
	int cantidad;
	int capacidad;
	T** elementos;
public:
	ListaGenerica(int capacidad) {
		this->cantidad = 0;
		this->capacidad = capacidad;
		this->elementos = new T * [capacidad];
	}

	~ListaGenerica() {
		for (int i = 0; i < cantidad; i++) {
			delete elementos[i];
		}
		delete[] elementos;
	}

	void agregar(T* nuevoElemento) {
		if (this->cantidad < this->capacidad) {
			this->elementos[cantidad] = nuevoElemento;
			this->cantidad++;
		}
	}

	void mostrar() {
		for (int i = 0; i < this->cantidad; i++) {
			this->elementos[i]->mostrar();
		}
	}

	int getCantidad() {
		return cantidad;
	}

	T* getElementoEn(int i) {
		if (i >= 0 && i < cantidad) {
			return elementos[i];
		}
		return nullptr;
	}

	T* buscar(string valorBuscado, string(*functionGet)(T*)) {
		for (int i = 0; i < this->cantidad; i++) {
			string valorActual = functionGet(this->elementos[i]);
			if (valorActual == valorBuscado) {
				return this->elementos[i];
			}
		}
		return nullptr;
	}

	
};