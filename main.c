#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX 5

int main() {
    char nombres[MAX][20];
    int tiempos[MAX];
    int recursos[MAX][3];
    int cantidades[MAX];
    int total = 0;
    int opcion;

    // Inicializar recursos y tiempo disponibles al inicio
    inicializarRecursos();

    do {
        printf("\nMenu:\n");
        printf("1. Ingresar producto\n");
        printf("2. Mostrar productos\n");
        printf("3. Editar producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Calcular produccion\n");
        printf("0. Salir\n");
        opcion = leerEnteroPositivo("Ingresa una opcion");

        switch (opcion) {
            case 1:
                ingresar(nombres, tiempos, recursos, cantidades, &total, MAX);
                break;
            case 2:
                mostrar(nombres, tiempos, recursos, cantidades, total);
                break;
            case 3:
                editar(nombres, tiempos, recursos, cantidades, total);
                break;
            case 4:
                eliminar(nombres, tiempos, recursos, cantidades, &total);
                break;
            case 5:
                calcular(nombres, tiempos, recursos, cantidades, total);
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 0);

    return 0;
}
