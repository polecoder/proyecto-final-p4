#ifndef INMUEBLE_H
#define INMUEBLE_H

#include "Propietario.h"
#include "AdministraPropiedad.h"
#include <algorithm>
#include <string>

using namespace std;

class Inmueble
{
private:
    int codigo;
    string direccion;
    int numeroPuerta;
    int superficie;
    int anoConstruccion;
    Propietario *propietario;
    vector<AdministraPropiedad *> administraPropiedad;

public:
    /**
     * @brief Constructor de Inmueble
     *
     * @param codigo
     * @param direccion
     * @param numeroPuerta
     * @param superficie
     * @param anoConstruccion
     */
    Inmueble(int codigo, string direccion, int numeroPuerta, int superficie, int anoConstruccion);
    /**
     * @brief Getter para codigo
     *
     * @return int
     */
    int getCodigo();
    /**
     * @brief Getter para direccion
     *
     * @return string
     */
    string getDireccion();
    /**
     * @brief Getter para numeroPuerta
     *
     * @return int
     */
    int getNumeroPuerta();
    /**
     * @brief Getter para superficcie
     *
     * @return int
     */
    int getSuperficie();
    /**
     * @brief Getter para anoConstruccion
     *
     * @return int
     */
    int getAnoConstruccion();
    /**
     * @brief Getter para propietario
     *
     * @return Propietario*
     */
    Propietario *getPropietario();
    /**
     * @brief Geter de AdministraPropiedad
     *
     * @return vector<AdministraPropiedad *>
     */
    vector<AdministraPropiedad *> getAdministraPropiedad();
    /**
     * @brief Seter para codigo
     *
     * @param codigo
     */
    void setCodigo(int codigo);
    /**
     * @brief Seter para direccion
     *
     * @param direccion
     */
    void setDireccion(string direccion);
    /**
     * @brief Seter para numeroPuerta
     *
     * @param numeroPuerta
     */
    void setNumeroPuerta(int numeroPuerta);
    /**
     * @brief Seter para superficie
     *
     * @param superficie
     */
    void setSuperficie(int superficie);
    /**
     * @brief Seter para anoConstruccion
     *
     * @param anoConstruccion
     */
    void setAnoConstruccion(int anoConstruccion);
    /**
     * @brief Seter para propietario
     *
     * @param propietario
     */
    void setPropietario(Propietario *propietario);
    /**
     * @brief Asocia administraPropiedad al innmueble
     *
     * @param administraPropiedad
     */
    void agregarAdministraPropiedad(AdministraPropiedad *administraPropiedad);
    /**
     * @brief Destructor de Inmueble
     *
     */
    virtual ~Inmueble();
};

#endif