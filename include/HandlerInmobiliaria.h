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
    
    void agregarInmobiliaria(const string& nickname, const string& contrasena,const string& nombre, const string& email, const string& direccion, const string& url,const string& telefono);
    void eliminarInmobiliaria(const string& nickname);

    map<string, Inmobiliaria> DevolverInmobiliarias() const;
    vector<AdministraPropiedad> DevolverAdProp(string nickname);//devuelve los ap realcionado con una inmobiliaria con el nickname dado
};

#endif // HANDLER_INMOBILIARIA