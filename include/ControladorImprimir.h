#ifndef CONTROLADORIMPRIMIR_H
#define CONTROLADORIMPRIMIR_H

#include "HandlerAdministraPropiedad.h"
#include "HandlerInmobiliarias.h"
#include "HandlerPublicacion.h"
#include "HandlerClientes.h"
#include "HandlerPropietarios.h"
#include "HandlerInmueble.h"
#include "IControladorImprimir.h"

class ControladorImprimir : public IControladorImprimir
{
private:
    static ControladorImprimir *instancia;
    HandlerAdministraPropiedad *handlerAdministraPropiedad;
    HandlerInmobiliarias *handlerInmobiliarias;
    HandlerPublicacion *handlerPublicaciones;
    HandlerClientes *handlerClientes;
    HandlerPropietarios *handlerPropietarios;
    HandlerInmueble *handlerInmuebles;
    ControladorImprimir();

public:
    static ControladorImprimir *getInstancia();
    ~ControladorImprimir();
    void imprimirColeccionClientes();
    void imprimirColeccionInmobiliarias();
    void imprimirColeccionInmuebles();
    void imprimirColeccionPropietarios();
    void imprimirColeccionPublicaciones();
    void imprimirColeccionAdministraPropiedad();
};

#endif