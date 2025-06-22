#ifndef CARGADATOS_H
#define CARGADATOS_H

#include "IControladorFechaActual.h"
#include "IControladorSubeYBaja.h"
#include "IControladorSuscripciones.h"

class CargaDatos
{
private:
    static CargaDatos *instancia;
    CargaDatos();
    IControladorSubeYBaja *interfazSubeYBaja;
    IControladorFechaActual *interfazFechaActual;
    IControladorSuscripciones *interfazSuscripciones;

public:
    static CargaDatos *getInstancia();
    ~CargaDatos();
    static void destroy();
};

#endif