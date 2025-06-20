#ifndef HANDLERINMOBILIARIAS_H
#define HANDLERINMOBILIARIAS_H
#include "Inmobiliaria.h"
#include <map>
#include <string>
#include <vector>
using namespace std; // Esto evita tener que escribir std:: 



class HandlerInmobiliarias {
private:
    map<string, Inmobiliaria*> coleccionInmobiliarias;
    static HandlerInmobiliarias* instancia;
    HandlerInmobiliarias();

public:
    static HandlerInmobiliarias* getInstancia();
    
    void agregarInmobiliaria(Inmobiliaria* inmobiliaria);
    void eliminarInmobiliaria(string nickname);

    const map<string, Inmobiliaria *> &getColeccionInmobiliarias() const;// Devuelve el mapa completo.
    Inmobiliaria* getInmobiliaria(string nickname);// Devuelve la inmobiliaria con ese nickname.
    vector<AdministraPropiedad *> getColeccionAdministraPropiedad(string nickname);//devuelve los ap realcionado con una inmobiliaria con el nickname dado.
    bool existeInmobiliaria(string nickname);
    ~HandlerInmobiliarias(); // Destructor, borra la coleccion
};

#endif // HANDLER_INMOBILIARIA
