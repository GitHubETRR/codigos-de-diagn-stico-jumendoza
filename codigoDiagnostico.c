#include <stdio.h>
#define MAX 100
#define MAX_CHAR 100

typedef struct{
    char marca[MAX_CHAR];
    char modelo[MAX_CHAR];
    char patente[MAX_CHAR];
    int presio;
}concesionaria_t;

int ingresarAuto(concesionaria_t autos[], int);
void verAutos(concesionaria_t autos[], int);

int ingresarAuto(concesionaria_t autos[], int numAutos){
    if (numAutos >= MAX){
        printf("Maximo de autos alcanzado\n");
        return numAutos;
    }
    printf("Ingrese la marca de su auto\n");
    scanf("%s", autos[numAutos].marca);
    printf("Ingrese el modelo de su auto\n");
    scanf("%s", autos[numAutos].modelo);
    printf("Ingrese la patente de su auto\n");
    scanf("%s", autos[numAutos].patente);
    printf("Ingrese el precio de su auto\n");
    scanf("%d", &autos[numAutos].presio);
    return numAutos + 1;
}

void verAutos(concesionaria_t autos[], int numAutos){
    if (numAutos == 0){
        printf("No se han ingresado autos\n");
        return;
    }
    printf("Lista de autos disponibles\n");
    for (int i = 0; i < numAutos; i++){
        printf("Auto numero: %d\n", i + 1);
        printf("Marca del auto:%s\n", autos[i].marca);
        printf("Modelo del auto:%s\n", autos[i].modelo);
        printf("Patente del auto:%s\n", autos[i].patente);
        printf("Precio del auto:%d\n", autos[i].presio);
    }
}

int main()
{
    concesionaria_t autos[MAX];
    int numAutos = 0;
    int opcion;
    do{
        printf("Bienvenido a nuestra concesionaria, ingrese lo que quiere hacer\n");
        printf("1: Ingresar un auto\n");
        printf("2: Ver autos disponibles\n");
        printf("3: Salir del programa\n");
        printf("Ingrese su opcion:\n");
        scanf("%d", &opcion);
        switch (opcion){
            case 1:
                numAutos = ingresarAuto(autos, numAutos);
                break;
            case 2:
                verAutos(autos, numAutos);
                break;
            case 3:
                printf("Saliendo del programa...");
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while (opcion != 3);
    return 0;
}
