#include "../include/HandlerAdministraPropiedad.h"

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

HandlerAdministraPropiedad * HandlerAdministraPropiedad::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new HandlerAdministraPropiedad();
    }
    return instancia;
}