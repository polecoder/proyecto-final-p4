#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorFechaActual.h"
#include "IControladorListar.h"
#include "IControladorSubeYBaja.h"
#include "IControladorSuscripciones.h"
#include "IControladorImprimir.h"

class Factory
{
private:
    static Factory *instancia;
    Factory();

public:
    static Factory *getInstancia();
    static void destroy();
    ~Factory();

    IControladorFechaActual *getControladorFechaActual();
    IControladorSubeYBaja *getControladorSubeYBaja();
    IControladorListar *getControladorListar();
    IControladorSuscripciones *getControladorSuscripciones();
    IControladorImprimir *getControladorImprimir();
};

#endif