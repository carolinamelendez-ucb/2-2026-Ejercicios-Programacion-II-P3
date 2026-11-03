#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <class T>
class ListaGenerica {
private:
    T** elementos;
    int cantidad;
    int capacidad;

public:
    ListaGenerica(int capacidad) {
        if (capacidad <= 0) {
            throw runtime_error("La capacidad debe ser mayor que cero");
        }
        this->capacidad = capacidad;
        this->cantidad = 0;
        this->elementos = new T * [capacidad];
    }

    ~ListaGenerica() {
        delete[] elementos;
    }

    bool estaLlena() {
        return cantidad >= capacidad;
    }

    void agregar(T* nuevoElemento) {
        if (estaLlena()) {
            throw runtime_error("La lista esta llena");
        }
        elementos[cantidad] = nuevoElemento;
        cantidad++;
    }

    T* buscar(string valor, bool (*comparar)(T*, string)) {
        for (int i = 0; i < cantidad; i++) {
            if (comparar(elementos[i], valor)) {
                return elementos[i];
            }
        }
        return nullptr;
    }

    void mostrar() {
        for (int i = 0; i < cantidad; i++) {
            elementos[i]->mostrar();
            cout << endl;
        }
    }

    void ordenar(bool (*esMayor)(T*, T*)) {
        for (int i = 0; i < cantidad - 1; i++) {
            for (int j = 0; j < cantidad - 1 - i; j++) {
                if (esMayor(elementos[j], elementos[j + 1])) {
                    T* aux = elementos[j];
                    elementos[j] = elementos[j + 1];
                    elementos[j + 1] = aux;
                }
            }
        }
    }
    double calcularTotal() {
        double total = 0;

        for (int i = 0; i < cantidad; i++) {
            total += elementos[i]->calcularCosto();
        }

        return total;
    }

};
