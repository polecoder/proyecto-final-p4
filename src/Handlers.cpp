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