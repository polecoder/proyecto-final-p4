#ifndef ICONTROLADORSubeYBaja_H
#define ICONTROLADORSubeYBaja_H

#include <string>
#include "TipoPublicacion.h"
using namespace std;

class IControladorSubeYBaja {
    public:
        virtual  bool altaPublicacion(string nicknameInmobiliaria, int codigoInmueble,TipoPublicacion tipoPublicacion, string texto, float precio)=0;
        
        virtual bool altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono)=0;
        virtual bool altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono)=0;
        virtual bool altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento)=0;
        
        virtual ~IControladorSubeYBaja() {} // Destructor virtual para permitir la eliminación adecuada de objetos derivados

};

#endif