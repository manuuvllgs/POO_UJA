/** 
 * @file Informe.cpp
 * @author Casipro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <stdexcept>
#include <sstream>

#include "Informe.h"

using std::string;

long Informe::_numInformes = 0;

Informe::Informe() : Informe(0) {
}

Informe::Informe(long fecha) :
        _fechaEstelar(fecha) {
    setFechaEstelar(fecha); // Lanza excepción si fecha no válida

    _numInformes++;
    _idI = _numInformes;
}

Informe::Informe(const Informe &orig) :
        _idPiloto(orig._idPiloto),
        _fechaEstelar(orig._fechaEstelar),
        _datosInforme(orig._datosInforme) {
}

Informe::~Informe() {
}

Informe &Informe::setDatosInforme(string datosInforme) {
    this->_datosInforme = datosInforme;

    return *this;
}

string Informe::getDatosInforme() const {
    return _datosInforme;
}

/**
 * @todo Comprobar el valor, y si es negativo, lanzar excepción
 */
Informe &Informe::setFechaEstelar(long fechaEstelar) {
    if (fechaEstelar < 0) {
        throw std::invalid_argument("Informe::setFechaEstelar: se ha pasado una fecha negativa");
    } else {

        this->_fechaEstelar = fechaEstelar;
    }
    return *this;
}

long Informe::getFechaEstelar() const {
    return _fechaEstelar;
}

/**
 * @todo Comprobar el valor, y si es negativo, lanzar excepción
 */
Informe &Informe::setIdPiloto(int idPiloto) {
    if (idPiloto < 0) {
        throw std::invalid_argument("Informe::Informe: el identificador del"
                                    " piloto no puede ser negativo");
    }

    this->_idPiloto = idPiloto;

    return *this;
}

int Informe::getIdPiloto() const {
    return _idPiloto;
}

int Informe::getIdI() const {
    return _idI;
}

string Informe::toCSV() const {
    std::stringstream aux;

    aux << "Fecha estelar: " << _fechaEstelar << " ; "
        << "id de piloto: " << _idPiloto << " ; "
        << _datosInforme;

    return aux.str();
}

Informe &Informe::operator=(const Informe &otro) {
    if (this != &otro) {
        _idPiloto = otro._idPiloto;
        _fechaEstelar = otro._fechaEstelar;
        _datosInforme = otro._datosInforme;
    }

    return *this;
}

void Informe::fromCSV(string &datos) {
    std::stringstream ss;
    ss << datos;

    ss >> _numInformes;
    ss.ignore(1);
    ss >> _idI;
    ss.ignore(1);
    ss >> _idPiloto;
    ss.ignore(1);
    ss >> _fechaEstelar;
    ss.ignore(1);
    getline(ss, _datosInforme, ';');
}