
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

    void agregar(T* elemento) {
        if (estaLlena()) {
            throw runtime_error("La lista esta llena");
        }
        elementos[cantidad] = elemento;
        cantidad++;
    }

    template <class D>
    T* buscar(D valor, bool (*comparar)(T*, D)) {
        for (int i = 0; i < cantidad; i++) {
            if (comparar(elementos[i], valor)) {
                return elementos[i];
            }
        }
        return nullptr;
    }

    template <class D>
    int mostrarFiltrados(D valor, bool (*comparar)(T*, D)) {
        int encontrados = 0;
        for (int i = 0; i < cantidad; i++) {
            if (comparar(elementos[i], valor)) {
                elementos[i]->mostrar();
                encontrados++;
            }
        }
        return encontrados;
    }



    void ordenar(bool (*vaAntes)(T*, T*)) {
        for (int i = 0; i < cantidad - 1; i++) {
            for (int j = 0; j < cantidad - 1 - i; j++) {
                if (vaAntes(elementos[j + 1], elementos[j])) {
                    T* auxiliar = elementos[j];
                    elementos[j] = elementos[j + 1];
                    elementos[j + 1] = auxiliar;
                }
            }
        }
    }

    void mostrarOrdenados(bool (*vaAntes)(T*, T*)) {
        if (cantidad == 0) {
            cout << "No hay elementos registrados" << endl;
            return;
        }

        ListaGenerica<T> copia(capacidad);
        for (int i = 0; i < cantidad; i++) {
            copia.agregar(elementos[i]);
        }
        copia.ordenar(vaAntes);
        copia.mostrarTodos();
    }

    void mostrarTodos() {
        for (int i = 0; i < cantidad; i++) {
            elementos[i]->mostrar();
        }
    }


};
