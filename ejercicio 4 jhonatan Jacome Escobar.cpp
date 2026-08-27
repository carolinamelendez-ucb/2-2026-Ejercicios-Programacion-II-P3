// ejercicio 4 jhonatan Jacome Escobar.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<string>
using namespace std;

class Autor {
private:
	string nombre;
	string nacionalidad;
	int librosPublicados;
public:
	Autor() {
		this->nombre = "";
		this->nacionalidad = "";
		this->librosPublicados = 0;
	}
	Autor(string nombre, string nacionalidad, int librosPublicados) {
		this->nombre = nombre;
		this->nacionalidad = nacionalidad;
		this->librosPublicados = librosPublicados;
	}

	string getNombre() {
		return nombre;
	}
	string getNacionalidad() {
		return nacionalidad;
	}
	int getLibrosPublicados() {
		return librosPublicados;
	}
	void mostrar() {
		cout << "Autor: " << nombre << endl;
		cout << "Nacionalidad: " << nacionalidad << endl;
		cout << "Cantidad de Libros Publicados: " << librosPublicados << endl;
	}
};

class Libro {
	string titulo;
	double precio;
	Autor* autor;
public:
	Libro() {
		this->titulo = "";
		this->precio = 0;
		this->autor = nullptr;
	}
	Libro(string titulo, double precio, Autor* autor) {
		this->titulo = titulo;
		this->precio = precio;
		this->autor = autor;
	}
	string getTitulo() {
		return titulo;
	}
	double getPrecio() {
		return precio;
	}
	Autor* getAutor() {
		return autor;
	}
	bool esBestSeller() {
		if (autor != nullptr) {
			return autor->getLibrosPublicados() > 5;
		}
		return false;
	}
	void mostrar() {
		cout << "Titulo: " << titulo << endl;
		cout << "Precio: " << precio << endl;
		if (autor != nullptr) {
			autor->mostrar();
		}
	}
};
double promedioPrecio(Libro** libros, int cantidad, int N) {
	double suma = 0;
	int contador = 0;
	for (int i = 0;i < cantidad; i++) {
		if (libros[i]->getAutor()->getLibrosPublicados() > N) {
			suma = suma + libros[i]->getPrecio();
			contador++;
		}
	}
	if (contador == 0) {
		return 0;
	}
	return suma / contador;
}
double promedioPrecioBestSeller(Libro** libros, int cantidad) {
	double suma = 0;
	int contador = 0;
	for (int i = 0;i < cantidad;i++) {
		if (libros[i]->esBestSeller()) {
			suma = suma + libros[i]->getPrecio();
			contador++;
		}
	}
	if (contador == 0) {
		return 0;
	}
	return suma / contador;
}
void mostrarLibroMasCaro(Libro** libros, int cantidad) {
	Libro* masCaro = nullptr;
	for (int i = 0;i < cantidad;i++) {
		if (libros[i]->getAutor()->getLibrosPublicados() > 5) {
			if (masCaro == nullptr || libros[i]->getPrecio() > masCaro->getPrecio()) {
				masCaro = libros[i];
			}
		}
	}
	if (masCaro != nullptr) {
		cout << "LIBRO MAS CARO DE AUTOR RECONOCIDO" << endl;
		masCaro->mostrar();
	}
	else {
		cout << "No se encontraron libros de autores reconocidos" << endl;
	}
}
int contarLibrosAutoresNovatos(Libro** libros, int cantidad) {
	int contador = 0;
	for (int i = 0;i < cantidad;i++) {
		if (libros[i]->getAutor()->getLibrosPublicados() <= 2) {
			contador++;
		}
	}
	return contador;
}
double totalRecaudadoAutores(Libro** libros, int cantidad) {
	double total = 0;
	for (int i = 0;i < cantidad;i++) {
		if (libros[i]->getAutor()->getLibrosPublicados() > 5) {
			total = total + libros[i]->getPrecio();
		}
	}
	return total;
}
int main() {
	Autor* a1 = new Autor("Gabriel Garcia Marquez", "Colombiano", 24);
	Autor* a2 = new Autor("Mario Vargas Llosa", "Espaniol", 35);
	Autor* a3 = new Autor("Mario Rodriguez", "Boliviano", 1);
	int capacidad = 100;
	int cantLibros = 4;
	Libro** libros = new Libro * [capacidad];
	libros[0] = new Libro("Cien Anios de Soledad", 150, a1);
	libros[1] = new Libro("El Amor en los Tiempos del Colera", 120, a1);
	libros[2] = new Libro("La Ciudad y los Perros", 90, a2);
	libros[3] = new Libro("Mi Primer Libro", 45, a3);
	cout << "PRECIO PROMEDIO DE AUTORES CON MAS DE 5 LIBROS" << endl;
	cout << promedioPrecio(libros, cantLibros, 5) << endl;
	cout << "PRECIO PROMEDIO DE BEST SELLERS: " << endl;
	cout << promedioPrecioBestSeller(libros, cantLibros) << endl;
	mostrarLibroMasCaro(libros, cantLibros);
	cout << endl;
	cout << "CANTIDAD DE LIBROS DE AUTORES NOVATOS" << endl;
	cout << contarLibrosAutoresNovatos(libros, cantLibros) << endl;
	cout << "TOTAL RECAUDADO POR LIBROS DE AUTORES PRODUCTIVOS" << endl;
	cout << totalRecaudadoAutores(libros, cantLibros) << endl;
	delete a1;
	delete a2;
	delete a3;
	for (int i = 0;i < cantLibros;i++) {
		delete libros[i];
	}
	delete[]libros;
	return 0;
}