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
        strcpy(Nombre, nombre);
        strcpy(Domicilio, domicilio);
        Sueldo = sueldo;
        strcpy(ReportaA, reportaA);
    }

    // Sobrecarga de operadores
    bool operator==(const Empleado& otro) const {
        return ClaveEmpleado == otro.ClaveEmpleado;
    }

    bool operator!=(const Empleado& otro) const {
        return ClaveEmpleado != otro.ClaveEmpleado;
    }

    bool operator>(const Empleado& otro) const {
        return Sueldo > otro.Sueldo;
    }

    bool operator<(const Empleado& otro) const {
        return Sueldo < otro.Sueldo;
    }

    Empleado operator+(const Empleado& otro) const {
        float nuevoSueldo = Sueldo + otro.Sueldo;
        return Empleado(0, "Combinado", "Sin Domicilio", nuevoSueldo, "N/A");
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
        strcpy(Domicilio, nuevoDomicilio);
    }

    void CambiaReportaA(const char* nuevoReportaA) {
        strcpy(ReportaA, nuevoReportaA);
    }

    void ActualSueldo(float porcentajeIncremento) {
        Sueldo += Sueldo * porcentajeIncremento / 100;
    }

    int getClaveEmpleado() const {
        return ClaveEmpleado;
    }
};

int main() {
    Empleado JefePlanta(8008, "Carlos Perez", "Rio Nilo 101", 50000, "Director General");
    Empleado JefePersonal(4567, "Ana Lopez", "Av. Revolucion 456", 40000, "Director General");

    cout << "Comparando sueldos:" << endl;
    if (JefePlanta > JefePersonal) {
        cout << "JefePlanta gana más que JefePersonal." << endl;
    } else {
        cout << "JefePersonal gana más o igual que JefePlanta." << endl;
    }

    Empleado combinado = JefePlanta + JefePersonal;
    cout << "Empleado combinado:" << endl;
    combinado.Imprime();

    return 0;
}
