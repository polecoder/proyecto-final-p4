#include "../include/ControladorFechaActual.h"
#include <cstddef>

ControladorFechaActual *ControladorFechaActual::instancia = NULL;

ControladorFechaActual::ControladorFechaActual()
{
    fechaActual = new DTFecha(1, 1, 1900);
}

ControladorFechaActual *ControladorFechaActual::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new ControladorFechaActual();
    }
    return instancia;
}

DTFecha *ControladorFechaActual::getFechaActual()
{
    return new DTFecha(*fechaActual);
}
void ControladorFechaActual::setNewFechaActual(int dia, int mes, int anio)
{
    delete fechaActual;
    fechaActual = new DTFecha(dia, mes, anio);
}

ControladorFechaActual::~ControladorFechaActual()
{
    delete fechaActual;
}

void ControladorFechaActual::destroy()
{
    delete instancia;
    instancia = NULL;
}