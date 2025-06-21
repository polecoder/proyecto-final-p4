#ifndef ICONTROLADORIMPRIMIR_H
#define ICONTROLADORIMPRIMIR_H

#include "HandlerInmobiliarias.h"
#include "HandlerPublicacion.h"
#include "HandlerClientes.h"
#include "HandlerPropietarios.h"
#include "HandlerInmueble.h"
#include "IControladorImprimir.h"

class IControladorImprimir
{
public:
    virtual void imprimirColeccionClientes() = 0;
    virtual void imprimirColeccionInmobiliarias() = 0;
    virtual void imprimirColeccionInmuebles() = 0;
    virtual void imprimirColeccionPropietarios() = 0;
    virtual void imprimirColeccionPublicaciones() = 0;
};

#endif