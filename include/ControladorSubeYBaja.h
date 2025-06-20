#ifndef CONTROLADORSUBEYBAJA_H
#define CONTROLADORSUBEYBAJA_H

#include "IControladorSubeYBaja.h"
#include "IControladorFechaActual.h"
#include "HandlerInmobiliarias.h"
#include "HandlerPublicacion.h"
#include "HandlerClientes.h"
#include "HandlerPropietarios.h"
#include "Publicacion.h"

#include <string>

using namespace std;

class ControladorSubeYBaja : public IControladorSubeYBaja
{
private:
    static ControladorSubeYBaja *instancia;
    
    HandlerInmobiliarias *Hinmobiliarias;
    HandlerPublicacion *HPublicacion;
    HandlerClientes *Hcliente;
    HandlerPropietarios *Hpropietario;

    Inmobiliaria* UltimaInmobiliaria = nullptr; // Tuve que agregarlo para una funcion nueva :(

    IControladorFechaActual *fechaActual;
    ControladorSubeYBaja();

public:
    static ControladorSubeYBaja *getInstancia();
    ~ControladorSubeYBaja();
    bool altaPublicacion(string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, string texto, float precio);

    bool altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono);
    bool altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono);
    bool altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento);

    void representarPropietario(string nicknamePropietario);
    void altaCasa (string direccion, int numeroPuerta, int superficie, bool esPH,TipoTecho techo);

};

#endif // CONTROLADORSUBEYBAJA_H