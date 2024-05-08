#include <iostream>

#include "Jornada.h"
#include "Natacion.h"

// Prueba 4: Modifica la función visualiza del archivo main.cpp, de tal forma
//          que si la actividad es de tipo natación, se muestre además la
//          distancia total (obtenida como número de largos*longitud de la
//          piscina)
void visualiza(Actividad &a) {
    std::cout << "   Inicio: " << a.getHoraInicio() << std::endl
              << "   Duración: " << a.getDuracionSegs() << " segundos"
              << std::endl
              << "   Pulso máximo: " << a.getPulsoMax() << std::endl
              << "   Pulso mínimo: " << a.getPulsoMin() << std::endl
              << "   Pulso medio: " << a.getPulsoMedio() << std::endl
              << "   Pulso normalizado: " << a.getPulsoNormalizado() << std::endl
              << "   Sensaciones: " << a.getSensaciones() << std::endl;
    if (dynamic_cast<Natacion *>(&a)) {
        std::cout << "Distancia total: "
                  << dynamic_cast<Natacion *>(&a)->getNumLargos() * dynamic_cast<Natacion *>(&a)->getLongitudPiscina();
    }
}

void visualiza(Jornada &j) {
    std::cout << "Actividades del día " << j.getFecha() << "" << std::endl
              << "----------------------------" << std::endl;
    int max = j.getNActividades();
    for (int i = 0; i < max; i++) {
        Actividad *act = j.getActividad(i);
        std::cout << "Actividad " << i + 1 << "" << std::endl;
        visualiza(*act);

        std::cout << "\n";
    }
}

int main() {
    Jornada j1(20230308, 8, 67.5);

    Actividad a1;
    a1.setHoraInicio(83000);
    a1.setDuracionSegs(3600);
    a1.setPulsoMax(110);
    a1.setPulsoMin(80);
    a1.setPulsoMedio(90);
    a1.setDescripcion("Caminata");
    a1.setSensaciones("Todo OK");

    Ubicacion u1, u2;
    u1.setDescripcion("El Neveral");
    u2.setDescripcion("Piscina UJA (por construir)");

    // Prueba 1: Crea en la función main dos actividades de Natación (usando el
    //           constructor parametrizado). Asocia la actividad de caminata con
    //           la ubicación 1 definida en la función main, y las actividades de
    //           natación con la ubicación 2 definida en la función main.
    //           Utiliza para los parámetros estos valores:
    //   Natación 1:                            Natación 2:
    //      Hora de inicio: 110000                 Hora de inicio: 200000
    //      Duración: 3600                         Duración: 3600
    //      Pulso máximo: 140                      Pulso máximo: 150
    //      Pulso mínimo: 120                      Pulso mínimo: 130
    //      Pulso medio: 130                       Pulso medio: 142
    //      Descripción: Natación fuerte           Descripción: Doble sesión
    //      Sensaciones: Bastante cansado          Sensaciones: Agotado
    //      Longitud de la piscina: 25             Longitud de la piscina: 25
    //      Número de largos: 52                   Número de largos: 60

    Natacion nat1(110000, 3600, 140, 120, 130, "Natacion fuerte", "Bastante cansado", 25, 52);
    Natacion *pNat1 = &nat1;
    Natacion nat2(200000, 3600, 150, 130, 142, "Doble sesion", "Agotado", 25, 60);
    Natacion *pNat2 = &nat2;

    a1.setLugar(u1);
    nat1.setLugar(u2);
    nat2.setLugar(u2);

    // Prueba 2: Añade las tres actividades a la Jornada ya existente.

    j1.addActividad(a1);
    j1.addActividad(*pNat1);
    j1.addActividad(*pNat2);

    // Prueba 3: Modifica el código de la función main para capturar las
    //           excepciones que se puedan producir durante la creación de las
    //           actividades de tipo Natación indicadas en la Prueba 1

    // Prueba 5: Muestra por consola (utilizando la función visualiza) la
    //           información de la actividad más intensa de la jornada.

    visualiza(*j1.actividadMasIntensa());
    visualiza(j1);

    return 0;
}