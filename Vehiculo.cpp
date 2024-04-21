//
// Created by Manu on 14/02/2024.
//

#include "Vehiculo.h"

using namespace vehiculos;

const int TAMAX = 100;


/**
 * @brief Funcion que pide un tamanio para asignar al vector
 * @author Manuel Villegas Aceituno
 * @date 19/2/24
 * @param [in],[out] tamv
 * @throw string si se pasa un tamanio negativo al vector
 * @ese Vehiculo.cpp
 */

void vehiculos::pideTamanio (int &tamv){
    std::cout << "Introduzca el numero de vehiculos cuya informacion va a ser almacenada: ";
    std::cin >> tamv;
    if (tamv < 0 ){
        throw std::string ("Se le ha pasado un tamanio negativo al vector.");
    }
};

/**
 * @brief Lee por teclado los datos de un vehiculo
 * @author Manuel Villegas Aceituno
 * @date 12/2/2024
 * @param [in] Vehiculo &vehiculo1
 * @pre no ha de cumplir ningun requisito
 * @post Inicizliza un nuevo vehiculo con los datos leidos por teclado
 * @note se utiliza el paso por referencia
 * @throw string si la marca del vehiculo no esta comprendida entre 3 y 20 caracteres
 * @throw string si el modelo del vehiculo no esta comprendido entre 1 y 30 caracteres
 * @throw string si el precio del vehiculo es negativo
 * @ese vehiculo.cpp
 */

void vehiculos::leePorTeclado(Vehiculo &vehiculo1) {
    do {
        std::cout << "Introduce la marca del vehiculo: ";
        getline(std::cin >> std::ws, vehiculo1.marca);
        if (!(vehiculo1.marca.length() > 2 && vehiculo1.marca.length() < 21)) {
            throw std::string("La marca del vehiculo debe estar comprendida entre 3 y 20 caracteres.");
        }
    } while (!(vehiculo1.marca.length() > 2 && vehiculo1.marca.length() < 21));
    do {
        std::cout << "Introduce el modelo del vehiculo: ";
        getline(std::cin >> std::ws, vehiculo1.modelo);
        if (!(vehiculo1.modelo.length() > 0 && vehiculo1.modelo.length() < 31)) {
            throw std::string("El modelo del vehiculo debe estar comprendio entre 1 y 30 caracteres.");
        }
    } while (!(vehiculo1.marca.length() > 2 && vehiculo1.marca.length() < 21));
    do {
        std::cout << "Introduce la matricula del vehiculo: ";
        getline(std::cin >> std::ws, vehiculo1.matricula);
        if (!(vehiculo1.matricula.length() == 6)) {
            throw std::string("La matricula del vehiculo debe tener 6 caracteres.");
        }
    } while (!(vehiculo1.matricula.length() == 6));
    std::cout << "Introduzca el anio de fabricacion: ";
    std::cin >> vehiculo1.anio_fabricacion;
    do {
        std::cout << "Introduzca el precio del vehiculo: ";
        std::cin >> vehiculo1.precio;
        if (vehiculo1.precio < 0) {
            throw std::string("El precio del vehiculo debe ser mayor que 0.");
        }
    } while (vehiculo1.precio < 0);
}

/**
 * @brief Muestra en pantalla los datos de un vehiculo
 * @author Manuel Villegas Aceituno
 * @date 12/2/2024
 * @param [out] Vehiculo &vehiculo1
 * @pre debe estar inicializado un dato tipo Vehiculo
 * @post Muestra en pantalla los datos de un vehiculo
 * @note se utiliza el paso por referencia
 * @ese mvehiculo.cpp
 */

void vehiculos::muestraPorPantalla(const Vehiculo &vehiculo1) {
    std::cout << "Informacion del vehiculo solicitado.";
    std::cout << std::endl;
    std::cout << " Marca: " << vehiculo1.marca;
    std::cout << " Modelo: " << vehiculo1.modelo;
    std::cout << " Matricula: " << vehiculo1.matricula;
    std::cout << " Anio de fabricacion: " << vehiculo1.anio_fabricacion;
    std::cout << " Precio: " << vehiculo1.precio;
}

/**
 * @brief Lee por teclado los datos de un vehiculo
 * @author Manuel Villegas Aceituno
 * @date 12/2/2024
 * @param [in] Vehiculo *vehiculo1
 * @pre no ha de cumplir ningun requisito
 * @post Devuelve un puntero que direcciona a la direccion de memoria con los datos del vehiculo almacenado
 * @note se utiliza sobrecarga con puntero
 * @ese vehiculo.cpp
 */

void vehiculos::leePorTecladoSobrecarga(Vehiculo *vehiculo1) {
    do {
        std::cout << "Introduce la marca del vehiculo: ";
        getline(std::cin >> std::ws, vehiculo1->marca);
        if (!(vehiculo1->marca.length() > 2 && vehiculo1->marca.length() < 21)) {
            std::cout << "La marca del vehiculo debe estar comprendida entre 3 y 20 caracteres." << std::endl;
        }
    } while (!(vehiculo1->marca.length() > 2 && vehiculo1->marca.length() < 21));
    do {
        std::cout << "Introduce el modelo del vehiculo: ";
        getline(std::cin >> std::ws, vehiculo1->modelo);
        if (!(vehiculo1->modelo.length() > 0 && vehiculo1->modelo.length() < 31)) {
            std::cout << "El modelo del vehiculo debe estar comprendio entre 1 y 30 caracteres." << std::endl;
        }
    } while (!(vehiculo1->marca.length() > 2 && vehiculo1->marca.length() < 21));
    do {
        std::cout << "Introduce la matricula del vehiculo: ";
        getline(std::cin >> std::ws, vehiculo1->matricula);
        if (!(vehiculo1->matricula.length() == 6)) {
            std::cout << "La matricula del vehiculo debe tener 6 caracteres." << std::endl;
        }
    } while (!(vehiculo1->matricula.length() == 6));
    std::cout << "Introduzca el anio de fabricacion: ";
    std::cin >> vehiculo1->anio_fabricacion;
    do {
        std::cout << "Introduzca el precio del vehiculo: ";
        std::cin >> vehiculo1->precio;
        if (vehiculo1->precio < 0) {
            std::cout << "El precio del vehiculo debe ser mayor que 0." << std::endl;
        }
    } while (vehiculo1->precio < 0);
}

/**
 * @brief Muestra en pantalla los datos de un vehiculo
 * @author Manuel Villegas Aceituno
 * @date 12/2/2024
 * @param [out] Vehiculo *vehiculo1
 * @pre debe estar inicializado un dato tipo Vehiculo
 * @post Muestra en pantalla los datos de un vehiculo
 * @note se utiliza sobrecarga con punteros
 * @ese vehiculo.cpp
 */

void vehiculos::muestraPorPantallaSobrecarga(const Vehiculo *vehiculo1) {
    std::cout << "Informacion del vehiculo solicitado" << std::endl;
    std::cout << "Marca: " << vehiculo1->marca << std::endl;
    std::cout << "Modelo: " << vehiculo1->modelo << std::endl;
    std::cout << "Matricula: " << vehiculo1->matricula << std::endl;
    std::cout << "Anio de fabricacion: " << vehiculo1->anio_fabricacion << std::endl;
    std::cout << "Precio: " << vehiculo1->precio << std::endl;
}

/**
 * @brief Rellena un vector pidiendo al usuario que
introduzca por teclado los datos de cada uno de los vehículos que lo forman.
 * @author Manuel Villegas Aceituno
 * @date 15/2/24
 * @param [in] Vehiculo v[]
 * @param [in] int tamv
 * @pre debe de haberse definido una cantidad de vehiculos que actuara como tamanio del vector
 * @post guarda un vector con informacion de los vehiculos
 * @throw string si tamanio que se le da al vector es negativo
 * @ese vehiculo.cpp
 */

void vehiculos::rellenarVector(Vehiculo v[], const int tamv) {
    Vehiculo *catalogoVehiculos = new Vehiculo[tamv];

    if (tamv < 0) {
        throw std::string("Se ha pasado un tamanio al vector menor que 0.");
    }
    for (int i = 0; i < tamv; ++i) {
        std::cout << "Vehiculo " << i + 1 << ": " << std::endl;
        leePorTeclado(v[i]);
        std::cout << std::endl;
    }
}

/**
 * @brief Muestra por pantalla el contenido del
vector de vehículos (una línea por cada vehículo). Los vehículos se mostrarán de 5
en 5, haciendo una pausa y esperando a que el usuario pulse una tecla para
continuar.
 * @author Manuel Villegas Aceituno
 * @date 15/2/24
 * @param [in],[out] Vehiculo v
 * @param [in] int tamv
 * @pre debe existir un vector con datos tipo Vehiculo almacenados y una variable que contenga el numero de vehiculos almacenados
 * @post se imprimira en pantalla el contenido del vector de 5 en 5
 * @ese vehiculo.cpp
 */

void vehiculos::mostrarEnPantalla(const Vehiculo v[], const int tamv) {
    int j = 0;
    int contador = 0;
    char aux = '-';
    int cociente = 0, resto = 0;
    cociente = tamv / 5;
    resto = tamv % 5;

    for (int i = 0; i < cociente; i++) {
        aux = '-';
        for (j = 0; j < 5; j++) {
            std::cout << std::endl;
            muestraPorPantalla(v[j + (i * 5)]);
        }
        while (aux == '-') {
            std::cout << std::endl << "Pulse una letra para continuar, (si no lo hace, el programa no continuara):";
            std::cin >> aux;
        }
        contador = i * 5 + j;
    }
    for (int i = 0; i < resto; i++) {
        std::cout << std::endl;
        muestraPorPantalla(v[contador + i]);
    }
}

/**
 * @brief Busca en el vector el vehiculo cuyo precio es mayor y devuelve la posicion en la que se encuentra
 * @author Manuel Villegas Aceituno
 * @date 15/2/24
 * @param [in] Vehiculo v[]
 * @param [in] tamv
 * @pre el vector de vehiculos debe estar relleno
 * @post devuelve la posicion del vehiculo con mayor precio
 * @return devuelve la posicion del vehiculo con mayor precio
 * @ese vehiculo.cpp
 */

int vehiculos::maxPrecio(const Vehiculo v[], int tamv) {
    int pos_max_precio, precio_max = 0;
    for (int i = 0; i < tamv; ++i) {
        if (v[i].precio > precio_max) {
            pos_max_precio = i;
            precio_max = v[i].precio;
        }
    }
    return pos_max_precio;
}

/**
 * @brief funcion que busca un vehiculo del vector segun una matricula dada y devuelve su posicion
 * @author Manuel Villegas Aceituno
 * @date 15/2/24
 * @param [in] string matricula
 * @param [in] Vehiculo v[]
 * @param [in] int tamv
 * @pre el vector de vehiculos debe estar relleno y la posicion que se indica debe de ser menor al tamanio del mismo
 * @return posicion del vehiculo cuya matricula coincide con la dada
 * @throw string la matricula introducida no coincide con la de ningun vehiculo del vector
 * @ese vehiculo.cpp
 */

int vehiculos::buscarPorMatricula(std::string matricula, const Vehiculo v[], int tamv) {
    int pos_matricula = -1;
    for (int i = 0; i < tamv; ++i) {
        if (v[i].matricula == matricula) {
            pos_matricula = i;
        }
    }
    if (pos_matricula == -1) {
        throw std::string("No hay ningun vehiculo con la matricula que ha introducido.");
    }
    return pos_matricula;
}

/**
 * @brief Funcion que dada una posicion del vector modifica la informacion que hay almacenada.
 * @author Manuel Villegas Aceituno
 * @date 19/2/24
 * @param [in] v
 * @param [in] tamv
 * @param [in] precio_dado
 * @pre el vector de vehiculos debe estar relleno y la posicion que se indica debe de ser menor al tamanio del mismo
 * @ese Vehiculo.cpp
 */


void vehiculos::modificaVehiculo(Vehiculo v[], int posicion_vehiculo) {
    std::cout << std::endl;
    leePorTeclado(v[posicion_vehiculo]);
}

/**
 * @brief Funcion que dado un precio muestra el rango de vehiculos cuyo precio es superior al indicado
 * @author Manuel Villegas Aceituno
 * @date 19/2/24
 * @param [in] v
 * @param [in] tamv
 * @param precio_dado
 * @pre se debe de haber rellenado el vector de vehiculos
 * @throw string si el precio que se le da es menor que 0
 * @ese Vehiculo.cpp
 */

void vehiculos::mayorQuePrecio(Vehiculo v[], int tamv, float precio_dado) {
    Vehiculo rangoMayor[TAMAX];
    int j=0;
    std::cout<<std::endl <<"Los vehiculos cuyo precio es mayor que el indicado son: " <<std::endl;
    if (precio_dado < 0){
        throw std::string ("Se ha pasado un precio menor que 0.");
    }
    for (int i = 0; i < tamv; ++i) {
        if (v[i].precio > precio_dado) {
            rangoMayor[j] = v[i];
            ++j;
        }
    }
    vehiculos::mostrarEnPantalla(rangoMayor,j);
}





