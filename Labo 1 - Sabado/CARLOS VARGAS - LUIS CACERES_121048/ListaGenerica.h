#pragma once
#include<iostream>
#include<string>
using namespace std;
template<class T>
class ListaGenerica{
private:
	int cantidad;
	int capacidad;
	T** elementos;
public:
	ListaGenerica(int capacidad) {
		this->cantidad = 0;
		this->capacidad = capacidad;
		this->elementos = new T*[this->capacidad];
	}
	int getCantidad() {
		return this->cantidad;
	}
	void agregar(T* nuevo) {
		if (this->cantidad < this->capacidad) {
			this->elementos[this->cantidad] = nuevo;
			this->cantidad++;
		}

	}
	T* obtener(int index) {
		if (index >= 0 && index < this->cantidad) {
			return this->elementos[index];
		}
		return nullptr;
	}
	T* buscar(string valorBuscado, string (*funcionGetter)(T*)) {
		for (int i = 0;i < this->cantidad;i++) {
			if (funcionGetter(this->elementos[i]) == valorBuscado) {
				return this->elementos[i];

			}
		}
		return nullptr;
	}
	void ordenar(bool (*criterio)(T* a,T* b))  {
		for (int i = 0;i < this->cantidad - 1;i++) {
			for (int j = 0;j < cantidad - i - 1;j++) {
				if(criterio(this->elementos[j],this->elementos[j+1])) {
					T* aux = this->elementos[j];
					this->elementos[j] = this->elementos[j+1];
					this->elementos[j + 1] = aux;
				}
			}
		}
	}
	~ListaGenerica() {
		for (int i = 0;i < this->cantidad;i++) {
			delete[]elementos;
		}
	}
};


