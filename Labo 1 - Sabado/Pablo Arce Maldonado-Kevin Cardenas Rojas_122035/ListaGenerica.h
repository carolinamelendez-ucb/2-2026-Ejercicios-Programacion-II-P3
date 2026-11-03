#pragma once
#include <iostream>
#include <string>
using namespace std;



template <class T>
class ListaGenerica {
private:
    int cantidad;
    int capacidad;
    T** elementos;

public:
    ListaGenerica(int capacidad) {
        this->cantidad = 0;
        this->capacidad = capacidad;
        this->elementos = new T * [capacidad];
    }

    ~ListaGenerica() {
        for (int i = 0; i < cantidad; i++) {
            delete elementos[i];
        }
        delete[] elementos;
    }

    int getCantidad() { 
        return this->cantidad; 
    }
    bool estaLlena() { 
        return this->cantidad >= this->capacidad; 
    }
    T* obtener(int indice) { 
        return this->elementos[indice]; 
    }

    void agregar(T* nuevoElemento) {
        if (this->cantidad < this->capacidad) {
            this->elementos[cantidad] = nuevoElemento;
            this->cantidad++;
        }
    }

    void mostrar() {
        for (int i = 0; i < this->cantidad; i++) {
            this->elementos[i]->mostrar();
        }
    }

    T* buscar(int valorBuscado, int (*getter) (T*)) {
        for (int i = 0; i < this->cantidad; i++) 
        {
            if (getter(this->elementos[i]) == valorBuscado) {
                return this->elementos[i];
            }
        }
        return nullptr;
    }
};