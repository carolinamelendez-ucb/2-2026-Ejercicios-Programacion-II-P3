/*Peluquería Canina
La peluquería canina “Patitas Felices” necesita un sistema para administrar los servicios de baño y corte de pelo que ofrece a sus clientes.
La peluquería registra los perros que recibe para su atención.Para atenderlos, se ofrecen diferentes tipos de servicios, como baño y corte de pelo.
Cada servicio tiene un costo base y condiciones particulares.
Al registrar una atención, el sistema debe verificar que el perro esté registrado y que no tenga otra atención registrada.
El costo final dependerá del tipo de servicio solicitado y de las características del perro.
Además, la peluquería necesita llevar un control de las atenciones realizadas para consultar los servicios recibidos por cada perro.
Clases involucradas
● Perro(atributos: codigo, nombre, raza, tamanio).
○ El tamaño puede ser pequeño, mediano o grande.
● ServicioBano(atributos:codigo, nombre, costoProductos).
○ Incluye baño y secado.
○ El costo final incluye el costo de los productos utilizados.
● ServicioCorte(atributos:codigo, nombre, costoCorte).
○ Incluye corte de pelo.
○ Los perros grandes tienen un costo adicional de Bs. 15
● Atencion(atributos: codigo, perro, servicio, costoFinal).
○ Almacena la información de una atención realizada.
● SistemaPeluqueria(atributos: nombre, listaPerros, listaServicios, listaAtenciones).
Requerimientos
Utilizar la clase SistemaPeluqueria que centralice todas las operaciones para :
1. Registrar un perro. 10pts
● Throw PerroDuplicadoException, si el código del perro ya existe.
2. Registrar un servicio. 10pts
● Registrar un servicio de cualquiera de los tipos disponibles.
● Throw ServicioDuplicadoException, si el código del servicio ya existe.
3. Registrar una atención. 25pts
● Recibir el código del perro y el código del servicio.
● Calcular el costo final según el tipo de servicio y las características del perro.
● Throw PerroNoEncontradoException, si el perro no existe.
● Throw ServicioNoEncontradoException, si el servicio no existe.
4. Mostrar las atenciones de un perro. 25pts
● Recibir el código del perro.
● Mostrar sus datos y los servicios que recibió.
● Mostrar el costo de cada atención y el total gastado.
● Throw PerroNoEncontradoException, si el perro no existe.
6. Mostrar todos los perros registrados, ordenados alfabéticamente según su nombre.EXTRA. 10pts
Nota : Todos los requerimientos deben ser ejemplificados en el main(), incluyendo la ejecución y visualización de los mensajes de TODAS las excepciones.*/

#include "SistemaPeluqueria.h"
#include "ServicioCorte.h"
#include "ServicioBano.h"
#include "PerroGrande.h"
#include "PerroMed.h"
#include "PerroPequenho.h"



using namespace std;

int main() {

    SistemaPeluqueria* sistema = new SistemaPeluqueria("Patitas Felices", 10, 2, 3);

    sistema->registrarPerro(new Perro());
    sistema->registrarPerro(new Perro());
    sistema->registrarPerro(new Perro());


    sistema->registrarServicio(new Servicio());
    sistema->registrarServicio(new Servicio());
    sistema->registrarServicio(new Servicio());

    sistema->mostrarPerrosRegistrados("Mucho");
    sistema->mostrarPerrosRegistrados("Trabajo");

    sistema->mostrarInformacionPerro("123");
    sistema->mostrarInformacionPerro("321");

    
    sistema->mostrarPerrosOrdenados();

    delete sistema;
    return 0;
}
