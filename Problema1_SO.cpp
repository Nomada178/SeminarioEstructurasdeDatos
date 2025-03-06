#include <iostream>
using namespace std;

class Empleado {
public:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    float Sueldo;
    string ReportaA;

    Empleado(int clave, string nombre, string domicilio, float sueldo, string reportaA)
        : ClaveEmpleado(clave), Nombre(nombre), Domicilio(domicilio), Sueldo(sueldo), ReportaA(reportaA) {}

    void Imprime() const {
        cout << "Clave: " << ClaveEmpleado << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Domicilio: " << Domicilio << endl;
        cout << "Sueldo: " << Sueldo << endl;
        cout << "Reporta a: " << ReportaA << endl;
    }

    Empleado& operator+=(float porcentaje) {
        Sueldo += Sueldo * (porcentaje / 100);
        return *this;
    }

    Empleado& operator=(const string& nuevoDomicilio) {
        Domicilio = nuevoDomicilio;
        return *this;
    }

    void operator()(const string& nuevoReportaA) {
        ReportaA = nuevoReportaA;
    }
};

int main() {
    Empleado emp1(101, "Juan Gonzalez", "Calle Rio", 15000, "Gerente A");
    Empleado emp2(102, "Elizabeth Gomez", "Avenida Azul", 18000, "Gerente B");

    int opcion, clave;
    string nuevoDomicilio, nuevoReportaA;
    float porcentaje;

    do {
        cout << "\nMenu de opciones:" << endl;
        cout << "1. Cambiar domicilio" << endl;
        cout << "2. Actualizar sueldo" << endl;
        cout << "3. Imprimir datos" << endl;
        cout << "4. Cambiar Jefe" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Ingrese clave del empleado: ";
                cin >> clave;
                cin.ignore();
                cout << "Ingrese nuevo domicilio: ";
                getline(cin, nuevoDomicilio);
                (clave == emp1.ClaveEmpleado ? emp1 : emp2) = nuevoDomicilio;
                break;
            case 2:
                cout << "Ingrese clave del empleado: ";
                cin >> clave;
                cout << "Ingrese porcentaje de aumento: ";
                cin >> porcentaje;
                (clave == emp1.ClaveEmpleado ? emp1 : emp2) += porcentaje;
                break;
            case 3:
                cout << "Ingrese clave del empleado: ";
                cin >> clave;
                (clave == emp1.ClaveEmpleado ? emp1 : emp2).Imprime();
                break;
            case 4:
                cout << "Ingrese clave del empleado: ";
                cin >> clave;
                cin.ignore();
                cout << "Ingrese nuevo nombre del Jefe: ";
                getline(cin, nuevoReportaA);
                (clave == emp1.ClaveEmpleado ? emp1 : emp2)(nuevoReportaA);
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 5);

    return 0;
