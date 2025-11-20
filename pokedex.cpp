#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Pokemon {
    private: 
        string nombre;
        string tipo;
        int nivel;
    
    public:
        Pokemon(){}
        Pokemon(string n, string t, int lvl): nombre(n), tipo(t), nivel(lvl) {}
        string getNombre() const {return nombre;}
        string getTipo() const {return tipo;}
        int getNivel() const {return nivel;}
        void mostrar() const{
            cout << "Nombre: " << nombre;
            cout << "\nTipo: " << tipo;
            cout << "\nNivel: " << nivel << "\n";
            cout << endl;
        }
};

class Pokedex {
    private:
        vector<Pokemon> lista;
    string minusculas(string s)const{
        for(char &c : s)c = tolower(c);
        return s;
    }
    public:
        void agregar() {
            string nombre, tipo;
            int nivel;
            cout << "Nombre del pokemon: ";
            cin >> nombre;
            nombre = minusculas(nombre);
            cout << "Tipo: ";
            cin >> tipo;
            cout << "Nivel: ";
            cin >> nivel;
            lista.emplace_back(nombre, tipo, nivel);
            cout << "Pokemon agregado!\n";
        }
        void mostrarTodos() const{
            if (lista.empty()) {
                cout << "No hay pokemon cargados";
                return;
            }
            cout << "\n---LISTA DE POKEMON---\n";
            for (const auto& p : lista){
                p.mostrar();
            }
        }
        void buscar() const{
            string nombre;
            cout << "Nombre del pokemon a buscar: ";
            cin >> nombre;
            nombre = minusculas(nombre);
            for (const auto& p : lista){
                if (p.getNombre() == nombre){
                    cout << "\nEncontrado: \n";
                    p.mostrar();
                    cout << "\n";
                    return;
                }
            }
            cout << "No encontrado\n";
        }
        void eliminar(){
            string nombre;
            cout << "A que pokemon desea eliminar: \n";
            cin >> nombre;
            nombre = minusculas(nombre);
            for(auto it = lista.begin(); it!= lista.end(); it++){
                if (it->getNombre() == nombre){
                    lista.erase(it);
                    cout << "Pokemon eliminado\n";
                    return;
                }
            }
            cout << "No se encontro a ese pokemon\n";
        }
};

 int main(){
     Pokedex dex;
     int opcion;
     do {
        cout << "\n====== POKEDEX ======\n";
        cout << "1) Agregar Pokemon\n";
        cout << "2) Mostrar todos\n";
        cout << "3) Buscar por nombre\n";
        cout << "4) Eliminar Pokemon\n";
        cout << "0) Salir\n";
        cout << "Eliga una opcion: ";
        cin >> opcion;
        switch (opcion){
            case 1: 
                dex.agregar();
                break;
            case 2:
                dex.mostrarTodos();
                break;
            case 3:
                dex.buscar();
                break;
            case 4:
                dex.eliminar();
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida...\n";
                break;
        }
     }
     while (opcion != 0);
 return 0;
}
