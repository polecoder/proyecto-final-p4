#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include <string>

using namespace std;

class Inmobiliaria : public Usuario
{
private:
    string direccion;
    string url;
    string telefono;

public:
    /**
     * @brief Constructor de Inmobiliaria
     *
     * @param nickname
     * @param contrasena
     * @param nombre
     * @param email
     * @param direccion
     * @param url
     * @param telefono
     */
    Inmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono);
    /**
     * @brief Getter de Direccion
     *
     * @return * string
     */
    string getDireccion();
    /**
     * @brief Getter de Url
     *
     * @return string
     */
    string getUrl();
    /**
     * @brief Getter de Telefono
     *
     * @return string
     */
    string getTelefono();
    /**
     * @brief Destructor Inmobiliaria
     *
     */
    ~Inmobiliaria();
};

#endif