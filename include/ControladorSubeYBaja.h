#ifndef CONTROLADORSUBEYBAJA_H
#define CONTROLADORSUBEYBAJA_H

#include "Inmueble.h"
#include "DTInmueble.h"
#include "IControladorSubeYBaja.h"
#include "Handlers.h"
#include <set>

class ControladorSubeYBaja : public IControladorSubeYBaja
{
private:
    static ControladorSubeYBaja *instance;
    HandlerInmuebles *handlerInmuebles;
    /**
     * @brief Constructor de ControladorSubeYBaja
     *
     */
    ControladorSubeYBaja();

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
     * @brief Elimina la instancia de inmueble y todos sus links
     *
     * @param codigoInmueble
     */
    void eliminarInmueble(int codigoInmueble);
    /**
     * @brief Destroy the Controlador Sube Y Baja object
     *
     */
    ~ControladorSubeYBaja();
};

#endif