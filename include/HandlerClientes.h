#ifndef HANDLERCLIENTES_H
#define HANDLERCLIENTES_H
#include "Cliente.h"
#include <map>
#include <string>

using namespace std;

class HandlerClientes{
private:
    map<string, Cliente*> coleccionClientes;
    static HandlerClientes* instancia;
    HandlerClientes();

public:
    static HandlerClientes* getInstancia();
    ~HandlerClientes();

    void agregarCliente(Cliente* &cliente);
    void eliminarCliente(string nickname);
    bool existeCliente(string nickname);

    Cliente* getCliente(string nickname);
    map<string, Cliente*> getColeccionClientes();
};

#endif