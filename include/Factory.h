<<<<<<< HEAD
#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorFechaActual.h"

class Factory {
    private:
        static Factory* instance;
        Factory();

    public:
        static Factory* getInstance();
        IControladorFechaActual* getControladorFechaActual();
        //TODO: Get interfaces de controladores
        ~Factory();
};

=======
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

>>>>>>> origin/main
#endif