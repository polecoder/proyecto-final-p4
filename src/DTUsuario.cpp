#include "../include/DTUsuario.h"
#include <iostream>

using namespace std;

DTUsuario::DTUsuario(string nickname, string nombre)
{
    this->nickname = nickname;
    this->nombre = nombre;
}

string DTUsuario::getNickname()
{
    return nickname;
}

string DTUsuario::getNombre()
{
    return nombre;
}

bool DTUsuario::operator<(DTUsuario &other)
{
    return nickname < other.nickname; // Comparar directamente los campos
}
