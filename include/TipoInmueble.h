#ifndef TIPOINMUEBLE_H
#define TIPOINMUEBLE_H

#include <ostream>

using namespace std;

enum TipoInmueble
{
    Todos,
    Casa,
    Apartamento
};

/**
 * @brief Sobrecarga para operador << para imprimir en pantalla elementos de tipo TipoInmueble
 */
ostream &operator<<(ostream &os, TipoInmueble tipo);

#endif