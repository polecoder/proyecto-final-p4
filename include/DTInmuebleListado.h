#ifndef DTINMUEBLELISTADO_H
#define DTINMUEBLELISTADO_H
#include <string>

using namespace std;

class DTInmuebleListado {
    private:
        int codigo;
        string direccion;
        string propietario;

    public:
        DTInmuebleListado(int codigo, string direccion, string propietario);
        int getCodigo()const;
        string getDireccion()const;
        string getPropietario()const;

        bool operator<(const DTInmuebleListado& other) const;
};

#endif