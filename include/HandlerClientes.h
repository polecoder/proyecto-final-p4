#ifndef HANDLERCLIENTES_H
#define HANDLERCLIENTES_H
#include "Cliente.h"
#include <map>
#include <string>

using namespace std;

class HandlerClientes
{
private:
    map<string, Cliente *> coleccionClientes;
    static HandlerClientes *instancia;
    HandlerClientes();

public:
    static HandlerClientes *getInstancia();
    ~HandlerClientes();

    void agregarCliente(Cliente *cliente);
    void eliminarCliente(string nickname);
    bool existeCliente(string nickname);

    Cliente *getCliente(string nickname);
    const map<string, Cliente *> &getColeccionClientes() const; // ACLARACIÓN: La definición de la función es de esta forma porque:
                                                                //  queremos devolver una referencia a la colección no modificable, que además no modifique al objeto desde el cual se llama al método
    void imprimirColeccionClientes();
};

#endif
