#include "../include/DTUsuario.h"
#include <iostream>

DTUsuario::DTUsuario(std::string nickname, std::string nombre) {
    this->nickname = nickname;
    this->nombre = nombre;
}
//le tuve que poner los const porque sino no lo puedo llamar desde el menu
std::string DTUsuario::getNickname() const {
    return nickname;
}

std::string DTUsuario::getNombre()const{
    return nombre;
}

bool DTUsuario::operator<(const DTUsuario& other) const {
    return nickname < other.nickname; // Comparar directamente los campos
}
