#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H
#include "DTFecha.h"
#include "Usuario.h"
#include "Inmobiliaria.h"

class AdministraPropiedad
{
private:
    DTFecha *fecha;
    Inmobiliaria *inmobiliaria;
    Inmueble *inmueble;

public:
    /**
     * @brief Constructor AdministraPropiedad
     *
     * @param fecha
     * @param Inmobiliaria
     */
    AdministraPropiedad(DTFecha *fecha, Inmueble *inmueble, Inmobiliaria *inmobiliaria);
    /**
     * @brief Geter del Inmueble asociado
     *
     * @return Inmueble*
     */
    Inmueble *getInmueble();
    /**
     * @brief Getter de la Inmobiliaria asociada
     *
     * @return Inmobiliaria*
     */
    Inmobiliaria *getInmobiliaria();
    /**
     * @brief Obtiene el nickname de Inmobiliaria
     *
     * @return string
     */
    string getNicknameInmobiliaria();
    /**
     * @brief Destructor de AdministraPropiedad
     *
     */
    ~AdministraPropiedad();
};

#endif