/**
 * @file main.cpp
 * @author algarcia
 *
 * @date 6 de abril de 2016
 */

#include <iostream>
#include <fstream>
#include "EquipoMutante.h"
#include "ordena.h"

using namespace std;

/***@brief Visualiza la información completa de un mutante*/
void visualiza(Mutante &m) {
    std::cout << "MUTANTE: "
              << m.toCSV() << std::endl;
    std::cout << "  Poderes : " << std::endl;
    for (int i = 0; i < m.getNumPoderes(); i++) {
        std::cout << "    - " << m.getPoder(i).toCSV() << std::endl;
    }
}

/***@brief Visualiza los datos de todos los miembros de un equipo mutante*/
void visualiza(EquipoMutante &eq) {
    std::cout << "EQUIPO: " << eq.getNombre()
              << " (Base: " << eq.getBase() << ")" << std::endl
              << "============================"
              << std::endl;
    for (int i = 0; i < eq.getNumMiembros(); i++) {
        visualiza(*(eq.getMutante(i)));
    }
}

//ToDo
/***@brief Visualiza un vector de mutantes en formato CSV*/
void visualiza() {
}


/**@brief Almacena los mutantes de un vector en una archivo CSV 
   @param Mutante* v[], vector de punteros a objetos mutantes
   @param unsigned int tamv, número de mutantes almacenados en el vector
   @param string nomArchivo, archivo donde se almacenarán los mutantes. Si ya sobreescribirá.
   @post  Almacena los datos simples (sin poderes) de cada mutante en formato CSV en una línea diferente del Archivo indicado
 */
void almacenaMutantesCSV(Mutante *v[], unsigned int tamv,
                         std::string nomArchivo) {
    std::ofstream archivo;
    archivo.open(nomArchivo.c_str()); //c_str() no es necesario si compilador soporta >= C++11

    if (archivo.good()) {
        for (unsigned int i = 0; i < tamv; i++) {
            archivo << v[i]->toCSV() << std::endl;
        }

        archivo.close();
    }
}

//ToDo
/**@brief Recupera los mutantes de un fichero CSV en un vector
   @param Mutante* v[], vector de punteros a objetos mutantes
   @param unsigned int tamv, número máximo de mutantes que se pueden almacenar en v
   @param string nomArchivo, archivo de donde se recuperarán los mutantes en formato CSV
   @post  Las posiciones del vector se sobreescribirán
   @post  Recupera mutantes del fichero y los crea en memoria dinámica, asociando cada uno a una posición del vector
   @return número de mutantes leídos y creados (como máximo será tamv)
 */

int recuperaMutantesCSV(Mutante *v[], int tamv, std::string nombreArchivo) {
    std::ifstream fe;
    std::string cad;
    int cont = 0;
    fe.open(nombreArchivo);
    if (fe.good()) {
        while (!fe.eof() && cont < tamv) {
            getline(fe, cad);
            if (cad != "") {
                v[cont]->fromCSV(cad);
                cad = "";
                ++cont;
            }
        }
        fe.close();

    }
    return cont;
}


/**@brief inicializa vector de mutantes y crea algunos
   @pre v debe tener al menos tamv posiciones
   @post se inicializan todas las posiciones de v a 0 o a un nuevo mutante 
   @return número de muntantes creados en el vector*/
int inicializaMutantes(Mutante *v[], int tamv) {
    for (int i = 0; i < tamv; i++) {
        v[i] = 0;
    }

    int creados = 0;
    v[creados++] = new Mutante("Logan", "Lobezno", 19320101, "Estadounidense");
    v[creados++] = new Mutante("Marie", "Rogue", 19700101, "Estadounidense");
    v[creados++] = new Mutante("Ororo", "Tormenta", 19500101, "Keniata");
    v[creados++] = new Mutante("Scott", "Cíclope", 19300101, "Estadounidense");
    v[creados++] = new Mutante("Charles", "Profesor X", 19200101, "Estadounidense");

    return creados;
}

void visualiza(Mutante *v[], int tamv) {
    for (int i = 0; i < tamv; ++i) {
        std::cout << v[i]->toCSV() << endl;
    }
}

int main(int argc, char **argv) {
    const int MAXMUTANTES = 5;
    Mutante *mutantes[MAXMUTANTES];
    int numMutantes = 0;
    std::string archivoMutantes = "mutantes.csv";

    numMutantes = inicializaMutantes(mutantes, MAXMUTANTES);
    //ToDo, recuperar mutantes del archivo

    Mutante *recuperadosMutantes[5];
    inicializaMutantes(recuperadosMutantes, 5);
    recuperaMutantesCSV(recuperadosMutantes, 5, "mutantes.csv");

    //ToDo, Visualizar vector de muntantes en formato CSV


    visualiza(mutantes, 5);
    //Creación de los equipos y configuración de poderes
    EquipoMutante equipo1("Patrulla X", "Mansión");
    equipo1.addMutante(mutantes[1]);
    equipo1.addMutante(mutantes[3]);

    EquipoMutante equipo2("Los malos", "Casa Magneto");
    equipo2.addMutante(mutantes[0]);
    equipo2.addMutante(mutantes[2]);
    equipo2.addMutante(mutantes[4]);

    //Diferentes formas de añadir poderes: usando datos o objetos de tipo Poder
    mutantes[0]->addPoder("longevidad", "vivir mucho", "su cuerpo", 0);
    mutantes[1]->addPoder(Poder("absorción", "absorve poderes de otros mutantes",
                                "cualquier mutante", 100));
    mutantes[2]->addPoderFisico("clima", "puede manejar el clima", "atmósfera",
                                150);
    mutantes[3]->addPoder(PoderFisico("rayo", "expulsa láser por los ojos",
                                      "lo que pille por delante", 500));
    mutantes[4]->addPoder(PoderPsiquico("AtacaMente",
                                        "ataca la mente de su enemigo",
                                        "cualquiera", 150, 0));

    visualiza(equipo1);
    visualiza(equipo2);


    //ToDo, Crear poder físico asfixia y añadir a Doctor X

    PoderPsiquico *asfixia = new PoderPsiquico;
    asfixia->setNombre("Asfixia");
    asfixia->setDescripcion("Asfixia al oponente");
    asfixia->setAfectaA("Objetivos físicos");
    asfixia->setLucidez(0.75);
    asfixia->setCapacidadDestructiva(600);
    std::cout << "Antes de aniadir asfixia: " << mutantes[4]->capacidadDestructivaTotal();
    mutantes[4]->addPoder(*asfixia);
    std::cout << "\nDespues de aniadir asfixia: " << mutantes[4]->capacidadDestructivaTotal();


    //ToDo, Ordenar y visualizar vector de mutantes con plantilla de método Ordena

    ordenar(mutantes, 5);
    std::cout << "\n";
    visualiza(mutantes, 5);
    //Comprobar que DoctorX a mejorado su posición por que ha aumentado su capacidad
    //Destructiva

    ordenar(mutantes, 5);
    almacenaMutantesCSV(mutantes, 5, archivoMutantes);

    for (int i = 0; i < MAXMUTANTES; i++) {
        delete mutantes[i];
        mutantes[i] = nullptr;
    }

    // ToDo, ejercicio opcional

    Poder *poderesDiferentes[5];
    poderesDiferentes[1] = new Poder;
    poderesDiferentes[2] = new Poder;
    poderesDiferentes[3] = new Poder;
    poderesDiferentes[4] = new Poder;
    poderesDiferentes[0] = new Poder;

    poderesDiferentes[1]->setNombre("Poder").setCapacidadDestructiva(100).setAfectaA("T").setDescripcion("Poder (normal)");
    poderesDiferentes[1]->setNombre("Poder fisico").setDescripcion("Poder fisico").setAfectaA("F").setCapacidadDestructiva(120);
    poderesDiferentes[2]->setNombre("Poder2").setCapacidadDestructiva(200).setAfectaA("TT").setDescripcion("Poder 2(normal)");
    poderesDiferentes[3]->setNombre("Poder psiquico").setCapacidadDestructiva(129.34).setAfectaA("Q").setDescripcion("Poder psiquico");
    poderesDiferentes[0]->setNombre("Poder fisico 2").setDescripcion("Poder fisico").setAfectaA("FF").setCapacidadDestructiva(240);

    ordenar(poderesDiferentes,5);

    for (int i=0; i < 5; ++i){
        std::cout << poderesDiferentes[i]->toCSV() <<"\n";
    }

    std::ofstream f1;
    f1.open("poderestoCSV.csv");
    if (f1.good()){
        for (int i=0; i < 5; ++i){
            f1 << poderesDiferentes[i]->toCSV() << "\n";
        }
    }

    return 0;

}