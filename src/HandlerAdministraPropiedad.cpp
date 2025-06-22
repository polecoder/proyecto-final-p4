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

void HandlerAdministraPropiedad::imprimirColeccionAdministraPropiedad()
{
    vector<AdministraPropiedad *>::iterator it;
    int contador = 1;
    cout << "-- IMPRIMIR COLECCION ADMINISTRAPROPIEDAD --" << endl;
    for (it = this->coleccionAdministraPropiedad.begin(); it != this->coleccionAdministraPropiedad.end(); it++)
    {
        cout << contador << " - " << **it << endl;
        contador++;
    }
}