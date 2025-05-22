#include <stdio.h>

int main(){
    int numero = 10;
    int *puntero;
    puntero = &numero;
    printf("Numero actual: %d\n", numero);
    printf("Direccion del numero: %d\n", &numero);
    printf("Valor que guarda el puntero: %d\n", puntero);
    printf("Valor al que apunta el puntero: %d\n", *puntero);
    scanf("%d", puntero);
    printf("Nuevo valor avtualizado; %d\n", numero);
}
