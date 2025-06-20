#ifndef CONTROLADORSUBEYBAJA_H
#define CONTROLADORSUBEYBAJA_H

#include "Publicacion.h"
#include "Inmobiliaria.h"
#include "HandlerInmobiliarias.h"
#include "HandlerPublicacion.h"
#include "DTFecha.h"
#include "IControladorFechaActual.h"
#include "AdministraPropiedad.h"
#include "TipoPublicacion.h"
#include "DTNotificacion.h"
#include "Casa.h"
#include "IControladorSubeYBaja.h"
#include "Apartamento.h"
#include "TipoInmueble.h"
#include "TipoTecho.h"
#include "HandlerClientes.h"
#include "HandlerPropietarios.h"
#include "HandlerInmueble.h"
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
    HandlerInmueble *HInmueble;

    Inmobiliaria* UltimaInmobiliaria = nullptr; // Tuve que agregarlo para una funcion nueva :(
    Propietario* UltimoPropietario = nullptr; // No estoy seguro de si tiene que estar aca, me parece que en el handler no, pero creo que es necesario.    
    int codigoUltimoInmueble = 0; // Para llevar un control del ultimo codigo de inmueble creado  

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
    void altaCasa (string direccion, int numeroPuerta, int superficie,int anoConstruccion, bool esPH,TipoTecho techo);
    void altaApartamento (string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes);
    void finalizarAltaUsuario();

};

#endif // CONTROLADORSUBEYBAJA_H