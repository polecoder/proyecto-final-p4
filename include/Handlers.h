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
     * @brief Devuelve true si existe una Inmobiliaria tal que Inmobiliaria.codigo=codigoInmueble, de lo contrario devuelve false
     *
     * @param codigoInmueble
     */
    bool existeInmobiliaria(string nicknameInmobiliaria);
    /**
     * @brief Obtiene la inmobiliaria de la coleccion
     *
     * @return Inmobiliaria
     */
    Inmobiliaria *getInmobiliaria(string nicknameInmobiliaria);
    /**
     * @brief Getter de la Colecccion Inmobiliaria
     *
     * @return map<int, Inmobiliaria*>
     */
    const map<string, Inmobiliaria *> &getColecccionInmobiliaria();
};

class HandlerAdministraPropiedad
{
private:
    vector<AdministraPropiedad *> coleccionAdministraPropiedad;
    static HandlerAdministraPropiedad *instance;
    /**
     * @brief Constructor de HandlerAdministraPropiedad
     *
     */
    HandlerAdministraPropiedad();

public:
    /**
     * @brief Getter de la instancia del HandlerAdministraPropiedad
     *
     * @return HandlerAdministraPropiedad*
     */
    static HandlerAdministraPropiedad *getInstance();
    /**
     * @brief Getter de la Colecccion AdministraPropiedad
     *
     * @return map<DTFecha, AdministraPropiedad*>
     */
    const vector<AdministraPropiedad *> &getColecccionAdministraPropiedad() const;
    /**
     * @brief Agrega administraPropiedad a la coleccion
     *
     * @param administraPropiedad
     */
    void agregarAdministraPropiedad(AdministraPropiedad *administraPropiedad);
    /**
     * @brief Destructor de HandlerAdministraPropiedad
     *
     */
    ~HandlerAdministraPropiedad();
};

#endif