#ifndef CASA_H
#define CASA_H
#include "Inmueble.h"
#include "DTCasa.h"
#include "TipoTecho.h"

class Casa : public Inmueble
{
private:
    bool esPH;
    TipoTecho techo;

public:
    /**
     * @brief Constructor de Casa
     *
     * @param esPH
     * @param techo
     */
    Casa(bool esPH, TipoTecho techo);
    /**
     * @brief Devuelve true si casa es una propiedad horizontal, de lo contrario devuelve false
     *
     */
    bool getEsPH();
    /**
     * @brief Getter de techo
     *
     * @return TipoTecho
     */
    TipoTecho getTecho();
    /**
     * @brief Destructor de Casa
     *
     */
    ~Casa();
};

#endif