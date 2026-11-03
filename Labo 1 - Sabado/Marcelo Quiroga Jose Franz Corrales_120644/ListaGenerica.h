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
	T** listaElementos;
	float acumulado;
	int sumador;
public:
	ListaGenerica(int capacidad) {
		this->indice = 0;
		this->capacidad = capacidad;
		this->acumulado = 0;
		this->sumador = 0;
		this->listaElementos = new T * [capacidad];
	}

	void agregarElemento(T* nuevoElemento) {
		if (indice < capacidad) {
			listaElementos[indice] = nuevoElemento;
			indice++;
		}
		else {
			//exception
		}
	}

	void mostrarElementos() {
		for (int i = 0; i < indice; i++) {
			listaElementos[i]->mostrarDatos();
			sumador++;
			cout << "---------------------------" << endl;
		}
	}

	void mostrarElementoBuscado(string buscarIdentificador) {
		for (int i = 0; i < indice; i++) {
			if (buscarElementos(buscarIdentificador) == true) {
				listaElementos[i]->mostrarDatos();
			}
		}
	}

	int devolverIndice() {
		return sumador;
	}

	bool buscarElementos(string buscarIdentificador) {
		for (int i = 0; i < indice; i++) {
			if (listaElementos[i]->getIdentificador() == buscarIdentificador) {
				return true;
			}
		}
		return false;
	}

	float acumulador() {
		acumulado = 0;
		for (int i = 0; i < indice; i++) {
			acumulado = acumulado + listaElementos[i]->calcularCosto();
		}
		return acumulado;
	}
};

