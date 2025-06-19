#ifndef HANDLERPROPIETARIOS_H
#define HANDLERPROPIETARIOS_H

#include <string>
#include <map>
#include "Propietario.h"

using namespace std;

class HandlerPropietarios
{
private:
    map<string, Propietario *> coleccionPropietarios;
    static HandlerPropietarios *instancia;
    HandlerPropietarios();

public:
    static HandlerPropietarios *getInstancia();
    ~HandlerPropietarios();
    /**
     * @brief Agrega un Propietario a la colección de Propietarios, se utiliza el nickname del propietario pasado por parámetro para agregarlo a la colección
     *
     * PRE-CONDICIÓN: existePropietario(propietario.nickname) == false
     *
     * @param propietario El propietario que se quiere agregar a la colección
     */
    void agregarPropietario(Propietario *propietario);
    /**
     * @brief Elimina al Propietario "p" tal que p.nickname=nickname de la colección de Propietarios y libera la memoria asociada a dicho objeto "p"
     *
     * PRE-CONDICIÓN: existePropietario(nickname) == true
     *
     * @param nickname El nickname del propietario que se quiere eliminar
     */
    void eliminarPropietario(string nickname);
    /**
     * @brief Devuelve true si y sólo si existe un Propietario "p" en la colección tal que p.nickname=nickname. En caso contrario devuelve false
     *
     * @param nickname El nickname del propietario que se quiere buscar
     */
    bool existePropietario(string nickname);
    /**
     * @brief Devuelve el Propietario "p" en la colección de Propietarios tal que p.nickname=nickname
     *
     * PRE-CONDICIÓN: existePropietario(nickname) == true
     *
     * @param nickname El nickname del propietario que se quiere devolver
     * @return Un Propietario p tal que p.nickname=nickname
     */
    Propietario *getPropietario(string nickname);
    /**
     * @brief Devuelve la colección de todos los propietarios que hay en el sistema
     *
     * @return map<string, Propietario*>
     */
    const map<string, Propietario *> &getColeccionPropietarios() const; // ACLARACIÓN: La definición de la función es de esta forma porque: queremos devolver una referencia a la colección no modificable, que además no modifique al objeto desde el cual se llama al método
};

#endif // HANDLERPROPIETARIOS_H