#include <iostream>
#include <string>

// Practica 5
template <typename T>
class Cola {
private:
    struct Nodo {
        T dato;
        Nodo* siguiente;
        Nodo(T d) : dato(d), siguiente(nullptr) {}
    };

    Nodo* frente;
    Nodo* final;

public:
    Cola() : frente(nullptr), final(nullptr) {}

    bool Vacia() const {
        return frente == nullptr;
    }

    void Enqueue(const T& s) {
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
            std::cout << "\nCola vacia, no hay solicitudes para procesar.";
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
            std::cout << "\nCola vacia, no hay solicitudes para mostrar.";
            return;
        }
        std::cout << frente->dato << "\n";
    }

    int BuscarLineal(const T& s) const {
        Nodo* actual = frente;
        int posicion = 0;
        while (actual) {
            if (actual->dato == s) {
                return posicion;
            }
            actual = actual->siguiente;
            posicion++;
        }
        return -1;
    }
};

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

    bool operator<(const Solicitud &otro) const {
        return promedio < otro.promedio;
    }

    bool operator>(const Solicitud &otro) const {
        return promedio > otro.promedio;
    }

    friend std::ostream& operator<<(std::ostream& os, const Solicitud& s) {
        os << "Nombre: " << s.nombre << ", Carrera: " << s.carrera
           << ", Materias aprobadas: " << s.materias_aprobadas
           << ", Promedio: " << s.promedio;
        return os;
    }
};

int main() {
    Cola<Solicitud> cola;
    int opcion;
    do {
        std::cout << "\nMenu:\n1. Registrar materias \n2. Procesar registro \n3. Mostrar Frente\n4. Buscar solicitud (lineal)\n5. Salir\nSeleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore();

        if (opcion == 1) {
            std::string nombre, carrera;
            int materias_aprobadas;
            float promedio;
            std::cout << "Ingrese Nombre: ";
            std::getline(std::cin, nombre);
            std::cout << "Ingrese Carrera: ";
            std::getline(std::cin, carrera);
            std::cout << "Ingrese Materias Aprobadas: ";
            std::cin >> materias_aprobadas;
            std::cout << "Ingrese Promedio: ";
            std::cin >> promedio;
            cola.Enqueue(Solicitud(nombre, carrera, materias_aprobadas, promedio));
        } else if (opcion == 2) {
            cola.Dequeue();
        } else if (opcion == 3) {
            cola.MostrarFrente();
        } else if (opcion == 4) {
            std::string nombre, carrera;
            std::cout << "Ingrese Nombre: ";
            std::getline(std::cin, nombre);
            std::cout << "Ingrese Carrera: ";
            std::getline(std::cin, carrera);
            Solicitud s(nombre, carrera, 0, 0);
            int pos = cola.BuscarLineal(s);
            if (pos != -1) {
                std::cout << "Faltan " << pos << " constancias antes de la suya.\n";
            } else {
                std::cout << "No se encontro la solicitud. Debe darla de alta.\n";
            }
        } else if (opcion == 5) {
            std::cout << "Saliendo...\n";
        } else {
            std::cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}
