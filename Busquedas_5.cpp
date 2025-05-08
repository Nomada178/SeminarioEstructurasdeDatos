#include <iostream>
#include <string>
const int Tam = 50;

class alumno {
private:
    std::string nombre;
    std::string carrera;
    int aprobadas;
    float promedio;

public:
    alumno() : nombre(" "), carrera(" "), aprobadas(0), promedio(0.0f) {}

    void setNombre(const std::string& nom) { nombre = nom; }
    void setCarrera(const std::string& carr) { carrera = carr; }
    void setAprobadas(int apro) { aprobadas = apro; }
    void setPromedio(float prom) { promedio = prom; }

    std::string getNombre() const { return nombre; }
    std::string getCarrera() const { return carrera; }
    int getAprobadas() const { return aprobadas; }
    float getPromedio() const { return promedio; }

    friend std::ostream& operator<<(std::ostream& os, const alumno& emp);
    friend std::istream& operator>>(std::istream& is, alumno& emp);

    bool operator==(const alumno& otro) const {
        return promedio == otro.promedio && nombre == otro.nombre &&
               aprobadas == otro.aprobadas && carrera == otro.carrera;
    }

    bool operator>(const alumno& otro) const {
        return promedio > otro.promedio;
    }

    bool operator<(const alumno& otro) const {
        return promedio < otro.promedio;
    }

    bool operator!=(const alumno& otro) const {
        return !(*this == otro);
    }

    alumno operator+(const alumno& otro) const {
        alumno temp;
        temp.promedio = this->promedio + otro.promedio;
        return temp;
    }
};

class ColaEmpleado {
private:
    alumno datos[Tam];
    int frente, final;

public:
    ColaEmpleado() : frente(0), final(-1) {}

    bool vacia() const { return final < frente; }
    bool llena() const { return final == Tam - 1; }

    void insertar(const alumno& emp) {
        if (llena()) {
            std::cout << "\nError: Cola llena.\n";
        } else {
            datos[++final] = emp;
        }
    }

    void eliminar() {
        if (vacia()) {
            std::cout << "\nError: Cola vacía.\n";
        } else {
            ++frente;
        }
    }

    alumno recuperar() const {
        if (vacia()) {
            std::cout << "\nError: Cola vacía.\n";
            return alumno();
        }
        return datos[final];
    }

    void mostrar() const {
        if (vacia()) {
            std::cout << "\nCola vacía.\n";
        } else {
            for (int i = frente; i <= final; i++) {
                std::cout << datos[i] << '\n';
            }
        }
    }

    void buscar(const alumno& emp) const {
        if (vacia()) {
            std::cout << "\nCola vacía.\n";
            return;
        }
        for (int i = frente; i <= final; i++) {
            if (datos[i] == emp) {
                std::cout << "\nAlumno encontrado:\n" << datos[i] << '\n';
                return;
            }
        }
        std::cout << "\nNo se encontró ningún alumno.\n";
    }
};

std::ostream& operator<<(std::ostream& os, const alumno& emp) {
    os << "Nombre del alumno: " << emp.nombre << '\n';
    os << "Nombre de la materia: " << emp.carrera << '\n';
    os << "Materias aprobadas: " << emp.aprobadas << '\n';
    os << "Promedio: " << emp.promedio << '\n';
    return os;
}

std::istream& operator>>(std::istream& is, alumno& emp) {
    std::cout << "Introduce el nombre del alumno: ";
    is >> emp.nombre;
    std::cout << "Introduce el nombre de la materia: ";
    is >> emp.carrera;
    std::cout << "Introduce las materias aprobadas: ";
    is >> emp.aprobadas;
    std::cout << "Introduce el promedio: ";
    is >> emp.promedio;
    return is;
}

int main() {
    ColaEmpleado Micola;
    alumno emp;
    int op = 0, num;

    while (op != 6) {
        std::cout << "\nBienvenido\n"
                  << "Elige una opción:\n"
                  << "1: Registrar alumnos\n"
                  << "2: Mostrar todos los alumnos\n"
                  << "3: Eliminar el primer alumno\n"
                  << "4: Mostrar el último alumno\n"
                  << "5: Buscar alumno\n"
                  << "6: Salir\n";
        std::cin >> op;

        switch (op) {
        case 1:
            std::cout << "¿Cuántos alumnos quieres registrar? ";
            std::cin >> num;
            for (int i = 0; i < num; i++) {
                std::cout << "\nIntroduce los datos del alumno " << i + 1 << ":\n";
                std::cin >> emp;
                Micola.insertar(emp);
            }
            break;
        case 2:
            std::cout << "\nAlumnos registrados:\n";
            Micola.mostrar();
            break;
        case 3:
            std::cout << "\nAlumno eliminado.\n";
            Micola.eliminar();
            break;
        case 4:
            std::cout << "\nÚltimo alumno registrado:\n" << Micola.recuperar();
            break;
        case 5:
            std::cout << "\nIntroduce el alumno a buscar:\n";
            std::cin >> emp;
            Micola.buscar(emp);
            break;
        case 6:
            std::cout << "\nGracias.\n";
            return 0;
        default:
            std::cout << "\nOpción inválida.\n";
            break;
        }
    }
}
