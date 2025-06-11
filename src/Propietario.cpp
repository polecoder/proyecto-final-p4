#include "../include/Propietario.h"
#include <iostream>
using namespace std;

Propietario::Propietario(string nickname, string contrasena, string nombre, string email, string apellido, string documento)
:Usuario(nickname, contrasena, nombre, email){
    this->cuentaBancaria = cuentaBancaria;
    this->telefono = telefono;
};

Propietario::~Propietario(){

};

void Propietario::agregarNotificacion(DTNotificacion notificacion){
    notificaciones.insert(notificacion);
};