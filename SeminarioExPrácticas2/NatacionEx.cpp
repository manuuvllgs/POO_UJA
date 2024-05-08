//
// Created by Manuel Villegas Aceituno on 8/5/24.
//

#include "NatacionEx.h"

NatacionEx::NatacionEx(const std::string &s) : domain_error(s) {}

NatacionEx::NatacionEx(const char *s) : domain_error(s) {}

NatacionEx::NatacionEx(const std::domain_error &error) : domain_error(error) {}
