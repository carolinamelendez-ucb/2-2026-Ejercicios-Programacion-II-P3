// PracticaII_4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string>

using namespace std;
class Autor {
private:
	string nombre;
	string nacionalidad;
	int cantidadLibrosPublicados;

public:
	Autor() {
		this->nombre = "";
		this->nacionalidad = "";
		this->cantidadLibrosPublicados = 0;
	}

	Autor(string nombre, string nacionalidad, int cantidadLibrosPublicados) {
		this->nombre = nombre;
		this->nacionalidad = nacionalidad;
		this->cantidadLibrosPublicados = cantidadLibrosPublicados;
	}

	void mostrar() {
		cout << "Autor: " << nombre << endl;
		cout << " Nacionalidad: " << nacionalidad << endl;
		cout<< " Libros publicados: " << cantidadLibrosPublicados << endl;
	}

	int getCantidadLibrosPublicados() {
		return cantidadLibrosPublicados;
	}

	string getNombre() {
		return nombre;
	}
};

class Libro {
private:
	string titulo;
	double precio;
	Autor autor;

public:
	Libro() {
		this->titulo = "";
		this->precio = 0.0;
		this->autor = Autor();
	}

	Libro(string titulo, double precio, Autor autor) {
		this->titulo = titulo;
		this->precio = precio;
		this->autor = autor;
	}

	bool esBestSeller() {
		return autor.getCantidadLibrosPublicados() > 5;
	}

	void mostrar() {
		cout << "Titulo: " << titulo << " y Precio: " << precio << endl;
		autor.mostrar();
	}

	double getPrecio() {
		return precio;
	}

	Autor getAutor() {
		return autor;
	}
};

class Libreria {
private:
	Libro* libros;
	int nroLibros;
	int capacidadMax;

public:
	Libreria(int capacidadMax) {
		this->capacidadMax = capacidadMax;
		this->libros = new Libro[capacidadMax];
		this->nroLibros = 0;
	}

	bool agregarLibro(Libro l) {
		if (nroLibros < capacidadMax) {
			libros[nroLibros] = l;
			nroLibros++;
			return true;
		}
		return false;
	}

	void mostrar() {
		for (int i = 0; i < nroLibros; i++) {
			libros[i].mostrar();
			cout << endl;
		}
	}

	double promedioPrecioAutoresN(int N) {
		double suma = 0;
		int contador = 0;
		for (int i = 0; i < nroLibros; i++) {
			if (libros[i].getAutor().getCantidadLibrosPublicados() > N) {
				suma += libros[i].getPrecio();
				contador++;
			}
		}
		if (contador == 0) return 0.0;
		return suma / contador;
	}

	double promedioPrecioBestSeller() {
		double suma = 0;
		int contador = 0;
		for (int i = 0; i < nroLibros; i++) {
			if (libros[i].esBestSeller()) {
				suma += libros[i].getPrecio();
				contador++;
			}
		}
		if (contador == 0) return 0.0;
		return suma / contador;
	}

	void mostrarLibroMasCaroReconocido() {
		int indiceMax = -1;
		double mayorPrecio = -1.0;
		for (int i = 0; i < nroLibros; i++) {
			if (libros[i].getAutor().getCantidadLibrosPublicados() > 5) {
				if (libros[i].getPrecio() > mayorPrecio) {
					mayorPrecio = libros[i].getPrecio();
					indiceMax = i;
				}
			}
		}
		if (indiceMax != -1) {
			cout << "Libro mas caro de autor reconocido:" << endl;
			libros[indiceMax].mostrar();
		}
		else {
			cout << "No hay libros de autores reconocidos." << endl;
		}
	}

	int contarLibrosNovatos() {
		int contador = 0;
		for (int i = 0; i < nroLibros; i++) {
			if (libros[i].getAutor().getCantidadLibrosPublicados() <= 2) {
				contador++;
			}
		}
		return contador;
	}

	double totalRecaudadoProductivos() {
		double total = 0;
		for (int i = 0; i < nroLibros; i++) {
			if (libros[i].getAutor().getCantidadLibrosPublicados() > 10) {
				total += libros[i].getPrecio();
			}
		}
		return total;
	}
};

int main() {
	Libreria lib(5);

	Autor autor1("Gabriel", "Colombiana", 12);
	Autor autor2("Ana", "Boliviana", 2);
	Autor autor3("Carlos", "Argentina", 6);

	Libro libro1("Cien Anios", 45.50, autor1);
	Libro libro2("Poemas cortos", 15.00, autor2);
	Libro libro3("Ficciones", 30.00, autor3);

	lib.agregarLibro(libro1);
	lib.agregarLibro(libro2);
	lib.agregarLibro(libro3);

	lib.mostrar();

	cout << "Promedio " << lib.promedioPrecioAutoresN(5) << endl;
	cout << "Promedio Best Seller: " << lib.promedioPrecioBestSeller() << endl;
	lib.mostrarLibroMasCaroReconocido();
	cout << "Libros de novatos: " << lib.contarLibrosNovatos() << endl;
	cout << "Total recaudado productivos: " << lib.totalRecaudadoProductivos() << endl;

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
