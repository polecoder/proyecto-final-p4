#ifndef HANDLER_INMOBILIARIA
#define HANDLER_INMOBILIARIA
#include "Inmobiliaria.h"
#include <map>
#include <string>
using namespace std; // Esto evita tener que escribir std:: 



class handlerInmobiliaria {
private:
    map<string, Inmobiliaria> coleccionInmobiliarias;

public:
    handlerInmobiliaria();  // Constructor
    ~handlerInmobiliaria(); // Destructor, borra la coleccion
    
    void agregarInmobiliaria(Inmobiliaria inmobiliaria);
    void eliminarInmobiliaria(string& nickname);

    map<string, Inmobiliaria> DevolverInmobiliarias() ;
    vector<AdministraPropiedad> DevolverAdProp(string nickname);//devuelve los ap realcionado con una inmobiliaria con el nickname dado
};

#endif // HANDLER_INMOBILIARIA