#include <stdio.h>
#include <string.h>

#include "funciones.h"

int leerEnteroPositivo(const char *mensaje) {
    int valor;
    do {
        printf("%s", mensaje);
        if (scanf("%d", &valor) != 1 || valor < 0) {
            printf("Ingrese un numero entero positivo valido.\n");
            while (getchar() != '\n'); // Limpiar buffer
        }
    } while (valor < 0);
    while (getchar() != '\n'); // Limpiar buffer
    return valor;
}

void ingresar(char nombres[][20], int tiempos[], int recursos[], int cantidades[], int *total, int MAX) {
    if (*total < MAX) {
        printf("Nombre del producto: ");
        scanf(" %[^\n]", nombres[*total]);
        tiempos[*total] = leerEnteroPositivo("Tiempo por unidad (min): ");
        recursos[*total] = leerEnteroPositivo("Recursos por unidad: ");
        cantidades[*total] = leerEnteroPositivo("Cantidad a fabricar: ");
        (*total)++;
    } else {
        printf("No se pueden agregar mas productos.\n");
    }
}

void mostrar(char nombres[][20], int tiempos[], int recursos[], int cantidades[], int total) {
    if (total == 0) {
        printf("No hay productos ingresados.\n");
    } else {
        for (int i = 0; i < total; i++) {
            printf("%d. %s - Tiempo: %d min - Recursos: %d - Cantidad: %d\n",
                   i + 1, nombres[i], tiempos[i], recursos[i], cantidades[i]);
        }
    }
}

void editar(char nombres[][20], int tiempos[], int recursos[], int cantidades[], int total) {
    char buscado[30];
    printf("Nombre del producto a editar: ");
    scanf(" %[^\n]", buscado);
    int encontrado = -1;

    for (int i = 0; i < total; i++) {
        if (strcmp(nombres[i], buscado) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        printf("Nuevo nombre: ");
        scanf(" %[^\n]", nombres[encontrado]);
        tiempos[encontrado] = leerEnteroPositivo("Nuevo tiempo: ");
        recursos[encontrado] = leerEnteroPositivo("Nuevos recursos: ");
        cantidades[encontrado] = leerEnteroPositivo("Nueva cantidad: ");
    } else {
        printf("Producto no encontrado.\n");
    }
}

void eliminar(char nombres[][20], int tiempos[], int recursos[], int cantidades[], int *total) {
    char buscado[30];
    printf("Nombre del producto a eliminar: ");
    scanf(" %[^\n]", buscado);
    int encontrado = -1;

    for (int i = 0; i < *total; i++) {
        if (strcmp(nombres[i], buscado) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        for (int j = encontrado; j < *total - 1; j++) {
            strcpy(nombres[j], nombres[j + 1]);
            tiempos[j] = tiempos[j + 1];
            recursos[j] = recursos[j + 1];
            cantidades[j] = cantidades[j + 1];
        }
        (*total)--;
        printf("Producto eliminado.\n");
    } else {
        printf("Producto no encontrado.\n");
    }
}

void calcular(char nombres[][20], int tiempos[], int recursos[], int cantidades[], int total) {
    int tiempo_total = 0;
    int recursos_total = 0;

    for (int i = 0; i < total; i++) {
        tiempo_total += tiempos[i] * cantidades[i];
        recursos_total += recursos[i] * cantidades[i];
    }

    int tiempo_max, recursos_max;
    tiempo_max = leerEnteroPositivo("Tiempo disponible (min): ");
    recursos_max = leerEnteroPositivo("Recursos disponibles: ");

    printf("Tiempo total requerido: %d min\n", tiempo_total);
    printf("Recursos totales requeridos: %d\n", recursos_total);

    if (tiempo_total <= tiempo_max && recursos_total <= recursos_max) {
        printf("Si se puede cumplir con la produccion.\n");
    } else {
        printf("No se puede cumplir con la produccion.\n");
    }
}

