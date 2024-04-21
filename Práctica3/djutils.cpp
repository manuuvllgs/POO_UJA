//
// Created by Manuel Villegas Aceituno on 21/2/24.
//

#include "djutils.h"

const int TAMAX = 100;

/**
 * @brief Funcion que muestra en pantalla los datos de un Temazo
 * @author Manuel Villegas Aceituno
 * @date 21/02/2024
 * @param [in] t1
 * @ese djutils.cpp
 */

void djutils::mostrarTemazo(const Temazo &t1) {
    std::cout << "Titulo: " << t1.getTitulo() << " | Interprete: " << t1.getInterprete() << " | Duracion: "
              << t1.getDuracion() << " | Ultimo garito: " << t1.getNombreUltimoGarito() << " | Ultima fecha: ";
    mostrarFecha(t1.getFechaUltimoUso());
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


void djutils::modificaGarito(Garito &g1) {
    std::string modifica1_nombre;
    std::string modifica1_direccion;
    std::cout << "Introduce el nombre del garito modificado: ";
    std::getline(std::cin >> std::ws, modifica1_nombre);
    g1.setNombre(modifica1_nombre);
    std::cout << "Introduce la direccion del garito modificada: ";
    std::getline(std::cin >> std::ws, modifica1_direccion);
    g1.setDireccion(modifica1_direccion);
}

/**
 * @brief Funcion que muestra los datos de los temazos situados en un vector cuyo valor del atributo fechaUltimoUso es menor que el valor de un valor tipo Fecha que se le pasa
 * @author Manuel Villegas Aceituno
 * @date 28/2/2024
 * @param [in] temas
 * @param [in] numTemazos
 * @param [in] fechaFiltrar
 * @ese djutils.cpp
 */

void djutils::mostrarTemazosAnteriores(Temazo temas[], int numTemazos, Fecha fechaFiltrar) {
    Temazo temas_filtrados[TAMAX];
    int j = 0;
    for (int i = 0; i < numTemazos; ++i) {
        if (fechaFiltrar.operator>=(temas[i].getFechaUltimoUso())) {
            temas_filtrados[j] = temas[i];
            ++j;
        }
    }
    for (int i = 0; i < j; ++i) {
        std::cout << std::endl;
        mostrarTemazo(temas_filtrados[i]);
    }
}

/**
 * @brief Funcion que busca el Temazo con menor duracion dentro de un vector y devuelve su posicion
 * @author Manuel Villegas Aceituno
 * @date 4/3/2024
 * @param [in] temas
 * @param [in] tamanio_vector
 * @return posicion del vector donde se encuentra el Temazo con menor duracion
 */

int djutils::menorDuracion(Temazo temas[], int tamanio_vector){
    int posicion=0;
    for (int i=1; i < tamanio_vector; ++i){
        if (temas[posicion].operator>(temas[i])){
            posicion = i;
        }
    }
    return posicion;
};
