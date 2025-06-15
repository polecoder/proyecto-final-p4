#ifndef CONTROLADORLISTAR_H
#define CONTROLADORLISTAR_H

#include "Inmueble.h"
#include "DTInmueble.h"
#include "DTInmuebleListado.h"
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
     * @brief Construct a new Controlador Listar object
     *
     */
    ControladorListar();

public:
    /**
     * @brief Get the Instance object
     *
     * @return ControladorListar*
     */
    ControladorListar *getInstance();
    /**
     * @brief
     *
     * @return set<DTInmuebleListado>
     */
    set<DTInmuebleListado> listarInmuebles();
    /**
     * @brief
     *
     * @return DTInmueble
     */
    DTInmueble detalleInmueble(int codigoInmueble);
    /**
     * @brief Destroy the Controlador Listar object
     *
     */
    ~ControladorListar();
};

#endif