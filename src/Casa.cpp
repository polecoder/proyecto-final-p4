#include "../include/Casa.h"

#include <iostream>

using namespace std;
Casa::Casa(bool esPH, TipoTecho techo) : Inmueble(), esPH(esPH), techo(techo) {
    // Constructor de Casa, inicializa los atributos
}
Casa::~Casa() {
    // Destructor de Casa, no es necesario liberar memoria ya que no hay punteros
    // Los Handlers se encargan de liberar su propia memoria
}