/** @file Medico.cpp
 * @author POOUJA
 */

#include "Medico.h"


Medico::Medico(const std::string &nombre, const std::string &dni, const std::string &especialidad, int numConsulta)
        : _nombre(nombre), _dni(dni), _especialidad(especialidad), _numConsulta(numConsulta){}

Medico::~Medico() {

}

const std::string &Medico::getNombre() const{
    return _nombre;
}

void Medico::setNombre(const std::string &nombre){
    _nombre = nombre;
}

const std::string &Medico::getDni() const{
    return _dni;
}

void Medico::setDni(const std::string &dni){
    _dni = dni;
}

const std::string &Medico::getEspecialidad() const{
    return _especialidad;
}

void Medico::setEspecialidad(const std::string &especialidad){
    _especialidad = especialidad;
}

int Medico::getNumConsulta() const{
    return _numConsulta;
}

void Medico::setNumConsulta(int numConsulta){
    _numConsulta = numConsulta;
}
