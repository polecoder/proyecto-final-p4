#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include "DTNotificacion.h"
#include <set>
#include <string>

using namespace std;

class Cliente : public Usuario
{
private:
    string apellido;
    string documento;
    set<DTNotificacion> notificaciones;

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
     * @return Un string correspondiente a la cuenta bancaria del cliente
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
     * @brief Se encarga de eliminar la notificación pasada por parámetro al set de notificaciones del cliente
     *
     * @param codigoPublicacion El código de la publicación asociada a la notificación que se quiere eliminar al set de notificaciones
     */
    void eliminarNotificacion(int codigoPublicacion);
    /**
     * @brief Se encarga de eliminar TODAS las notificaciones del set de notificaciones del cliente
     *
     */
    void eliminarNotificaciones();
};

#endif