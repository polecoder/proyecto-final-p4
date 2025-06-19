#include "../include/Inmobiliaria.h"
#include <iostream>

using namespace std;
Inmobiliaria::Inmobiliaria() : Usuario() // Llama al constructor por defecto de Usuario
{
    direccion = "";
    url = "";
    telefono = "";
    // El vector administraProps se inicializa solo
}

Inmobiliaria::Inmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono)
    : Usuario(nickname, contrasena, nombre, email) // Llama al constructor de Usuario
{
    this->direccion = direccion;
    this->url = url;
    this->telefono = telefono;
    // El vector administraProps se inicializa solo
}
Inmobiliaria:: ~Inmobiliaria(){
};
        
string Inmobiliaria:: getDireccion(){
    return direccion;

};
string Inmobiliaria::getUrl() {
    return url;

};
string Inmobiliaria:: getTelefono() {
    return telefono;

};
vector<AdministraPropiedad*> Inmobiliaria:: getadministraProps() {
    return administraProps;

};

void Inmobiliaria:: notificar(DTNotificacion notificacion){
    map<string,Cliente*> ::iterator it;
    map<string,Propietario*>:: iterator it2;
    for (it=clientesAsociados.begin();it!=clientesAsociados.end();it++){
        (*it).second->agregarNotificacion(notificacion);
    };
    for (it2=PropietariosAsociados.begin();it2!=PropietariosAsociados.end();it++){
        (*it2).second->agregarNotificacion(notificacion);
    }
}