#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream archivoEsc("nombres.txt"); 
    if (!archivoEsc) {
        cout << "No se pudo abrir el archivo para escribir.\n";
        return 1;
    }
    cout << "Escribiendo nombres en el archivo...\n";
    archivoEsc << "Juan\n";
    archivoEsc << "Mateo\n";
    archivoEsc << "Matip\n";
    archivoEsc << "Kapu\n";
    archivoEsc.close();
    cout << "Archivo guardado.\n";

    ifstream archivoLee("nombres.txt"); 
    if (!archivoLee) {
        cout << "No se pudo abrir el archivo para leer.\n";
        return 1;
    }
    cout << "Leyendo nombres desde el archivo:\n";
    string linea;
    while (getline(archivoLee, linea)) {  
        cout << "- " << linea << endl;
    }
    archivoLee.close();
    return 0;
}