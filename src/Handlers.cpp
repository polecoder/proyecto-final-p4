#include <map>
#include <string>
#include "../include/Handlers.h"

using namespace std;

HandlerPropietarios *HandlerPropietarios::instance = NULL;

HandlerPropietarios::HandlerPropietarios()
{
    map<string, Propietario *> coleccionPropietarios;
    this->coleccionPropietarios = coleccionPropietarios;
}

HandlerPropietarios *HandlerPropietarios::getInstance()
{
    if (instance == NULL)
    {
        instance = new HandlerPropietarios;
    }
    return instance;
}

HandlerPropietarios::~HandlerPropietarios()
{
    map<string, Propietario *>::iterator it;

    for (it = this->coleccionPropietarios.begin(); it != this->coleccionPropietarios.end(); it++)
    {
        delete it->second;
    }

    this->coleccionPropietarios.clear();
}

void HandlerPropietarios::agregarPropietario(Propietario *propietario)
{
    string nickname = propietario->getNickname();
    this->coleccionPropietarios[nickname] = propietario;
}

void HandlerPropietarios::eliminarPropietario(string nickname)
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

HandlerInmobiliarias *HandlerInmobiliarias::instance = NULL;

HandlerInmobiliarias::HandlerInmobiliarias()
{
    map<string, Inmobiliaria *> coleccionInmobiliarias;
    this->coleccionInmobiliarias = coleccionInmobiliarias;
}

HandlerInmobiliarias *HandlerInmobiliarias::getInstance()
{
    if (instance == NULL)
    {
        instance = new HandlerInmobiliarias;
    }
    return instance;
}

HandlerInmobiliarias::~HandlerInmobiliarias()
{
    map<string, Inmobiliaria *>::iterator it;

    for (it = this->coleccionInmobiliarias.begin(); it != this->coleccionInmobiliarias.end(); it++)
    {
        delete it->second;
    }

    this->coleccionInmobiliarias.clear();
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

HandlerClientes *HandlerClientes::instance = NULL;

HandlerClientes::HandlerClientes()
{
    map<string, Cliente *> coleccionClientes;
    this->coleccionClientes = coleccionClientes;
}

HandlerClientes *HandlerClientes::getInstance()
{
    if (instance == NULL)
    {
        instance = new HandlerClientes;
    }
    return instance;
}

HandlerClientes::~HandlerClientes()
{
    map<string, Cliente *>::iterator it;

    for (it = this->coleccionClientes.begin(); it != this->coleccionClientes.end(); it++)
    {
        delete it->second;
    }

    this->coleccionClientes.clear();
}

void HandlerClientes::agregarCliente(Cliente *cliente)
{
    string nickname = cliente->getNickname();
    this->coleccionClientes[nickname] = cliente;
}

void HandlerClientes::eliminarCliente(string nickname)
{
    // find() retorna this->coleccionClientes.end() si el elemento no existe
    map<string, Cliente *>::iterator it = this->coleccionClientes.find(nickname);
    if (it != this->coleccionClientes.end())
    {
        delete it->second; // Llama al destructor de Cliente
        coleccionClientes.erase(it);
    }
}

bool HandlerClientes::existeCliente(string nickname)
{
    // find() retorna this->coleccionClientes.end() si el elemento no existe
    return this->coleccionClientes.find(nickname) != this->coleccionClientes.end();
}

Cliente *HandlerClientes::getCliente(string nickname)
{
    return this->coleccionClientes[nickname];
}

const map<string, Cliente *> &HandlerClientes::getColeccionClientes() const
{
    return this->coleccionClientes;
}