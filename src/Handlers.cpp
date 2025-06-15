#include "Handlers.h"

HandlerInmuebles *HandlerInmuebles::instance = NULL;

HandlerInmuebles::HandlerInmuebles()
{
    map<int, Inmueble *> coleccionInmuebles;
    this->coleccionInmuebles = coleccionInmuebles;
}

HandlerInmuebles *HandlerInmuebles::getInstance()
{
    if (instance == NULL)
    {
        instance = new HandlerInmuebles();
    }
    return instance;
}

bool HandlerInmuebles::existeInmueble(int codigoInmueble)
{
    return coleccionInmuebles.find(codigoInmueble) != coleccionInmuebles.end();
}

Inmueble *HandlerInmuebles::getInmueble(int codigoInmueble)
{
    if (existeInmueble(codigoInmueble))
    {
        return coleccionInmuebles[codigoInmueble];
    }
    return NULL;
}

const map<int, Inmueble *> &HandlerInmuebles::getColecccionInmuebles() const
{
    return coleccionInmuebles;
}

void HandlerInmuebles::eliminarInmuebleColeccion(int codigoInmueble)
{
    coleccionInmuebles.erase(codigoInmueble);
}

HandlerInmuebles::~HandlerInmuebles()
{
    for (auto &par : coleccionInmuebles)
    {
        delete par.second;
    }
    coleccionInmuebles.clear();
}