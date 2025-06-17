#include "../include/Inmobiliaria.h"
#include <iostream>

using namespace std;

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
vector<AdministraPropiedad> Inmobiliaria:: getadministraProps() {
    return administraProps;

};

void Inmobiliaria::agregarClienteSuscripto(Cliente *cliente){
    this->coleccionClientes[cliente->getNickname()] = cliente;
};

void Inmobiliaria::agregarPropietarioSuscripto(Propietario *propietario){
    this->coleccionPropietarios[propietario->getNickname()] = propietario;
};