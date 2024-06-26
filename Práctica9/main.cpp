/* 
 * File:   main.cpp
 * Author: jrbalsas
 *
 * Created on 15 de abril de 2016, 11:11
 */

#include <cstdlib>
#include <iostream>

#include "Contenedor.h"
#include "Item.h"
#include "Bloque.h"
#include "Espada.h"
#include "Filete.h"
#include "Cofre.h"
#include "Inventario.h"

using namespace std;

/**Inicializa el vector de items inicial
 * @pre v no contiene punteros inicializados
 * @post crea algunos objetos en el vector e inicializa el resto de elementos a 0
 * @return número de posiciones del vector con items creados*/
int inicializaItems(Contenedor<Item> *v, int tamv) {
    int numItems = 0;

    v->mete(new Bloque(5));
    v->mete(new Bloque(8));
    v->mete(new Bloque());
    v->mete(new Espada());
    v->mete(new Filete());


    return v->cuantosHay();
}

/**Libera los items del vector creados en memoria dinámica*/
void liberaItems(Contenedor<Item> *v, int numItems) {
    for (int i = 1; i < numItems; i++) {
        v->saca(1);
    }
}

void visualiza(Contenedor<Item> &c) {
    std::cout << "\nCONTENIDO DEL CONTENEDOR" << std::endl
              << "===================" << std::endl;
    for (int i = 1; i <= c.cuantosHay(); i++) {
        std::cout << i << ".- "
                  << c.consulta(i).getDescripcion() << std::endl;
    }

}

/**@brief Probando los Cofres
 * 
 */

void visualizaTipo(Inventario &inv) {
    std::cout << "CONTENIDO DEL INVENTARIO";
    for (int i = 1; i < inv.cuantosHay()+1; ++i) {
        Item &item = inv.consulta(i);
        std::cout << "\n";
        if (dynamic_cast<Cofre *>(&item)) {
            std::cout << "Posicion " << i << ": Cofre";
        } else if (dynamic_cast<Espada *>(&item)) {
            std::cout << "Posicion " << i << ": Espada";
        } else if (dynamic_cast<Filete *>(&item)) {
            std::cout << "Posicion " << i << ": Filete";
        } else if (dynamic_cast<Bloque*>(&item)){
            std::cout << "Posicion " << i << ": Bloque";
        }
    }
}

int main(int argc, char **argv) {

    const int MAXITEMS = 10;
    Contenedor<Item> cont1;
    Contenedor<Item> *objetos = &cont1;

    try {

        //Inicializamos algunos objetos de prueba
        int numObjetos = inicializaItems(objetos, MAXITEMS);

        Cofre c; //Creamos un cofre con 27 posiciones
        Cofre *pC = &c;
        //Metemos todos los objetos en el cofre (YA ESTAN METIDOS EN EL CONTENEDOR POR LA FUNCION ANTERIOR)

        inicializaItems(pC, MAXITEMS);

        // Comprobar en el programa principal que podemos crear un objeto de tipo inventario y añadirle el cofre
        // que ya teníamos.
        Inventario inv1;
        Inventario *inv = &inv1;
        inv->mete(pC);

        visualizaTipo(*inv);

        // Ejercicio 5 -> Intentamos añadir un cofre dentro de otro cofre

        Cofre cof1, cof2;
        Cofre *pCof1 = &cof1;
        Cofre *pCof2 = &cof2;

        // pCof1->mete(pCof2); (quitar comentario para excepcion)

        // Ejercicio 6

        visualiza(dynamic_cast<Cofre &>(inv->consulta(1)));
        //Liberamos recursos
        liberaItems(objetos, numObjetos);

    } catch (std::exception &e) {
        //Capturamos cualquier excepción que se haya podido escapar
        //En tiempo de desarrollo
        std::cerr << "Finalización del programa por excepción sin capturar: "
                  << e.what() << std::endl;
    }
    return 0;
}

