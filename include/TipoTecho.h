#ifndef TIPOTECHO_H
#define TIPOTECHO_H
#include<ostream>

using namespace std;

enum TipoTecho {
    Liviano,
    A_dos_aguas,
    Plano
};
    ostream &operator<<(ostream &os, TipoTecho tipo);
#endif