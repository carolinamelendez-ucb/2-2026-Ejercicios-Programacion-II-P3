#pragma once
#include"Servicio.h"
#include"Perro.h"
#include"Atencion.h"
#include"VectorGenerico.h"
#include"Excepcion.h"
#include"ExcepcionDuplicado.h"
#include"ExcepcionSercicioDuplicado.h"
#include"ExcepcionPerroNoEncontrado.h"
#include"ExcepcionServicioNoEncontrado.h"
class SistemaPeluqueria
{
private:
	string nombre;
	VectorGenerico<Perro>* perros;
	VectorGenerico<Servicio>* servicios;
	VectorGenerico<Atencion>* atenciones;

public:
	SistemaPeluqueria(string nombre, int capacidad) {
		this->nombre = nombre;
		this->perros = new VectorGenerico<Perro>(capacidad);
		this->servicios = new VectorGenerico<Servicio>(capacidad);
		this->atenciones = new VectorGenerico<Atencion>(capacidad);
	}
	~SistemaPeluqueria() {};

	void mostrarPerros() {
		perros->mostrar();
	}
	void mostrarSercicios() {
		atenciones->mostrar();
	}
	void mostrarAtenciones() {
		servicios->mostrar();
	}

	void agregarPerro(Perro* nuevoPerro) {
		Perro* perroBuscado = perros->buscar(nuevoPerro->getCodigo(), Perro::comparador);
		try
		{
			if (perroBuscado != nullptr)
			{
				throw ExcepcionDuplicado();
			}
			perros->agregarElemento(nuevoPerro);
		}
		catch (Excepcion err)
		{
			cout << err.getMensaje();
		}
	}
	void agregarServicio(Servicio* nuevoServicio) {
		Servicio* servicioBuscado = servicios->buscar(nuevoServicio->getCodigo(), Servicio::comparador);
		try
		{
			if (servicioBuscado != nullptr)
			{
				throw ExcepcionServicioDuplicado();
			}
			servicios->agregarElemento(nuevoServicio);
			cout << "Se agrego el servicio" << endl;
		}
		catch (Excepcion err)
		{
			cout <<endl<< err.getMensaje()<<endl;
		}
	}

	void agregarAtencion(string codAtencion,string codigoPerro, string codigoServicio) {
		try
		{
			Perro* perroBuscado = perros->buscar(codigoPerro, Perro::comparador);
			Servicio* servicioBuscado = servicios->buscar(codigoServicio, Servicio::comparador);
			if (perroBuscado== nullptr){
				throw ExcepcionPerroNoEncontrado();
			}
			if (servicioBuscado==nullptr)
			{
				throw ExcepcionServicioNoEncontrado();
			}
			Atencion* atencion = new Atencion(codAtencion, perroBuscado, servicioBuscado);
			atenciones->agregarElemento(atencion);
			cout << "Se agrego la atencion";
		}
		catch (Excepcion err)
		{
			cout <<endl<< err.getMensaje();
		}
	}

	void buscarAtencionesPerro(string perroBuscado) {
		try
		{
			Perro* perroEncontrado = perros->buscar(perroBuscado, Perro::comparador);
			if (perroEncontrado==nullptr)
			{
				throw ExcepcionPerroNoEncontrado();
			}
			cout << "El perro buscado es: " << endl;
			perroEncontrado->mostrar();
			cout << "El servicio que recibio y datos de la atencion son: " << endl;
			Atencion* atencionConPerroBuscado = atenciones->buscar(perroBuscado, Atencion::comparador);
			atencionConPerroBuscado->mostrar();
		}
		catch (Excepcion err)
		{
			cout << endl << err.getMensaje();
		}
	}

	void mostrarDatosUnperro(string codPerro) {
		atenciones->mostrarDeUnElento(codPerro, Atencion::comparador);
		int total = atenciones->totalDeUnElemento(codPerro, Atencion::comparador);
		cout << total;
	}
};
