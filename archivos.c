#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 100

typedef struct Persona {
    char nombre[MAX_CHAR];
    int edad;
    struct Persona *siguiente;
} Persona;

void agregarPersona(Persona **lista);
void mostrarPersonas(Persona *lista);
void guardarEnArchivo(Persona *lista, const char *nombreArchivo);
void cargarDesdeArchivo(Persona **lista, const char *nombreArchivo);
void liberarLista(Persona *lista);

void agregarPersona(Persona **lista) {
    Persona *nueva = (Persona *)malloc(sizeof(Persona));
    printf("\nIngrese nombre: ");
    fgets(nueva->nombre, MAX_CHAR, stdin);
    nueva->nombre[strcspn(nueva->nombre, "\n")] = '\0';
    printf("Ingrese edad: ");
    scanf("%d", &nueva->edad);
    getchar(); // Limpiar buffer
    nueva->siguiente = *lista;
    *lista = nueva;
}

void mostrarPersonas(Persona *lista) {
    if (lista == NULL) {
        printf("\nLa lista está vacía.\n");
        return;
    }
    Persona *actual = lista;
    while (actual != NULL) {
        printf("Nombre: %s - Edad: %d\n", actual->nombre, actual->edad);
        actual = actual->siguiente;
    }
}

void guardarEnArchivo(Persona *lista, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w");
    Persona *actual = lista;
    while (actual != NULL) {
        fprintf(archivo, "%s;%d\n", actual->nombre, actual->edad);
        actual = actual->siguiente;
    }
    fclose(archivo);
    printf("\nDatos guardados en %s\n", nombreArchivo);
}

void cargarDesdeArchivo(Persona **lista, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");
    char linea[MAX_CHAR];
    while (fgets(linea, sizeof(linea), archivo)) {
        Persona *nueva = (Persona *)malloc(sizeof(Persona));
        if (nueva == NULL) {
            printf("\nError al asignar memoria.\n");
            fclose(archivo);
            return;
        }
        sscanf(linea, "%[^;];%d", nueva->nombre, &nueva->edad);
        nueva->siguiente = *lista;
        *lista = nueva;
    }
    fclose(archivo);
    printf("\nDatos cargados desde %s\n", nombreArchivo);
}

void liberarLista(Persona *lista) {
    Persona *actual;
    while (lista != NULL) {
        actual = lista;
        lista = lista->siguiente;
        free(actual);
    }
}

int main() {
    Persona *lista = NULL;
    int opcion;
    char nombreArchivo[] = "personas.txt";
    do {
        printf("\n--- MENU ---\n");
        printf("1. Agregar persona\n");
        printf("2. Mostrar personas\n");
        printf("3. Guardar en archivo\n");
        printf("4. Leer desde archivo\n");
        printf("5: Borrar lista actual\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();
        switch (opcion) {
            case 1:
                agregarPersona(&lista);
                break;
            case 2:
                mostrarPersonas(lista);
                break;
            case 3:
                guardarEnArchivo(lista, nombreArchivo);
                break;
            case 4:
                liberarLista(lista);
                lista = NULL;
                cargarDesdeArchivo(&lista, nombreArchivo);
                break;
            case 5:
                liberarLista (lista);
                lista = NULL;
                printf("\nLista reiniciada\n");
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 6);
    liberarLista(lista);
    return 0;
}
