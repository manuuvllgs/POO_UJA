//
// Created by Manuel Villegas Aceituno on 24/4/24.
//

#include "Espada.h"

std::string Espada::getDescripcion() {
    std::stringstream aux;
    aux << "Una Espada (";
    if (this->getPuntosEstado()==0){
        aux << "Rota)";
    } else {
        aux << this->getPuntosEstado() << ")";
    }
    return aux.str();
}


Espada::~Espada() {

}
