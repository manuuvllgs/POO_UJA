//
// Created by Manuel Villegas Aceituno on 11/4/24.
//

#include "PoderFisico.h"
#include <fstream>

PoderFisico::PoderFisico(const std::string &nombre, const std::string &descripcion, const std::string &afectaA,
                         float capacidadDestructiva) : Poder(nombre, descripcion, afectaA, capacidadDestructiva) {}


PoderFisico::PoderFisico(const Poder &orig) : Poder(orig) {}

PoderFisico::PoderFisico() : Poder() {}

/*
 * @brief Funcion que sirve para grabar los datos de un poder fisico en un archivo
 * @author Manuel Villegas Aceituno
 * @date 15/04/2024
 * @param nombre del archivo que se va a crear con los datos del poder fisico
 * @post si no ocurren errores se creara un archivo con la info proporcionada
 * @throw  si no se puede crear el archivo
 * @ese PoderFisico.cpp
 */

void PoderFisico::grabarPoderFisico(std::string nombreArchivo) {
    std::ofstream f;
    f.open(nombreArchivo);
    if (f.good()) {
        f << "Nombre del poder fisico: " << this->getNombre() << std::endl << "Capacidad destructiva del poder: "
          << this->getCapacidadDestructiva();
        f.close();
    } else {
        std::cerr << "No se ha creado el archivo correctamente";
    }


}

