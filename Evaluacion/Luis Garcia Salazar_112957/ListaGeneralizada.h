#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class ListaGeneralizada {
private:
    T** elementos;
    int cantidad;
    int capacidad;

public:
    ListaGeneralizada(int capacidad) {
        this->capacidad = capacidad;
        this->cantidad = 0;
        this->elementos = new T * [capacidad];
    }

    ~ListaGeneralizada() {
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

    int getCantidad() {
        return cantidad;
    }

    bool estaVacia() {
        return cantidad == 0;
    }

    T* buscar(string valor, bool (*comparar)(string, T*)) {
        for (int i = 0; i < this->cantidad; i++) {
            if (comparar(valor, this->elementos[i])) {
                return this->elementos[i];
            }
        }
        return nullptr;
    }

    T* obtenerMenor(bool (*comparar)(T*, T*)) {
        T* menor = this->elementos[0];

        for (int i = 1; i < this->cantidad; i++) {
            if (comparar(this->elementos[i], menor)) {
                menor = this->elementos[i];
            }
        }

        return menor;
    }

    void mostrar() {
        for (int i = 0; i < this->cantidad; i++) {
            this->elementos[i]->mostrar();
        }
    }

    void ordenarBurbuja(bool (*comparar)(T*, T*)) {
        for (int i = 0; i < this->cantidad - 1; i++) {
            for (int j = 0; j < this->cantidad - i - 1; j++) {
                if (comparar(this->elementos[j + 1],
                    this->elementos[j])) {
                    T* auxiliar = this->elementos[j];
                    this->elementos[j] = this->elementos[j + 1];
                    this->elementos[j + 1] = auxiliar;
                    }
                }
            }
        }
};

