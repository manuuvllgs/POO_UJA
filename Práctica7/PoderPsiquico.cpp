/**
 * @file PoderPsiquico.cpp
 * @author algarcia
 *
 * @date 6 de abril de 2016
 */

#include <sstream>

#include "PoderPsiquico.h"
#include <sstream>

using std::string;

PoderPsiquico::PoderPsiquico(string nmb, string dsc, string aA, float cD, float lucidez) :
        Poder(nmb, dsc, aA, cD), _lucidez(lucidez) {}

PoderPsiquico::PoderPsiquico(const PoderPsiquico &orig, float lucidez) :
        Poder(orig), _lucidez(lucidez) {}

PoderPsiquico::~PoderPsiquico() {}


float PoderPsiquico::getCapacidadDestructiva() const {
    return Poder::getCapacidadDestructiva() * _lucidez;

}

float PoderPsiquico::getLucidez() const {
    return _lucidez;
}

void PoderPsiquico::setLucidez(float lucidez) {
    if (lucidez < 0 || lucidez > 1) {
        throw std::out_of_range("[PoderPsiquico::setLucidez] se ha pasado un parametro no valido");
    } else {
        _lucidez = lucidez;
    }
}

string PoderPsiquico::toCSV() const {
    std::stringstream aux;
    aux << this->Poder::toCSV() << " ; " << this->_lucidez;
    return aux.str();
}


void PoderPsiquico::operator=(const PoderPsiquico &orig) {
    if (this != &orig) {
        Poder::operator=(orig);
        _lucidez = orig._lucidez;
    }
}