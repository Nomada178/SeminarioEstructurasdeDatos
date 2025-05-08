
#include <iostream>
#include <string>
const int Tam = 50;

class empleado {
private:
    int ClaveEmpleado;
    std::string nombre;
    std::string domicilio;
    float sueldo;
    std::string ReportaA;

public:
    empleado() : ClaveEmpleado(0), nombre(" "), domicilio(" "), sueldo(0.0), ReportaA(" ") {}

    void setClaveE(int clave) { ClaveEmpleado = clave; }
    void setnombre(const std::string& nom) { nombre = nom; }
    void setdomicilio(const std::string& dom) { domicilio = dom; }
    void setsueldo(float s) { sueldo = s; }
    void setReporta(const std::string& reporta) { ReportaA = reporta; }

    int getClaveE() const { return ClaveEmpleado; }
    std::string getNombre() const { return nombre; }
    std::string getDomicilio() const { return domicilio; }
    float getsueldo() const { return sueldo; }
    std::string getReportaA() const { return ReportaA; }

    friend std::ostream& operator<<(std::ostream& os, const empleado& emp);
    friend std::istream& operator>>(std::istream& is, empleado& emp);

    bool operator==(const empleado& otro) const {
        return ClaveEmpleado == otro.ClaveEmpleado &&
               nombre == otro.nombre &&
               domicilio == otro.domicilio &&
               sueldo == otro.sueldo &&
               ReportaA == otro.ReportaA;
    }

    bool operator>(const empleado& otro) const { return sueldo > otro.sueldo; }
    bool operator<(const empleado& otro) const { return sueldo < otro.sueldo; }
    bool operator!=(const empleado& otro) const { return sueldo != otro.sueldo; }

    empleado operator+(const empleado& otro) const {
        empleado temp;
        temp.sueldo = this->sueldo + otro.sueldo;
        return temp;
    }
};

class ListaEmpleado {
private:
    empleado datos[Tam];
    int ult;

public:
    ListaEmpleado() : ult(-1) {}

    bool vacia() const { return ult == -1; }
    bool llena() const { return ult == Tam - 1; }

    void insertar(int pos, const empleado& emp) {
        if (llena()) {
            std::cout << "\nError: La lista está llena." << std::endl;
        } else if (pos < 0 || pos > ult + 1) {
            std::cout << "\nError: Posición inválida." << std::endl;
        } else {
            for (int i = ult; i >= pos; --i) {
                datos[i + 1] = datos[i];
            }
            datos[pos] = emp;
            ++ult;
        }
    }

    void eliminar(int pos) {
        if (vacia()) {
            std::cout << "\nError: La lista está vacía." << std::endl;
        } else if (pos < 0 || pos > ult) {
            std::cout << "\nError: Posición inválida." << std::endl;
        } else {
            for (int i = pos; i < ult; ++i) {
                datos[i] = datos[i + 1];
            }
            --ult;
        }
    }

    empleado recuperar(int pos) const {
        if (vacia() || pos < 0 || pos > ult) {
            std::cout << "\nError: Posición inválida o lista vacía." << std::endl;
            return empleado();
        } else {
            return datos[pos];
        }
    }

    int ultimo() const { return ult; }

    int buscar(const std::string& emp) const {
        for (int i = 0; i <= ult; i++) {
            if (datos[i].getNombre() == emp || datos[i].getDomicilio() == emp || datos[i].getReportaA() == emp) {
                return i;
            }
        }
        return -1;
    }
};

std::ostream& operator<<(std::ostream& os, const empleado& emp) {
    os << "\nClave de empleado: " << emp.ClaveEmpleado << std::endl;
    os << "Nombre: " << emp.nombre << std::endl;
    os << "Domicilio: " << emp.domicilio << std::endl;
    os << "Sueldo: " << emp.sueldo << std::endl;
    os << "Reporta a: " << emp.ReportaA << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, empleado& emp) {
    std::cout << "Introduce la clave de empleado: ";
    is >> emp.ClaveEmpleado;
    std::cout << "Introduce el nombre: ";
    is >> emp.nombre;
    std::cout << "Introduce el domicilio: ";
    is >> emp.domicilio;
    std::cout << "Introduce el sueldo: ";
    is >> emp.sueldo;
    std::cout << "Reporte: ";
    is >> emp.ReportaA;
    return is;
}

int main() {
    ListaEmpleado Milista;
    empleado emp;
    int op = 0, num, pos;

    while (op != 8) {
        std::cout << "\nBienvenido\nElige una opción:\n"
                  << "1: Registrar empleado\n"
                  << "2: Mostrar empleado\n"
                  << "3: Eliminar un empleado\n"
                  << "4: Mostrar empleado \n"
                  << "5: Buscar empleado \n"
                  << "6: Verificar si la lista está vacía\n"
                  << "7: Verificar si la lista está llena\n"
                  << "8: Salir \n\n";
        std::cin >> op;

        switch (op) {
            case 1:
                std::cout << "¿Cuántos empleados quieres registrar? ";
                std::cin >> num;
                for (int i = 0; i < num; i++) {
                    std::cout << "\nIntroduce los datos del empleado " << i + 1 << ":\n";
                    std::cin >> emp;
                    std::cout << "¿En qué posición deseas insertar? (0-" << Milista.ultimo() + 1 << "): ";
                    std::cin >> pos;
                    Milista.insertar(pos, emp);
                }
                break;

            case 2:
                std::cout << "\nEmpleados registrados:\n";
                for (int i = 0; i <= Milista.ultimo(); i++) {
                    std::cout << Milista.recuperar(i) << std::endl;
                }
                break;

            case 3:
                std::cout << "¿Qué posición deseas eliminar? (0-" << Milista.ultimo() << "): ";
                std::cin >> pos;
                Milista.eliminar(pos);
                std::cout << "\nEmpleado eliminado.\n";
                break;

            case 4:
                std::cout << "¿Qué posición deseas recuperar? (0-" << Milista.ultimo() << "): ";
                std::cin >> pos;
                std::cout << "\nEmpleado en la posición " << pos << ":\n";
                std::cout << Milista.recuperar(pos) << std::endl;
                break;

            case 5: {
                std::string empBuscar;
                if (Milista.vacia()) {
                    std::cout << "\nError: La lista está vacía." << std::endl;
                    break;
                }
                std::cout << "Introduce nombre, domicilio o jefe del empleado a buscar:\n";
                std::cin >> empBuscar;
                pos = Milista.buscar(empBuscar);
                if (pos != -1) {
                    std::cout << "\nEmpleado encontrado en la posición " << pos << ":\n";
                    std::cout << Milista.recuperar(pos) << std::endl;
                } else {
                    std::cout << "\nEmpleado no encontrado.\n";
                }
                break;
            }

            case 6:
                std::cout << (Milista.vacia() ? "La lista está vacía.\n" : "La lista no está vacía.\n");
                break;

            case 7:
                std::cout << (Milista.llena() ? "La lista está llena.\n" : "La lista no está llena.\n");
                break;

            case 8:
                std::cout << "Gracias." << std::endl;
                break;

            default:
                std::cout << "\nIntroduce una opción correcta.\n";
                break;
        }
    }
}
