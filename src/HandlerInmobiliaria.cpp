#include "../include/HandlerInmobiliarias.h"
#include "../include/Inmobiliaria.h"
#include <iostream>

using namespace std;
HandlerInmobiliaria* HandlerInmobiliaria::instancia = nullptr;

HandlerInmobiliaria::HandlerInmobiliaria() {
}

HandlerInmobiliaria::~HandlerInmobiliaria() {
    for (auto it = coleccionInmobiliarias.begin(); it != coleccionInmobiliarias.end(); ++it) {
        delete it->second; // Libera la memoria de cada Inmobiliaria
    }
    coleccionInmobiliarias.clear(); // Limpia el mapa
}

HandlerInmobiliaria* HandlerInmobiliaria::getInstancia() {
    if (instancia == nullptr) {
        instancia = new HandlerInmobiliaria();
    }
    return instancia;
}

void HandlerInmobiliaria::agregarInmobiliaria( Inmobiliaria*& inmobiliaria) {
    coleccionInmobiliarias[inmobiliaria->getNickname()] = inmobiliaria; // Agrega una nueva inmobiliaria al mapa
}


void HandlerInmobiliaria::eliminarInmobiliaria(string& nickname) {
    coleccionInmobiliarias.erase(nickname);
}

map<string, Inmobiliaria*> HandlerInmobiliaria::getInmobiliarias() {
    return coleccionInmobiliarias;
}
Inmobiliaria* HandlerInmobiliaria::getInmobiliaria(string nickname) {
    return coleccionInmobiliarias.find(nickname)->second;
}
vector<AdministraPropiedad*> HandlerInmobiliaria::getAdProp(string nickname) {
    return coleccionInmobiliarias[nickname]->getadministraProps();
};