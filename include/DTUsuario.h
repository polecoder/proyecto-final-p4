#ifndef DTUSUARIO_H
#define DTUSUARIO_H
#include <string>

using namespace std;

class DTUsuario
{
private:
    string nickname;
    string nombre;

public:
    DTUsuario(string nickname, string nombre);
    string getNickname();
    string getNombre();
    bool operator<(DTUsuario &other);
};
#endif