#pragma once
#include <iostream>
#include <string>

using namespace std;

template<class T>
class ListaGenerica {
private:
	int cantidad;
	int tamanio;

	T** elementos;
public:
	ListaGenerica(int tamanio) {
		this->cantidad = 0;
		this->tamanio = tamanio;
		this->elementos = new T * [tamanio];
	}
	void agregar(T* nuevoElemento) {
		if (tamanio > cantidad) {
			elementos[cantidad] = nuevoElemento;
			cantidad++;
		}

	}
	int getCantidad() {
		return this->cantidad;
	}
	int getTamanio() {
		return this->tamanio;
	}
	T* Buscar(string CodigoBuscado, bool (*getter)(string, T*)  ) {
		for (int i = 0;i < cantidad;i++) {
			//string valorBuscado = getter(elementos[i]);
			/*if (CodigoBuscado == valorBuscado) {
				return elementos[i];
			}*/
			if (getter(CodigoBuscado, elementos[i]) == true) {
				return elementos[i];
			}
		}
		return nullptr;
	}
	void Mostar() {
		for (int i = 0;i < cantidad;i++) {
			elementos[i]->mostrar();
		}
	}
	
};