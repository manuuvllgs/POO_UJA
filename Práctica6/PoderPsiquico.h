//
// Created by Manuel Villegas Aceituno on 11/4/24.
//

#ifndef PROJECT_PR6_PODERPSIQUICO_H
#define PROJECT_PR6_PODERPSIQUICO_H
#include "Poder.h"

class PoderPsiquico: public Poder{
public:
    PoderPsiquico(const std::string &nombre, const std::string &descripcion, const std::string &afectaA,
                  float capacidadDestructiva);

    explicit PoderPsiquico(const Poder &orig);

    PoderPsiquico();
};


#endif //PROJECT_PR6_PODERPSIQUICO_H
