#include <iostream>
using namespace std;

void leerVector(int* vector, int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> vector[i];
    }
}

void mostrarVector(int* vector, int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        cout << vector[i] << " ";
    }
    cout << endl;
}

double calcularPromedioDinamico(int* vector, int tamanio) {
    int sumatoria = 0;
    for (int i = 0; i < tamanio; i++) {
        sumatoria += vector[i];
    }
    return static_cast<double>(sumatoria) / tamanio; 
}

int main() {
    int numero = 5;
    cout << "Direccion de numero: " << &numero << endl;
    int* punteroANumero = new int(5);
    cout << "Direccion de punteroANumero: " << punteroANumero << endl;
    cout << "Direccion de la variable punteroANumero: " << &punteroANumero << endl;
    int capacidad, tamanio;
    cout << "Ingrese capacidad: ";
    cin >> capacidad;
    cout << "Ingrese tamaño (cantidad de elementos a usar): ";
    cin >> tamanio;
    int* notasDinamicas = new int[capacidad];
    leerVector(notasDinamicas, tamanio);
    mostrarVector(notasDinamicas, tamanio);
    cout << "El promedio es: " << calcularPromedioDinamico(notasDinamicas, tamanio) << endl;
    delete[] notasDinamicas;
    delete punteroANumero;

    return 0;
}
