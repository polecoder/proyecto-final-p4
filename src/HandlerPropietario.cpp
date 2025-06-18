#include "../include/HandlerPropietario.h"
#include "../include/Propietario.h"
#include <map>
#include <string>
using namespace std;

// Devuelve las instancias 
HandlerPropietario* HandlerPropietario::instancia = nullptr;

HandlerPropietario* HandlerPropietario::getInstancia() {
    if (instancia == nullptr) {
        instancia = new HandlerPropietario();
    }
    return instancia;
}

//Agregra un propietario al map de propietarios
void HandlerPropietario::agregarPropietario(Propietario* propietario) {
    string nick = propietario->getNickname();
    propietarios[nick] = propietario;
}

//Devuelve el propietario 
Propietario* HandlerPropietario::obtenerPropietario(const string& nickname) {
    if (propietarios.count(nickname)) // funcion que está en map, verifica si el nickname existe
        return propietarios[nickname];
    return nullptr;
}

// DEvuelve true si existe el propietario, false si no
bool HandlerPropietario::existePropietario(const string& nickname) {
    return propietarios.count(nickname) > 0; // si existe devueleve 1, si no 0
}