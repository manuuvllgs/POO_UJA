//
// Created by Manuel Villegas Aceituno on 21/2/24.
//

#include "Temazo.h"
#include <iostream>

/**
 * @brief Constructor por defecto de la clase Temazo
 * @ese Temazo.cpp
 */

Temazo::Temazo() {
    setTitulo("Teva");
    setDuracion(178);
    setInterprete("Inma Bunny");
    setNombreUltimoGarito("Flan - A4");
    setFechaUltimoUso(Fecha());
}

/**
 * @brief Destructor de la clase Temazo
 * @ese Temazo.cpp
 */

Temazo::~Temazo() {

}

/**
 * @brief Constructor parametrizado de la clase Temazo
 * @param [in]_titulo
 * @param [in]_interprete
 * @param [in]_duracion
 */

Temazo::Temazo (const std::string _titulo, const std::string _interprete,const int _duracion){
this->duracion = _duracion;
this->interprete = _interprete;
this->titulo = _titulo;
}

/**
 * @brief Constructor por copia de la clase Temazo
 * @param [in]orig
 * @ese Temazo.cpp
 */

Temazo::Temazo(const Temazo &orig){
    this->setTitulo(orig.getTitulo());
    this->setInterprete(orig.getInterprete());
    this->setDuracion(orig.getDuracion());
}

/**
 * @brief Get del atributo titulo de la clase Temazo
 * @return atributo titulo
 * @ese Temazo.cpp
 */

const std::string &Temazo::getTitulo() const {
    return titulo;
}

/**
 * @brief Set del atributo titulo de la clase Temazo.cpp
 * @param [in]titulo
 * @ese Temazo.cpp
 */

void Temazo::setTitulo(const std::string &titulo) {
    Temazo::titulo = titulo;
}

/**
 * @brief Get del interprete titulo de la clase Temazo
 * @return atributo interprete
 * @ese Temazo.cpp
 */

const std::string &Temazo::getInterprete() const {
    return interprete;
}

/**
 * @brief Set del atributo interprete de la clase Temazo
 * @param [in]interprete
 * @ese Temazo.cpp
 */

void Temazo::setInterprete(const std::string &interprete) {
    Temazo::interprete = interprete;
}

/**
 * @brief Get del atributo duracion de la clase Temazo
 * @return atributo duracion
 * @ese Temazo.cpp
 */

int Temazo::getDuracion() const {
    return duracion;
}

/**
 * @brief Set del atributo duracion de la clase Temazo
 * @param [in] duracion
 * @ese Temazo.cpp
 */

void Temazo::setDuracion(int duracion) {
    Temazo::duracion = duracion;
}

/**
 * @brief Get del atributo NombreUltimoGarito de la clase Temazo
 * @ese Temazo.cpp
 */

const std::string &Temazo::getNombreUltimoGarito() const {
    return nombreUltimoGarito;
}

/**
 * @brief Set del atributo NombreUltimoGarito de la clase Temazo
 * @param [in] nombreUltimoGarito
 * @ese Temazo.cpp
 */

void Temazo::setNombreUltimoGarito(const std::string &nombreUltimoGarito) {
    Temazo::nombreUltimoGarito = nombreUltimoGarito;
}

/**
 * @brief Get del atributo FechaUltimoUso de la clase Temazo
 * @ese Temazo.cpp
 */


const Fecha &Temazo::getFechaUltimoUso() const {
    return fechaUltimoUso;
}


/**
 * @brief Set del atributo FechaUltimoUso de la clase Temazo
 * @param [in] nombreUltimoGarito
 * @ese Temazo.cpp
 */

void Temazo::setFechaUltimoUso(const Fecha &fechaUltimoUso) {
    Temazo::fechaUltimoUso = fechaUltimoUso;
}

/**
 * @brief operador mayor que de la clase Temazo segun la duracion
 * @param [in] t2
 * @return true si la duracion del Temazo que llama a la funcion es mayor que del que se pasa por parametro
 */

bool Temazo::operator>(const Temazo &t2){
    if (this->getDuracion()>t2.getDuracion()){
        return true;
    } else return false;
}

