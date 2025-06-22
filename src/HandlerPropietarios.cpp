#include <map>
#include <string>
#include <iostream>
#include "../include/Propietario.h"
#include "../include/HandlerPropietarios.h"

using namespace std;

HandlerPropietarios *HandlerPropietarios::instancia = NULL;

HandlerPropietarios::HandlerPropietarios()
{
    map<string, Propietario *> coleccionPropietarios;
    this->coleccionPropietarios = coleccionPropietarios;
}

HandlerPropietarios *HandlerPropietarios::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new HandlerPropietarios;
    }
    return instancia;
}

HandlerPropietarios::~HandlerPropietarios()
{
    for (map<string, Propietario *>::iterator it = this->coleccionPropietarios.begin(); it != this->coleccionPropietarios.end(); it++)
    {
        delete it->second;
    }
    this->coleccionPropietarios.clear();
}

void HandlerPropietarios::agregarPropietario(Propietario *&propietario)
{
    string nickname = propietario->getNickname();
    this->coleccionPropietarios[nickname] = propietario;
}

void HandlerPropietarios::eliminarPorpietario(string nickname)
{
    // find() retorna this->coleccionPropietarios.end() si el elemento no existe
    map<string, Propietario *>::iterator it = this->coleccionPropietarios.find(nickname);
    if (it != this->coleccionPropietarios.end())
    {
        delete it->second; // Llama al destructor de Propietario
        coleccionPropietarios.erase(it);
    }
}

bool HandlerPropietarios::existePropietario(string nickname)
{
    // find() retorna this->coleccionPropietarios.end() si el elemento no existe
    return this->coleccionPropietarios.find(nickname) != this->coleccionPropietarios.end();
}

Propietario *HandlerPropietarios::getPropietario(string nickname)
{
    return this->coleccionPropietarios[nickname];
}

const map<string, Propietario *> &HandlerPropietarios::getColeccionPropietarios() const
{
    return this->coleccionPropietarios;
}


void HandlerPropietarios::destroy()
{
    delete instancia;
    instancia = NULL;
}