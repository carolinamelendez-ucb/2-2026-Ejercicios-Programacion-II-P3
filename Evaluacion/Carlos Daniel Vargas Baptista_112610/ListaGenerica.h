#pragma once
#include<iostream>
#include<string>
using namespace std;

template <class T>
class ListaGenerica{
private:
	int cantidad;
	int capacidad;
	T** elementos;
public:
	ListaGenerica(int capacidad){
		this->cantidad = 0;
		this->capacidad = capacidad;
		this->elementos = new T * [this->capacidad];
	}
    int getCantidad() { return this->cantidad; }

    void agregar(T* nuevo) {
        if (this->cantidad < this->capacidad) {
            this->elementos[this->cantidad] = nuevo;
            this->cantidad++;
        }
    }

    T* buscar(string valorBuscado, string(*functionGetter)(T*)) {
        for (int i = 0; i < this->cantidad; i++) {
            if (functionGetter(this->elementos[i]) == valorBuscado) {
                return this->elementos[i];
            }
        }
        return nullptr;
    }
    void mostrar() {
        for (int i = 0; i < this->cantidad; i++) {
            this->elementos[i]->mostrar();
        }
    }

    ~ListaGenerica() {
        for (int i = 0;i < this->cantidad;i++) {
            delete elementos[i];
        }
        delete[] elementos;
    }
};

