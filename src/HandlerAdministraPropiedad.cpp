#include "../include/HandlerAdministraPropiedad.h"
#include <iostream>

HandlerAdministraPropiedad *HandlerAdministraPropiedad::instancia = NULL;

HandlerAdministraPropiedad::HandlerAdministraPropiedad()
{
    coleccionAdministraPropiedad = vector<AdministraPropiedad *>();
}

const vector<AdministraPropiedad *> &HandlerAdministraPropiedad::getColecccionAdministraPropiedad() const
{
    return coleccionAdministraPropiedad;
}

void HandlerAdministraPropiedad::agregarAdministraPropiedad(AdministraPropiedad *AdministraPropiedad)
{
    coleccionAdministraPropiedad.push_back(AdministraPropiedad);
}

HandlerAdministraPropiedad *HandlerAdministraPropiedad::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new HandlerAdministraPropiedad();
    }
    return instancia;
}

HandlerAdministraPropiedad::~HandlerAdministraPropiedad()
{
    for (vector<AdministraPropiedad *>::iterator it = coleccionAdministraPropiedad.begin(); it != coleccionAdministraPropiedad.end(); ++it)
    {
        delete *it;
    }
    coleccionAdministraPropiedad.clear();
}


void HandlerAdministraPropiedad::destroy()
{
    delete instancia;
    instancia = NULL;
}