//
// Created by Manuel Villegas Aceituno on 8/5/24.
//

#ifndef G1_NATACIONEX_H
#define G1_NATACIONEX_H
#include <iostream>

class NatacionEx: public std::domain_error {
public:
    explicit NatacionEx(const std::string &s);

    explicit NatacionEx(const char *s);

    explicit NatacionEx(const domain_error &error);
};


#endif //G1_NATACIONEX_H
