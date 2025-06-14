#include "../include/HandlerInmobiliaria.h"
#include "../include/Inmobiliaria.h"
#include <iostream>

using namespace std;
HandlerInmobiliaria* HandlerInmobiliaria::instancia = nullptr;

HandlerInmobiliaria::HandlerInmobiliaria() {
}

HandlerInmobiliaria::~HandlerInmobiliaria() {
    map<string,Inmobiliaria>::iterator it;
    while (it != coleccionInmobiliarias.end()) {
        it = coleccionInmobiliarias.erase(it); // erase() devuelve el siguiente iterador válido
    }
}

HandlerInmobiliaria* HandlerInmobiliaria::getInstancia() {
    if (instancia == nullptr) {
        instancia = new HandlerInmobiliaria();
    }
    return instancia;
}

void HandlerInmobiliaria::agregarInmobiliaria( Inmobiliaria inmobiliaria) {
    coleccionInmobiliarias[inmobiliaria.getNickname()]= inmobiliaria; // Agrega una nueva inmobiliaria al mapa
}


void HandlerInmobiliaria::eliminarInmobiliaria( string& nickname) {
    coleccionInmobiliarias.erase(nickname);
}

map<string, Inmobiliaria> HandlerInmobiliaria::DevolverInmobiliarias() {
    return coleccionInmobiliarias; 
}
Inmobiliaria HandlerInmobiliaria:: DevolverInmobiliaria(string nickname){
    return coleccionInmobiliarias.find(nickname)->second;
}
vector<AdministraPropiedad> HandlerInmobiliaria:: DevolverAdProp(string nickname){
    return  coleccionInmobiliarias[nickname].getadministraProps();
 };