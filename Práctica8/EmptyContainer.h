//
// Created by Manuel Villegas Aceituno on 24/4/24.
//

#ifndef PROJECT_PR8_EMPTYCONTAINER_H
#define PROJECT_PR8_EMPTYCONTAINER_H
#include <iostream>

class EmptyContainer: public std::domain_error {
public:
    EmptyContainer(std::string error);

    EmptyContainer(const EmptyContainer &orig);

    ~EmptyContainer() override;

};


#endif //PROJECT_PR8_EMPTYCONTAINER_H
