#ifndef HANDLERS_H
#define HANDLERS_H

#include <string>
#include <map>
#include "Usuario.h"

using namespace std;

class HandlerUsuarios
{
private:
    map<string, Usuario> coleccionUsuarios;
    static HandlerUsuarios *instance;
    /**
     * @brief Constructor de HandlerUsuarios (PRIVADO)
     *
     */
    HandlerUsuarios();

public:
    /**
     * @brief Getter para la instancia del HandlerUsuarios
     *
     * @return HandlerUsuarios
     */
    static HandlerUsuarios *getInstance();
    /**
     * @brief Destructor de HandlerUsuarios
     *
     */
    ~HandlerUsuarios();
    /**
     * @brief Agrega un Usuario a la colección de Usuarios, se utiliza el nickname del usuario pasado por parámetro para agregarlo a la colección
     *
     * @param usuario El usuario que se quiere agregar a la colección
     */
    void agregarUsuario(const Usuario &usuario);
    /**
     * PRE-CONDICIÓN: existeUsuario(nickname) == true
     *
     * @brief Elimina al Usuario u tal que u.nickname=nickname de la colección de Usuarios y libera la memoria asociada a dicho elemento u
     *
     * @param nickname El nickname del usuario que se quiere eliminar
     */
    void eliminarUsuario(string nickname);
    /**
     * @brief Devuelve true si y sólo si existe un Usuario u en la colección tal que u.nickname=nickname. En caso contrario devuelve false
     *
     * @param nickname El nickname del usuario que se quiere buscar
     */
    bool existeUsuario(string nickname);
    /**
     * PRE-CONDICIÓN: existeUsuario(nickname) == true
     *
     * @brief Devuelve el Usuario u en la colección de Usuarios tal que u.nickname=nickname
     *
     * @param nickname El nickname del usuario que se quiere devolver
     * @return Un Usuario u tal que u.nickname=nickname
     */
    Usuario getUsuario(string nickname);
};

#endif