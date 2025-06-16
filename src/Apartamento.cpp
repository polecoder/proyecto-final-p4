#include "../include/Apartamento.h"
#include <iostream>
using namespace std;

Apartamento::Apartamento(int piso, bool tieneAscensor, float gastosComunes) 
    : Inmueble(), piso(piso), tieneAscensor(tieneAscensor), gastosComunes(gastosComunes) {
    // Constructor de Apartamento, inicializa los atributos
}
Apartamento::~Apartamento() {
    // Destructor de Apartamento, no es necesario liberar memoria ya que no hay punteros
    // Los Handlers se encargan de liberar su propia memoria
}