#ifndef CONTROLADORNOTIFICACIONES_H
#define CONTROLADORNOTIFICACIONES_H

#include "Handlers.h"

using namespace std;

class ControladorNotificaciones
{
private:
    static ControladorNotificaciones *instance;
    HandlerUsuarios &handlerUsuarios;
    /**
     * @brief Constructor de ControladorNotificaciones (PRIVADO)
     *
     */
    ControladorNotificaciones();

public:
    /**
     * @brief Getter para la instancia del ControladorNotificaciones
     *
     * @return ControladorNotificaciones
     */
    static ControladorNotificaciones *getInstance();
    /**
     * @brief Destructor de ControladorNotificaciones
     *
     */
    ~ControladorNotificaciones();
};

#endif