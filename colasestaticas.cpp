// Corregir 
#include <iostream>
#include "Cola.h"

int main() {
    Cola MiCola;
    persona x;

    std::cout << "=== Registro de solicitudes ===\n";
    for (int i = 1; i <= 5; i++) {
        std::cout << "\nSolicitud #" << i << ":\n";
        std::cin >> x;
        MiCola.enqueue(x);
    }

    std::cout << "\n=== Constancias elaboradas ===\n";
    for (int i = 1; i <= 5; i++) {
        persona& atendido = MiCola.dequeue();
        std::cout << atendido;
    }

    return 0;
}
