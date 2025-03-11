#include <iostream>
#include <string>

const int MAX = 500;

class Empleado {
private:
    int claveEmpleado;
    std::string nombre;

public:
    Empleado() : claveEmpleado(0), nombre("") {}
    Empleado(int clave, std::string nom) : claveEmpleado(clave), nombre(nom) {}

    int getClave() const { return claveEmpleado; }
    std::string getNombre() const { return nombre; }

    bool operator==(const Empleado& otro) const {
        return claveEmpleado == otro.claveEmpleado;
    }

    friend std::ostream& operator<<(std::ostream& os, const Empleado& e) {
        os << "Clave: " << e.claveEmpleado << ", Nombre: " << e.nombre;
        return os;
    }
};

template <typename T>
class ListaEstatica {
private:
    T datos[MAX];
    int tam;

public:
    ListaEstatica() : tam(0) {}

    bool Agrega(T elem) {
        if (tam >= MAX) {
            std::cout << "\nLista llena. No se pudo agregar.";
            return false;
        }
        datos[tam++] = elem;
        return true;
    }

    int Busca(T elem) {
        if (tam == 0) {
            std::cout << "\nLa lista está vacía.";
            return -1;
        }
        for (int i = 0; i < tam; i++) {
            if (datos[i] == elem) {
                std::cout << "\nEmpleado encontrado en la posición: " << i;
                return i;
            }
        }
        std::cout << "\nEmpleado no encontrado.";
        return -1;
    }

    bool Elimina(T elem) {
        if (tam == 0) {
            std::cout << "\nLa lista está vacía. No se puede eliminar.";
            return false;
        }
        int pos = Busca(elem);
        if (pos == -1) return false;
        for (int i = pos; i < tam - 1; i++) {
            datos[i] = datos[i + 1];
        }
        tam--;
        return true;
    }

    bool Inserta(T elem, int pos) {
        if (tam >= MAX) {
            std::cout << "\nLista llena. No se pudo insertar.";
            return false;
        }
        if (pos < 0 || pos > tam) {
            std::cout << "\nPosición inválida.";
            return false;
        }
        for (int i = tam; i > pos; --i) {
            datos[i] = datos[i - 1];
        }
        datos[pos] = elem;
        tam++;
        return true;
    }

    void Muestra() {
        if (tam == 0) {
            std::cout << "\nLa lista está vacía.";
            return;
        }
        for (int i = 0; i < tam; i++) {
            std::cout << datos[i] << "\n";
        }
    }
};

int main() {
    ListaEstatica<Empleado> lista;
    int opcion;

    do {
        std::cout << "\n\nMenú:";
        std::cout << "\n1. Agrega\n2. Buscar\n3. Elimina\n4. Inserta\n5. Muestra\n6. Salir";
        std::cout << "\nSeleccione una opción: ";
        std::cin >> opcion;

        if (opcion == 1) {
            int clave;
            std::string nombre;
            std::cout << "Ingrese clave del empleado: ";
            std::cin >> clave;
            std::cin.ignore();
            std::cout << "Ingrese nombre del empleado: ";
            std::getline(std::cin, nombre);
            lista.Agrega(Empleado(clave, nombre));
        }
        else if (opcion == 2) {
            int clave;
            std::cout << "Ingrese clave del empleado a buscar: ";
            std::cin >> clave;
            lista.Busca(Empleado(clave, ""));
        }
        else if (opcion == 3) {
            int clave;
            std::cout << "Ingrese clave del empleado a eliminar: ";
            std::cin >> clave;
            lista.Elimina(Empleado(clave, ""));
        }
        else if (opcion == 4) {
            int clave, pos;
            std::string nombre;
            std::cout << "Ingrese clave del empleado a insertar: ";
            std::cin >> clave;
            std::cin.ignore();
            std::cout << "Ingrese nombre del empleado: ";
            std::getline(std::cin, nombre);
            std::cout << "Ingrese la posición: ";
            std::cin >> pos;
            lista.Inserta(Empleado(clave, nombre), pos);
        }
        else if (opcion == 5) {
            lista.Muestra();
        }
        else if (opcion == 6) {
            std::cout << "Saliendo...";
        }
        else {
            std::cout << "Opción inválida. Intente de nuevo.";
        }
    } while (opcion != 6);
    return 0;
}
