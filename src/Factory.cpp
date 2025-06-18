#include "../include/Factory.h"
#include "../include/ControladorFechaActual.h"
#include "../include/IControladorFechaActual.h"
#include "../include/ControladorListar.h"
#include "../include/IControladorListar.h"
#include "../include/ControladorSuscripciones.h"
#include "../include/IControladorSuscripciones.h"
#include <cstddef>

Factory *Factory::instance = NULL;

Factory::Factory() {}

Factory *Factory::getInstance()
{
    if (instance == NULL)
    {
        instance = new Factory();
    }
    return instance;
}

IControladorFechaActual *Factory::getControladorFechaActual()
{
    return ControladorFechaActual::getInstance();
}

IControladorListar *Factory::getControladorListar()
{
    return ControladorListar::getInstance();
}

IControladorSuscripciones *Factory::getControladorSuscripciones()
{
    return ControladorSuscripciones::getInstance();
}