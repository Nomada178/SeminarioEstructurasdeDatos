#ifndef COLA_H
#define COLA_H
#include <iostream>
#include <string>

const int TAM = 100;

class persona {
private:
    std::string nombre;
    std::string carrera;
    int materiasAprobadas;
    float promedio;
public:
    persona() : nombre(""), carrera(""), materiasAprobadas(0), promedio(0.0f) {}
    persona(std::string n, std::string c, int m, float p)
        : nombre(n), carrera(c), materiasAprobadas(m), promedio(p) {}

    void operator=(persona& x) {
        nombre = x.nombre;
        carrera = x.carrera;
        materiasAprobadas = x.materiasAprobadas;
        promedio = x.promedio;
    }

    friend std::ostream& operator<<(std::ostream& os, persona& p) {
        os << "Constancia de estudios\n";
        os << "Nombre: " << p.nombre << "\n";
        os << "Carrera: " << p.carrera << "\n";
        os << "Materias aprobadas: " << p.materiasAprobadas << "\n";
        os << "Promedio general: " << p.promedio << "\n\n";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, persona& p) {
        std::cout << "Nombre: ";
        std::getline(is >> std::ws, p.nombre);
        std::cout << "Carrera: ";
        std::getline(is, p.carrera);
        std::cout << "Materias aprobadas: ";
        is >> p.materiasAprobadas;
        std::cout << "Promedio general: ";
        is >> p.promedio;
        return is;
    }
};

class Cola {
private:
    persona datos[TAM];
    int ult;

    bool elimina(int pos) {
        if (pos < 0 || pos > ult)
            return false;
        for (int i = pos; i < ult; i++)
            datos[i] = datos[i + 1];
        ult--;
        return true;
    }

    int inserta(persona& elem, int pos) {
        if (llena() || pos < 0 || pos > ult + 1)
            return -1;
        for (int i = ult + 1; i > pos; i--)
            datos[i] = datos[i - 1];
        datos[pos] = elem;
        ult++;
        return pos;
    }

public:
    Cola() : ult(-1) {}

    bool vacia() const { return ult == -1; }
    bool llena() const { return ult == TAM - 1; }
    int ultimo() const { return ult; }

    void enqueue(persona& elem) {
        inserta(elem, ult + 1);
    }

    persona& dequeue() {
        if (vacia()) {
            std::cerr << "La cola está vacía\n";
            exit(EXIT_FAILURE);
        }
        persona& temp = datos[0];
        elimina(0);
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& os, Cola& L) {
        for (int i = 0; i <= L.ult; i++)
            os << L.datos[i];
        return os;
    }
};

#endif 
