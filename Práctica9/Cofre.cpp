//
// Created by Manuel Villegas Aceituno on 2/5/24.
//

#include "Cofre.h"
#include <sstream>

std::string Cofre::getDescripcion() const {
    std::stringstream aux;
    aux << "Cofre (Contiene " <<this->cuantosHay() << ")";
    return aux.str();
}

void Cofre::mete(Item *item) {
    if ( dynamic_cast<Cofre*>(item)){
        throw std::invalid_argument ("[Cofre::mete] se esta intentando añadir un cofre a otro cofre");
    }
    Contenedor::mete(item);
}


