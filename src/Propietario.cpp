#include "../include/Propietario.h"
#include <iostream>
using namespace std;

Propietario::Propietario(string nickname, string contrasena, string nombre, string email, string apellido, string documento)
:Usuario(nickname, contrasena, nombre, email){
    this->cuentaBancaria = cuentaBancaria;
    this->telefono = telefono;
};

Propietario::~Propietario(){
    // Destructor vacio, no es necesario liberar memoria ya que no hay punteros
};

void Propietario::agregarNotificacion(DTNotificacion notificacion){
    notificaciones.insert(notificacion);
};