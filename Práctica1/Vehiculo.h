//
// Created by Manu on 14/02/2024.
//

#ifndef PROJECT_PRACTICA1_VEHICULO_H
#define PROJECT_PRACTICA1_VEHICULO_H


#include <iostream>

namespace vehiculos {

    class Vehiculo {
    public:
        std::string marca; //< longitud máxima 20  ymínima 3
        std::string modelo; //< longitud máxima 30 y mínima 1
        std::string matricula; //< longitud 6
        int anio_fabricacion = 0;
        float precio = 0; //< >0
    };
    void leePorTeclado(Vehiculo &vehiculo);

    void muestraPorPantallaSobrecarga(const Vehiculo *vehiculo);

    void muestraPorPantalla(const Vehiculo &vehiculo1);

    void leePorTecladoSobrecarga(Vehiculo *vehiculo1);

    void rellenarVector(Vehiculo v[], const int tamv);

    void mostrarEnPantalla(const Vehiculo *v, int tamv);

    int maxPrecio(const Vehiculo v[], int tamv);

    int buscarPorMatricula(std::string matricula, const Vehiculo v[], int tamv);

    void modificaVehiculo (Vehiculo v[], int posicion_vehiculo);

    void mayorQuePrecio (Vehiculo v[], int tamv, float precio_dado);

    void pideTamanio (int &tamv);

}


#endif //PROJECT_PRACTICA1_VEHICULO_H
