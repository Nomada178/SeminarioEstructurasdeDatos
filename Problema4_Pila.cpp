#include <iostream>
#include <string>

const int MAX = 500;

class Empleado {
public:
    std::string nombre;
    int id;

    Empleado() : nombre(""), id(0) {}
    Empleado(std::string n, int i) : nombre(n), id(i) {}

    bool operator==(const Empleado &otro) const {
        return id == otro.id;
    }

    friend std::ostream& operator<<(std::ostream& os, const Empleado& e) {
        os << "ID: " << e.id << ", Nombre: " << e.nombre;
        return os;
    }
};

class Pila {
private:
    Empleado datos[MAX];
    int tope;

public:
    Pila() : tope(-1) {}

    bool Vacia() const {
        return tope == -1;
    }

    bool Llena() const {
        return tope == MAX - 1;
    }

    void Push(const Empleado& elem) {
        if (Llena()) {
            std::cout << "\nPila llena, no se puede agregar más elementos.";
            return;
        }
        datos[++tope] = elem;
    }

    void Pop() {
        if (Vacia()) {
            std::cout << "\nPila vacía, no hay elementos para eliminar.";
            return;
        }
        --tope;
    }

    void Top() const {
        if (Vacia()) {
            std::cout << "\nPila vacía, no hay elementos para mostrar.";
            return;
        }
        std::cout << datos[tope] << "\n";
    }
};

int main() {
    Pila pila;
    int opcion;
    do {
        std::cout << "\nMenú:\n1. Push\n2. Pop\n3. Top\n4. Salir\nSeleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        if (opcion == 1) {
            std::string nombre;
            int id;
            std::cout << "Ingrese ID: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Ingrese Nombre: ";
            std::getline(std::cin, nombre);
            pila.Push(Empleado(nombre, id));
        } else if (opcion == 2) {
            pila.Pop();
        } else if (opcion == 3) {
            pila.Top();
        } else if (opcion == 4) {
            std::cout << "Saliendo...\n";
        } else {
            std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}
