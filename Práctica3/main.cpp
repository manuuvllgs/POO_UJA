#include <iostream>
#include "Fecha.h"
#include "Garito.h"
#include "Temazo.h"
#include "djutils.h"
#include "ParametroNoValido.h"

int main() {

    Temazo tema1;
    Temazo tema2("Adios", "Jhaimens", 158);
    Temazo tema3(tema2);


    Garito garito1("Flan - A4", "Universidad de Jaen");
    Garito garito2(garito1);

    Fecha fecha1;
    Fecha fecha2(27, 04, 2019);

    try {

        int a;
        do {
            std::cout << std::endl;
            std::cout << "Introduzca el numero indicado segun el proceso que desee realizar: " << std::endl;
            std::cout << "1. Mostrar los datos de los Temazos." << std::endl;
            std::cout << "2. Mostrar los datos de los Garitos." << std::endl;
            std::cout << "3. Mostrar los datos de las Fechas." << std::endl;
            std::cout << "4. Modificar los datos del segundo Garito." << std::endl;
            std::cout << "5. Terminar el programa." << std::endl;
            std::cin >> a;


            switch (a) {
                case 1: {
                    djutils::mostrarTemazo(tema1);
                    std::cout << std::endl;
                    djutils::mostrarTemazo(tema2);
                    std::cout << std::endl;
                    djutils::mostrarTemazo(tema3);
                    std::cout << std::endl;
                }
                    break;

                case 2: {
                    djutils::mostrarGarito(garito1);
                    std::cout << std::endl;
                    djutils::mostrarGarito(garito2);
                    std::cout << std::endl;
                }
                    break;

                case 3: {
                    djutils::mostrarFecha(fecha1);
                    std::cout << std::endl;
                    djutils::mostrarFecha(fecha2);
                    std::cout << std::endl;
                }
                    break;

                case 4: {
                    djutils::modificaGarito(garito2);
                }
                    break;
            }

        } while (!(a == 5));
    } catch (ParametroNoValido &error){
        std::cerr << error.queOcurre();
    }
    return 0;
}
