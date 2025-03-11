#include <iostream>
#include <string>

class Materia {
private:
    int clave;
    std::string nombre;
    std::string profesorTitular;
    std::string libroTexto;

public:
    Materia() : clave(0), nombre(""), profesorTitular(""), libroTexto("") {}
    Materia(int clave, std::string nom, std::string profe, std::string libro)
        : clave(clave), nombre(nom), profesorTitular(profe), libroTexto(libro) {}

    void cambiaClave(int nuevaClave) { clave = nuevaClave; }
    void cambiaProfesor(const std::string& nuevoProfe) { profesorTitular = nuevoProfe; }
    void imprime() const {
        std::cout << "Clave: " << clave << "\nNombre: " << nombre
                  << "\nProfesor Titular: " << profesorTitular
                  << "\nLibro de Texto: " << libroTexto << "\n";
    }
    int getClave() const { return clave; }

    // Sobrecarga de operadores
    bool operator==(const Materia& otra) const { return clave == otra.clave; }
    bool operator!=(const Materia& otra) const { return clave != otra.clave; }
    bool operator>(const Materia& otra) const { return clave > otra.clave; }
    bool operator<(const Materia& otra) const { return clave < otra.clave; }
    Materia operator+(const Materia& otra) const {
        return Materia(clave + otra.clave, nombre, profesorTitular, libroTexto);
    }
};

int main() {
    Materia programacion(101, "Programacion", "Dr. Lopez", "C++ Primer"),
            basesDatos(102, "Bases de Datos", "Ing. Martinez", "Database Systems");

    int opcion, nuevaClave;
    std::string nuevoDato;

    do {
        std::cout << "\nMenu:\n1. Cambiar clave de Programacion\n2. Cambiar profesor de Bases de Datos\n3. Imprimir datos de Bases de Datos\n4. Salir\nSeleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese la nueva clave para Programacion: ";
                std::cin >> nuevaClave;
                programacion.cambiaClave(nuevaClave);
                break;
            case 2:
                std::cin.ignore();
                std::cout << "Ingrese el nuevo profesor de Bases de Datos: ";
                std::getline(std::cin, nuevoDato);
                basesDatos.cambiaProfesor(nuevoDato);
                break;
            case 3:
                basesDatos.imprime();
                break;
            case 4:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 4);
    
    return 0;
}

