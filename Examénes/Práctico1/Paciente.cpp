//
// Created by admin on 08/04/2024.
//

#include "Paciente.h"
#include <stdexcept>

const std::string &Paciente::getNombre() const {
    return _nombre;
}


int Paciente::getNumCitas() const {
    return _numCitas;
}

Paciente &Paciente::setNombre(const std::string &nombre) {
  _nombre = nombre;
    return (*this);
}

Paciente::Paciente() {}

Paciente::Paciente(const std::string &dni) : _dni(dni) {}

const std::string &Paciente::getDni() const {
    return _dni;
}

Paciente &Paciente::setDni(const std::string &dni) {
    _dni = dni;
    return (*this);
}

int Paciente::getEdad() const {
    return _edad;
}

Paciente &Paciente::setEdad(int edad) {
    if (edad < 0) {
        throw std::invalid_argument("[Paciente::setEdad] se ha pasado una edad negativa");
    }
    _edad = edad;
    return (*this);
}

/**
 * @brief Funcion que sirve para añadir citas a un paciente
 * @author Manuel Villegas Aceituno
 * @date 8/04/2024
 * @param cita Cita que se va a asignar al paciente
 * @pre el medico que esta asignado a la cita debe de tener dni
 * @post al paciente se le habra asignado una nueva cita en su historial y habra aumentado su numero de citas en una unidad
 * @ese Paciente.cpp
 */

void Paciente::addCita(Cita cita) {
    if (_numCitas > _MAX_CITAS) {
        throw std::out_of_range("[Paciente::addCita] se ha superado el numero maximo de citas");
    }
    _citasPaciente[_numCitas] = new Cita(cita);
    ++_numCitas;
}

Paciente::Paciente(const Paciente &orig) {
    _nombre = orig._nombre;
    _edad = orig._edad;
    _dni = orig._dni;
    _numCitas = orig._numCitas;
    for (int i=0; i < orig._numCitas; ++i){
        _citasPaciente[i] = new Cita (*orig._citasPaciente[i]);
    }


}

Cita *Paciente::getCita(int pos) {
    if (pos < 0 || pos > _numCitas) {
        return nullptr;
    } else {
        return _citasPaciente[pos];
    }
}

Paciente::~Paciente() {
    for (int i = 0; i < _numCitas; ++i) {
        if (_citasPaciente[i] != nullptr) { delete _citasPaciente[i]; }
        _citasPaciente[i] = nullptr;
    }

}

Cita* Paciente::getMayorDuracion(){
    int mayorDuracion=0;
    for (int i=1;i < _numCitas;++i){
        if (_citasPaciente[i]->getDuracionMinutos() > _citasPaciente[mayorDuracion]->getDuracionMinutos()){
            mayorDuracion = i;
        }
    }
    return _citasPaciente[mayorDuracion];
}
