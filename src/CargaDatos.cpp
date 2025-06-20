#include "../include/CargaDatos.h"
#include <cstddef>

CargaDatos *CargaDatos::instancia = NULL;

CargaDatos::CargaDatos()
{
    // TODO: Cargar los datos de prueba
}

CargaDatos *CargaDatos::getInstancia()
{
    if (instancia == 0)
    {
        instancia = new CargaDatos();
    }
    return instancia;
}