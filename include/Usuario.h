<<<<<<< HEAD

#ifndef USUARIO_H
#define USUARIO_H
#include <string>

class Usuario {
    private:
        std::string nickname;
        std::string contrasena;
        std::string nombre;
        std::string email;

    public:
        Usuario(); // Constructor por defecto
        Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email);
        virtual ~Usuario();
        std::string getNickname()const ;

        std::string getContrasena() ;
        std::string getNombre() ;
        std::string getEmail() ;
};

=======
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
    string getNickname() const;
    /**
     * @brief Getter para contrasena
     *
     * @return Un string correspondiente a la contraseña del usuario
     */
    string getContrasena() const;
    /**
     * @brief Getter para nombre
     *
     * @return Un string correspondiente al nombre del usuario
     */
    string getNombre() const;
    /**
     * @brief Getter para email
     *
     * @return Un string correspondiente al email del usuario
     */
    string getEmail() const;
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

>>>>>>> origin/main
#endif