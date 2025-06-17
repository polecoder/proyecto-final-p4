#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include "Inmobiliaria.h"
#include "DTNotificacion.h"
#include <set>
#include <map>
#include <string>

using namespace std;

class Cliente : public Usuario
{
private:
    string apellido;
    string documento;
    set<DTNotificacion> notificaciones;
    map<string, Inmobiliaria *> suscripciones;

public:
    /**
     * @brief Constructor de Cliente
     *
     * @param nickname
     * @param contrasena
     * @param nombre
     * @param email
     * @param apellido
     * @param documento
     */
    Cliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento);
    /**
     * @brief Destructor de Cliente
     *
     */
    ~Cliente();
    /**
     * @brief Getter para apellido
     *
     * @return Un string correspondiente al apellido del cliente
     */
    string getApellido();
    /**
     * @brief Getter para documento
     *
     * @return Un string correspondiente al documento del cliente
     */
    string getDocumento();
    /**
     * @brief Getter para notificaciones
     *
     * @return Un set<DTNotificacion> correspondiente a TODAS las notificaciones del cliente
     */
    set<DTNotificacion> getNotificaciones();
    /**
     * @brief Devuelve todas las suscripciones del cliente
     *
     * @return set<Inmobiliaria*> que contiene todas las suscripciones del cliente
     */
    map<string, Inmobiliaria *> getSuscripciones();
    /**
     * @brief Setter para apellido
     *
     * @param apellido Apellido para asignar al cliente
     */
    void setApellido(string apellido);
    /**
     * @brief Setter para documento
     *
     * @param documento Documento para asignar al cliente
     */
    void setDocumento(string documento);
    /**
     * @brief Se encarga de agregar la notificación pasada por parámetro al set de notificaciones del cliente
     *
     * @param notificacion La notificación que se quiere agregar al set de notificaciones
     */
    void agregarNotificacion(DTNotificacion const &notificacion);
    /**
     * @brief Se encarga de eliminar TODAS las notificaciones del set de notificaciones del cliente
     *
     */
    void eliminarNotificaciones();
    /**
     * @brief Se encarga de agregar la inmobiliaria pasada por parámetro al set de Inmobiliarias a las que el usuario está suscrito
     *
     * @param inmobiliaria La inmobiliaria que se quiere agregar al set de suscripciones
     */
    void agregarSuscripcion(Inmobiliaria *inmobiliaria);
    /**
     * @brief Se encarga de eliminar la inmobiliaria "i" del set de suscripciones tal que i.nickname=nicknameInmobiliaria
     *
     * @param nicknameInmobiliaria El nickname de la inmobiliaria que se quiere eliminar del set de suscripciones
     */
    void eliminarSuscripcion(string nicknameInmobiliaria);
};

#endif