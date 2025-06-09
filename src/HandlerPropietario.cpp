#include "../include/HandlerPropietario.h"
#include "../include/Propietario.h"
#include <map>
#include <string>
using namespace std;


static HandlerPropietario* HandlerPropietario::instancia = nullptr;

agregarPropietario(Propietario* propietario) {
    string nick = propietario->getNickname();
    propietarios[nick] = propietario;
}

Propietario* HandlerPropietario::obtenerPropietario(const string& nickname) {
    if (propietarios.count(nickname))
        return propietarios[nickname];
    return nullptr;
}

bool HandlerPropietario::existePropietario(const string& nickname) {
    return propietarios.count(nickname) > 0;
}