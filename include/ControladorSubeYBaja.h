#ifndef CONTROLADORSUBEYBAJA_H
#define CONTROLADORSUBEYBAJA_H

#include "Inmueble.h"
#include "Propietario.h"
#include "DTInmueble.h"
#include "DTInmuebleListado.h"
#include "IControladorSubeYBaja.h"
#include "Handlers.h"
#include <set>

class ControladorSubeYBaja : public IControladorSubeYBaja
{
private:
    static ControladorSubeYBaja *instance;
    HandlerInmuebles *handlerInmuebles;
    HandlerInmobiliarias *handlerInmobiliarias;
    HandlerAdministraPropiedad *handlerAdministraPropiedad;
    /**
     * @brief Constructor de ControladorSubeYBaja
     *
     */
public:
    /**
     * @brief Getter de la instancia
     *
     * @return ControladorSubeYBaja
     */
    static ControladorSubeYBaja *getInstance();
    /**
     * @brief Devuelve true si existe un inmueble tal que inmueble.codigoInmueble=codigoInmueble, de lo contrario devuelve false
     *
     * @param codigoInmueble
     *
     */
    bool existeInmueble(int codigoInmueble);
    /**
     * @brief Obtiene inmueble tal que inmueble.codigoInmueble=codigoInmueble
     *
     * @param codigoInmueble
     * @return Inmueble*
     */
    Inmueble *getInmueble(int codigoInmueble);
    /**
     * @brief Elimina la instancia de inmueble y todos sus links
     *
     * @param codigoInmueble
     */
    void eliminarInmueble(int codigoInmueble);
    /**
     * @brief Obtiene la inmobiliaria tal que inmobiliaria.nickname = nicknameInmobiliaria
     *
     * @param nicknameInmobiliaria
     * @return Inmobiliaria*
     */
    Inmobiliaria *getInmobiliaria(string nicknameInmobiliaria);
    /**
     * @brief Crea una instancia de AdministraPropiedad
     *
     * @param nicknameInmobiliaria
     * @param codigoInmueble
     */
    void altaAdministraPropiedad(string nicknameInmobiliaria, int codigoInmueble);
    /**
     * @brief Destructor de ControladorSubeYBaja
     *
     */
    ~ControladorSubeYBaja();
};
#endif