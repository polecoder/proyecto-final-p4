#ifndef PROPIETARIO_H
#define PROPIETARIO_H

#include "Usuario.h"
#include "Inmueble.h"
#include <vector>
#include <string>

class Propietario : public Usuario
{
private:
    string cuentaBancaria;
    string telefono;
    vector<Inmueble *> inmuebles;

public:
    /**
     * @brief Constructor de Propietario
     *
     * @param nickname
     * @param contrasena
     * @param nombre
     * @param email
     * @param cuentaBancaria
     * @param telefono
     */
    Propietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono);
    /**
     * @brief Getter de cuentaBancaria
     *
     * @return string
     */
    string getCuentaBancaria();
    /**
     * @brief Getter de telefono
     *
     * @return string
     */
    string getTelefono();
    /**
     * @brief Getter de la coleccion de inmuebles
     *
     * @return vector<Inmueble *>&
     */
    vector<Inmueble *> &getInmuebles();
    /**
     * @brief Setter de cuentaBancaria
     *
     * @param cuentaBancaria
     */
    void setCuentaBancaria(string cuentaBancaria);
    /**
     * @brief Setter de telefono
     *
     * @param telefono
     */
    void setTelefono(string telefono);
    /**
     * @brief Asocia el inmueble con el propietario
     *
     * @param inmueble
     */
    void agregarInmueble(Inmueble *inmueble);
};

#endif