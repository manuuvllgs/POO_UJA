/** @file main.cpp
 * @author POOUJA
 */

#include <iostream>
#include "Paciente.h"
#include "Cita.h"
#include "Medico.h"

int main() {
    /**
     * Prueba 1
     *
     * Crea un Paciente con el nombre "Segis", dni "77390286X" y edad 20.
     * Crea un Paciente con el nombre "Marta", dni "25936546L" y edad -1.
     *
    */


    Paciente p1, p2;
    try {
        p1.setNombre("Segis").setDni("77390286X").setEdad(20);
        p2.setNombre("Marta").setDni("25936546L").setEdad(-1);
    } catch (std::invalid_argument &ia) {
        std::cerr << ia.what();
    }


    /**
     * Prueba 2
     *
     * Crea dos Médicos y dos Citas con los siguientes datos:
     *
        Médico 1: "Juan Martinez", "25786765L", "Cardiologia", 22
        Médico 2: "Carmen Sanchez", "77298976R", "Dermatologia", 17
        Cita 1: "09042024", "120000", "Dolor en el pecho", 60
        Cita 2: "11042024", "093000", "Erupcion en la cara", 20

     *
     * Asigna a cada cita un médico, informando por pantalla de cualquier error que hubiera podido ocurrir en el proceso.
     *
    */

    Medico m1("Juan Martinez", "25786765L", "Cardiologia", 22);
    Medico m2("Carmen Sanchez", "77298976R", "Dermatologia", 17);

    Cita c1("09042024", "120000", "Dolor en el pecho", 60);
    Cita c2("11042024", "093000", "Erupcion en la cara", 20);
    try {
        c1.setMedicoCita(&m1);
        c2.setMedicoCita(&m2);
    } catch (std::invalid_argument &ia) {
        std::cerr << ia.what();
    }

    /**
     * Prueba 3
     *
     * Añade las dos citas creadas al paciente Segis.
     *
     * Recupera la segunda cita del paciente Segis y muestra por pantalla la fecha, la hora y el motivo,
     * informando por pantalla de cualquier error que hubiera podido ocurrir en el proceso.
     *
     */

    try {
        p1.addCita(c1);
        p1.addCita(c2);
        std::cout << "Fecha de la cita: " << p1.getCita(1)->getFecha() << " | Hora de la cita: "
                  << p1.getCita(1)->getHora()
                  << " | Motivo de la cita: " << p1.getCita(1)->getMotivo();
    } catch (std::invalid_argument &ia){
        std::cerr << ia.what();
    }



    /**
     * Prueba 4
     *
     * Crea un nuevo paciente, pacienteCopia, que sea copia del paciente Segis.
     *
     * Muestra por pantalla el nombre, el dni y la edad del pacienteCopia.
     *
     * Recupera la primera cita del pacienteCopia y muestra por pantalla
     * su médico (nombre, dni, especialidad y número de consulta).
     *
    */

    Paciente pacienteCopia(p1);

    std::cout <<std::endl <<  "Nombre: " << pacienteCopia.getNombre() << " | DNI: " << pacienteCopia.getDni() << " | Edad: "
              << pacienteCopia.getEdad();

    std::cout <<std::endl <<  "Nombre del medico asociado a la primera cita: " << pacienteCopia.getCita(0)->getMedicoCita()->getNombre() << " | DNI del medico asociado a la primera cita: " << pacienteCopia.getCita(0)->getMedicoCita()->getDni() << " | Especialidad del medico asociado a la primera cita: " << pacienteCopia.getCita(0)->getMedicoCita()->getEspecialidad() << " | Numero de consulta del medico asociado a la primera cita: " << pacienteCopia.getCita(0)->getMedicoCita()->getNumConsulta();



    /**
      * Prueba 5
      *
      * Obtén la cita de mayor duración del paciente Segis y asígnale como responsable al médico
      * con más experiencia, cuyos datos son (en orden de atributos según el diagrama de clases):
      * "Paula Jiménez", "26923435X", "Cardiologia", 1
      *
      * Muestra por pantalla la fecha, hora, motivo, duración en minutos y nombre del médico
      * de la cita de mayor duración. Si la cita no tiene médico asignado, deberá indicarse
      * "La cita no tiene médico asignado"
     */

    Medico m_experiencia("Paula Jimenez", "26923435X", "Cardiologia", 1);
    p1.getMayorDuracion()->setMedicoCita(&m_experiencia);

    std::cout <<std::endl << "Fecha: " << p1.getMayorDuracion()->getFecha() << " | Hora: " << p1.getMayorDuracion()->getHora()
              << " | Motivo: " << p1.getMayorDuracion()->getMotivo() << " | Duracion (minutos): "
              << p1.getMayorDuracion()->getDuracionMinutos() << " | Medico de la cita: ";
    if (p1.getMayorDuracion()->getMedicoCita() == nullptr) {
        std::cout << "La cita no tiene medico asignado";
    } else {
        std::cout << p1.getMayorDuracion()->getMedicoCita()->getNombre();
    }

        return 0;
    }
