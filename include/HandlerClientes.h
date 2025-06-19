#ifndef HANDLERCLIENTES_H
#define HANDLERCLIENTES_H

#include <string>
#include <map>
#include "Cliente.h"

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
    /**
     * @brief Agrega un Cliente a la colección de Clientes, se utiliza el nickname del cliente pasado por parámetro para agregarlo a la colección
     *
     * PRE-CONDICIÓN: existeCliente(cliente.nickname) == false
     *
     * @param cliente El cliente que se quiere agregar a la colección
     */
    void agregarCliente(Cliente *cliente);
    /**
     * @brief Elimina la Cliente "c" tal que c.nickname=nickname de la colección de Clientes y libera la memoria asociada a dicho elemento "c"
     *
     * PRE-CONDICIÓN: existeCliente(nickname) == true
     *
     * @param nickname El nickname del cliente que se quiere eliminar
     */
    void eliminarCliente(string nickname);
    /**
     * @brief Devuelve true si y sólo si existe un Cliente "c" en la colección tal que c.nickname=nickname. En caso contrario devuelve false
     *
     * @param nickname El nickname del cliente que se quiere buscar
     */
    bool existeCliente(string nickname);
    /**
     * @brief Devuelve el Cliente c en la colección de Clientes tal que c.nickname=nickname
     *
     * PRE-CONDICIÓN: existeCliente(nickname) == true
     *
     * @param nickname El nickname del cliente que se quiere devolver
     * @return Un Cliente c tal que c.nickname=nickname
     */
    Cliente *getCliente(string nickname);
    /**
     * @brief Devuelve la colección de todos las clientes que hay en el sistema.
     *
     * @return map<string, Cliente*>
     */
    const map<string, Cliente *> &getColeccionClientes() const; // ACLARACIÓN: La definición de la función es de esta forma porque: queremos devolver una referencia a la colección no modificable, que además no modifique al objeto desde el cual se llama al método
};

#endif // HANDLERCLIENTES_H