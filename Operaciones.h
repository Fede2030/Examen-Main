#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <string>

template <typename T>
class LStack {
private:
    struct Node {
        T value;        // Valor almacenado en el nodo
        Node* next;     // Puntero al siguiente nodo en la pila
    };

    Node* topNode;      // Puntero al nodo superior de la pila

public:
    LStack();           // Constructor de la pila
    ~LStack();          // Destructor de la pila

    void Push(const T& value);  // Inserta un elemento en la parte superior de la pila
    void Pop();                 // Elimina el elemento en la parte superior de la pila
    T Top();                    // Devuelve el valor del elemento en la parte superior de la pila
    bool IsEmpty();             // Verifica si la pila está vacía
};

template <typename T>
class LQueue {
public:
    struct Node {
        T value;            // Valor almacenado en el nodo
        Node* next = nullptr;   // Puntero al siguiente nodo en la cola (inicializado a nullptr)
    };

private:
    Node* frontNode;       // Puntero al nodo frontal de la cola
    Node* backNode;        // Puntero al nodo posterior de la cola

public:
    LQueue();              // Constructor de la cola
    ~LQueue();             // Destructor de la cola

    void Enqueue(const T& value);   // Inserta un elemento al final de la cola
    void Dequeue();                 // Elimina el elemento del frente de la cola
    T Front();                      // Devuelve el valor del elemento en el frente de la cola
    T Back();                       // Devuelve el valor del elemento en la parte posterior de la cola
    bool IsEmpty();                  // Verifica si la cola está vacía

    Node* GetFrontNode();    // Devuelve un puntero al nodo frontal de la cola
};

class Triage {
private:
    struct Patient {
        std::string name;       // Nombre del paciente
        int urgency;            // Nivel de urgencia del paciente
        Patient* next;          // Puntero al siguiente paciente en la lista
    };

    LQueue<Patient*>* queues;   // Colas de pacientes organizadas por nivel de urgencia

public:
    Triage();                    // Constructor del sistema de triaje
    ~Triage();                   // Destructor del sistema de triaje

    void AddPatient(int urgency, const std::string& patient_name);    // Agrega un paciente al sistema de triaje
    void PassPatient();          // Pasa al siguiente paciente en el sistema de triaje
    void Print();                // Imprime el estado actual del sistema de triaje
};

#endif




