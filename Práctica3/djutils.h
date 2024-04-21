//
// Created by Manuel Villegas Aceituno on 21/2/24.
//

#ifndef PROJECT_DJUTILS_H
#define PROJECT_DJUTILS_H

#include <iostream>
#include "Temazo.h"
#include "Fecha.h"
#include "Garito.h"


namespace djutils {
    class djutils {

    };

    void mostrarTemazo(const Temazo &t1);

    void mostrarGarito(const Garito &g1);

    void mostrarFecha(const Fecha &f1);

    void modificaGarito(Garito &g1);

    void mostrarTemazosAnteriores (Temazo temas[], int numTemazos, Fecha fechaFiltrar);

    int menorDuracion(Temazo temas[], int tamanio_vector);

}

#endif //PROJECT_DJUTILS_H
