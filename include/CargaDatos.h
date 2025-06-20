#ifndef CARGADATOS_H
#define CARGADATOS_H


class CargaDatos
{
private:
    static CargaDatos *instancia;
    CargaDatos();

public:
    static CargaDatos *getInstancia();
    ~CargaDatos();
};

#endif