#include "../include/Propietario.h"

using namespace std;

Propietario::Propietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono)
    : Usuario(nickname, contrasena, nombre, email)
{
    this->cuentaBancaria = cuentaBancaria;
    this->telefono = telefono;
};

string Propietario::getCuentaBancaria() const{
    return this->cuentaBancaria;
};

string Propietario::getTelefono() const{
    return this->telefono;
};

map<string, Inmobiliaria*> Propietario::getSuscripciones() const{
    return this->suscripciones;
};

void Propietario::setCuentaBancaria(string cuentaBancaria){
    this->cuentaBancaria = cuentaBancaria;
};

void Propietario::setTelefono(string telefono){
    this->telefono = telefono;
};

void Propietario::agregarSuscripcion(Inmobiliaria* inmobiliaria){
    this->suscripciones.insert({inmobiliaria->getNickname(), inmobiliaria});
}

void Propietario::eliminarSuscripcion(string nicknameInmobiliaria){
    if(this->suscripciones.find(nicknameInmobiliaria) != this->suscripciones.end())
        this->suscripciones.erase(nicknameInmobiliaria);
};

bool Propietario::estaSuscripto(const string &nicknameInmobiliaria){
    return this->suscripciones.find(nicknameInmobiliaria) != this->suscripciones.end();
};

void Propietario::agregarNotificacion(DTNotificacion notificacion){
    notificaciones.insert(notificacion);
};

Propietario::~Propietario(){
    suscripciones.clear();
    notificaciones.clear();
};

void Propietario::eliminarNotificaciones(){
    this->notificaciones.clear();
};