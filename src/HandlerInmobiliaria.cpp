#include "../include/HandlerInmobiliaria.h"
#include "../include/Inmobiliaria.h"
#include <iostream>

using namespace std;

 handlerInmobiliaria::handlerInmobiliaria() {
     //constructor, no es necesario poner nada, map se inicializa solo
}
 handlerInmobiliaria::~handlerInmobiliaria() {
    map<string,Inmobiliaria>::iterator it;
    while (it != coleccionInmobiliarias.end()) {
        it = coleccionInmobiliarias.erase(it); // erase() devuelve el siguiente iterador válido
    }
}

void handlerInmobiliaria::agregarInmobiliaria(const string& nickname, const string& contrasena,const string& nombre, const string& email, const string& direccion, const string& url,const string& telefono) {
    coleccionInmobiliarias[nickname]= Inmobiliaria(nickname,contrasena,nombre,email, direccion, url,telefono); // Agrega una nueva inmobiliaria al mapa
}


void handlerInmobiliaria::eliminarInmobiliaria(const string& nickname) {
    coleccionInmobiliarias.erase(nickname);
}

map<string, Inmobiliaria> handlerInmobiliaria::DevolverInmobiliarias() const {
    return coleccionInmobiliarias; // Devuelve el mapa completo
}

  vector<AdministraPropiedad> handlerInmobiliaria:: DevolverAdProp(string nickname){
    return  coleccionInmobiliarias[nickname].getadministraProps();
  };