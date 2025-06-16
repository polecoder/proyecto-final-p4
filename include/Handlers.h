#ifndef HANDLERS_H
#define HANDLERS_H

#include "Inmueble.h"
#include "Inmobiliaria.h"
#include <map>

using namespace std;

class HandlerInmuebles
{
private:
    map<int, Inmueble *> coleccionInmuebles;
    static HandlerInmuebles *instance;
    /**
     * @brief Constructor de HandlerInmuebles
     *
     */
    HandlerInmuebles();

public:
    /**
     * @brief Getter de la instancia del HandlerInmuebles
     *
     * @return HandlerInmuebles*
     */
    static HandlerInmuebles *getInstance();
    /**
     * @brief Devuelve true si existe un inmueble en la coleccion tal que inmueble.codigoInmueble=codigoInmueble, de lo contrario devuelve false
     *
     * @param codigoInmueble
     */
    bool existeInmueble(int codigoInmueble);
    /**
     * @brief Getter de Inmueble
     *
     * @return Inmueble
     */
    Inmueble *getInmueble(int codigoInmueble);
    /**
     * @brief Getter de la Colecccion Inmueble
     *
     * @return map<int, Inmueble*>
     */
    const map<int, Inmueble *> &getColecccionInmuebles() const;
    /**
     * @brief Elimina de la coleccion el inmueble que coincida con el codigo
     *
     * @param codigoInmueble
     */
    void eliminarInmuebleColeccion(int codigoInmueble);
    /**
     * @brief Destructor de HandlerInmueble
     *
     */
    ~HandlerInmuebles();
};

class HandlerInmobiliarias
{
private:
    map<string, Inmobiliaria *> coleccionInmobiliarias;
    static HandlerInmobiliarias *instance;
    /**
     * @brief Constructor de HandlerInmobiliarias
     *
     */
    HandlerInmobiliarias();

public:
    /**
     * @brief Getter de la instancia del HandlerInmobiliarias
     *
     * @return HandlerInmobiliarias*
     */
    static HandlerInmobiliarias *getInstance();
    /**
     * @brief Getter de la Colecccion Inmobiliaria
     *
     * @return map<int, Inmobiliaria*>
     */
    const map<string, Inmobiliaria *> &getColecccionInmobiliaria() const;
};
#endif