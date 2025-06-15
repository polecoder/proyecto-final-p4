#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <string>
#include "TipoPublicacion.h"
#include "TipoInmueble.h"

using namespace std;

class DTNotificacion
{
private:
    string nicknameInmobiliaria;
    int codigoPublicacion;
    string textoPublicacion;
    TipoPublicacion tipoPublicacion;
    TipoInmueble tipoInmueble;

public:
   
    DTNotificacion( string nicknameInmobiliaria,  int codigoPublicacion,  string textoPublicacion,  TipoPublicacion tipoPublicacion,  TipoInmueble tipoInmueble);

    ~DTNotificacion();

    string getNicknameInmobiliaria();

    int getCodigoPublicacion();
   
    string getTextoPublicacion();
   
    TipoPublicacion getTipoPublicacion();
   
    TipoInmueble getTipoInmueble();
  
    void setNicknameInmobiliaria(string nicknameInmobiliaria);

    void setCodigoPublicacion(int codigoPublicacion);
 
    void setTextoPublicacion(string textoPublicacion);
   
    void setTipoPublicacion(TipoPublicacion tipoPublicacion);
   
    void setTipoInmueble(TipoInmueble tipoInmueble);
};

#endif