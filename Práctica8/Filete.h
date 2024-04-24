//
// Created by Manuel Villegas Aceituno on 24/4/24.
//

#ifndef PROJECT_PR8_FILETE_H
#define PROJECT_PR8_FILETE_H
#include "Item.h"

class Filete : public Item{
public:
    Filete();

    virtual std::string getDescripcion() override;

    virtual ~Filete();


};


#endif //PROJECT_PR8_FILETE_H
