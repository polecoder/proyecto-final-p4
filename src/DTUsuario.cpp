
#include "../include/DTUsuario.h"
#include <iostream>

using namespace std;

DTUsuario::DTUsuario(string nickname, string nombre)
{
    this->nickname = nickname;
    this->nombre = nombre;
}

string DTUsuario::getNickname() const
{
    return nickname;
}

string DTUsuario::getNombre() const
{
    return nombre;
}

bool DTUsuario::operator<(const DTUsuario &other) const
{
    return nickname < other.nickname; // Comparar directamente los campos
}

ostream &operator<<(ostream &os, const DTUsuario &dt)
{
    os << "NICKNAME: " << dt.getNickname() << ", NOMBRE: " << dt.getNombre();
    return os;
}
