
#include <iostream>
#include "Sistema.h"
#include "ServicioBano.h";
#include "ServicioCorte.h"
using namespace std;

int main()
{
    Sistema sis("patitas",10,10,10);
    Perro* per1 = new Perro("111","drako","pastor","mediano");
    Perro* per2 = new Perro("111", "lucy", "chilwawa", "mediano");
   
    ///1 Registrar un perro
    sis.agregarperro(per1);
    sis.agregarperro(per2);
    sis.mostrar();

    //registrar un servicio
    Servicio* ser1 = new ServicioBano("bano","AAA",50);

    Servicio* ser2 = new ServicioCorte(" moicano", "BBB", 50,"grande");
    Servicio* ser3 = new ServicioBano("dado", "AAA", 50);

    sis.registrarservicio(ser1);
    sis.registrarservicio(ser2);
    sis.registrarservicio(ser3);
    sis.mostrarservico();
    // registrar atenciones 
    
    Atencion* at1 = new Atencion("111AAA",10);
    Atencion* at2 = new Atencion("222BBB", 10);

    sis.registraratencio(at1,"111","AAA");
    sis.registraratencio(at2, "111", "AAA");
    cout << " mostrar " << endl;


    sis.mostraratencionesDEperro("111",at1);


}