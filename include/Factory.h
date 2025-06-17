#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorFechaActual.h"
#include "IControladorListar.h"
#include "IControladorSuscripciones.h"

class Factory
{
private:
    static Factory *instance;
    Factory();

public:
    static Factory *getInstance();
    IControladorFechaActual *getControladorFechaActual();
    IControladorListar *getControladorListar();
    IControladorSuscripciones *getControladorSuscripciones();
    // TODO: Get interfaces de controladores
    ~Factory();
};

#endif