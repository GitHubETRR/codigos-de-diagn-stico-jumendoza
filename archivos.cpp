#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int opcion;
    do {
        cout << "\n===== MENU PERSONAS =====\n";
        cout << "1. Agregar persona\n";
        cout << "2. Mostrar personas\n";
        cout << "3. Salir\n";
        cout << "Elija una opcion: ";
        cin >> opcion;
        cin.ignore();
        if (opcion == 1) {
            string nombre;
            int edad;
            cout << "Ingrese nombre: ";
            getline(cin, nombre);
            cout << "Ingrese edad: ";
            cin >> edad;
            ofstream archivoEsc("personas.txt", ios::app);
            if (!archivoEsc) {
                cout << "Error abriendo archivo para escribir.\n";
                return 1;
            }
            archivoEsc << nombre << "," << edad << "\n";
            archivoEsc.close();
            cout << "Persona guardada.\n";
        }
        else if (opcion == 2) {
            ifstream archivoLee("personas.txt");
            if (!archivoLee) {
                cout << "No existe el archivo o no se pudo abrir.\n";
            } else {
                cout << "\n--- Personas Registradas ---\n";
                string linea;
                while (getline(archivoLee, linea)) {
                    cout << linea << endl;
                }
                archivoLee.close();
            }
        }
        else if (opcion != 3) {
            cout << "Opcion invalida.\n";
        }
    } while (opcion != 3);
    cout << "Programa finalizado.\n";
    return 0;
}