#pragma once
#include"ListaGenerica.h"
#include"Atencion.h"
#include"Servicio.h"
#include"Perro.h"
class SistemaPeluqueria
{
private:
	string nombre;
	ListaGenerica<Perro>* listaPerros;
	ListaGenerica<Atencion>* listaAtenciones;
	ListaGenerica<Servicio>* listaServicios;
public:
	SistemaPeluqueria(string nombre, int maxPerros, int maxAtenciones, int maxServicios) {
		this->nombre = nombre;
		this->listaPerros = new ListaGenerica<Perro>(maxPerros);
		this->listaAtenciones = new ListaGenerica<Atencion>(maxAtenciones);
		this->listaServicios = new ListaGenerica<Servicio>(maxServicios);
	}
	void registrarPerro(Perro* nuevoPerro) {
		string codigo = nuevoPerro->getCodigo();
		try {
			Perro* duplicado = listaPerros->buscar(codigo, Perro::compararCodigo);
			if (duplicado != nullptr) {
				throw runtime_error("PerroDuplicadoException: El codigo del perro ya existe");
			}
			listaPerros->agregar(nuevoPerro);
			cout << "registro del perro: "<< nuevoPerro->getCodigo()<<" existoso" << endl;
		}
		catch (const exception& e) {
			cout << "Error: " << e.what() << endl;
		}
	}
	void registrarServicio(Servicio* nuevoServicio) {
		string codigo = nuevoServicio->getCodigo();
		try {
			Servicio* duplicado = listaServicios->buscar(codigo, Servicio::compararCodigoServicio);
			if (duplicado != nullptr) {
				throw runtime_error("ServicioDuplicadoException: El codigo del servicio ya existe");
			}
			listaServicios->agregar(nuevoServicio);
			cout << "registro del servicio: "<<nuevoServicio->getCodigo()<<" existoso" << endl;
		}
		catch (const exception& e) {
			cout << "Error: " << e.what() << endl;
		}
	}
	void registrarAtencion(string codigoPerro,string codigoServicio,Atencion* nuevaAtencion) {
		string codigoAtencion = nuevaAtencion->getCodigo();
		try {
			Atencion* duplicado = listaAtenciones->buscar(codigoAtencion, Atencion::compararCodigoAtencion);
			Perro* perroBuscado = listaPerros->buscar(codigoPerro, Perro::compararCodigo);
			Servicio* servicioBuscado = listaServicios->buscar(codigoServicio, Servicio::compararCodigoServicio);
			if (duplicado != nullptr) {
				throw runtime_error("AtencionDuplicadoException: el codigo con esa atencion ya existe");
			}
			if (perroBuscado == nullptr) {
				throw runtime_error("ServicioDuplicadoException: El perro con ese codigo no existe");
			}
			if (servicioBuscado == nullptr) {
				throw runtime_error("ServicioNoEncontradoException: El servicio con ese codigo no existe");
			}
			listaAtenciones->agregar(nuevaAtencion);
			nuevaAtencion->agregarPerro(perroBuscado);
			nuevaAtencion->agregarServicio(servicioBuscado);
			cout << "registro exitoso " << endl;
		}
		catch(const exception& e){
			cout << "Error: " << e.what() << endl;
		}

	}
	void mostrarAtencionesDeUnPerro(string codigo) {
		try {
			Perro* perro = listaPerros->buscar(codigo, Perro::compararCodigo);
			if (perro == nullptr) {
				throw runtime_error("NinioNoEncontradoException: el ninio no existe");
			}
			this->listaAtenciones->mostrarFiltrados(codigo,Atencion::mostrarAtencionesPerro);

		}
		catch (const exception& e) {
			cout << "Error: " << e.what() << endl;
		}
	}
	void mostrarPerrosOrdenados() {
		listaPerros->mostrarOrdenados(Perro::mostrarNombreOrdenado);
	}
};

