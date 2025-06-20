#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include "Propietario.h"
#include <string>
#include <map>

using namespace std;

class Inmobiliaria : public Usuario
{
private:
    string direccion;
    string url;
    string telefono;
    map<string, Propietario *> propietariosRepresentados;
    vector<AdministraPropiedad *> administraPropiedad;

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
     * @brief Getter de los propietarios representados
     *
     * @return map<string, Propietario *>
     */
    map<string, Propietario *> getPropietarios();
    /**
     * @brief Asocia administraPropiedad a la inmobiliaria
     *
     * @param administraPropiedad
     */
    void agregarAdministraPropiedad(AdministraPropiedad *administraPropiedad);
    /**
     * @brief Destructor Inmobiliaria
     *
     */
    ~Inmobiliaria();
};

#endif