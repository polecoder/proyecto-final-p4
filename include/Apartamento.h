#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include "Inmueble.h"

class Apartamento : public Inmueble
{
private:
    int piso;
    bool tieneAscensor;
    float gastosComunes;

public:
    /**
     * @brief Constructor de Apartamento
     *
     * @param piso
     * @param tieneAscensor
     * @param gastosComunes
     */
    Apartamento(int piso, bool tieneAscensor, float gastosComunes);
    /**
     * @brief Geter de piso
     *
     * @return int
     */
    int getPiso();
    /**
     * @brief Devuelve true si Casa tiene ascensor, de lo contrario devuelve false
     *
     */
    bool getTieneAscensor();
    /**
     * @brief Geter de gastosComunes
     *
     * @return gastosComunes
     */
    float getGastosComunes();
    /**
     * @brief Destructor de Apartamento
     *
     */
    ~Apartamento();
};

#endif