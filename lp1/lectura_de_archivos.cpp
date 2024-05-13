#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() 
{
    string nombreArchivo;
    cout << "Ingrese el nombre del archivo de texto: "; cin >> nombreArchivo;

    ifstream archivo(nombreArchivo);

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    vector<double> datos;
    double dato;
    while (archivo >> dato) 
    {
        datos.push_back(dato);
    }
    archivo.close();

    int n = datos.size();
    double suma = 0.0;
    double sumaCuadrados = 0.0;

    for (double d : datos) 
    {
        suma += d;
        sumaCuadrados += d * d;
    }
    double promedio = suma / n;
    double varianza = (sumaCuadrados / n) - (promedio * promedio);
    double desviacionEstandar = sqrt(varianza);

    // Crear un archivo de resultados
    ofstream resultado("resultados.txt");
    if (!resultado.is_open()) 
    {
        cout << "No se pudo crear el archivo de resultados." << endl;
        return 1;
    }

    resultado << "Número de datos: " << n << endl;
    resultado << "Promedio: " << promedio << endl;
    resultado << "Varianza: " << varianza << endl;
    resultado << "Desviación estándar: " << desviacionEstandar << endl;
    resultado << "Coeficiente de variacion : " << (desviacionEstandar/varianza)*100<<" % ";

    resultado.close();

    cout << "Los resultados se han guardado en 'resultados.txt'." << endl;

    return 0;
}
