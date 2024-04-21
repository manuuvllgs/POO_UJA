/**
 * @file main.cpp
 * @author 
 *
 */

#include <iostream>
#include "EquipoMutante.h"
#include <fstream>


using namespace std;

/***@brief Visualiza la información completa de un mutante*/
void visualiza(Mutante &m) {
    std::cout << "MUTANTE: "
              << m.toCSV() << std::endl;
    std::cout << "  Poderes : " << std::endl;
    for (int i = 0; i < m.getNumPoderes(); ++i) {
        std::cout << m.getPoderesMutante(i)->getNombre() << " ; ";
    }
    //ToDo, Mostrar los poderes del mutante

}

/***@brief Visualiza los datos de todos los miembros de un equipo mutante*/
void visualiza(EquipoMutante &eq) {
    std::cout << "EQUIPO: " << eq.getNombre()
              << " (Base: " << eq.getBase() << ")" << std::endl
              << "============================"
              << "Miembros del equipo: ";
    for (int i = 0; i < eq.getNumMiembros(); ++i) {
        std::cout << eq.getMutante(i)->getApodo() << " ; ";
    }
    std::cout << std::endl;
    //ToDo, Mostrar los mutantes del equipo (usar función anterior)

}

//ToDo, Método para almacenar un vector de punteros a mutantes
//almacenaMutantesCSV()

void almacenarMutantesCSV(Mutante v[], int tamv, std::string nombreArchivo) {
    std::ofstream f;
    f.open(nombreArchivo);
    if (f.good()) {
        for (int i = 0; i < tamv; ++i) {
            f << v[i].toCSV() << endl;
        }
        f.close();
    } else {
        std::cerr << "No se ha creado correctamente el archivo";
    }

}


int main(int argc, char **argv) {


    // Crea un array de 5 punteros a mutantes, asignándoles los valores a sus
    // atributos directamente en el código fuente
    // ejercicio 7, apartado a

    Mutante *mutantes = new Mutante[5];
    mutantes[0].setApodo("Mono").setNacionalidad("Brasil").setFechaDeNacimiento(19990412).setNombreReal("Gorila");
    mutantes[1].setApodo("Destructor").setNacionalidad("Española").setFechaDeNacimiento(20050915).setNombreReal("Teva");
    mutantes[2].setApodo("Cochino").setNacionalidad("Española").setFechaDeNacimiento(20091019).setNombreReal("David");
    mutantes[3].setApodo("Enano").setNacionalidad("Venezolana").setFechaDeNacimiento(20170615).setNombreReal("Elfo");
    mutantes[4].setApodo("MVP").setNacionalidad("Jaen").setFechaDeNacimiento(20050330).setNombreReal("Doncic");




    // Crea dos equipos mutantes, asignando al primero los mutantes que ocupan
    // las posiciones pares del array, y al segundo los de las posiciones impares
    // ejercicio 7, apartado b


    EquipoMutante q1("Bernabeu", "Madrid");
    EquipoMutante q2("Camp Nou", "Barcelona");

    q1.addMutante(&mutantes[1]);
    q1.addMutante(&mutantes[3]);
    q2.addMutante(&mutantes[0]);
    q2.addMutante(&mutantes[2]);
    q2.addMutante(&mutantes[4]);

    // ejercicio 7, apartado c

    std::cout << q1.toCSV() << "\n" << q2.toCSV();

    // Añade varios poderes a cada mutante, utilizando los métodos ya
    // implementados: usando datos o objetos de tipo Poder
    // Muestra por la consola la información de cada equipo mutante en formato CSV


    mutantes[0].addPoder("Volar", "Permite volar", "Todo el mundo", 1000.38);
    mutantes[1].addPoder("Invisible", "No te ven", "Videntes", 734.87);
    mutantes[2].addPoder("Poder3", "Permite poder3", "A los de linares", 29.21);
    mutantes[3].addPoder("Poder4", "Permite poder4", "A los de Baeza", 100.8);
    mutantes[4].addPoder("Poder5", "Permite poder5", "A los de Andujar", 10000000000.9);


    //Guardamos datos de mutantes en fichero CSV
    //ejercicio 7, apartado d

    almacenarMutantesCSV(mutantes, 5, "datosMutantes.txt");


    // Destruye todos los objetos creados en memoria dinámica antes de la
    // finalización del programa
    // ejercicio 7, apartado e
    delete []mutantes;

    // ejercicio propuesto en clase de la práctica
    PoderFisico poderF1, poderF2;
    poderF1.setNombre("Llave UFC");
    poderF1.setAfectaA("Objetivos terrestres");
    poderF1.setCapacidadDestructiva(19283.3489);
    poderF1.setDescripcion("Propicia una llave de UFC a aquel objetivo que se marque");

    poderF1.grabarPoderFisico("datos.txt");





    return 0;
}

