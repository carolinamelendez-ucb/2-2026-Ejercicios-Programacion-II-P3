#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class ListaGenerica {
private:
	int cant;
	int cap;
	T** elementos;
public:
	ListaGenerica(int cap) {
		this->cant = 0;
		this->cap = cap;
		this->elementos = new T * [cap];
	}
	~ListaGenerica() {
		for (int i = 0;i < cant;i++) {
		delete elementos[i];
	}
		delete[] elementos;
	}

	void agregar(T* elemeto) {
		if (this->cant < this->cap) {
		for (int i = 0;i < cant;i++) {
			elementos[cant]->elemento;
			this->cant++;
		}
	}
	}
		int getCant(){
			return this->cant;
		}
		T* buscar(int valor, bool(*comparar)(string, T*)) {
			for (int i = 0;i < cant;i++) {
				comparar(valor,elementos[i]);
				return this->elementos[i];
			}
			return nullptr;
	}


};