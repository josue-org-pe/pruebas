#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct DetallesPersonales 
{
    string nombre;
    int edad;
    string email;
};

void leerDetallesDesdeArchivo(const string& nombreArchivo, vector<DetallesPersonales>& detalles) {
    ifstream archivo(nombreArchivo);
    if (archivo.fail()) 
    {
        cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }

    DetallesPersonales detalle;
    while (archivo >> detalle.nombre >> detalle.edad >> detalle.email) 
    {
        detalles.push_back(detalle);
    }

    archivo.close();
}

void escribirEmailsMayoresDe18(const vector<DetallesPersonales>& detalles, const string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << " para escribir." << std::endl;
        return;
    }

    for (const auto& detalle : detalles) {
        if (detalle.edad > 18) {
            archivo << detalle.email << std::endl;
        }
    }

    archivo.close();
}

int main() {
    std::vector<DetallesPersonales> detalles;
    leerDetallesDesdeArchivo("detalles.txt", detalles);
    escribirEmailsMayoresDe18(detalles, "emails_mayores_de_18.txt");

    std::cout << "Se han creado exitosamente los emails de personas mayores de 18 años en 'emails_mayores_de_18.txt'." << std::endl;

    return 0;
}
