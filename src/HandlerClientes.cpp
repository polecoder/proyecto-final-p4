#include <string>
#include <map>
#include <iostream>
#include "../include/HandlerClientes.h"
#include "../include/Cliente.h"

using namespace std;

HandlerClientes *HandlerClientes::instancia = NULL;

HandlerClientes::HandlerClientes()
{
    map<string, Cliente *> coleccionClientes;
    this->coleccionClientes = coleccionClientes;
}

HandlerClientes *HandlerClientes::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new HandlerClientes;
    }
    return instancia;
}

HandlerClientes::~HandlerClientes()
{
    for (map<string, Cliente *>::iterator it = this->coleccionClientes.begin(); it != this->coleccionClientes.end(); it++)
    {
        delete it->second;
    }
    this->coleccionClientes.clear();
}

void HandlerClientes::agregarCliente(Cliente *cliente) // saco el "&" de aca
{
    pair<string, Cliente *> entry(cliente->getNickname(), cliente);
    coleccionClientes.insert(entry);
    // string nickname = cliente->getNickname();
    // this->coleccionClientes[nickname] = cliente;
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


void HandlerClientes::destroy()
{
    delete instancia;
    instancia = NULL;
}