//
// Created by Manuel Villegas Aceituno on 21/2/24.
//

#include "Garito.h"
#include "ParametroNoValido.h"

/**
 * @brief Constructor por defecto de la clase Garito
 * @ese Garito.cpp
 */

Garito::Garito() {}

/**
 * @brief Constructor parametrizado de la clase Garito
 * @param [in]_nombre
 * @param [in]_direccion
 * @ese Garito.cpp
 */

Garito::Garito(std::string _nombre, std::string _direccion) {
    this->setNombre(_nombre);
    this->setDireccion(_direccion);
}

/**
 * @brief Constructor por copia de la clase Garito
 * @param [in]orig
 * @ese Garito.cpp
 */

Garito::Garito(const Garito &orig) {
    this->setDireccion(orig.getDireccion());
    this->setNombre(orig.getNombre());
}

/**
 * @brief Destructor de la clase Garito
 * @ese Garito.cpp
 */


Garito::~Garito() {

}

/**
 * @brief Get del atributo nombre de la clase Garito
 * @return atributo nombre
 * @ese Garito.cpp
 */

const std::string &Garito::getNombre() const {
    return nombre;
}

/**
 * @brief Set del atributo nombre de la clase Garito
 * @param [in]nombre
 * @throw ParametroNoValido si se pasa una cadena vacia para el nombre
 * @ese Garito.cpp
 */

void Garito::setNombre(const std::string &nombre) {
    if (nombre == "") {
        throw ParametroNoValido("Garito::setNombre",
                                "El valor que se intenta asignar al atributo correspondiente es una cadena vacia");
    }
    Garito::nombre = nombre;
}

/**
 * @brief Get del atributo direccion de la clase Garito
 * @return atributo direccion
 * @ese Garito.cpp
 */

const std::string &Garito::getDireccion() const {
    return direccion;
}

/**
 * @brief Set del atributo direccion de la clase Garito
 * @param [in]direccion
 * @ese Garito.cpp
 */

void Garito::setDireccion(const std::string &direccion) {
    Garito::direccion = direccion;
}
