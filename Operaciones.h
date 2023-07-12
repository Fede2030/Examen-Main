#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <string>

class LStack {
private:
    struct Node {
        int value;
        Node* next;
    };

    Node* topNode;  // Puntero al nodo superior de la pila

public:
    LStack();  // Constructor de la clase LStack
    ~LStack();  // Destructor de la clase LStack

    void Push(int value);  // Agrega un elemento a la pila
    void Pop();  // Elimina el elemento superior de la pila
    int Top();  // Retorna el valor del elemento superior de la pila
    bool IsEmpty();  // Verifica si la pila está vacía
};

class LQueue {
public:
    struct Node {
        std::string value;
        Node* next = nullptr; // Inicialización de la variable miembro "next" a nullptr
    };

private:
    Node* frontNode;  // Puntero al nodo frontal de la cola
    Node* backNode;  // Puntero al nodo final de la cola

public:
    LQueue();  // Constructor de la clase LQueue
    ~LQueue();  // Destructor de la clase LQueue

    void Enqueue(const std::string& value);  // Agrega un elemento al final de la cola
    void Dequeue();  // Elimina el elemento frontal de la cola
    std::string Front();  // Retorna el valor del elemento frontal de la cola
    std::string Back();  // Retorna el valor del elemento final de la cola
    bool IsEmpty();  // Verifica si la cola está vacía

    Node* GetFrontNode();  // Obtiene el puntero al nodo frontal de la cola
};

class Triage {
private:
    struct Patient {
        std::string name;
        int urgency;
        Patient* next;
    };

    LQueue* queues;  // Arreglo de colas para cada nivel de urgencia

public:
    Triage();  // Constructor de la clase Triage
    ~Triage();  // Destructor de la clase Triage

    void AddPatient(int urgency, const std::string& patient_name);  // Agrega un paciente al triage
    void PassPatient();  // Atiende al siguiente paciente según las reglas del triage
    void Print();  // Imprime la lista de pacientes en cada nivel de urgencia
};

#endif







