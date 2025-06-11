#include "../include/Cliente.h"
#include <iostream>
using namespace std;

Cliente ::Cliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento)
:Usuario(nickname, contrasena, nombre, email){
    this->apellido = apellido;
    this->documento = documento;

};

Cliente:: ~Cliente(){

};

void Cliente::agregarNotificacion(DTNotificacion notificacion){
    notificaciones.insert(notificacion);
};