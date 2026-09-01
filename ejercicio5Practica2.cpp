// ejercicio5Practica2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;

class Carrera {
private:
    string nombre;
    int duracionAnios;
    bool cupoDisponible;

public:
    Carrera() {}
    Carrera(string nombre, int duracionAnios, bool cupoDisponible) {
        this->nombre = nombre;
        this->duracionAnios = duracionAnios;
        this->cupoDisponible = cupoDisponible;
    }

    string getNombre() { return nombre; }
    int getDuracionAnios() { return duracionAnios; }
    bool getCupoDisponible() { return cupoDisponible; }

    void mostrar() {
        cout << "Carrera: " << nombre<< endl;
        cout << " Duracion: " << duracionAnios << " anos"<< endl;
        cout << " Cupo: " << (cupoDisponible ? "Disponible" : "Agotado") << endl;
    }
};

class Estudiante {
private:
    string nombre;
    int edad;
    Carrera* carrera; 

public:
    Estudiante(string nombre, int edad, Carrera* carrera) {
        this->nombre = nombre;
        this->edad = edad;
        this->carrera = carrera;
    }

    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    Carrera* getCarrera() { return carrera; }

    bool puedeInscribirse() {
        return (edad >= 18) && (carrera != nullptr && carrera->getCupoDisponible());
    }

    void mostrar() {
        cout << "Estudiante: " << nombre << " | Edad: " << edad << " anos" << endl;
        if (carrera != nullptr) {
            carrera->mostrar();
        }
    }
};

class ListaEstudiantes {
private:
    Estudiante** estudiantes; 
    int capacidad;
    int cantidad;

public:
    ListaEstudiantes(int capacidad) {
        this->capacidad = capacidad;
        this->cantidad = 0;
        this->estudiantes = new Estudiante * [capacidad];
    }

    void agregar(Estudiante* nuevoEstudiante) {
        if (cantidad < capacidad) {
            estudiantes[cantidad] = nuevoEstudiante;
            cantidad++;
        }
        else {
            cout << "Lista llena." << endl;
        }
    }

    void mostrar() {
        for (int i = 0; i < cantidad; i++) {
            estudiantes[i]->mostrar();
            cout << "-----------------------------------" << endl;
        }
    }

    int contarInscriptibles() {
        int contador = 0;
        for (int i = 0; i < cantidad; i++) {
            if (estudiantes[i]->puedeInscribirse()) {
                contador++;
            }
        }
        return contador;
    }

    void mostrarEstudianteCarreraMasLarga() {
        if (cantidad == 0) return;

        Estudiante* mayor = estudiantes[0];
        for (int i = 1; i < cantidad; i++) {
            if (estudiantes[i]->getCarrera()->getDuracionAnios() > mayor->getCarrera()->getDuracionAnios()) {
                mayor = estudiantes[i];
            }
        }
        cout << "Estudiante con la carrera mas larga: " << mayor->getNombre()
            << " (" << mayor->getCarrera()->getNombre() << " - "
            << mayor->getCarrera()->getDuracionAnios() << " anos)" << endl;
    }

    double promedioEdadConCupo() {
        int sumaEdad = 0;
        int contador = 0;
        for (int i = 0; i < cantidad; i++) {
            if (estudiantes[i]->getCarrera()->getCupoDisponible()) {
                sumaEdad += estudiantes[i]->getEdad();
                contador++;
            }
        }
        if (contador > 0) return (double)sumaEdad / contador;
        return 0.0;
    }

    int contarSinCupo() {
        int contador = 0;
        for (int i = 0; i < cantidad; i++) {
            if (!estudiantes[i]->getCarrera()->getCupoDisponible()) {
                contador++;
            }
        }
        return contador;
    }

    int contarPorCarrera(string nombreCarrera) {
        int contador = 0;
        for (int i = 0; i < cantidad; i++) {
            if (estudiantes[i]->getCarrera()->getNombre() == nombreCarrera) {
                contador++;
            }
        }
        return contador;
    }

    ~ListaEstudiantes() {
        for (int i = 0; i < cantidad; i++) {
            delete estudiantes[i];
        }
        delete[] estudiantes;
    }
};

int main() {
    ListaEstudiantes lista(10);

    Carrera* c1 = new Carrera("Sistemas", 5, true);
    Carrera* c2 = new Carrera("Medicina", 6, false);

    lista.agregar(new Estudiante("Carlos", 20, c1));
    lista.agregar(new Estudiante("Ana", 17, c1));
    lista.agregar(new Estudiante("Pedro", 22, c2));

    cout << "--- LISTA DE ESTUDIANTES ---" << endl;
    lista.mostrar();

    cout << "1. Estudiantes que pueden inscribirse: " << lista.contarInscriptibles() << endl;
    lista.mostrarEstudianteCarreraMasLarga();
    cout << "3. Edad promedio (con cupo): " << lista.promedioEdadConCupo() << endl;
    cout << "4. Estudiantes sin cupo: " << lista.contarSinCupo() << endl;
    cout << "5. Estudiantes en Sistemas: " << lista.contarPorCarrera("Sistemas") << endl;

    return 0;
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
