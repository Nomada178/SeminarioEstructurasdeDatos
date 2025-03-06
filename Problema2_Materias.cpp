#include <iostream>
using namespace std;

class Materia {
public:
    int Clave;
    string Nombre;
    string ProfesorTit;
    string LibroTexto;

    Materia(int clave, string nombre, string profesor, string libro) {
        Clave = clave;
        Nombre = nombre;
        ProfesorTit = profesor;
        LibroTexto = libro;
    }

    void Imprime() {
        cout << "Clave: " << Clave << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Profesor Titular: " << ProfesorTit << endl;
        cout << "Libro de Texto: " << LibroTexto << endl;
    }

    void CambiaClave(int nuevaClave) {
        Clave = nuevaClave;
    }

    void CambiaProfe(string nuevoProfesor) {
        ProfesorTit = nuevoProfesor;
    }
};

int main() {
    Materia prog(101, "Programacion", "Jorge Perez", "C++ Basico");
    Materia bd(102, "Bases de Datos", "Maria Gomez", "SQL Fundamentos");

    int opcion, nuevaClave;
    string nuevoProfesor;

    do {
        cout << "\nMenu de opciones:" << endl;
        cout << "1. Cambiar clave de Programacion" << endl;
        cout << "2. Cambiar profesor de Bases de Datos" << endl;
        cout << "3. Imprimir datos de Bases de Datos" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Ingrese la nueva clave de Programacion: ";
                cin >> nuevaClave;
                prog.CambiaClave(nuevaClave);
                break;
            case 2:
                cout << "Ingrese el nuevo profesor de Bases de Datos: ";
                cin.ignore();
                getline(cin, nuevoProfesor);
                bd.CambiaProfe(nuevoProfesor);
                break;
            case 3:
                bd.Imprime();
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 4);

    return 0;
}
