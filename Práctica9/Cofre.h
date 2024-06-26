//
// Created by Manuel Villegas Aceituno on 2/5/24.
//

#ifndef PROJECT_PR9_COFRE_H
#define PROJECT_PR9_COFRE_H
#include "Contenedor.h"
#include "Item.h"

class Cofre : public Contenedor<Item>, public Item{
public:
virtual std::string getDescripcion() const override;

virtual void mete(Item* item) override;
};


#endif //PROJECT_PR9_COFRE_H
