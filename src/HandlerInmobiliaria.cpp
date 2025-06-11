#include "../include/HandlerInmobiliaria.h"
#include "../include/Inmobiliaria.h"
#include <iostream>

using namespace std;
handlerInmobiliaria* handlerInmobiliaria::instancia = nullptr;

handlerInmobiliaria::handlerInmobiliaria() {
}

handlerInmobiliaria::~handlerInmobiliaria() {
    map<string,Inmobiliaria>::iterator it;
    while (it != coleccionInmobiliarias.end()) {
        it = coleccionInmobiliarias.erase(it); // erase() devuelve el siguiente iterador válido
    }
}

handlerInmobiliaria* handlerInmobiliaria::getInstancia() {
    if (instancia == nullptr) {
        instancia = new handlerInmobiliaria();
    }
    return instancia;
}

void handlerInmobiliaria::agregarInmobiliaria( Inmobiliaria inmobiliaria) {
    coleccionInmobiliarias[inmobiliaria.getNickname()]= inmobiliaria; // Agrega una nueva inmobiliaria al mapa
}


void handlerInmobiliaria::eliminarInmobiliaria( string& nickname) {
    coleccionInmobiliarias.erase(nickname);
}

map<string, Inmobiliaria> handlerInmobiliaria::DevolverInmobiliarias() {
    return coleccionInmobiliarias; 
}
Inmobiliaria handlerInmobiliaria:: DevolverInmobiliaria(string nickname){
    return coleccionInmobiliarias.find(nickname)->second;
}
vector<AdministraPropiedad> handlerInmobiliaria:: DevolverAdProp(string nickname){
    return  coleccionInmobiliarias[nickname].getadministraProps();
 };