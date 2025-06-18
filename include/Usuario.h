#ifndef USUARIO_H
#define USUARIO_H
#include <string>

using namespace std;

class Usuario
{
private:
    string nickname;
    string contrasena;
    string nombre;
    string email;

public:
    /**
     * @brief Constructor de Usuario
     *
     * @param nickname
     * @param contrasena
     * @param nombre
     * @param email
     */
    Usuario(string nickname, string contrasena, string nombre, string email);
    /**
     * @brief Destructor de Usuario
     *
     */
    virtual ~Usuario();
    /**
     * @brief Getter para nickname
     *
     * @return Un string correspondiente al nickname del usuario
     */
    string getNickname();
    /**
     * @brief Getter para contrasena
     *
     * @return Un string correspondiente a la contraseña del usuario
     */
    string getContrasena();
    /**
     * @brief Getter para nombre
     *
     * @return Un string correspondiente al nombre del usuario
     */
    string getNombre();
    /**
     * @brief Getter para email
     *
     * @return Un string correspondiente al email del usuario
     */
    string getEmail();
    /**
     * @brief Setter para nickname
     *
     * @param nickname Nickname para asignar al cliente
     */
    void setNickname(string nickname);
    /**
     * @brief Setter para contrasena
     *
     * @param contrasena Contraseña para asignar al cliente
     */
    void setContrasena(string contrasena);
    /**
     * @brief Setter para nombre
     *
     * @param nombre Nombre para asignar al cliente
     */
    void setNombre(string nombre);
    /**
     * @brief Setter para email
     *
     * @param email Email para asignar al cliente
     */
    void setEmail(string email);
};

#endif