#include <iostream>
#include <string>
using namespace std;

class Materia {
private:
    int Clave;
    string Nombre;
    string ProfesorTit;
    string LibroTexto;

public:
    // Constructor
    Materia(int clave, string nombre, string profesor, string libro)
        : Clave(clave), Nombre(nombre), ProfesorTit(profesor), LibroTexto(libro) {}

    // Métodos
    void Imprime() {
        cout << "Clave: " << Clave << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Profesor: " << ProfesorTit << endl;
        cout << "Libro de texto: " << LibroTexto << endl;
    }

    void CambiaClave(int nuevaClave) {
        Clave = nuevaClave;
    }

    void CambiaProfe(string nuevoProfesor) {
        ProfesorTit = nuevoProfesor;
    }

    // Sobrecarga de operadores
    bool operator==(const Materia& otra) const {
        return Clave == otra.Clave;
    }

    bool operator!=(const Materia& otra) const {
        return Clave != otra.Clave;
    }

    bool operator>(const Materia& otra) const {
        return Clave > otra.Clave;
    }

    bool operator<(const Materia& otra) const {
        return Clave < otra.Clave;
    }

    Materia operator+(const Materia& otra) {
        return Materia(Clave + otra.Clave, Nombre + " & " + otra.Nombre,
                       ProfesorTit + " y " + otra.ProfesorTit, LibroTexto);
    }

    friend ostream& operator<<(ostream& os, const Materia& m) {
        os << "Clave: " << m.Clave << "\nNombre: " << m.Nombre
           << "\nProfesor: " << m.ProfesorTit
           << "\nLibro de texto: " << m.LibroTexto << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Materia& m) {
        cout << "Ingrese clave: ";
        is >> m.Clave;
        is.ignore();
        cout << "Ingrese nombre: ";
        getline(is, m.Nombre);
        cout << "Ingrese profesor: ";
        getline(is, m.ProfesorTit);
        cout << "Ingrese libro de texto: ";
        getline(is, m.LibroTexto);
        return is;
    }
};

int main() {
    Materia Programacion(8, "Programacion", "Echauri", "Estructuras de Datos");
    Materia BasesDatos(10, "Bases de Datos", "Javier", "Bases de datos 1");

    int opcion;
    do {
        cout << "\nMenu:\n";
        cout << "1. Cambiar la clave de la materia Programacion.\n";
        cout << "2. Cambiar el nombre del maestro de Bases Datos.\n";
        cout << "3. Imprimir todos los datos de la materia Bases Datos.\n";
        cout << "4. Salir.\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int nuevaClave;
            cout << "Ingrese la nueva clave para la materia de Programacion: ";
            cin >> nuevaClave;
            Programacion.CambiaClave(nuevaClave);
            cout << "Clave actualizada.\n";
            break;
        }
        case 2: {
            string nuevoProfesor;
            cout << "Ingrese el nuevo nombre del maestro de Bases Datos: ";
            cin.ignore(); // Limpiar el buffer
            getline(cin, nuevoProfesor);
            BasesDatos.CambiaProfe(nuevoProfesor);
            cout << "Nombre del maestro actualizado correctamente.\n";
            break;
        }
        case 3:
            cout << "Datos de la materia Bases Datos:\n";
            cout << BasesDatos;
            break;
        case 4:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}
