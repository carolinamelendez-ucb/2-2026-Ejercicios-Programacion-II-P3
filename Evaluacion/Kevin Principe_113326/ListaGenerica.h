#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class ListaGenerica
{
private:
	int cantidad;
	int capacidad;
	T** elementos;
public:
	ListaGenerica() {
		this->cantidad = 0;
		this->capacidad = 3;
		this->elementos = new T * [capacidad];
	}

	~ListaGenerica() {}

	void agregar(T* nuevoElemento) {
			elementos[cantidad] = nuevoElemento;
			cantidad++;
	}

	bool verificarCodigos(string codigoAVerificar) {
		for (int i = 0; i < cantidad;i++) {
			if (elementos[i]->getCodigo() == codigoAVerificar) {
				return true;
			}
		}	return false;
	}

	void mostrar() {
		for (int i = 0;i < cantidad;i++) {
			cout << "===========================" << endl;
			elementos[i]->mostrar();
		}
	}

	int getCantidad() {
		return cantidad;
	}

	int getCapacidad() {
		return capacidad;
	}
};

