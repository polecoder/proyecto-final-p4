#ifndef TIPOPUBLICACION_H
#define TIPOPUBLICACION_H

#include <ostream>

using namespace std;

enum TipoPublicacion
{
    Venta,
    Alquiler
};

/**
 * @brief Sobrecarga para operador << para imprimir en pantalla elementos de tipo TipoPublicacion
 */
ostream &operator<<(ostream &os, TipoPublicacion tipo);

#endif