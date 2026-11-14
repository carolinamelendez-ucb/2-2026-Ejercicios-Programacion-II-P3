#pragma once
#include <iostream>
#include <string>
using namespace std;
template <class T>
class ListaGenerica {
private: 
	int cantidad;
	int capacidad;
	T** opjeto;
public:
	ListaGenerica(int capacidad) {
		this->cantidad = 0;
		this->capacidad = capacidad;
		this->opjeto = new T * [capacidad];

	}
	~ListaGenerica() {

	}
	void registrar(T* nuevo) {
		if (cantidad < capacidad) {

			opjeto[cantidad] = nuevo;
			cantidad++;
		}

	}
	int getcapacidad() {
		return capacidad;
	}
	T* buscar(string criterio, string(*getter)(T*)) {
		for (int i = 0;i < cantidad;i++) {
			if (getter(opjeto[i])==criterio) {
				 return opjeto[i];
			}
		}

		return nullptr;

	}
	void mostrar() {
		for (int i = 0;i < cantidad;i++) {
			 opjeto[i]->mostrar();
		}
	}


};