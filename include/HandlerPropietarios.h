#ifndef HANDLERPROPIETARIO_H
#define HANDLERPROPIETARIO_H
#include "Propietario.h"
#include <map>
#include <string>

using namespace std;

class HandlerPropietarios{
private:
    map<string, Propietario*> coleccionPropietarios;
    static HandlerPropietarios* instancia;
    HandlerPropietarios();

public:
    static HandlerPropietarios* getInstancia();
    ~HandlerPropietarios();

    void agregarPropietario(Propietario* &propietario);
    void eliminarPorpietario(string nickname);
    bool existePropietario(string nickname);

    Propietario* getPropietario(string nickname);
    const map<string, Propietario *> &getColeccionPropietarios() const;// ACLARACIÓN: La definición de la función es de esta forma porque: 
                                        queremos devolver una referencia a la colección no modificable, que además no modifique al objeto desde el cual se llama al método
};

#endif
