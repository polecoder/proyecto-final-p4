#ifndef DTINMUEBLE_H
#define DTINMUEBLE_H
#include <string>

using namespace std;

class DTInmueble {
    private:
        int codigo;
        string direccion;
        int numeroPuerta;
        int superficie;
        int anioConstruccion;

    public:
        DTInmueble(int codigo, string direccion, int numeroPuerta, int superficie, int anioConstruccion);
        int getCodigo() const;
        string getDireccion() const;
        int getNumeroPuerta() const;
        int getSuperficie() const;
        int getAnioConstruccion() const;
        virtual ~DTInmueble();

        bool operator<(const DTInmueble& other) const;
};

#endif