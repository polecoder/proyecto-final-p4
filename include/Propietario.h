#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include "DTNotificacion.h"
#include <set>
#include <string>

using namespace std;

class Propietario : public Usuario
{
private:
    string cuentaBancaria;
    string telefono;
    set<DTNotificacion> notificaciones;

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
};

#endif