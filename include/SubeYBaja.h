#ifndef SUBEYBAJA_H
#define SUBEYBAJA_H

#include "DTUsuario.h"
#include "Propietario.h"    
#include "Inmobiliaria.h"
#include <string>
#include  <set>


class SubeYBaja {
private:
    
public:
    bool altaPropietario(nickname:String, contrasena:String, nombre:String, email:String, cuentaBancaria:String, telefono:String);
    bool altaInmobiliaria(nickname:String, contrasena:String, nombre:String, email:String, url:String, telefono:String);
    bool altaCliente(nickname:String, contrasena:String, nombre:String, email:String, apellido:String, documento:String);


}

#endif // SUBEYBAJA_H