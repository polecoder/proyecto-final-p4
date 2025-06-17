#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorFechaActual.h"
#include "IControladorListar.h"
#include "IControladorSubeYBaja.h"

class Factory {
    private:
        static Factory* instance;
        Factory();

    public:
        static Factory* getInstance();
        IControladorFechaActual* getControladorFechaActual();
        IControladorSubeYBaja* getControladorSubeYBaja();
        IControladorListar* getControladorListar();
        ~Factory();
};

#endif