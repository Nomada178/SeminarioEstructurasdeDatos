#include <iostream>
#include <string>

class Solicitud {
public:
    std::string nombre;
    std::string carrera;
    int materias_aprobadas;
    float promedio;

    Solicitud(std::string n, std::string c, int m, float p)
        : nombre(n), carrera(c), materias_aprobadas(m), promedio(p) {}

    bool operator==(const Solicitud &otro) const {
        return nombre == otro.nombre && carrera == otro.carrera;
    }

    friend std::ostream& operator<<(std::ostream& os, const Solicitud& s) {
        os << "Nombre: " << s.nombre << ", Carrera: " << s.carrera
           << ", Materias aprobadas: " << s.materias_aprobadas
           << ", Promedio: " << s.promedio;
        return os;
    }
};

class Nodo {
public:
    Solicitud dato;
    Nodo* siguiente;

    Nodo(Solicitud s) : dato(s), siguiente(nullptr) {}
};

class Cola {
private:
    Nodo* frente;
    Nodo* final;

public:
    Cola() : frente(nullptr), final(nullptr) {}

    bool Vacia() const {
        return frente == nullptr;
    }

    void Enqueue(const Solicitud& s) {
        Nodo* nuevo = new Nodo(s);
        if (Vacia()) {
            frente = final = nuevo;
        } else {
            final->siguiente = nuevo;
            final = nuevo;
        }
    }

    void Dequeue() {
        if (Vacia()) {
            std::cout << "\nCola vacía, no hay solicitudes para procesar.";
            return;
        }
        Nodo* temp = frente;
        frente = frente->siguiente;
        delete temp;
        if (frente == nullptr) {
            final = nullptr;
        }
    }

    void MostrarFrente() const {
        if (Vacia()) {
            std::cout << "\nCola vacía, no hay solicitudes para mostrar.";
            return;
        }
        std::cout << frente->dato << "\n";
    }
};

int main() {
    Cola cola;
    int opcion;
    do {
        std::cout << "\nMenú:\n1. Enqueue\n2. Dequeue\n3. Mostrar Frente\n4. Salir\nSeleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        if (opcion == 1) {
            std::string nombre, carrera;
            int materias;
            float promedio;
            std::cout << "Ingrese Nombre: ";
            std::getline(std::cin, nombre);
            std::cout << "Ingrese Carrera: ";
            std::getline(std::cin, carrera);
            std::cout << "Ingrese Materias Aprobadas: ";
            std::cin >> materias;
            std::cout << "Ingrese Promedio: ";
            std::cin >> promedio;
            cola.Enqueue(Solicitud(nombre, carrera, materias, promedio));
        } else if (opcion == 2) {
            cola.Dequeue();
        } else if (opcion == 3) {
            cola.MostrarFrente();
        } else if (opcion == 4) {
            std::cout << "Saliendo...\n";
        } else {
            std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}
