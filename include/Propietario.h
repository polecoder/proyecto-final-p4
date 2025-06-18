#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include "DTNotificacion.h"
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
     * @brief Destructor de Propietario
     *
     */
    ~Propietario();
    /**
     * @brief Getter para cuentaBancaria
     *
     * @return Un string correspondiente a la cuenta bancaria del propietario
     */
    string getCuentaBancaria();
    /**
     * @brief Getter para telefono
     *
     * @return Un string correspondiente al telefono del propietario
     */
    string getTelefono();
    /**
     * @brief Getter para notificaciones
     *
     * @return Un set<DTNotificacion> correspondiente a TODAS las notificaciones del propietario
     */
    set<DTNotificacion> getNotificaciones();
    /**
     * @brief Devuelve todas las suscripciones del cliente
     *
     * @return map<string, Inmobiliaria *> que contiene todas las suscripciones del cliente
     */
    map<string, Inmobiliaria *> getSuscripciones();
    /**
     * @brief Setter para cuentaBancaria
     *
     * @param cuentaBancaria Cuenta bancaria para asignar al propietario
     */
    void setCuentaBancaria(string cuentaBancaria);
    /**
     * @brief Setter para telefono
     *
     * @param telefono Telefono para asignar al propietario
     */
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