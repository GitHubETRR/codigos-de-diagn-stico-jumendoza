#include <iostream>
using namespace std;

class Animal{
    public:
        virtual void sonido(){
            cout << "*Ruido de animal*\n";
        }
        virtual ~Animal(){
            cout << "Animal Destruido \n";
        }    
};

class Gato : public Animal{
    public:
        void sonido() override{
            cout << "Meow meow\n";
        }
        virtual ~Gato(){
            cout << "Gato Destruido \n";
        }
};

class Perro : public Animal{
    public:
        void sonido() override{
            cout << "Guau guau\n";
        }
        virtual ~Perro(){
            cout << "Perro Destruido \n";
        }
};

int main(){
    Animal *animales[2];
    animales[0] = new Gato();
    animales[1] = new Perro();
    for (int i = 0; i <2; i++){
        animales[i]->sonido();
    }
    for (int i = 0; i < 2; i++){
        delete animales [i];
    }
    return 0;
}
