#ifndef CONTROLADORLISTAR_H
#define CONTROLADORLISTAR_H

#include "Inmueble.h"
#include "DTInmueble.h"
#include "DTInmuebleListado.h"
#include "DTUsuario.h"
#include "Handlers.h"
#include "IControladorListar.h"
#include <set>

using namespace std;

class ControladorListar : public IControladorListar
{
private:
    static ControladorListar *instance;
    HandlerInmuebles *handlerInmuebles;
    /**
     * @brief Constructor de ControladorListar
     *
     */
    ControladorListar();

public:
    /**
     * @brief Getter de la instancia de ControladorListar
     *
     * @return ControladorListar*
     */
    ControladorListar *getInstance();
    /**
     * @brief Devuelve la información de código, dirección y nombre del propietario de los inmuebles de la coleccion
     *
     * @return set<DTInmuebleListado>
     */
    set<DTInmuebleListado> listarInmuebles();
    /**
     * @brief Devuelve la información el nickname y nombre de todas las inmobiliarias de la coleccion
     *
     * @return set<DTUsuario>
     */
    set<DTUsuario> listarInmobiliarias();
    /**
     * @brief Devuelve la información detallada del inmueble tal que inmueble.inmueble=codigoInmueble
     *
     * @return DTInmueble
     */
    DTInmueble detalleInmueble(int codigoInmueble);
    /**
     * @brief Destructor de ControladorListar
     *
     */
    ~ControladorListar();
};

#endif