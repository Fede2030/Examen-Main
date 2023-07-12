// Examen Main.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Operaciones.h"

int main() {
    // Crear una instancia de Triage
    Triage myTriage = Triage();

    // Agregar pacientes al triage
    myTriage.AddPatient(1, "Pablo");   // Urgencia: 1
    myTriage.AddPatient(5, "Maria");   // Urgencia: 5
    myTriage.AddPatient(3, "Luis");    // Urgencia: 3
    myTriage.AddPatient(2, "Pancho");  // Urgencia: 2
    myTriage.AddPatient(1, "Juan");    // Urgencia: 1
    myTriage.AddPatient(4, "Pepe");    // Urgencia: 4
    myTriage.AddPatient(5, "Ana");     // Urgencia: 5
    myTriage.AddPatient(1, "Pedro");   // Urgencia: 1

    // Atender a los pacientes
    myTriage.PassPatient();  // Se atiende al paciente con menor urgencia (Juan)
    myTriage.PassPatient();  // Se atiende al paciente con menor urgencia (Pedro)

    // Imprimir la lista de pacientes por nivel de urgencia
    myTriage.Print();

    return 0;
}


