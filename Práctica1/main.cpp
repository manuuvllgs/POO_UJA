#include <iostream>
#include "Vehiculo.h"

using namespace vehiculos;


int main() {
    int num_vehiculos;
    std::string matricula_vehiculo;

    try {
        pideTamanio(num_vehiculos);

        Vehiculo *catalogoVehiculos = new Vehiculo [num_vehiculos];
        rellenarVector(catalogoVehiculos, num_vehiculos);
        std::cout << "Los datos han sido leidos correctamente." << std::endl;


        mostrarEnPantalla(catalogoVehiculos, num_vehiculos);

        std::cout << std::endl << "El vehiculo con mayor precio se encuentra en la posicion "
                  << maxPrecio(catalogoVehiculos, num_vehiculos);

        std::cout << std::endl << "Introduce la matricula del vehiculo que quiera modificar: ";
        getline(std::cin >> std::ws, matricula_vehiculo);


        buscarPorMatricula(matricula_vehiculo, catalogoVehiculos, num_vehiculos);
        std::cout << std::endl << "El vehiculo con la matricula introducida se encuentra en la posicion "
                  << buscarPorMatricula(matricula_vehiculo, catalogoVehiculos, num_vehiculos);


        modificaVehiculo(catalogoVehiculos,
                         buscarPorMatricula(matricula_vehiculo, catalogoVehiculos,
                                            num_vehiculos));

        mostrarEnPantalla(catalogoVehiculos, num_vehiculos);


        mayorQuePrecio(catalogoVehiculos, num_vehiculos, 10000);

        delete[] catalogoVehiculos;

    } catch (const std::string &e) {
        std::cout << "No se ha completado el proceso correctamente. Motivo: " << e;
    }

}

