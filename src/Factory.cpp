#include "../include/Factory.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ControladorSubeYBaja.h"
#include "../include/IControladorSubeYBaja.h"
#include "../include/ControladorFechaActual.h"
#include "../include/IControladorFechaActual.h"
#include "../include/ControladorListar.h"
#include "../include/IControladorListar.h"
#include "../include/ControladorSuscripciones.h"
#include "../include/IControladorSuscripciones.h"
#include <cstddef>

Factory *Factory::instancia = NULL;

Factory::Factory() {}

Factory::~Factory() {}

Factory *Factory::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new Factory();
    }
    return instancia;
}

IControladorFechaActual *Factory::getControladorFechaActual()
{
    return ControladorFechaActual::getInstancia();
}

IControladorSubeYBaja *Factory::getControladorSubeYBaja()
{
    return ControladorSubeYBaja::getInstancia();
}

IControladorListar *Factory::getControladorListar()
{
    return ControladorListar::getInstancia();
}

IControladorSuscripciones *Factory::getControladorSuscripciones()
{
    return ControladorSuscripciones::getInstancia();
}


void Factory::destroy()
{
    delete instancia;
    instancia = NULL;
}