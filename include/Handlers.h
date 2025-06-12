#ifndef HANDLERS_H
#define HANDLERS_H

#include <string>
#include <map>
#include "Cliente.h"
#include "Inmobiliaria.h"
#include "Propietario.h"

using namespace std;

class HandlerPropietarios
{
private:
    map<string, Propietario> coleccionPropietarios;
    static HandlerPropietarios *instance;
    /**
     * @brief Constructor de HandlerPropietarios (PRIVADO)
     *
     */
    HandlerPropietarios();

public:
    /**
     * @brief Getter para la instancia del HandlerPropietarios
     *
     * @return HandlerPropietarios
     */
    static HandlerPropietarios *getInstance();
    /**
     * @brief Destructor de HandlerPropietarios
     *
     */
    ~HandlerPropietarios();
    /**
     * @brief Agrega un Propietario a la colección de Propietarios, se utiliza el nickname del propietario pasado por parámetro para agregarlo a la colección
     *
     * @param propietario El propietario que se quiere agregar a la colección
     */
    void agregarPropietario(const Propietario &propietario);
    /**
     * @brief Elimina al Propietario "p" tal que p.nickname=nickname de la colección de Propietarios y libera la memoria asociada a dicho objeto "p"
     *
     * PRE-CONDICIÓN: existePropietario(nickname) == true
     *
     * @param nickname El nickname del propietario que se quiere eliminar
     */
    void eliminarPropietario(string nickname);
    /**
     * @brief Devuelve true si y sólo si existe un Propietario "p" en la colección tal que p.nickname=nickname. En caso contrario devuelve false
     *
     * @param nickname El nickname del propietario que se quiere buscar
     */
    bool existePropietario(string nickname);
    /**
     * @brief Devuelve el Propietario "p" en la colección de Propietarios tal que p.nickname=nickname
     *
     * PRE-CONDICIÓN: existePropietario(nickname) == true
     *
     * @param nickname El nickname del propietario que se quiere devolver
     * @return Un Propietario p tal que p.nickname=nickname
     */
    Propietario getPropietario(string nickname);
    /**
     * @brief Devuelve la colección de todos los propietarios que hay en el sistema
     *
     * @return map<string, Propietario>
     */
    map<string, Propietario> getColeccionPropietarios();
};

class HandlerInmobiliarias
{
private:
    map<string, Inmobiliaria> coleccionInmobiliarias;
    static HandlerInmobiliarias *instance;
    /**
     * @brief Constructor de HandlerInmobiliarias (PRIVADO)
     *
     */
    HandlerInmobiliarias();

public:
    /**
     * @brief Getter para la instancia del HandlerInmobiliarias
     *
     * @return HandlerInmobiliarias
     */
    static HandlerInmobiliarias *getInstance();
    /**
     * @brief Destructor de HandlerInmobiliarias
     *
     */
    ~HandlerInmobiliarias();
    /**
     * @brief Agrega un Inmobiliaria a la colección de Inmobiliarias, se utiliza el nickname del inmobiliaria pasado por parámetro para agregarlo a la colección
     *
     * @param inmobiliaria El inmobiliaria que se quiere agregar a la colección
     */
    void agregarInmobiliaria(const Inmobiliaria &inmobiliaria);
    /**
     * @brief Elimina la Inmobiliaria "i" tal que i.nickname=nickname de la colección de Inmobiliarias y libera la memoria asociada a dicho elemento "i"
     *
     * PRE-CONDICIÓN: existeInmobiliaria(nickname) == true
     *
     * @param nickname El nickname de la inmobiliaria que se quiere eliminar
     */
    void eliminarInmobiliaria(string nickname);
    /**
     * @brief Devuelve true si y sólo si existe un Inmobiliaria i en la colección tal que i.nickname=nickname. En caso contrario devuelve false
     *
     * @param nickname El nickname del inmobiliaria que se quiere buscar
     */
    bool existeInmobiliaria(string nickname);
    /**
     * @brief Devuelve el Inmobiliaria i en la colección de Inmobiliarias tal que i.nickname=nickname
     *
     * PRE-CONDICIÓN: existeInmobiliaria(nickname) == true
     *
     * @param nickname El nickname del inmobiliaria que se quiere devolver
     * @return Un Inmobiliaria i tal que i.nickname=nickname
     */
    Inmobiliaria getInmobiliaria(string nickname);
    /**
     * @brief Devuelve la colección de todos las inmobiliarias que hay en el sistema
     *
     * @return map<string, Inmobiliaria>
     */
    map<string, Inmobiliaria> getColeccionInmobiliarias();
};

class HandlerClientes
{
private:
    map<string, Cliente> coleccionClientes;
    static HandlerClientes *instance;
    /**
     * @brief Constructor de HandlerClientes (PRIVADO)
     *
     */
    HandlerClientes();

public:
    /**
     * @brief Getter para la instancia del HandlerClientes
     *
     * @return HandlerClientes
     */
    static HandlerClientes *getInstance();
    /**
     * @brief Destructor de HandlerClientes
     *
     */
    ~HandlerClientes();
    /**
     * @brief Agrega un Cliente a la colección de Clientes, se utiliza el nickname del cliente pasado por parámetro para agregarlo a la colección
     *
     * @param cliente El cliente que se quiere agregar a la colección
     */
    void agregarCliente(const Cliente &cliente);
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
    Cliente getCliente(string nickname);
    /**
     * @brief Devuelve la colección de todos las clientes que hay en el sistema
     *
     * @return map<string, Cliente>
     */
    map<string, Cliente> getColeccionClientes();
};

#endif