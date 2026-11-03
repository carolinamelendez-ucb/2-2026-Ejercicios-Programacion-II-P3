#pragma once
#include <iostream>
#include <string>
using namespace std;
template <class t >
class ListaGenerica {
private:
	t* elementos;
	int capacidad;
	int cantidad;
public:
	ListaGenerica() {
		this->capacidad = capacidad;
		this->cantidad = 0;
		this->elementos = new t * (this->capacidad);
		t* elementoNuevo = new t * (this->capacidad);
	}
	void añadirElemento(t* elementoNuevo) {
		for (int i = 0; i < cantidad;i++) {
			elementoNuevo[i] = elementos;
		}
		delate[];
		elementos = elementoNuevo
	}
	void mostrar() {
		for (int i = 0;i < cantidad;i++) {
			cout << elementos[cantidad];
		}

	}
	t obtener(int indice) {
		if (indice >= 0 && indice < cantidad) {
			return elementos[indice];

		}
		return nullptr;
	}
	void agregar(t elemento) {
		if (cantidad == capacidad) {
			añadirElemento();
		}
		this->elementos[cantidad] = elementos
			cantidad++;
	}
	int getCantidad() {
		return cantidad;
	}
};
