#pragma once
#include <iostream>
#include<string>
using namespace std;
template<class T>
class ListaGenerica {
private:
    int cant;
    int tam;
    T** elementos;
public:
    ListaGenerica(int tam)
    {
        this->cant = 0;
        this->tam = tam;
        this->elementos = new T * [tam];
    }

    void Agregar(T* nuevoelemento) {
        if (cant < tam) {
            elementos[cant] = nuevoelemento;
            cant++;
        }
    }
    ~ListaGenerica() {
        for (int i = 0;i < cant;i++) {
            delete elementos[i];
        }
        delete[] elementos;
    }
  
    T* Buscar(string ci, bool(*Comparar)(string, T*)) {
        for (int i = 0;i < cant;i++) {
            if (Comparar(ci,elementos[i])) {
                return elementos[i];
            }
        }
        return nullptr;
    }
   
    void Mostrar() {
        for (int i = 0;i < cant;i++) {
            cout << endl;
           elementos[i]->Mostrar();
        }
    }

};