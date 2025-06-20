#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <string>
#include <ostream>
#include "TipoPublicacion.h"
#include "TipoInmueble.h"

using namespace std;

class DTNotificacion
{
private:
    string nicknameInmobiliaria;
    int codigoPublicacion;
    string textoPublicacion;
    TipoPublicacion tipoPublicacion;
    TipoInmueble tipoInmueble;

public:
    /**
     * @brief Constructor de DTNotificación
     *
     * @param nicknameInmobiliaria Nickname de la inmobiliaria que creó la publicación asociada a la notificación
     * @param codigoPublicacion Código de la publicación asociada a la notificación
     * @param textoPublicacion Texto de la publicación asociada a la notificación
     * @param tipoPublicacion Tipo de la publicación asociada a la notificación
     * @param tipoInmueble Tipo del inmueble de la publicación asociada a la notificación
     */
    DTNotificacion(const string &nicknameInmobiliaria, const int &codigoPublicacion, const string &textoPublicacion, const TipoPublicacion &tipoPublicacion, const TipoInmueble &tipoInmueble);
    /**
     * @brief Destructor de DTNotificacion
     *
     */
    ~DTNotificacion();
    /**
     * @brief Getter para nicknameInmobiliaria
     *
     * @return Un string correspondiente al nickname de la inmobiliaria que creó la publicación asociada a la notificación
     */
    string getNicknameInmobiliaria() const;
    /**
     * @brief Getter para codigoPublicacion
     *
     * @return Un int correspondiente al código de la publicación asociada a la notificación
     */
    int getCodigoPublicacion() const;
    /**
     * @brief Getter para textoPublicacion
     *
     * @return Un string correspondiente al texto de la publicación asociada a la notificación
     */
    string getTextoPublicacion() const;
    /**
     * @brief Getter para tipoPublicacion
     *
     * @return Un TipoPublicacion correspondiente al tipo de la publicación asociada a la notificación
     */
    TipoPublicacion getTipoPublicacion() const;
    /**
     * @brief Getter para tipoInmueble
     *
     * @return Un TipoInmueble correspondiente al tipo del inmueble de la publicación asociada a la notificación
     */
    TipoInmueble getTipoInmueble() const;
    /**
     * @brief Setter para nicknameInmobiliaria
     *
     * @param nicknameInmobiliaria Nickname de la inmobiliaria que creó la publicación asociada a la notificación
     */
    void setNicknameInmobiliaria(string nicknameInmobiliaria);
    /**
     * @brief Setter para codigoPublicacion
     *
     * @param codigoPublicacion Código de la publicación asociada a la notificación
     */
    void setCodigoPublicacion(int codigoPublicacion);
    /**
     * @brief Setter para textoPublicacion
     *
     * @param textoPublicacion Texto de la publicación asociada a la notificación
     */
    void setTextoPublicacion(string textoPublicacion);
    /**
     * @brief Setter para TipoPublicacion
     *
     * @param tipoPublicacion Tipo de la publicación asociada a la notificación
     */
    void setTipoPublicacion(TipoPublicacion tipoPublicacion);
    /**
     * @brief Setter para tipoInmueble
     *
     * @param tipoInmueble Tipo del inmueble de la publicación asociada a la notificación
     */
    void setTipoInmueble(TipoInmueble tipoInmueble);
    /**
     * @brief Operador < para comparar DTNotificacion, se usa para ordenar un set de este tipo
     */
    bool operator<(const DTNotificacion &other) const;
};

/**
 * @brief Sobrecarga para operador << para imprimir en pantalla elementos de tipo DTNotificacion
 */
ostream &operator<<(ostream &os, const DTNotificacion &dt);

#endif