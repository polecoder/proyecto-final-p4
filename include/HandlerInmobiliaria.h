#ifndef HANDLER_INMOBILIARIA
#define HANDLER_INMOBILIARIA
#include "Inmobiliaria.h"
#include <map>
#include <string>
using namespace std; // Esto evita tener que escribir std:: 



class handlerInmobiliaria {
private:
    map<string, Inmobiliaria> coleccionInmobiliarias;
    static handlerInmobiliaria* instancia;
    handlerInmobiliaria();  // Constructor
    ~handlerInmobiliaria(); // Destructor, borra la coleccion
public:
    static handlerInmobiliaria* getInstancia(); 
    
    void agregarInmobiliaria(Inmobiliaria inmobiliaria);
    void eliminarInmobiliaria(string& nickname);

    map<string, Inmobiliaria> DevolverInmobiliarias() ;// Devuelve el mapa completo
    Inmobiliaria DevolverInmobiliaria(string nickname);// Devuelve la inmobiliaria con ese nickname
    vector<AdministraPropiedad> DevolverAdProp(string nickname);//devuelve los ap realcionado con una inmobiliaria con el nickname dado
};

#endif // HANDLER_INMOBILIARIA