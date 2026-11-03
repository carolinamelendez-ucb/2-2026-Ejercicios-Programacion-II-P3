#include"SistemaEnvios.h"


int main()
{
    SistemaEnvios* sistema = new SistemaEnvios("Sistema", 5, 5);
    Cliente* cliente1 = new Cliente("20121", "paolo", "Mexico");
    sistema->registrarCliente(cliente1);
    Cliente* cliente2 = new Cliente("20121", "Miguel", "Peru");
    sistema->registrarCliente(cliente2);
    sistema->mostrarClientes();


//Envio Duplicado
    Envio* envio1 = new Envio("11", 120327, 35, 4);
    Envio* envio2 = new Envio("11", 125402, 40, 5);
    sistema->registrarEnvios(envio1);
    sistema->registrarEnvios(envio2);
 //Cliente no encontrado  
    sistema->registrarEnvioACliente("20121", envio1);
    sistema->registrarEnvioACliente("20127",envio2 );
    
//no se ejecuta paquete duplicado si salta primero la exapcion de envio duplicado, camiar 
    Paquete* paquete1 = new Paquete("1232", "Rosas", 3, 5);
    Paquete* paquete2 = new Paquete("1232", "Rosas", 3, 5);
    sistema->registrarPaqueteAEnvio(paquete1, "11");
    sistema->registrarPaqueteAEnvio(paquete1, "12");//aqui para ver esa excapcion
    sistema->mostrarEnvios();
    cout << endl;
    cout << endl;
    cout << endl;

    sistema->BuscarCliente(cliente1);

}
