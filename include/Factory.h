
#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorFechaActual.h"
#include "IControladorListar.h"
#include "IControladorSubeYBaja.h"
#include "IControladorSuscripciones.h"

class Factory
{
private:
    static Factory *instancia;
    Factory();

public:
    static Factory *getInstancia();
    IControladorFechaActual *getControladorFechaActual();
    IControladorSubeYBaja *getControladorSubeYBaja();
    IControladorListar *getControladorListar();
    IControladorSuscripciones *getControladorSuscripciones();
    ~Factory();
};


#endif