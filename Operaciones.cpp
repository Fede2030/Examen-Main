#include "Operaciones.h"
#include <iostream>

/* -----------------------------------------------
          Implementación de LStack
--------------------------------------------------*/

LStack::LStack() {
    topNode = nullptr;  // Inicializar el nodo superior como nulo al crear una nueva pila
}

LStack::~LStack() {
    while (!IsEmpty()) {
        Pop();  // Eliminar todos los nodos de la pila al destruirla
    }
}

void LStack::Push(int value) {
    Node* newNode = new Node;  // Crear un nuevo nodo
    newNode->value = value;  // Asignar el valor proporcionado al nuevo nodo
    newNode->next = topNode;  // Establecer el siguiente nodo como el nodo superior actual
    topNode = newNode;  // Actualizar el nodo superior para que sea el nuevo nodo
}

void LStack::Pop() {
    if (!IsEmpty()) {
        Node* temp = topNode;  // Mantener una referencia al nodo superior actual
        topNode = topNode->next;  // Actualizar el nodo superior para que sea el siguiente nodo
        delete temp;  // Eliminar el nodo anterior del nodo superior
    }
}

int LStack::Top() {
    if (!IsEmpty()) {
        return topNode->value;  // Devolver el valor del nodo superior actual
    }
    return -1;  // o cualquier otro valor de error apropiado cuando la pila esté vacía
}

bool LStack::IsEmpty() {
    return (topNode == nullptr);  // Verificar si la pila está vacía comparando el nodo superior con nulo
}

/* -----------------------------------------------
          Implementación de LQueue
--------------------------------------------------*/

LQueue::LQueue() {
    frontNode = nullptr;  // Inicializar el nodo frontal y el nodo posterior como nulos al crear una nueva cola
    backNode = nullptr;
}

LQueue::~LQueue() {
    while (!IsEmpty()) {
        Dequeue();  // Eliminar todos los nodos de la cola al destruirla
    }
}

void LQueue::Enqueue(const std::string& value) {
    Node* newNode = new Node;  // Crear un nuevo nodo
    newNode->value = value;  // Asignar el valor proporcionado al nuevo nodo
    newNode->next = nullptr;  // Establecer el siguiente nodo como nulo

    if (IsEmpty()) {
        frontNode = newNode;  // Si la cola está vacía, tanto el nodo frontal como el nodo posterior apuntan al nuevo nodo
        backNode = newNode;
    }
    else {
        backNode->next = newNode;  // Enlazar el nuevo nodo al nodo posterior existente
        backNode = newNode;  // Actualizar el nodo posterior para que sea el nuevo nodo
    }
}

void LQueue::Dequeue() {
    if (!IsEmpty()) {
        Node* temp = frontNode;  // Mantener una referencia al nodo frontal actual
        frontNode = frontNode->next;  // Actualizar el nodo frontal para que sea el siguiente nodo
        if (frontNode == nullptr) {
            backNode = nullptr;  // Si después de eliminar el nodo frontal la cola queda vacía, también se actualiza el nodo posterior como nulo
        }
        delete temp;  // Eliminar el nodo frontal anterior
    }
}

std::string LQueue::Front() {
    if (!IsEmpty()) {
        return frontNode->value;  // Devolver el valor del nodo frontal actual
    }
    return "";  // o cualquier otro valor de error apropiado cuando la cola esté vacía
}

std::string LQueue::Back() {
    if (!IsEmpty()) {
        return backNode->value;  // Devolver el valor del nodo posterior actual
    }
    return "";  // o cualquier otro valor de error apropiado cuando la cola esté vacía
}

bool LQueue::IsEmpty() {
    return (frontNode == nullptr);  // Verificar si la cola está vacía comparando el nodo frontal con nulo
}

LQueue::Node* LQueue::GetFrontNode() {
    return frontNode;  // Obtener el nodo frontal actual
}

/* -----------------------------------------------
          Implementación de Triage
--------------------------------------------------*/

Triage::Triage() {
    queues = new LQueue[5];  // Crear un array de colas con 5 niveles de urgencia
}

Triage::~Triage() {
    delete[] queues;  // Liberar la memoria asignada para el array de colas al destruir el objeto Triage
}

void Triage::AddPatient(int urgency, const std::string& patient_name) {
    queues[urgency - 1].Enqueue(patient_name);  // Agregar un paciente a la cola correspondiente según su nivel de urgencia
}

void Triage::PassPatient() {
    for (int i = 0; i < 5; i++) {
        if (!queues[i].IsEmpty()) {
            queues[i].Dequeue();  // Pasar al siguiente paciente eliminando al paciente actual en la cola de mayor urgencia no vacía
            break;
        }
    }
}

void Triage::Print() {
    for (int i = 0; i < 5; i++) {
        std::cout << i + 1 << "-> ";

        if (!queues[i].IsEmpty()) {
            LQueue::Node* current = queues[i].GetFrontNode();  // Obtener el nodo frontal de la cola actual

            while (current != nullptr) {
                std::cout << current->value;

                if (current->next != nullptr) {
                    std::cout << ", ";
                }

                current = current->next;  // Mover al siguiente nodo
            }
        }
        else {
            std::cout << "No hay pacientes";
        }

        std::cout << std::endl;
    }
}




