#include <iostream>

using namespace std;

struct Vehiculo {
    string marca; //< longitud máxima 20  ymínima 3
    string modelo; //< longitud máxima 30 y mínima 1
    string matricula; //< longitud 6
    int anio_fabricacion;
    float precio; //< >0
};

/**
 * @brief Lee por teclado los datos de un vehiculo
 * @author Manuel Villegas Aceituno
 * @date 12/2/2024
 * @param [in] Vehiculo &vehiculo1
 * @pre no ha de cumplir ningun requisito
 * @post Inicizliza un nuevo vehiculo con los datos leidos por teclado
 * @note se utiliza el paso por referencia
 * @ese main.cpp
 */

void leePorTeclado(Vehiculo &vehiculo1) {
    do {
        cout << "Introduce la marca del vehiculo: ";
        getline(cin >> ws, vehiculo1.marca);
        if (!(vehiculo1.marca.length() > 2 && vehiculo1.marca.length() < 21)) {
            cout << "La marca del vehiculo debe estar comprendida entre 3 y 20 caracteres." << endl;
        }
    } while (!(vehiculo1.marca.length() > 2 && vehiculo1.marca.length() < 21));
    do {
        cout << "Introduce el modelo del vehiculo: ";
        getline(cin >> ws, vehiculo1.modelo);
        if (!(vehiculo1.modelo.length() > 0 && vehiculo1.modelo.length() < 31)) {
            cout << "El modelo del vehiculo debe estar comprendio entre 1 y 30 caracteres." << endl;
        }
    } while (!(vehiculo1.marca.length() > 2 && vehiculo1.marca.length() < 21));
    do {
        cout << "Introduce la matricula del vehiculo: ";
        getline(cin >> ws, vehiculo1.matricula);
        if (!(vehiculo1.matricula.length() == 6)) {
            cout << "La matricula del vehiculo debe tener 6 caracteres." << endl;
        }
    } while (!(vehiculo1.matricula.length() == 6));
    cout << "Introduzca el anio de fabricacion: ";
    cin >> vehiculo1.anio_fabricacion;
    do {
        cout << "Introduzca el precio del vehiculo: ";
        cin >> vehiculo1.precio;
        if (vehiculo1.precio < 0) {
            cout << "El precio del vehiculo debe ser mayor que 0." << endl;
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
 * @ese main.cpp
 */

void muestraPorPantalla(Vehiculo &vehiculo1) {
    cout << "Informacion del vehiculo solicitado" << endl;
    cout << "Marca: " << vehiculo1.marca << endl;
    cout << "Modelo: " << vehiculo1.modelo << endl;
    cout << "Matricula: " << vehiculo1.matricula << endl;
    cout << "Anio de fabricacion: " << vehiculo1.anio_fabricacion << endl;
    cout << "Precio: " << vehiculo1.precio << endl;
}

/**
 * @brief Lee por teclado los datos de un vehiculo
 * @author Manuel Villegas Aceituno
 * @date 12/2/2024
 * @param [in] Vehiculo *vehiculo1
 * @pre no ha de cumplir ningun requisito
 * @post Devuelve un puntero que direcciona a la direccion de memoria con los datos del vehiculo almacenado
 * @note se utiliza sobrecarga con puntero
 * @ese main.cpp
 */

void leePorTecladoSobrecarga(Vehiculo *vehiculo1) {
    do {
        cout << "Introduce la marca del vehiculo: ";
        getline(cin >> ws, vehiculo1->marca);
        if (!(vehiculo1->marca.length() > 2 && vehiculo1->marca.length() < 21)) {
            cout << "La marca del vehiculo debe estar comprendida entre 3 y 20 caracteres." << endl;
        }
    } while (!(vehiculo1->marca.length() > 2 && vehiculo1->marca.length() < 21));
    do {
        cout << "Introduce el modelo del vehiculo: ";
        getline(cin >> ws, vehiculo1->modelo);
        if (!(vehiculo1->modelo.length() > 0 && vehiculo1->modelo.length() < 31)) {
            cout << "El modelo del vehiculo debe estar comprendio entre 1 y 30 caracteres." << endl;
        }
    } while (!(vehiculo1->marca.length() > 2 && vehiculo1->marca.length() < 21));
    do {
        cout << "Introduce la matricula del vehiculo: ";
        getline(cin >> ws, vehiculo1->matricula);
        if (!(vehiculo1->matricula.length() == 6)) {
            cout << "La matricula del vehiculo debe tener 6 caracteres." << endl;
        }
    } while (!(vehiculo1->matricula.length() == 6));
    cout << "Introduzca el anio de fabricacion: ";
    cin >> vehiculo1->anio_fabricacion;
    do {
        cout << "Introduzca el precio del vehiculo: ";
        cin >> vehiculo1->precio;
        if (vehiculo1->precio < 0) {
            cout << "El precio del vehiculo debe ser mayor que 0." << endl;
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
 * @ese main.cpp
 */

void muestraPorPantallaSobrecarga(Vehiculo *vehiculo1) {
    cout << "Informacion del vehiculo solicitado" << endl;
    cout << "Marca: " << vehiculo1->marca << endl;
    cout << "Modelo: " << vehiculo1->modelo << endl;
    cout << "Matricula: " << vehiculo1->matricula << endl;
    cout << "Anio de fabricacion: " << vehiculo1->anio_fabricacion << endl;
    cout << "Precio: " << vehiculo1->precio << endl;
}


int main() {

    const int MAX_VEHICULOS = 10;
    int num_vehiculos = 0;

    // De esta manera se utilizan las funciones pasadas por referencia
    Vehiculo v1;
    leePorTeclado(v1);
    cout << endl;
    muestraPorPantalla(v1);


    // De esta manera se utiliza la sobrecarga con punteros
    Vehiculo *v1p = new Vehiculo;
    leePorTecladoSobrecarga(v1p); cout<<endl;
    muestraPorPantallaSobrecarga(v1p); cout<<endl;


    do {
        cout << "Introduce el numero de vehiculos que desea introducir: ";
        cin >> num_vehiculos;
        if (num_vehiculos > MAX_VEHICULOS) {
            cout << "El numero maximo de vehiculos permitidos es " << MAX_VEHICULOS << endl;
        }
    } while (!(num_vehiculos > 0 && num_vehiculos < MAX_VEHICULOS));

    // Paso por referencia
    Vehiculo vehiculos[MAX_VEHICULOS];

    for (int i = 0; i < num_vehiculos; ++i) {
        cout << "Vehiculo " << i + 1 << ": " << endl;
        leePorTeclado(vehiculos[i]);
        cout << endl;
    }

    for (int j = 0; j < num_vehiculos; ++j) {
        cout << "Vehiculo " << j + 1 << ": " << endl;
        muestraPorPantalla(vehiculos[j]);
        cout << endl;
    }



    // Sobrecarga con punteros
    Vehiculo *pvehiculos = new Vehiculo[MAX_VEHICULOS];

    for (int i = 0; i < num_vehiculos; ++i) {
        cout << "Vehiculo " << i + 1 << ": " << endl;
        leePorTecladoSobrecarga(&pvehiculos[i]);
        cout << endl;
    }

    for (int j = 0; j < num_vehiculos; ++j) {
        cout << "Vehiculo " << j + 1 << ": " << endl;
        muestraPorPantallaSobrecarga(&pvehiculos[j]);
        cout << endl;
    }


    // Vehiculo con mayor precio con paso de referencia
    Vehiculo vehiculo_mayor_precio;
    int mayor_precio = 0;

    for (int i = 0; i < num_vehiculos; ++i) {
        if (vehiculos[i].precio > mayor_precio) {
            vehiculo_mayor_precio = vehiculos[i];
            mayor_precio = vehiculos[i].precio;
        }
    }
    cout << "Vehiculo mas caro:" << endl;
    muestraPorPantalla(vehiculo_mayor_precio);


    return 0;
}
