//
// Created by Manuel Villegas Aceituno on 11/4/24.
//

#include "PoderPsiquico.h"

PoderPsiquico::PoderPsiquico(const std::string &nombre, const std::string &descripcion, const std::string &afectaA,
                             float capacidadDestructiva) : Poder(nombre, descripcion, afectaA, capacidadDestructiva) {}


PoderPsiquico::PoderPsiquico(const Poder &orig) : Poder(orig) {}

PoderPsiquico::PoderPsiquico() : Poder() {}
