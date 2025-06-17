#ifndef ICONTROLADORLISTAR_H
#define ICONTROLADORLISTAR_H

#include "CListar.h"

class IControladorListar{
    public:
        virtual set<DTUsuario> listarInmobiliarias()=0;
        virtual set<DTInmuebleAdministrado> listarInmueblesAdministrados(string nicknameInmobiliaria)=0;
};

#endif