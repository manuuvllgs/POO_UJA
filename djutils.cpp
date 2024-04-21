//
// Created by Manuel Villegas Aceituno on 21/2/24.
//

#include "djutils.h"

/**
 * @brief Funcion que muestra en pantalla los datos de un Temazo
 * @author Manuel Villegas Aceituno
 * @date 21/02/2024
 * @param [in] t1
 * @ese djutils.cpp
 */

void djutils::mostrarTemazo(const Temazo &t1) {
    std::cout << "Titulo: " << t1.getTitulo() << " | Interprete: " << t1.getInterprete() << " | Duracion: "
              << t1.getDuracion();
};


/**
 * @brief Funcion que muestra en pantalla los datos de un Garito
 * @author Manuel Villegas Aceituno
 * @date 21/02/2024
 * @param [in] g1
 * @ese djutils.cpp
 */

void djutils::mostrarGarito(const Garito &g1) {
    std::cout << "Nombre: " << g1.getNombre() << " | Direccion: " << g1.getDireccion();
};


/**
 * @brief Funcion que muestra en pantalla los datos de una Fecha
 * @author Manuel Villegas Aceituno
 * @date 21/02/2024
 * @param [in] f1
 * @ese djutils.cpp
 */


void djutils::mostrarFecha(const Fecha &f1) {

    std::cout << f1.getDia();
    std::cout << " - ";
    std::cout << f1.getMes();
    std::cout << " - ";
    std::cout << f1.getAnio();
}


/**
 * @brief Funcion que modifica los datos de un Garito que se le pasa
 * @author Manuel Villegas Aceituno
 * @date 21/02/2024
 * @param [in] g1
 * @throw ParametroNoValido si se pasa una cadena vacia para el nombre del garito
 * @ese djutils.cpp

 */


void djutils::modificaGarito(Garito &g1){
    std::string modifica1_nombre;
    std::string modifica1_direccion;
    std::cout<<"Introduce el nombre del garito modificado: "; std::getline(std::cin>> std::ws, modifica1_nombre);
    g1.setNombre(modifica1_nombre);
    std::cout<< "Introduce la direccion del garito modificada: "; std::getline(std::cin>> std::ws, modifica1_direccion);
    g1.setDireccion(modifica1_direccion);
}
