//
// Created by Manuel Villegas Aceituno on 24/4/24.
//

#ifndef PROJECT_PR8_ESPADA_H
#define PROJECT_PR8_ESPADA_H
#include "ItemUsable.h"
#include <sstream>


class Espada: public ItemUsable {
public:
    Espada(): ItemUsable(){}

    virtual std::string getDescripcion() override;

    virtual ~Espada();

};


#endif //PROJECT_PR8_ESPADA_H
