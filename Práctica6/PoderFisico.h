//
// Created by Manuel Villegas Aceituno on 11/4/24.
//

#ifndef PROJECT_PR6_PODERFISICO_H
#define PROJECT_PR6_PODERFISICO_H
#include "Poder.h"


class PoderFisico: public Poder
        {
public:
    PoderFisico(const std::string &nombre, const std::string &descripcion, const std::string &afectaA,
                float capacidadDestructiva);

    explicit PoderFisico(const Poder &orig);

    PoderFisico();

    void grabarPoderFisico(std::string nombreArchivo);
};


#endif //PROJECT_PR6_PODERFISICO_H
