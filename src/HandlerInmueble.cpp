#include "../include/HandlerInmueble.h"
#include <iostream>
#include <map>
using namespace std;

HandlerInmueble *HandlerInmueble::instancia = nullptr;

HandlerInmueble::HandlerInmueble() {
    // No es necesario inicializar el mapa, ya que se crea vacio por defecto
};

HandlerInmueble::~HandlerInmueble()
{
    for (map<int, Inmueble *>::iterator it = this->coleccionInmuebles.begin(); it != this->coleccionInmuebles.end(); it++)
    {
        delete it->second;
    }
    this->coleccionInmuebles.clear();
}

HandlerInmueble *HandlerInmueble::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new HandlerInmueble();
    }
    return instancia;
}

bool HandlerInmueble::existeInmueble(int codigoInmueble)
{
    return coleccionInmuebles.find(codigoInmueble) != coleccionInmuebles.end();
}

void HandlerInmueble::agregarInmueble(Inmueble *inmueble)
{
    coleccionInmuebles.insert({inmueble->getCodigo(), inmueble});
}

void HandlerInmueble::eliminarInmueble(int codigo)
{
    coleccionInmuebles.erase(codigo);
}

map<int, Inmueble *> HandlerInmueble::DevolverInmuebles()
{
    return coleccionInmuebles;
}
Inmueble *HandlerInmueble::DevolverInmueble(int codigo)
{
    return coleccionInmuebles[codigo];
}

void HandlerInmueble::imprimirColeccionInmuebles()
{
    map<int, Inmueble *>::iterator it;
    int contador = 1;
    cout << "-- IMPRIMIR COLECCION INMUEBLES --" << endl;
    for (it = this->coleccionInmuebles.begin(); it != this->coleccionInmuebles.end(); it++)
    {
        cout << contador << " - " << *(it->second) << endl;
    }
}

void HandlerInmueble::destroy()
{
    delete instancia;
    instancia = NULL;
}