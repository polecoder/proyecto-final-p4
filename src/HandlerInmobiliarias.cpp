#include <string>
#include <map>
#include <iostream>
#include "../include/HandlerInmobiliarias.h"
#include "../include/Inmobiliaria.h"

using namespace std;

HandlerInmobiliarias *HandlerInmobiliarias::instancia = nullptr;

HandlerInmobiliarias::HandlerInmobiliarias() {}

HandlerInmobiliarias::~HandlerInmobiliarias()
{
    for (map<string, Inmobiliaria *>::iterator it = this->coleccionInmobiliarias.begin(); it != this->coleccionInmobiliarias.end(); it++)
    {
        delete it->second;
    }
    this->coleccionInmobiliarias.clear();
}

HandlerInmobiliarias *HandlerInmobiliarias::getInstancia()
{
    if (instancia == nullptr)
    {
        instancia = new HandlerInmobiliarias();
    }
    return instancia;
}

void HandlerInmobiliarias::agregarInmobiliaria(Inmobiliaria *inmobiliaria)
{
    string nickname = inmobiliaria->getNickname();
    this->coleccionInmobiliarias[nickname] = inmobiliaria;
}

void HandlerInmobiliarias::eliminarInmobiliaria(string nickname)
{
    // find() retorna this->coleccionInmobiliarias.end() si el elemento no existe
    map<string, Inmobiliaria *>::iterator it = this->coleccionInmobiliarias.find(nickname);
    if (it != this->coleccionInmobiliarias.end())
    {
        delete it->second; // Llama al destructor de Inmobiliaria
        coleccionInmobiliarias.erase(it);
    }
}

bool HandlerInmobiliarias::existeInmobiliaria(string nickname)
{
    // find() retorna this->coleccionInmobiliarias.end() si el elemento no existe
    return this->coleccionInmobiliarias.find(nickname) != this->coleccionInmobiliarias.end();
}

Inmobiliaria *HandlerInmobiliarias::getInmobiliaria(string nickname)
{
    return this->coleccionInmobiliarias[nickname];
}

const map<string, Inmobiliaria *> &HandlerInmobiliarias::getColeccionInmobiliarias() const
{
    return this->coleccionInmobiliarias;
}

vector<AdministraPropiedad *> HandlerInmobiliarias::getColeccionAdministraPropiedad(string nickname)
{
    return coleccionInmobiliarias[nickname]->getAdministraProps();
};


void HandlerInmobiliarias::destroy()
{
    delete instancia;
    instancia = NULL;
}