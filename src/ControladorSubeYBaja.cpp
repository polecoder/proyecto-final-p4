#include "ControladorSubeYBaja.h"
using namespace std;

ControladorSubeYBaja *ControladorSubeYBaja::instance = NULL;

ControladorSubeYBaja::ControladorSubeYBaja()
{
    handlerInmuebles = HandlerInmuebles::getInstance();
}

ControladorSubeYBaja *ControladorSubeYBaja::getInstance()
{
    if (instance == NULL)
    {
        instance = new ControladorSubeYBaja();
    }
    return instance;
}

bool ControladorSubeYBaja::existeInmueble(int codigoInmueble)
{
    return handlerInmuebles->existeInmueble(codigoInmueble);
}

void ControladorSubeYBaja::eliminarInmueble(int codigoInmueble)
{
    Inmueble *inmuebleElim = handlerInmuebles->getInmueble(codigoInmueble);
    if (inmuebleElim != NULL)
    {
        Propietario *propietario = inmuebleElim->getPropietario();
        if (propietario != NULL)
        {
            vector<Inmueble *> &inmuebles = propietario->getInmuebles();
            vector<Inmueble *>::iterator inmuebleLinkeado = find(inmuebles.begin(), inmuebles.end(), inmuebleElim);
            if (inmuebleLinkeado != inmuebles.end())
            {
                inmuebles.erase(inmuebleLinkeado);
            }
        }
        handlerInmuebles->eliminarInmuebleColeccion(codigoInmueble);
        delete inmuebleElim;
    }
}

ControladorSubeYBaja::~ControladorSubeYBaja() {}