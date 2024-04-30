//
// Created by Manuel Villegas Aceituno on 24/4/24.
//

#ifndef PROJECT_PR8_ITEMAPILABLE_H
#define PROJECT_PR8_ITEMAPILABLE_H
#include "Item.h"

class ItemApilable: public Item {
public:
    const int MAX_ELEMENTOS = 64;
    const int MIN_ELEMENTOS = 1; // se sobreentiende

    explicit ItemApilable(int numElementos);

    void incrementaNumElementos(int cantidad);

    void decrementaNumElementos(int cantidad);

    explicit ItemApilable();

    int getNumElementos() const;

    virtual ~ItemApilable();


private:
    int _numElementos;
};


#endif //PROJECT_PR8_ITEMAPILABLE_H
