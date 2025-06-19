#ifndef HANDLERINMOBILIARIAS_H
#define HANDLERINMOBILIARIAS_H
#include "Inmobiliaria.h"
#include <map>
#include <string>

using namespace std;

class HandlerInmobiliarias
{
private:
    map<string, Inmobiliaria *> coleccionInmobiliarias;
    static HandlerInmobiliarias *instancia;
    HandlerInmobiliarias();

public:
    static HandlerInmobiliarias *getInstancia();
    /**
     * @brief Agrega un Inmobiliaria a la colección de Inmobiliarias, se utiliza el nickname del inmobiliaria pasado por parámetro para agregarlo a la colección
     *
     * PRE-CONDICIÓN: existeInmobiliaria(inmobiliaria.nickname) == false
     *
     * @param inmobiliaria El inmobiliaria que se quiere agregar a la colección
     */
    void agregarInmobiliaria(Inmobiliaria *inmobiliaria);
    /**
     * @brief Elimina la Inmobiliaria "i" tal que i.nickname=nickname de la colección de Inmobiliarias y libera la memoria asociada a dicho elemento "i"
     *
     * PRE-CONDICIÓN: existeInmobiliaria(nickname) == true
     *
     * @param nickname El nickname de la inmobiliaria que se quiere eliminar
     */
    void eliminarInmobiliaria(string nickname);
    /**
     * @brief Devuelve true si y sólo si existe un Inmobiliaria i en la colección tal que i.nickname=nickname. En caso contrario devuelve false
     *
     * @param nickname El nickname del inmobiliaria que se quiere buscar
     */
    bool existeInmobiliaria(string nickname);
    /**
     * @brief Devuelve el Inmobiliaria i en la colección de Inmobiliarias tal que i.nickname=nickname
     *
     * PRE-CONDICIÓN: existeInmobiliaria(nickname) == true
     *
     * @param nickname El nickname del inmobiliaria que se quiere devolver
     * @return Un Inmobiliaria i tal que i.nickname=nickname
     */
    Inmobiliaria *getInmobiliaria(string nickname);
    /**
     * @brief Devuelve la colección de todos las inmobiliarias que hay en el sistema
     *
     * @return map<string, Inmobiliaria*>
     */
    const map<string, Inmobiliaria *> &getColeccionInmobiliarias() const; // ACLARACIÓN: La definición de la función es de esta forma porque: queremos devolver una referencia a la colección no modificable, que además no modifique al objeto desde el cual se llama al método
    /**
     * @brief Devuelve la colección de todos las objetos AdministraPropiedad que están relacionados a la inmobiliaria "i" que cumple que (i.nickname==nickname)
     *
     * PRE-CONDICIÓN: existeInmobiliaria(nickname) == true
     *
     * @param nickname
     * @return vector<AdministraPropiedad *>
     */
    vector<AdministraPropiedad *> getColeccionAdministraPropiedad(string nickname);
    ~HandlerInmobiliarias();
};

#endif // HANDLERINMOBILIARIAS_H