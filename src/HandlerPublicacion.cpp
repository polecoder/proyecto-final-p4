#include "../include/HandlerPublicacion.h"
#include <string>
#include <map>
#include <set>
#include <iostream>

using namespace std;

HandlerPublicacion *HandlerPublicacion::instancia = NULL;

HandlerPublicacion::HandlerPublicacion() {}

HandlerPublicacion *HandlerPublicacion::getInstancia()
{
    if (instancia == NULL)
        instancia = new HandlerPublicacion();
    return instancia;
}

void HandlerPublicacion::agregarPublicacion(Publicacion *publicacion)
{
    coleccionPublicaciones.insert({publicacion->getCodigo(), publicacion});
}

void HandlerPublicacion::eliminarPublicacion(int codigo)
{
    map<int, Publicacion *>::iterator it = coleccionPublicaciones.find(codigo); // si ponemos como precondicion que existe podemos sacar este if
    if (it != coleccionPublicaciones.end())
    {
        coleccionPublicaciones.erase(it);
        delete it->second;
    }
}

bool HandlerPublicacion::existePublicacion(int codigo)
{
    return coleccionPublicaciones.find(codigo) != coleccionPublicaciones.end();
};

Publicacion *HandlerPublicacion::getPublicacion(int codigo)
{
    return coleccionPublicaciones.at(codigo);
}

set<Publicacion *> HandlerPublicacion::obtenerPublicacionesActivas()
{
    set<Publicacion *> publicacionesActivas;
    map<int, Publicacion *>::iterator it;
    for (it = coleccionPublicaciones.begin(); it != coleccionPublicaciones.end(); ++it)
    {
        if ((*it).second->getActiva())
            publicacionesActivas.insert((*it).second);
    }
    return publicacionesActivas;
};

HandlerPublicacion::~HandlerPublicacion()
{
    for (map<int, Publicacion *>::iterator it = this->coleccionPublicaciones.begin(); it != this->coleccionPublicaciones.end(); it++)
    {
        delete it->second;
    }
    this->coleccionPublicaciones.clear();
};



void HandlerPublicacion::destroy()
{
    delete instancia;
    instancia = NULL;
}