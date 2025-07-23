#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

// Estructura del Item
struct Item {
    std::string sku;
    std::string nombre;
    std::string fecha; // formato en Años/Meses/Dias
    int precioCentavos;
    int stock;
};

// Funciones de comparación
bool ordenarPorNombre(const Item& a, const Item& b) {
    return a.nombre < b.nombre;
}

bool ordenarPorPrecio(const Item& a, const Item& b) {
    return a.precioCentavos < b.precioCentavos;
}

bool ordenarPorStock(const Item& a, const Item& b) {
    return a.stock < b.stock;
}


// Función para imprimir los items
void printItem(const Item& item) {
    std::cout << "Nombre: " << item.nombre << "\n"
        << "Precio: $" << item.precioCentavos / 100 << "." << std::setfill('0') << std::setw(2) << item.precioCentavos % 100 << "\n"
        << "Stock: " << item.stock << "\n"
        << "------------------------\n";
}

// Mostrar todos los items
void mostrarBaseDeDatos(const std::vector<Item>& db) {
    for (const auto& item : db) {
        printItem(item);
    }
}

int main() {
    // Datos de ejemplo
    std::vector<Item> baseDeDatos = {
        {"A001", "Teclado mecanico", "2023-11-12", 45000, 25},
        {"B102", "Raton inalambrico", "2024-01-10", 32000, 40},
        {"C321", "Monitor\"", "2022-05-05", 125000, 10},
        {"D044", "Webcam", "2023-07-01", 23000, 15},
        {"E011", "Laptop", "2024-03-18", 550000, 5}
    };

    std::cout << "Seleccione una opcion de ordenamiento:\n";
    std::cout << "1 - Nombre\n";
    std::cout << "2 - Precio\n";
    std::cout << "3 - Stock\n";
    std::cout << "Opcion: ";

    int opcion;
    std::cin >> opcion;

    bool (*comparador)(const Item&, const Item&) = nullptr;

    switch (opcion) {
    case 1: comparador = ordenarPorNombre; break;
    case 2: comparador = ordenarPorPrecio; break;
    case 3: comparador = ordenarPorStock; break;
    default:
        std::cout << "Opcion inválida.\n";
        return 1;
    }

    std::sort(baseDeDatos.begin(), baseDeDatos.end(), comparador);

    std::cout << "\nBase de datos ordenada:\n";
    mostrarBaseDeDatos(baseDeDatos);

    return 0;
}
