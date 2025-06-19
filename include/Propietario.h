#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "DTNotificacion.h"
#include "Usuario.h"
#include "DTNotificacion.h"
#include "Propietario.h"
#include "Inmobiliaria.h"
#include <set>
#include <map>
#include <string>

using namespace std;

class Propietario : public Usuario
{
private:
    string cuentaBancaria;
    string telefono;
    set<DTNotificacion> notificaciones;
    map<string, Inmobiliaria *> suscripciones;

public:
    Propietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono);
    ~Propietario();
    string getCuentaBancaria() const;
    string getTelefono() const;
    set<DTNotificacion> getNotificaciones() const;
    map<string, Inmobiliaria *> getSuscripciones() const;
    void setCuentaBancaria(string cuentaBancaria);
    void setTelefono(string telefono);
    /**
     * @brief Se encarga de agregar la notificación pasada por parámetro al set de notificaciones del propietario
     *
     * @param notificacion La notificación que se quiere agregar al set de notificaciones
     */
    void agregarNotificacion(DTNotificacion const &notificacion);
    /**
     * @brief Se encarga de eliminar TODAS las notificaciones del set de notificaciones del propietario
     *
     */
    void eliminarNotificaciones();
    /**
     * @brief Se encarga de agregar la inmobiliaria pasada por parámetro al map de Inmobiliarias a las que el usuario está suscrito
     *
     * @param inmobiliaria La inmobiliaria que se quiere agregar al map de suscripciones
     */
    void agregarSuscripcion(Inmobiliaria *inmobiliaria);
    /**
     * @brief Se encarga de eliminar la inmobiliaria "i" del map de suscripciones tal que i.nickname=nicknameInmobiliaria
     *
     * @param nicknameInmobiliaria El nickname de la inmobiliaria que se quiere eliminar del map de suscripciones
     */
    void eliminarSuscripcion(string nicknameInmobiliaria);
};

#endif