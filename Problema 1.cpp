#include <iostream>
#include <cstring> 

using namespace std;

class Empleado {
private:
    int ClaveEmpleado;
    char Nombre[50];
    char Domicilio[100];
    float Sueldo;
    char ReportaA[50];

public:
    // Constructor
    Empleado(int clave, const char* nombre, const char* domicilio, float sueldo, const char* reportaA) {
        ClaveEmpleado = clave;
        for (int i = 0; i < 50; i++) Nombre[i] = nombre[i];
        for (int i = 0; i < 100; i++) Domicilio[i] = domicilio[i];
        Sueldo = sueldo;
        for (int i = 0; i < 50; i++) ReportaA[i] = reportaA[i];
    }

    // Métodos
    void Imprime() {
        cout << "Clave: " << ClaveEmpleado << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Domicilio: " << Domicilio << endl;
        cout << "Sueldo: " << Sueldo << endl;
        cout << "Reporta a: " << ReportaA << endl;
    }

    void CambiaDomic(const char* nuevoDomicilio) {
        for (int i = 0; i < 100; i++) Domicilio[i] = nuevoDomicilio[i];
    }

    void CambiaReportaA(const char* nuevoReportaA) {
        for (int i = 0; i < 50; i++) ReportaA[i] = nuevoReportaA[i];
    }

    void ActualSueldo(float porcentajeIncremento) {
        Sueldo = Sueldo + (Sueldo * porcentajeIncremento / 100);
    }

    int getClaveEmpleado() {
        return ClaveEmpleado;
    }
};

int main() {
    // Creación de los empleados
    Empleado JefePlanta(8008, "Carlos Perez", "Rio nilo101", 50000, "Director General");
    Empleado JefePersonal(4567, "Ana Lopez", "Av.Revolucion 456", 40000, "Director General");

    int opcion;
    do {
        cout << "\nMenu de opciones:\n";
        cout << "1. Cambiar domicilio\n";
        cout << "2. Actualizar sueldo\n";
        cout << "3. Imprimir datos\n";
        cout << "4. Cambiar nombre de quien reporta\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            int clave;
            char nuevoDomicilio[100];
            cout << "Ingrese la clave del empleado: ";
            cin >> clave;
            cin.ignore(); // Limpiar buffer
            cout << "Ingrese el nuevo domicilio: ";
            cin.getline(nuevoDomicilio, 100);

            if (clave == JefePlanta.getClaveEmpleado()) {
                JefePlanta.CambiaDomic(nuevoDomicilio);
            } else if (clave == JefePersonal.getClaveEmpleado()) {
                JefePersonal.CambiaDomic(nuevoDomicilio);
            } else {
                cout << "Empleado no encontrado." << endl;
            }
        } else if (opcion == 2) {
            int clave;
            float porcentaje;
            cout << "Ingrese la clave del empleado: ";
            cin >> clave;
            cout << "Ingrese el porcentaje de incremento: ";
            cin >> porcentaje;

            if (clave == JefePlanta.getClaveEmpleado()) {
                JefePlanta.ActualSueldo(porcentaje);
            } else if (clave == JefePersonal.getClaveEmpleado()) {
                JefePersonal.ActualSueldo(porcentaje);
            } else {
                cout << "Empleado no encontrado." << endl;
            }
        } else if (opcion == 3) {
            int clave;
            cout << "Ingrese la clave del empleado: ";
            cin >> clave;

            if (clave == JefePlanta.getClaveEmpleado()) {
                JefePlanta.Imprime();
            } else if (clave == JefePersonal.getClaveEmpleado()) {
                JefePersonal.Imprime();
            } else {
                cout << "Empleado no encontrado." << endl;
            }
        } else if (opcion == 4) {
            int clave;
            char nuevoReportaA[50];
            cout << "Ingrese la clave del empleado: ";
            cin >> clave;
            cin.ignore(); // Limpiar buffer
            cout << "Ingrese el nuevo nombre de quien reporta: ";
            cin.getline(nuevoReportaA, 50);

            if (clave == JefePlanta.getClaveEmpleado()) {
                JefePlanta.CambiaReportaA(nuevoReportaA);
            } else if (clave == JefePersonal.getClaveEmpleado()) {
                JefePersonal.CambiaReportaA(nuevoReportaA);
            } else {
                cout << "Empleado no encontrado." << endl;
            }
        } else if (opcion == 5) {
            cout << "Saliendo del programa..." << endl;
        } else {
            cout << "Opcion invalida." << endl;
        }
    } while (opcion != 5);

    return 0;
}
