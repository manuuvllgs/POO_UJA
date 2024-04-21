/** 
 * @file Piloto.cpp
 * @author Yoyapro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <stdexcept>
#include <sstream>

#include "Piloto.h"

using std::string;

int Piloto::_numPilotos = 0;

Piloto::Piloto() : Piloto("") {}

Piloto::Piloto(string nombre) : _nombre(nombre) {
    _numPilotos++;
    _idP = _numPilotos;
}

Piloto::Piloto(const Piloto &orig) : _nombre(orig._nombre),
                                     _nacionalidad(orig._nacionalidad),
                                     _numMisiones(orig._numMisiones),
                                     _fechaUltimaMision(orig._fechaUltimaMision),
                                     _incidenciasUltimaMision(orig._incidenciasUltimaMision) {
    _numPilotos++;
    _idP = _numPilotos;
}

Piloto::~Piloto() {}

/**
 * @todo Aquí hay que añadir la comprobación del parámetro y lanzar la excepción
 *       correspondiente. El número de misiones no puede ser <= 0
 */
Piloto &Piloto::setNumMisiones(int numMisiones) {
    if (numMisiones <= 0) {
        throw string("El número de misiones no puede ser <= 0");
    } else {
        this->_numMisiones = numMisiones;
    }
    return ( *this );
}

int Piloto::getNumMisiones() const {
    return _numMisiones;
}

Piloto &Piloto::setNacionalidad(string nacionalidad) {
    this->_nacionalidad = nacionalidad;
    return ( *this );
}

string Piloto::getNacionalidad() const {
    return _nacionalidad;
}

Piloto &Piloto::setNombre(string nombre) {
    this->_nombre = nombre;
    return ( *this );
}

string Piloto::getNombre() const {
    return _nombre;
}

int Piloto::getIdP() const {
    return _idP;
}

/**
 * @todo Si el número de misiones del piloto es 0, no puede tener incidencias;
 *       haz esta comprobación y lanza la excepción correspondiente
 */
Piloto &Piloto::setIncidenciasUltimaMision(string incidenciasUltimaMision) {
    if (this->getNumMisiones() == 0) {
        throw string("El numero de misiones del piloto es 0, por tanto no puede tener incidencias");
    } else {
        this->_incidenciasUltimaMision = incidenciasUltimaMision;
    }
    return ( *this );
}

string Piloto::getIncidenciasUltimaMision() const {
    return _incidenciasUltimaMision;
}

/**
 * @todo Si el número de misiones del piloto es 0, no puede tener fecha de
 *       última misión; haz esta comprobación y lanza la excepción
 *       correspondiente
 */
Piloto &Piloto::setFechaUltimaMision(long fechaUltimaMision) {
    if (this->getNumMisiones() == 0) {
        throw string("El numero de misiones del piloto es 0, por tanto no puede tener fecha de ultima mision");
    } else {
        this->_fechaUltimaMision = fechaUltimaMision;
    }
    return ( *this );
}

/**
 * @todo Si el número de misiones del piloto es 0, no puede tener fecha de
 *       última misión; haz esta comprobación y lanza la excepción
 *       correspondiente
 */
long Piloto::getFechaUltimaMision() const {
    if (this->getNumMisiones() == 0) {
        throw string("El numero de misiones del piloto es 0, por tanto no puede tener fecha de ultima mision");
    } else {
        return _fechaUltimaMision;
    }
}

string Piloto::toCSV() const {
    std::stringstream aux;

    aux << _nombre << " ; "
        << _nacionalidad << " ; "
        << _numMisiones << " ; "
        << _fechaUltimaMision << " ; "
        << _incidenciasUltimaMision;

    return (aux.str());
}

Piloto &Piloto::operator=(const Piloto &otro) {
    if (this != &otro) {
        _nombre = otro._nombre;
        _nacionalidad = otro._nacionalidad;
        _numMisiones = otro._numMisiones;
        _fechaUltimaMision = otro._fechaUltimaMision;
        _incidenciasUltimaMision = otro._incidenciasUltimaMision;
    }

    return ( *this );
}

Piloto &Piloto::setNavePiloto(StarFighter *st1) {

    _naveDelPiloto = st1;

    return ( *this );
}

StarFighter *Piloto::getNaveDelPiloto() const {
    return _naveDelPiloto;
}

Droide *Piloto::getDroideAuxiliar() const {
    return _droideAuxiliar;
}

Piloto &Piloto::setDroidePiloto(Droide *dr1) {
    _droideAuxiliar = dr1;
    return ( *this );
}

Informe Piloto::generaInforme() {
    Informe informe1;
    std::stringstream datosInf;
    std::string datos;
    if (this->_incidenciasUltimaMision == ""){
        datos = "No se encontraron incidencias";
    } else {
        datos = this->_incidenciasUltimaMision;
    }
    datosInf << datos << " ; " << this->getNaveDelPiloto()->getIdSF() << " ; "
             << this->getDroideAuxiliar()->getIdD();
    informe1.setIdPiloto(this->getIdP())
            .setDatosInforme(datosInf.str())
            .setFechaEstelar(this->getFechaUltimaMision());
    return informe1;
}
