#ifndef DTUSUARIO_H
#define DTUSUARIO_H
#include <string>
#include <ostream>

using namespace std;

class DTUsuario
{
private:
    string nickname;
    string nombre;

public:
    DTUsuario(string nickname, string nombre);
    string getNickname() const;
    string getNombre() const;
    bool operator<(const DTUsuario &other) const;
};

/**
 * @brief Sobrecarga para operador << para imprimir en pantalla elementos de tipo DTUsuario
 */
ostream &operator<<(ostream &os, const DTUsuario &dt);

#endif