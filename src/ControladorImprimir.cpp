#include "../include/ControladorImprimir.h"
#include <cstddef>

ControladorImprimir *ControladorImprimir::instancia = NULL;

ControladorImprimir::ControladorImprimir()
{
    this->handlerInmobiliarias = HandlerInmobiliarias::getInstancia();
    this->handlerPublicaciones = HandlerPublicacion::getInstancia();
    this->handlerClientes = HandlerClientes::getInstancia();
    this->handlerPropietarios = HandlerPropietarios::getInstancia();
    this->handlerInmuebles = HandlerInmueble::getInstancia();
    this->handlerAdministraPropiedad = HandlerAdministraPropiedad::getInstancia();
}

ControladorImprimir *ControladorImprimir::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new ControladorImprimir();
    }
    return instancia;
}

ControladorImprimir::~ControladorImprimir() {}

void ControladorImprimir::imprimirColeccionClientes()
{
    this->handlerClientes->imprimirColeccionClientes();
}

void ControladorImprimir::imprimirColeccionInmobiliarias()
{
    this->handlerInmobiliarias->imprimirColeccionInmobiliarias();
}

void ControladorImprimir::imprimirColeccionInmuebles()
{
    this->handlerInmuebles->imprimirColeccionInmuebles();
}

void ControladorImprimir::imprimirColeccionPropietarios()
{
    this->handlerPropietarios->imprimirColeccionPropietarios();
}

void ControladorImprimir::imprimirColeccionPublicaciones()
{
    this->handlerPublicaciones->imprimirColeccionPublicaciones();
}

void ControladorImprimir::imprimirColeccionAdministraPropiedad()
{
    this->handlerAdministraPropiedad->imprimirColeccionAdministraPropiedad();
}