

#include <iostream>
#include <string>
using namespace std;

class Exception {
protected:
	string mensaje;
public:
	Exception(string mensaje) {
		this->mensaje = mensaje;
	}
	string getMensaje() {
		return this->mensaje;
	}
};

class PerroDuplicadoException : public Exception {
public:
	PerroDuplicadoException(string codigo) : Exception("El codigo " + codigo + " del perro esta duplicado") {}
};

class ServicioDuplicadoException : public Exception {
public:
	ServicioDuplicadoException(string codigo) : Exception("El codigo " + codigo + " del sericio esta duplicado") {}
};

class PerroNoEncontradoException : public Exception {
public:
	PerroNoEncontradoException(string codigo) : Exception("El perro con el codigo:  " + codigo + " no se encontro") {}
};

class ServicioNoEncontradoException : public Exception {
public:
	ServicioNoEncontradoException(string codigo) : Exception("El servicio con el codigo:  " + codigo + " no se encontro") {}
};

template <class T>
class ListaGenerica {
private:
	int cantidad;
	int capacidad;
	T** elementos;
public:
	ListaGenerica(int capacidad) {
		this->cantidad = 0;
		this->capacidad = capacidad;
		this->elementos = new T * [capacidad];
	}

	void agregar(T* nuevoElemento) {
		if (this->cantidad < this->capacidad) {
			this->elementos[cantidad] = nuevoElemento;
			this->cantidad++;
		}
	}

	void mostrar() {
		for (int i = 0; i < this->cantidad; i++) {
			this->elementos[i]->mostrar();
		}
	}

	T* buscar(string valorBuscado, string(*functionGetter)(T*)) {
		for (int i = 0; i < this->cantidad; i++) {
			string valorActual = functionGetter(this->elementos[i]);
			if (valorActual == valorBuscado) {
				return this->elementos[i];
			}
		}
		return nullptr;
	}
	T* buscar(int valorBuscado, int(*functionGetter)(T*)) {
		for (int i = 0; i < this->cantidad; i++) {
			int valorActual = functionGetter(this->elementos[i]);
			if (valorActual == valorBuscado) {
				return this->elementos[i];
			}
		}
		return nullptr;
	}

	T* getElemento(int indice) {
		return elementos[indice];
	}

	int getCantidad() {
		return this->cantidad;
	}
};


class Perro {
private:
	string codigo;
	string nombre;
	string raza;
	string tamanio;
public:
	Perro(string codigo, string nombre, string raza, string tamanio) {
		this->codigo = codigo;
		this->nombre = nombre;
		this->raza = raza;
		this->tamanio = tamanio;
	}

	string getCodigo() {
		return this->codigo;
	}

	static string getCiEstatico(Perro* perro) {
		return perro->codigo;
	}

	void mostrar() {
		cout << "Codigo: " << codigo << endl;
		cout << "nombre: " << nombre << endl;
		cout << "raza: " << raza << endl;
		cout << "tamanio: " << tamanio << endl;
	}

	string getTamanio() {
		return this->tamanio;
	}
};

class Servicio {
protected:
	string codigo;
	string nombre;
	string tipo;
	double costo;
public:
	Servicio(string codigo, string nombre) {
		this->codigo = codigo;
		this->nombre = nombre;
		this->costo = 50;
	}

	string getCodigo() {
		return this->codigo;
	}

	static string getCodigoServicioEstatico(Servicio* perro) {
		return perro->codigo;
	}
	virtual double calcularCosto(Perro* p) = 0;

	double getCosto() {
		return this->costo;
	}

	void mostrar() {
		cout << "codigo: " << codigo << endl;
		cout << "nombre: " << nombre << endl;
	}

};

class ServicioBano : public Servicio {
private:
	double costoProductos;
public:
	ServicioBano(string codigo, string nombre, double costoProductos) : Servicio(codigo, nombre) {
		this->costoProductos = costoProductos;
		this->tipo = "Servicio Bano";
	}

	double calcularCosto(Perro* p) {
		double total = 0;
		total = costo + costoProductos;
		return total;
	}
};

class ServicioCorte : public Servicio {
private:
	double costoAdicional;
public:
	ServicioCorte(string codigo, string nombre) : Servicio(codigo, nombre) {
		this->costoAdicional = 15;
		this->tipo = "Servicio Corte";
	}

	double calcularCosto(Perro* p) {
		double total = 0;
		if (p->getTamanio() == "grande") {
			total = this->costo + this->costoAdicional;
			return total;
		}
		else
		{
			return total;
		}
	}

	double getCostoAdicional() {
		return this->costoAdicional;
	}
};

class Atencion {
private:
	string codigo;
	Perro* perro;
	Servicio* servicio;
public:
	Atencion(string codigo, Perro* perro, Servicio* servicio) {
		this->codigo = codigo;
		this->perro = perro;
		this->servicio = servicio;
	}

	double CalcularCostoFinal(Servicio* s, Perro* p) {
		double costo = s->calcularCosto(p);
		return costo;
	}

	static string getCodigoPerro(Atencion* a) {
		return a->perro->getCodigo();
	}

	void mostrar() {
		cout << "codigo: " << this->codigo << endl;
		cout << "codigo: " << this->codigo << endl;
		cout << endl << "servicio: ";
		this->servicio->mostrar();
		cout << endl;
	}

};

class SistemaPeluqueria {
private:
	string nombre;
	ListaGenerica<Perro>* listaPerros;
	ListaGenerica<Servicio>* listaServicios;
	ListaGenerica<Atencion>* listaAtenciones;
public:
	SistemaPeluqueria(string nombre) {
		this->nombre = nombre;
		this->listaPerros = new ListaGenerica<Perro>(10);
		this->listaServicios = new ListaGenerica<Servicio>(30);
		this->listaAtenciones = new ListaGenerica<Atencion>(50);
	}

	~SistemaPeluqueria() {
		delete listaPerros;
		delete listaServicios;
		delete listaAtenciones;
	}


	//1
	void registrarPerro(Perro* p) {
		try {
			if (listaPerros->buscar(p->getCodigo(), Perro::getCiEstatico) != nullptr)
			{
				throw PerroDuplicadoException(p->getCodigo());
			}
			listaPerros->agregar(p);
			cout << "El perro con el codigo " << p->getCodigo() << " se ha registrado con exito" << endl;
		}
		catch (Exception& e) {
			cout << "Error: " << e.getMensaje() << endl;
		}
		
	}

	//2
	void registrarServicio(Servicio* s) {
		try {
			if (listaServicios->buscar(s->getCodigo(), Servicio::getCodigoServicioEstatico) != nullptr)
			{
				throw ServicioDuplicadoException(s->getCodigo());
			}
			listaServicios->agregar(s);
			cout << "El servicio con el codigo " << s->getCodigo() << " se ha registrado con exito" << endl;
		}
		catch (Exception& e) {
			cout << "Error: " << e.getMensaje() << endl;
		}
	}

	//3
	void registrarAtenciones(string codAtencion, string codPerro, string codServicio) {
		try {
			Perro* pARegistrar = listaPerros->buscar(codPerro, Perro::getCiEstatico);
			Servicio* sARegistrar = listaServicios->buscar(codServicio, Servicio::getCodigoServicioEstatico);
			if (pARegistrar == nullptr)
			{
				throw PerroNoEncontradoException(codPerro);
			}if (sARegistrar == nullptr)
			{
				throw ServicioNoEncontradoException(codServicio);
			}
			Atencion* atencionAgregada = new Atencion(codAtencion, pARegistrar, sARegistrar);
			double cFinal = atencionAgregada->CalcularCostoFinal(sARegistrar, pARegistrar);
			cout << "La atencion con el codigo " << codAtencion << " fue agregada correctamente. Costo: " << cFinal << endl;
		}
		catch (Exception& e) {
			cout << "Error: " << e.getMensaje() << endl;
		}
	}

	//4
	void mostrarAtenciones(string p) {
		try {

			Perro* perro = listaPerros->buscar(p, Perro::getCiEstatico);
			if (perro == nullptr)
			{
				throw PerroNoEncontradoException(perro->getCodigo());
			}
			perro->mostrar();

			for (int i = 0; i < listaAtenciones->getCantidad(); i++)
			{
				Atencion* aAMostrar = listaAtenciones->buscar(perro->getCodigo(), Atencion::getCodigoPerro); // atencion 1
				if (aAMostrar != nullptr)
				{
					aAMostrar->mostrar();
				}
			}
		}
		catch (Exception& e) {
			cout << "Error: " << e.getMensaje() << endl;
		}
	}

	// Perrdo, atencion 1, atencion 2, atencion 3
	
};

int main()
{
	SistemaPeluqueria* s1 = new SistemaPeluqueria("Patitas felices");

	cout << "1. registrar perros" << endl;

	s1->registrarPerro(new Perro("001", "Pepito", "salchicha", "pequenio"));

	s1->registrarPerro(new Perro("001", "Pepito", "salchicha", "pequenio"));

	cout << endl << "2. registrar servicios" << endl;

	s1->registrarServicio(new ServicioBano("S01", "ServicioAura", 46));
	s1->registrarServicio(new ServicioCorte("S02", "ServicioElvis"));

	s1->registrarServicio(new ServicioBano("S01", "ServicioAura", 46));

	cout << endl << "3. registrar atenciones" << endl;

	s1->registrarAtenciones("A01", "001", "S01");
	s1->registrarAtenciones("A02", "002", "S01");

	cout << endl << "4. mostrarAtenciones" << endl;

	s1->mostrarAtenciones("001");

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
