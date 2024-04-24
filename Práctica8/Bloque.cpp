//
// Created by Manuel Villegas Aceituno on 24/4/24.
//

#include "Bloque.h"
#include <sstream>

std::string Bloque::getDescripcion() {
    std::stringstream aux;
    aux << "Bloque de tierra (" << this->getNumElementos() <<")";
    return aux.str();
}

Bloque::~Bloque() {

}

