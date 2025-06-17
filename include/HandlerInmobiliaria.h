
#ifndef HANDLER_INMOBILIARIA
#define HANDLER_INMOBILIARIA
#include "Inmobiliaria.h"
#include <map>
#include <string>
using namespace std; // Esto evita tener que escribir std:: 



class HandlerInmobiliaria {
private:
    map<string, Inmobiliaria*> coleccionInmobiliarias;
    static HandlerInmobiliaria* instancia;
    HandlerInmobiliaria();  // Constructor
    
public:
    static HandlerInmobiliaria* getInstancia();

    void agregarInmobiliaria(Inmobiliaria*& inmobiliaria);
    void eliminarInmobiliaria(string& nickname);
    bool existeInmobiliaria(const string& nickname); 

    map<string, Inmobiliaria*> DevolverInmobiliarias(); // Devuelve el mapa completo
    Inmobiliaria* DevolverInmobiliaria(string nickname); // Devuelve la inmobiliaria con ese nickname
    vector<AdministraPropiedad> DevolverAdProp(string nickname); //devuelve los ap realcionado con una inmobiliaria con el nickname dado
    ~HandlerInmobiliaria(); // Destructor, borra la coleccion
};

#endif // HANDLER_INMOBILIARIA

