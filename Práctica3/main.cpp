//
// Created by Manuel Villegas Aceituno on 28/2/24.
//
#include "Fecha.h"
#include "Temazo.h"
#include "Garito.h"
#include "djutils.h"
#include "ParametroNoValido.h"

const int TAMAX = 100;

int main() {
    Temazo vectorTemazos[TAMAX];
    Garito *pMiCasa;
    pMiCasa = new Garito("Piso", "Paseo de Espania");

    Garito *pVectorGaritos = new Garito[10];

    pVectorGaritos[0].setNombre("Casa de Miguel");
    pVectorGaritos[0].setDireccion("Paseo de Espania");
    pVectorGaritos[1].setNombre("Sitio2");
    pVectorGaritos[1].setDireccion("Direccion2");

    vectorTemazos[0].setNombreUltimoGarito(pMiCasa->getNombre());
    vectorTemazos[1].setNombreUltimoGarito(pVectorGaritos[0].getNombre());
    vectorTemazos[2].setNombreUltimoGarito(pVectorGaritos[1].getNombre());
    vectorTemazos[0].setFechaUltimoUso(Fecha(30, 3, 2005));
    vectorTemazos[1].setFechaUltimoUso(Fecha(3, 6, 2023));
    vectorTemazos[2].setFechaUltimoUso(Fecha(1, 1, 1900));
    vectorTemazos[8].setDuracion(15);

    djutils::mostrarTemazosAnteriores(vectorTemazos, 20, Fecha(1, 1, 2016));
    std::cout << std::endl;

    djutils::menorDuracion(vectorTemazos, 20);
    std::cout << "El temazo cuya duracion es la menor del vector se encuentra en la posicion "
              << djutils::menorDuracion(vectorTemazos, 20);

    delete[] pVectorGaritos;
    delete pMiCasa;


    return 0;
}
