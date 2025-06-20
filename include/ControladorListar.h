#ifndef CONTROLADORLISTAR_H
#define CONTROLADORLISTAR_H

#include "Inmueble.h"
#include "Propietario.h"
#include "DTInmueble.h"
#include "DTInmuebleListado.h"
#include "DTUsuario.h"
#include "Handlers.h"
#include "IControladorListar.h"
#include <set>

using namespace std;

// CONTROLADOR PARA INMUEBLES

class ControladorInmueblesListar : public IControladorListar
{
private:
    static ControladorInmueblesListar *instance;
    HandlerInmuebles *handlerInmuebles;
    /**
     * @brief Constructor de ControladorInmueblesListar
     *
     */
    ControladorInmueblesListar();

public:
    /**
     * @brief Getter de la instancia de ControladorInmueblesListar
     *
     * @return ControladorListar*
     */
    ControladorInmueblesListar *getInstance();
    /**ControladorInmueblesListar
     * @brief Devuelve la información de código, dirección y nombre del propietario de los inmuebles de la coleccion
     *
     * @return set<DTInmuebleListado>
     */
    set<DTInmuebleListado> listarInmuebles();
    /**
     * @brief Devuelve la información detallada del inmueble tal que inmueble.inmueble=codigoInmueble
     *
     * @return DTInmueble
     */
    DTInmueble detalleInmueble(int codigoInmueble);
    /**
     * @brief Destructor de ControladorInmueblesListar
     *
     */
    ~ControladorInmueblesListar();
};

// CONTROLADOR PARA INMOBILIARIAS

class ControladorInmobiliariasListar : public IControladorListar
{
private:
    static ControladorInmobiliariasListar *instance;
    HandlerInmobiliarias *handlerInmobiliarias;
    /**
     * @brief Constructor de ControladorInmobiliariasListar
     *
     */
    ControladorInmobiliariasListar();

public:
    /**
     * @brief Getter de la instancia de ControladorInmueblesListar
     *
     * @return ControladorInmobiliariasListar*
     */
    ControladorInmobiliariasListar *getInstance();
    /**
     * @brief Devuelve la información el nickname y nombre de todas las inmobiliarias de la coleccion
     *
     * @return set<DTUsuario>
     */
    set<DTUsuario> listarInmobiliarias();
    /**
     * @brief Obtiene inmobiliaria tal que inmobiliaria.nickname = nicknameInmobiliaria
     *
     * @param nicknameInmobiliaria
     * @return Inmobiliaria*
     */
    Inmobiliaria *getInmobiliaria(string nicknameInmobiliaria);
    /**
     * @brief Obtiene los inmuebles que no son administrados por la inmobiliaria
     *
     * @return set<DTInmuebleListado>
     */
    set<DTInmuebleListado> getInmueblesNoAdministradosInmobiliaria(string nicknameInmobiliaria);
    /**
     * @brief Obtiene los inmuebles que no son administrados por la inmobiliaria de un propietario con el que esta asociado
     *
     * @param Propietario
     * @return set<DTInmuebleListado>
     */
    set<DTInmuebleListado> getInmueblesNoAdministradosPropietario(Propietario Propietario);
    /**
     * @brief Destructor de ControladorInmobiliariasListar
     *
     */
    ~ControladorInmobiliariasListar();
};

#endif