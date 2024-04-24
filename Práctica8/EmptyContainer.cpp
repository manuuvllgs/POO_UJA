//
// Created by Manuel Villegas Aceituno on 24/4/24.
//

#include "EmptyContainer.h"

EmptyContainer::~EmptyContainer() {

}

EmptyContainer::EmptyContainer(std::string error): std::domain_error(error) {

}

EmptyContainer::EmptyContainer(const EmptyContainer &orig): std::domain_error(orig) {

}
