#pragma once
#include <iostream>
#include <string>
using namespace std;

template<class T>
class ListaGenerica {
private:
	int cantidad;
	int capacidad;

	T** elementos;
public:
	ListaGenerica(int capacidad) {
		this->capacidad = capacidad;
		this->cantidad = 0;
		this->elementos = new T * [capacidad];
	}
	~ListaGenerica() {
		for (int i = 0; i < this->cantidad; i++) {
			delete elementos[i];
		}
		delete[] elementos;
	}
	void agregar(T* nuevoElemento) {
		if (this->cantidad < this->capacidad) {
			this->elementos[cantidad] = nuevoElemento;
			cantidad++;
		}
	}
	int getCantidad() {
		return cantidad;
	}
	T* buscar(string codigo, bool (*compararCodigo)(string, T*)) {
		for (int i = 0; i < this->cantidad; i++) {
			if (compararCodigo(codigo, this->elementos[i])) {
				return elementos[i];
			}
		}
		return nullptr;
	}
	void mostrar() {
		for (int i = 0; i < this->cantidad; i++) {
			this->elementos[i]->mostrar();
		}
	}
};