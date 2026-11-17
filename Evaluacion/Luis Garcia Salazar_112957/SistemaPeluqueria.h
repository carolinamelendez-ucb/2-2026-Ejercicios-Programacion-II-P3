#pragma once
#include "ListaGeneralizada.h"
#include "Perro.h"
#include "Servicio.h"
#include "Atencion.h"

#include "PerroDuplicadoException.h"
#include "ServicioDuplicadoException.h"
#include "ServicioNoEncontradoException.h"
#include "PerroNoEncontradoException.h"

    class SistemaPeluqueria
    {
    private:
        string nombre;
        ListaGeneralizada<Perro>* listaPerros;
        ListaGeneralizada<Servicio>* listaServicio;
        ListaGeneralizada<Atencion>* listaAtencion;


    public:
        SistemaPeluqueria(string nombre, int capacidadServicio, int capacidadPerros, int capacidadAtencion) {
            this->nombre = nombre;
            this->listaPerros = new ListaGeneralizada<Perro>(capacidadPerros);
            this->listaServicio = new ListaGeneralizada<Servicio>(capacidadServicio);
            this->listaAtencion = new ListaGeneralizada<Atencion>(capacidadAtencion);

        }

        ~SistemaPeluqueria() {
            delete listaPerros;
            delete listaServicio;
            delete listaAtencion;

        }

        void registrarServicio(Servicio* nuevoServicio) {
            try {
                string codigo = nuevoServicio->getCodigo();
                Servicio* servicioDuplicado = listaServicio->buscar(codigo, Servicio::compararCodigo);

                if (servicioDuplicado != nullptr) {
                    throw ServicioDuplicadoException(codigo);
                }

                listaServicio->agregar(nuevoServicio);
            }
            catch (ServicioDuplicadoException& e) {
                cout << e.getMensaje() << endl;
            }
        }

        void registrarPerro(Perro* nuevoPerro) {
            try {
                string codigo = nuevoPerro->getCodigo();
                Perro* perroDuplicado = listaPerros->buscar(codigo, Perro::compararCodigo);

                if (perroDuplicado != nullptr) {
                    throw ServicioDuplicadoException(codigo);
                }

                string codigo = nuevoPerro->getCodigo();
                Atencion* perroRegistrado = listaAtencion->buscar(codigo, Atencion::compararPerroRegistrado);

                if (perroRegistrado == nullptr) {
                    throw  PerroNoEncontradoException(codigo);
                }

                listaPerros->agregar(nuevoPerro);
                perroRegistrado->agregar(nuevoPerro);
            }
            catch (Exception& e) {
                cout << e.getMensaje() << endl;
            }
        }

        void mostrarPerrosRegistrados(string codigo) const {
            try {
                Atencion* atencion = listaAtencion->buscar(codigo, Atencion::compararCodigo);

                if (atencion == nullptr) {
                    throw PerroNoEncontradoException(codigo);
                }

                atencion->mostrar();
                atencion->mostrarPerros();
            }
            catch (Exception& e) {
                cout << e.getMensaje() << endl;
            }
        }

        void mostrarInformacionPerro(string codigo) {
            try {
                Perro* perro = listaPerros->buscar(codigo, Perro::compararCodigo);
                if (perro == nullptr) {
                    throw PerroNoEncontradoException(codigo);
                }
                perro->mostrar();

            }
            catch (Exception& e) {
                cout << e.getMensaje() << endl;
            }
        }

        void mostrarPerrosOrdenados() const {
            listaPerros->ordenarBurbuja(Atencion::compararCantidadPerros);
            listaPerros->mostrar();
        }
    };

