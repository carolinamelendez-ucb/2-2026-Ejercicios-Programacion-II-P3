#pragma once
#include <string>
#include <iostream>
#include "Paquete.h"
#include "Cliente.h"
using namespace std;
template <class T>
class ListaGenerica {
private:
	int tam;
	int indice;
	T** lista;
public:
	ListaGenerica(int tam) {
		this->indice = 0;
		this->tam = tam;
		this->lista = new T * [tam];
	}
	void agregar(T* nuevo) {
		if (tam > indice) {
			lista[indice] = nuevo;
			indice++;
		}
	}
	void mostrar() {
		for (int i = 0;i < indice;i++) {
			this->lista[i]->mostrar();
		}
	}
	float total() {
		float costos=0;
		for (int i = 0;i < indice;i++) {
			costos = costos + lista[i]->costoFinal();
		}
		return costos;
	}
	T* buscar(string datoAbuscar, bool(*funcionGetter)(T*, string)) {
		T* pp=nullptr;
		for (int i = 0;i < indice;i++) {
			if (funcionGetter(this->lista[i], datoAbuscar)) {
				pp = this->lista[i];
			}
		}
		return pp;
	}


};