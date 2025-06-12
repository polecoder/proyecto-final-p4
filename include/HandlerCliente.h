#ifndef HANDLERCLIENTE_H
#define HANDLERCLIENTE_H

#include "Cliente.h"
#include <map>
#include <string>
using namespace std;

class HandlerCliente {
private:
    static HandlerCliente* instancia;
    map<string, Cliente*> clientes;

    HandlerCliente();

public:
    static HandlerCliente* getInstancia();

    void agregarCliente(Cliente* cliente);
    Cliente* obtenerCliente( string& nickname);
    bool existeCliente( string& nickname);

    ~HandlerCliente();
};

#endif