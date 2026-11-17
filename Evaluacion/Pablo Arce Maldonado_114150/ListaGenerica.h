#pragma once
#include <iostream>
#include <string>

using namespace std;
template <typename T>
class ListaGenerica {
private:
    T** elementos;
    int cantidad;
    int capacidad;

public:
    ListaGenerica(int capacidad) {
        this->capacidad = capacidad;
        this->cantidad = 0;
        this->elementos = new T * [capacidad];
    }

    ~ListaGenerica() {
        for (int i = 0; i < cantidad; i++) {
            delete elementos[i];
        }
        delete[] elementos;
    }

    void agregar(T* elemento) {
        if (this->cantidad < this->capacidad) {
            elementos[cantidad] = elemento;
            this->cantidad++;
        }
    }

    int getCantidad() { return cantidad; }

    T* buscar(string valor, bool (*comparar)(string, T*)) {
        for (int i = 0; i < this->cantidad; i++) {
            if (comparar(valor, this->elementos[i])) {
                return this->elementos[i];
            }
        }
        return nullptr;
    }

 

    /*void ordenarBurbuja(bool (*comparar)(T*, T*)) {
        for (int i = 0; i < this->cantidad - 1; i++) {
            for (int j = 0; j < this->cantidad - i - 1; j++) {
                if (comparar(this->elementos[j + 1], this->elementos[j])) {
                    T* auxiliar = this->elementos[j];
                    this->elementos[j] = this->elementos[j + 1];
                    this->elementos[j + 1] = auxiliar;
                }
            }
        }
    }*/

    void mostrar() {
        for (int i = 0; i < this->cantidad; i++) {
            this->elementos[i]->mostrar();
        }
    }
};