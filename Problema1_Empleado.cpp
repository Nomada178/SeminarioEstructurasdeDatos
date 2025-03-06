#include <iostream>
using namespace std;

class Empleado {
public:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    float Sueldo;
    string ReportaA;

    Empleado(int clave, string nombre, string domicilio, float sueldo, string reportaA) {
        ClaveEmpleado = clave;
        Nombre = nombre;
        Domicilio = domicilio;
        Sueldo = sueldo;
        ReportaA = reportaA;
    }

    void Imprime() {
        cout << "Clave: " << ClaveEmpleado << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Domicilio: " << Domicilio << endl;
        cout << "Sueldo: " << Sueldo << endl;
        cout << "Reporta a: " << ReportaA << endl;
    }

    void CambiaDomic(string nuevoDomicilio) {
        Domicilio = nuevoDomicilio;
    }

    void CambiaReportaA(string nuevoReportaA) {
        ReportaA = nuevoReportaA;
    }

    void ActualSueldo(float porcentaje) {
        Sueldo = Sueldo + (Sueldo * (porcentaje / 100));
    }

    int getClave() {
        return ClaveEmpleado;
    }
};

int main() {
    Empleado emp1(101, "Juan gonzales", "Calle rio", 15000, "Gerente A");
    Empleado emp2(102, "Elizabeth Gomez", "Avenida azul",1800,"GerentB");

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
                if (clave == emp1.getClave()) emp1.CambiaDomic(nuevoDomicilio);
                else emp2.CambiaDomic(nuevoDomicilio);
                break;
            case 2:
                cout << "Ingrese clave del empleado: ";
                cin >> clave;
                cout << "Ingrese porcentaje de aumento: ";
                cin >> porcentaje;
                if (clave == emp1.getClave()) emp1.ActualSueldo(porcentaje);
                else emp2.ActualSueldo(porcentaje);
                break;
            case 3:
                cout << "Ingrese clave del empleado: ";
                cin >> clave;
                if (clave == emp1.getClave()) emp1.Imprime();
                else emp2.Imprime();
                break;
            case 4:
                cout << "Ingrese clave del empleado: ";
                cin >> clave;
                cin.ignore();
                cout << "Ingrese nuevo nombre del Jefe : ";
                getline(cin, nuevoReportaA);
                if (clave == emp1.getClave()) emp1.CambiaReportaA(nuevoReportaA);
                else emp2.CambiaReportaA(nuevoReportaA);
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 5);

    return 0;
}
