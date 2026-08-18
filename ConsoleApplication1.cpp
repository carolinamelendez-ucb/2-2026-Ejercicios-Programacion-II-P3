#include <iostream>
#include <string>

using namespace std;
/*
REPASO
- Constructores
- Sobrecarga-constructores
- Atributos privados
- Setters, Getters
- Metodos
- Metodoso mostrar()

HOY
- Composión

*/

class Autor { 
    // Para autogenerar el constructor 
    // 1. mover el cursor sobre el nombre de la clase > 
    // "Ctrl + . " > 
    // "Agregar constructor con todos los campos" 
private:
    string nombre;
    string apellido;
public:
    // nota: TODOSO LOS CONSTRUCTORES DEBEN INICIALIZAR TODOS LOS ATRIBUTOS
    Autor() {
        nombre = "";
        apellido = "";
    }

    Autor(const string& nombre, const string& apellido)
        : nombre(nombre), apellido(apellido)
    {
    }

    string getApellido() {
        return apellido;
    }

    void mostrar() {
        cout << "Nombre:  " << nombre << endl;
        cout << "Apellido:  " << apellido << endl;
    }

    // Se puede navegar hacia la implementación con "Ctrl + Click Izquierdo"
    void setNombre(string nuevoNombre) {
        this->nombre = nuevoNombre;
    }
};


class Libro {
private: // <- modificador de accesso.
    // Atributos primitivos / simples
    string titulo;
    string descripcion;
    int nroPaginas;

    // objeto
    Autor* autor;
public:
    // EJEMPLO DE COMO NOOO HACER.
    // Motivo? no es extendible
    // Libro(string titulo, string descrip, int nroPaginas, string nombreAutor, string& apellidoAutor) {
    //    autor = Autor(nombreAutor, apellidoAutor);
    // }
    // EJEMPLO DE COMO SI HACER.
    Libro(string titulo, string descrip, int nroPaginas, Autor* autor) {
        this->titulo = titulo;
        this->descripcion = descrip;
        this->autor = autor;
        this->nroPaginas = nroPaginas;
    }

    void mostrar()
    {
        cout << "Titulo: " << titulo << endl;
        cout << "Description: " << descripcion << endl;
        cout << "Nro paginas: " << nroPaginas << endl;
        // Como mostrar el info del  objeto compuesto autor ??
        // Opcion 1. Si solo me interesa mostrar UN atributo -> realizar un get
        cout << "Apellido autor: " << autor->getApellido() << endl;

        // Opcion 2. Si necesito mostrar información COMPLETA. -> llamar al metodo mostrar del objeto
        cout << "Info del autor: " << endl;
        autor->mostrar();
    }

    // GET -> obtemer
    // SET -> Modificar/Editar. (UPDATE)

    // Getter y setter son parte del encapsulamiento.
    void setNroPaginas(int nuevoNroPaginas) {
        if (nuevoNroPaginas < 0) {
            cout << "Numero de paginas es invalido. Valor ingreado: " << nuevoNroPaginas << endl;
        } else{
            this->nroPaginas = nuevoNroPaginas;
        }
    }
    
    // ~  = Alt + 126
    ~Libro() {
        delete autor;
    }
};






int main()
{
    Autor* autorFernando = new Autor("Fernando", "Fernandez");

    Libro libroA = Libro("LibroA", "This is a description", 50, autorFernando);
    libroA.mostrar();
    libroA.setNroPaginas(10);
    cout << "-- Despues de un Set nroPaginas" << endl;
    libroA.mostrar();


    cout << "-- Despues de un Set Nombre del autor" << endl;
    autorFernando->setNombre("Marco");
    libroA.mostrar();

    cout << "-- Despues de un Set nroPaginas -2" << endl;
    libroA.setNroPaginas(-2) ;
    libroA.mostrar();
}
