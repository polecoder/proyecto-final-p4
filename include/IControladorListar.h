#ifndef ICONTROLADORLISTAR_H
#define ICONTROLADORLISTAR_H

#include <set>
#include <string>
#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"

using namespace std;

class IControladorListar{
    public:
        virtual set<DTUsuario> listarInmobiliarias()=0;
        virtual set<DTInmuebleAdministrado> listarInmueblesAdministrados(string nicknameInmobiliaria)=0;
};

#endif