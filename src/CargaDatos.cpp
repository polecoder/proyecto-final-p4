#include "../include/CargaDatos.h"
#include <cstddef>

<<<<<<< HEAD
CargaDatos* CargaDatos::instance = NULL;

CargaDatos::CargaDatos() {
    //TODO: Cargar los datos de prueba
}

CargaDatos* CargaDatos::getInstance() {
    if (instance == 0) {
        instance = new CargaDatos();
    }
    return instance;
=======
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
>>>>>>> origin/main
}