#include "../include/DTNotificacion.h"
#include <iostream>

DTNotificacion::DTNotificacion(string nicknameInmobiliaria, int codigoPublicacion, string textoPublicacion, TipoPublicacion tipoPublicacion, TipoInmueble tipoInmueble) {
    this->nicknameInmobiliaria = nicknameInmobiliaria;
    this->codigoPublicacion = codigoPublicacion;
    this->textoPublicacion = textoPublicacion;
    this->tipoPublicacion = tipoPublicacion;
    this->tipoInmueble = tipoInmueble;
}