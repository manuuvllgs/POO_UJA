/** 
 * @file main.cpp
 * @author Casipro Gramo
 *
 * @date Fecha estelar 20160309
 */

#include <cstdlib>
#include <string>
#include "Pieza.h"
#include "Piloto.h"
#include "StarFighter.h"
#include "Informe.h"
#include "Escuadron.h"
#include "Droide.h"

using namespace std;

/**
 * @todo Ver el enunciado del ejercicio 5 de la práctica
 */
int main(int argc, char **argv) {
    /*
    string datosPilotos[5] = {"Dameron Poe;Jakku;100;123456;---",
                              "Anakin Skywalker;Tatooine;133;126756;Derribados 3 cazas enemigos",
                              "Han Solo;Corellia;247;126786;Impacto en motor izquierdo",
                              "Chewbacca;Kashyyk;115;136786;---",
                              "Leia Organa;Alderaan;3;126336;Derribados 10 cazas enemigos"};
*/

    try {

        Piloto *pilotos = new Piloto[5];

        pilotos[0].fromCSV((string &) "Dameron Poe;Jakku;100;123456;---");
        pilotos[1].fromCSV((string &) "Anakin Skywalker;Tatooine;133;126756;Derribados 3 cazas enemigos");
        pilotos[2].fromCSV((string &) "Han Solo;Corellia;247;126786;Impacto en motor izquierdo");
        pilotos[3].fromCSV((string &) "Chewbacca;Kashyyk;115;136786;---");
        pilotos[4].fromCSV((string &) "Leia Organa;Alderaan;3;126336;Derribados 10 cazas enemigos");

        Escuadron escuadron1, escuadron2;

        escuadron1.setNombre("Madrid").setBase("Bernabeu");
        escuadron1.addPiloto(&pilotos[0]);
        escuadron1.addPiloto(&pilotos[1]);

        escuadron2.setNombre("Barcelona").setBase("Camp Nou");
        escuadron2.addPiloto(&pilotos[2]);
        escuadron2.addPiloto(&pilotos[3]);
        escuadron2.addPiloto(&pilotos[4]);

        std::cout << "Escuadron 1: " << escuadron1.getNombre() << " | Promedio de misiones: "
                  << escuadron1.promedioMisiones();
        std::cout << "\nEscuadron 2: " << escuadron2.getNombre() << " | Promedio de misiones: "
                  << escuadron2.promedioMisiones();


        StarFighter *st1;
        st1 = new StarFighter;
        StarFighter *st2;
        st2 = new StarFighter;
        st1->setMarca("Nave1").setModelo("Modelo1").setNumPlazas(3);
        st2->setMarca("Nave2").setModelo("Modelo2").setNumPlazas(1);

        st1->addPieza(new Pieza("Ala", 132.56, "Sirve para volar"));
        st1->addPieza(new Pieza("Ventana", 23.98, "Sirve para apreciar las vistas"));
        st1->addPieza(new Pieza("Motor", 456.27, "Sin el no podria volar"));
        st2->addPieza(new Pieza("Ruedas", 281.84, "Sirven para desplazarse en tierra"));
        st2->addPieza(new Pieza("Mandos", 71.45, "Sirven para controlaar la nave"));
        st2->addPieza(new Pieza("Propulsor", 1342.76, "Sirve para propulsar la nave"));


        std::cout << "\nPeso de la nave 1: " << st1->calculaPeso();
        std::cout << "\nPeso de la nave 2: " << st2->calculaPeso();

        std::cout << "\nNumero de pilotos con nacionalidad Jakku en el escuadron 1: " << escuadron1.numPilotos("Jakku");
        std::cout << "\nNumero de pilotos con nacionalidad Corellia en el escuadron 2: " << escuadron2.numPilotos("Corellia");


        delete[]pilotos;

    } catch (std::out_of_range &oor) {
        std::cerr << oor.what();
    }


    return 0;
}

