#pragma once
#include <string>
#include <iostream>
using namespace std;
template <class T>
class ListaGenerica {
private:
	int tamanio;
	int indice;
	T** lista;
public:
	ListaGenerica(int tamanio){
		this->tamanio = tamanio;
		this->indice = 0;
		this->lista = new T*[tamanio];
	}

	void agregar(T* nuevo) {
		if (tamanio > indice) {
			this->lista[indice] = nuevo;
			indice++;
		}
	}
	void mostrar() {
		for (int i = 0;i < indice;i++) {
			lista[i]->mostrar();
		}
	}

	T* buscar(string codigo, bool (*funciongetter)(T*, string)) {
		T* pp = nullptr;
		for (int i = 0;i < indice;i++) {
			if (funciongetter(lista[i], codigo)) {
				pp = lista[i];
			}
		}
		return pp;
	}

};