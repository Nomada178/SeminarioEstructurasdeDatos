#include <iostream>
#include <string>

class Empleado {
private:
    int claveEmpleado;
    std::string nombre;
    std::string domicilio;
    float sueldo;
    std::string reportaA;

public:
    Empleado() : claveEmpleado(0), nombre(""), domicilio(""), sueldo(0.0), reportaA("") {}
    Empleado(int clave, std::string nom, std::string dom, float suel, std::string rep)
        : claveEmpleado(clave), nombre(nom), domicilio(dom), sueldo(suel), reportaA(rep) {}

    void cambiaDomicilio(const std::string& nuevoDomicilio) { domicilio = nuevoDomicilio; }
    void actualizaSueldo(float porcentaje) { sueldo += sueldo * (porcentaje / 100); }
    void cambiaReportaA(const std::string& nuevoJefe) { reportaA = nuevoJefe; }
    void imprime() const {
        std::cout << "Clave: " << claveEmpleado << "\nNombre: " << nombre
                  << "\nDomicilio: " << domicilio << "\nSueldo: " << sueldo
                  << "\nReporta a: " << reportaA << "\n";
    }
    int getClave() const { return claveEmpleado; }
};

int main() {
    Empleado empleado1(101, "Juan Perez", "Calle azul, 123", 50000, "Maria Lopez");
    Empleado empleado2(102, "Ana Torres", "Calle rojo, 456", 55000, "Carlos Gomez");

    int opcion, clave;
    std::string nuevoDato;
    float porcentaje;

    do {
        std::cout << "\nMenu:\n1. Cambiar domicilio\n2. Actualizar sueldo\n3. Imprimir datos\n4. Cambiar reporta a\n5. Salir\nSeleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;
                std::cin.ignore();
                std::cout << "Ingrese el nuevo domicilio: ";
                std::getline(std::cin, nuevoDato);
                if (clave == empleado1.getClave()) empleado1.cambiaDomicilio(nuevoDato);
                else if (clave == empleado2.getClave()) empleado2.cambiaDomicilio(nuevoDato);
                break;
            case 2:
                std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;
                std::cout << "Ingrese el porcentaje de aumento: ";
                std::cin >> porcentaje;
                if (clave == empleado1.getClave()) empleado1.actualizaSueldo(porcentaje);
                else if (clave == empleado2.getClave()) empleado2.actualizaSueldo(porcentaje);
                break;
            case 3:
                std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;
                if (clave == empleado1.getClave()) empleado1.imprime();
                else if (clave == empleado2.getClave()) empleado2.imprime();
                break;
            case 4:
                std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;
                std::cin.ignore();
                std::cout << "Ingrese el nuevo nombre de la persona a quien reporta: ";
                std::getline(std::cin, nuevoDato);
                if (clave == empleado1.getClave()) empleado1.cambiaReportaA(nuevoDato);
                else if (clave == empleado2.getClave()) empleado2.cambiaReportaA(nuevoDato);
                break;
            case 5:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}
