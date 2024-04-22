//
// Created by Manuel Villegas Aceituno on 22/4/24.
//

#include "Replicante.h"
#include <iostream>

float Replicante::capacidadDestructivaTotal() const {
    return Mutante::capacidadDestructivaTotal() / 2;
}

void Replicante::addPoder(const PoderPsiquico &poder) {
    throw std::invalid_argument("[Replicante::addPoder] no se pueden aniadir poderes psiquicos a los replicantes");
};

void Replicante::addPoderPsiquico(std::string nombre, std::string descripcion,
                                  std::string afectaA, float capacidadD, float lucidez) {
    throw std::invalid_argument("[Replicante::addPoder] no se pueden aniadir poderes psiquicos a los replicantes");
}

Replicante::Replicante() : Mutante() {}

Replicante::Replicante(Mutante orig) : Mutante(orig) {}

Replicante::Replicante(std::string nombre, std::string apodo, int fechaN, std::string nacionalidad) :
        Mutante(nombre, apodo, fechaN, nacionalidad) {
}

Replicante::~Replicante() {

}
