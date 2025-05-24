#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX 5

char nombres[MAX][20];
int tiempos[MAX];
int recursos[MAX];
int cantidades[MAX];
int total = 0;

int main() {
    int opcion;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Calcular produccion\n");
        printf("5. Mostrar productos\n");
        printf("6. Salir\n");
        opcion = leerEnteroPositivo("Opcion: ");

        switch (opcion) {
            case 1:
                ingresar(nombres, tiempos, recursos, cantidades, &total, MAX);
                break;
            case 2:
                editar(nombres, tiempos, recursos, cantidades, total);
                break;
            case 3:
                eliminar(nombres, tiempos, recursos, cantidades, &total);
                break;
            case 4:
                calcular(nombres, tiempos, recursos, cantidades, total);
                break;
            case 5:
                mostrar(nombres, tiempos, recursos, cantidades, total);
                break;
            case 6:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 6);

    return 0;
}