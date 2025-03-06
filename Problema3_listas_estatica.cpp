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
};

template <typename T>
class ListaEstatica {
private:
    T datos[MAX];
    int tam;

public:
    ListaEstatica() : tam(0) {}

    int Inserta(T elem, int pos) {
        if (Llena() || pos < 0 || pos > tam) {
            std::cout << "\nError de inserción";
            return -1;
        }
        for (int i = tam; i > pos; --i) {
            datos[i] = datos[i - 1];
        }
        datos[pos] = elem;
        tam++;
        return pos;
    }

    int Agrega(T elem) {
        if (Llena()) {
            std::cout << "\nLista llena";
            return -1;
        }
        datos[tam++] = elem;
        return tam - 1;
    }

    int Busca(T elem) {
        for (int i = 0; i < tam; i++) {
            if (datos[i] == elem) {
                return i;
            }
        }
        return -1;
    }

    int Elimina(int pos) {
        if (Vacia() || pos < 0 || pos >= tam) {
            std::cout << "\nError de eliminación";
            return -1;
        }
        for (int i = pos; i < tam - 1; i++) {
            datos[i] = datos[i + 1];
        }
        tam--;
        return pos;
    }

    bool Vacia() const {
        return tam == 0;
    }

    bool Llena() const {
        return tam == MAX;
    }

    void Muestra() const {
        for (int i = 0; i < tam; i++) {
            std::cout << "ID: " << datos[i].id << ", Nombre: " << datos[i].nombre << "\n";
        }
        std::cout << "\n";
    }
};

int main() {
    ListaEstatica<Empleado> lista;
    int opcion;
    do {
        std::cout << "\nMenú:\n1. Agrega\n2. Buscar\n3. Elimina\n4. Inserta\n5. Muestra\n6. Salir\nSeleccione una opción: ";
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
            lista.Agrega(Empleado(nombre, id));
        } else if (opcion == 2) {
            int id;
            std::cout << "Ingrese ID del empleado a buscar: ";
            std::cin >> id;
            int pos = lista.Busca(Empleado("", id));
            if (pos != -1)
                std::cout << "Empleado encontrado en la posición: " << pos << "\n";
            else
                std::cout << "Empleado no encontrado\n";
        } else if (opcion == 3) {
            int id;
            std::cout << "Ingrese ID del empleado a eliminar: ";
            std::cin >> id;
            int pos = lista.Busca(Empleado("", id));
            if (pos != -1) {
                lista.Elimina(pos);
                std::cout << "Empleado eliminado\n";
            } else {
                std::cout << "Empleado no encontrado\n";
            }
        } else if (opcion == 4) {
            std::string nombre;
            int id, pos;
            std::cout << "Ingrese ID: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Ingrese Nombre: ";
            std::getline(std::cin, nombre);
            std::cout << "Ingrese la posición donde insertar: ";
            std::cin >> pos;
            lista.Inserta(Empleado(nombre, id), pos);
        } else if (opcion == 5) {
            lista.Muestra();
        } else if (opcion == 6) {
            std::cout << "Saliendo...\n";
        } else {
            std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}
