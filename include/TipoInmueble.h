#ifndef TIPOINMUEBLE_H
#define TIPOINMUEBLE_H

<<<<<<< HEAD
enum TipoInmueble {
=======
#include <ostream>

using namespace std;

enum TipoInmueble
{
>>>>>>> origin/main
    Todos,
    Casa,
    Apartamento
};

<<<<<<< HEAD
=======
/**
 * @brief Sobrecarga para operador << para imprimir en pantalla elementos de tipo TipoInmueble
 */
ostream &operator<<(ostream &os, TipoInmueble tipo);

>>>>>>> origin/main
#endif