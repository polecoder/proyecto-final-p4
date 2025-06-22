#ifndef ICONTROLADORSubeYBaja_H
#define ICONTROLADORSubeYBaja_H

#include <string>
#include "TipoPublicacion.h"
#include "TipoTecho.h"
using namespace std;

class IControladorSubeYBaja
{
public:
    virtual bool altaPublicacion(string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, string texto, float precio) = 0;

    virtual bool altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono) = 0;
    virtual bool altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono) = 0;
    virtual bool altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento) = 0;

    virtual void representarPropietario(string nicknamePropietario) = 0;
    virtual void altaCasa(string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo) = 0;
    virtual void altaApartamento(string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes) = 0;
    virtual void finalizarAltaUsuario() = 0;

    virtual ~IControladorSubeYBaja() = default; // Destructor virtual para permitir la eliminación adecuada de objetos derivados
    virtual void eliminarInmueble(int codigoInmueble) = 0;
    virtual void altaAdministraPropiedad(int codigoInmueble, string nicknameInmobiliaria) = 0;
};

#endif