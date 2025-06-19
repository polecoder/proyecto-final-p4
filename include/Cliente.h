#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include "Inmobiliaria.h"
#include "DTNotificacion.h"
#include <map>
#include <string>
#include <set>

using namespace std;

class Cliente : public Usuario
{
private:
    string apellido;
    string documento;
    set<DTNotificacion> notificaciones;
    map<string, Inmobiliaria *> suscripciones;

public:
    Cliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento);
    ~Cliente();
    string getApellido() const;
    string getDocumento() const;
    set<DTNotificacion> getNotificaciones() const;
    map<string, Inmobiliaria *> getSuscripciones() const;
    void setApellido(string apellido);
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