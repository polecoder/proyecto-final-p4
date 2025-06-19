#include "../include/Cliente.h"
#include <string>
#include <map>

using namespace std;

Cliente::Cliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento)
    :Usuario(nickname, contrasena, nombre, email)
{
    this->apellido = apellido;
    this->documento = documento;    
}

Cliente::~Cliente(){}

string Cliente::getApellido(){
    return this->apellido;
};
string Cliente:: getDocumento(){
    return this->documento;
};
map<string, Inmobiliaria*> Cliente::getSuscripciones(){
    return this->suscripciones;
};
void Cliente::setApellido(string &apellido){
    this->apellido = apellido;
};
void Cliente::setDocumento(string &documento){
    this->documento = documento;
};
void Cliente::agregarSuscripcion(Inmobiliaria* &inmobiliaria){
    this->suscripciones.insert({inmobiliaria->getNickname(), inmobiliaria});
};
void Cliente::eliminarSuscripcion(string &nicknameInmobiliaria){
    if(this->suscripciones.find(nicknameInmobiliaria) != this->suscripciones.end())
        this->suscripciones.erase(nicknameInmobiliaria);
};

bool Cliente::estaSuscripto(const string &nicknameInmobiliaria){
    return this->suscripciones.find(nicknameInmobiliaria) != this->suscripciones.end();
};

void Cliente::agregarNotificacion(DTNotificacion notificacion){
    notificaciones.insert(notificacion);
};