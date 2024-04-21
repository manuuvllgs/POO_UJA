/** 
 * @file main.cpp
 * @author Casipro Gramo 
 * @author Yoyapro GRamo
 *
 * @date Fecha estelar 20160309
 */

#include <cstdlib>
#include <string>
#include "Piloto.h"
#include "Droide.h"
#include "StarFighter.h"
#include "Informe.h"
#include <iostream>

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
    string datosNaves[5] = {"Kuat Systems;Delta-7;1",
                            "Kuat Systems;Delta-7B;1",
                            "Incom Corporation;T-65B X-wing;1",
                            "Koensayr Manufacturing;Y-wing;2",
                            "Kuat Systems;A-wing;1"};
    string datosDroides[5] = {"Industrial Automation;R2-D2",
                              "Industrial Automation;R2-KT",
                              "AccuTronics;R3-D3",
                              "AccuTronics;R3-KT",
                              "Arakyd Industries;C3PO"};
*/

    try {
        StarFighter *naves = new StarFighter[5];
        naves[0].setMarca("Kuat Systems").setModelo("Delta-7").setNumPlazas(1);
        naves[1].setMarca("Kuat Systems").setModelo("Delta-7B").setNumPlazas(1);
        naves[2].setMarca("Incom Corporation").setModelo("T-65B W-wing").setNumPlazas(1);
        naves[3].setMarca("Koensayr Manufacturing").setModelo("Y-wing").setNumPlazas(2);
        naves[4].setMarca("Kuat Systems").setModelo("A-wing").setNumPlazas(1);

        Droide *droides = new Droide[5];
        droides[0].setModelo("Industrial Automation").setMarca("R2-D2");
        droides[1].setModelo("Industrial Automation").setMarca("R2-KT");
        droides[2].setModelo("AccuTronics").setMarca("R3-D3");
        droides[3].setModelo("AccuTronics").setMarca("R3-KT");
        droides[4].setModelo("Arakyd Industries").setMarca("C3PO");

        Piloto *pilotos = new Piloto[5];
        pilotos[0].setNombre("Dameron Poe").setNumMisiones(100).setNavePiloto(&naves[1]).setDroidePiloto(
                &droides[2]).setFechaUltimaMision(
                123456).setNacionalidad("Jakku");
        pilotos[1].setNombre("Anakin Skywalker").setNumMisiones(133).setNavePiloto(&naves[3]).setDroidePiloto(
                &droides[0]).setFechaUltimaMision(
                126756).setNacionalidad("Tatooine").setIncidenciasUltimaMision(
                "Derribados 3 cazas enemigos");
        pilotos[2].setNombre("Han Solo").setNumMisiones(247).setNavePiloto(&naves[0]).setDroidePiloto(
                &droides[1]).setFechaUltimaMision(
                126786).setIncidenciasUltimaMision("Impacto en motor izquierdo");


        for (int i = 0; i < 3; ++i) {
            std::cout << "Informe " << i + 1 << ": " << pilotos[i].generaInforme().toCSV() << std::endl;
        }

        std::cout << "Pilotos auxiliados por droides de la marca AccuTronics: " << std::endl;
        for (int i = 0; i < 5; ++i) {
            if (pilotos[i].getDroideAuxiliar() != nullptr &&
                pilotos[i].getDroideAuxiliar()->getModelo() == "AccuTronics") {

                std::cout << pilotos[i].getNombre() << std::endl;

            }
        }

        delete[] pilotos;
        delete[] droides;
        delete[] naves;

    } catch (const string &e) {
        std::cerr << e;
    }


    return 0;
}

