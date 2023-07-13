#include "Operaciones.h"
#include <iostream>

/* -----------------------------------------------
          Implementación de LStack
--------------------------------------------------*/

template <typename T>
LStack<T>::LStack() {
    topNode = nullptr; // Inicializa el puntero superior de la pila como nulo
}

template <typename T>
LStack<T>::~LStack() {
    while (!IsEmpty()) {
        Pop(); // Elimina todos los elementos de la pila al liberar la memoria
    }
}

template <typename T>
void LStack<T>::Push(const T& value) {
    Node* newNode = new Node; // Crea un nuevo nodo en el montón
    newNode->value = value; // Asigna el valor al nuevo nodo
    newNode->next = topNode; // Establece el siguiente del nuevo nodo como el antiguo nodo superior
    topNode = newNode; // Establece el nuevo nodo como el nuevo nodo superior
}

template <typename T>
void LStack<T>::Pop() {
    if (!IsEmpty()) {
        Node* temp = topNode; // Crea un puntero temporal al nodo superior
        topNode = topNode->next; // Establece el siguiente nodo como el nuevo nodo superior
        delete temp; // Libera la memoria del nodo superior anterior
    }
}

template <typename T>
T LStack<T>::Top() {
    if (!IsEmpty()) {
        return topNode->value; // Devuelve el valor del nodo superior
    }
    // o cualquier valor de error apropiado cuando la pila está vacía
    throw std::runtime_error("Stack is empty");
}

template <typename T>
bool LStack<T>::IsEmpty() {
    return (topNode == nullptr); // Comprueba si la pila está vacía verificando si el nodo superior es nulo
}

/* -----------------------------------------------
          Implementación de LQueue
--------------------------------------------------*/

template <typename T>
LQueue<T>::LQueue() {
    frontNode = nullptr; // Inicializa el puntero frontal de la cola como nulo
    backNode = nullptr; // Inicializa el puntero posterior de la cola como nulo
}

template <typename T>
LQueue<T>::~LQueue() {
    while (!IsEmpty()) {
        Dequeue(); // Elimina todos los elementos de la cola al liberar la memoria
    }
}

template <typename T>
void LQueue<T>::Enqueue(const T& value) {
    Node* newNode = new Node; // Crea un nuevo nodo en el montón
    newNode->value = value; // Asigna el valor al nuevo nodo
    newNode->next = nullptr; // Establece el siguiente del nuevo nodo como nulo

    if (IsEmpty()) {
        frontNode = newNode; // Si la cola está vacía, el nuevo nodo se convierte en el nodo frontal y posterior
        backNode = newNode;
    }
    else {
        backNode->next = newNode; // Establece el siguiente del nodo posterior actual como el nuevo nodo
        backNode = newNode; // Establece el nuevo nodo como el nuevo nodo posterior
    }
}

template <typename T>
void LQueue<T>::Dequeue() {
    if (!IsEmpty()) {
        Node* temp = frontNode; // Crea un puntero temporal al nodo frontal
        frontNode = frontNode->next; // Establece el siguiente nodo como el nuevo nodo frontal
        if (frontNode == nullptr) {
            backNode = nullptr; // Si el nodo frontal es nulo, la cola está vacía y el nodo posterior también debe ser nulo
        }
        delete temp; // Libera la memoria del nodo frontal anterior
    }
}

template <typename T>
T LQueue<T>::Front() {
    if (!IsEmpty()) {
        return frontNode->value; // Devuelve el valor del nodo frontal
    }
    // o cualquier valor de error apropiado cuando la cola está vacía
    throw std::runtime_error("Queue is empty");
}

template <typename T>
T LQueue<T>::Back() {
    if (!IsEmpty()) {
        return backNode->value; // Devuelve el valor del nodo posterior
    }
    // o cualquier valor de error apropiado cuando la cola está vacía
    throw std::runtime_error("Queue is empty");
}

template <typename T>
bool LQueue<T>::IsEmpty() {
    return (frontNode == nullptr); // Comprueba si la cola está vacía verificando si el nodo frontal es nulo
}

template <typename T>
typename LQueue<T>::Node* LQueue<T>::GetFrontNode() {
    return frontNode; // Devuelve un puntero al nodo frontal de la cola
}

/* -----------------------------------------------
          Implementación de Triage
--------------------------------------------------*/

Triage::Triage() {
    queues = new LQueue<Patient*>[5]; // Crea un arreglo de 5 colas para diferentes niveles de urgencia
}

Triage::~Triage() {
    delete[] queues; // Libera la memoria del arreglo de colas
}

void Triage::AddPatient(int urgency, const std::string& patient_name) {
    Patient* newPatient = new Patient; // Crea un nuevo paciente en el montón
    newPatient->name = patient_name; // Asigna el nombre del paciente
    newPatient->urgency = urgency; // Asigna el nivel de urgencia del paciente
    newPatient->next = nullptr; // Establece el siguiente del nuevo paciente como nulo

    queues[urgency - 1].Enqueue(newPatient); // Agrega el paciente a la cola correspondiente al nivel de urgencia
}

void Triage::PassPatient() {
    for (int i = 0; i < 5; i++) {
        if (!queues[i].IsEmpty()) {
            queues[i].Dequeue(); // Elimina al paciente del frente de la cola más prioritaria (menor nivel de urgencia) y sale del bucle
            break;
        }
    }
}

void Triage::Print() {
    for (int i = 0; i < 5; i++) {
        std::cout << i + 1 << "-> ";

        if (!queues[i].IsEmpty()) {
            LQueue<Patient*>::Node* current = queues[i].GetFrontNode();

            while (current != nullptr) {
                std::cout << current->value->name; // Imprime el nombre del paciente

                if (current->next != nullptr) {
                    std::cout << ", ";
                }

                current = current->next;
            }
        }
        else {
            std::cout << "No hay pacientes"; // Mensaje cuando no hay pacientes en la cola actual
        }

        std::cout << std::endl;
    }
}









