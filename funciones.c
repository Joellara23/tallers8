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

void ingresar(char nombres[][20], int tiempos[], int recursos[][3], int cantidades[], int *total, int MAX) {
    if (*total < MAX) {
        printf("Nombre del producto: ");
        scanf(" %[^\n]", nombres[*total]);
        tiempos[*total] = leerEnteroPositivo("Tiempo por unidad (min): ");
        printf("Cantidad a fabricar: ");
        cantidades[*total] = leerEnteroPositivo("");
        printf("Ingrese la cantidad de recursos necesarios por unidad:\n");
        recursos[*total][0] = leerEnteroPositivo("Chips por unidad: ");
        recursos[*total][1] = leerEnteroPositivo("Placas por unidad: ");
        recursos[*total][2] = leerEnteroPositivo("Cables por unidad: ");
        (*total)++;
    } else {
        printf("No se pueden agregar mas productos.\n");
    }
}

void mostrar(char nombres[][20], int tiempos[], int recursos[][3], int cantidades[], int total) {
    if (total == 0) {
        printf("No hay productos ingresados.\n");
    } else {
        for (int i = 0; i < total; i++) {
            printf("%d. %s - Tiempo: %d min - Chips: %d - Placas: %d - Cables: %d - Cantidad: %d\n",
                   i + 1, nombres[i], tiempos[i],
                   recursos[i][0], recursos[i][1], recursos[i][2], cantidades[i]);
        }
    }
}

void editar(char nombres[][20], int tiempos[], int recursos[][3], int cantidades[], int total) {
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
        cantidades[encontrado] = leerEnteroPositivo("Nueva cantidad: ");
        printf("Ingrese la nueva cantidad de recursos necesarios por unidad:\n");
        recursos[encontrado][0] = leerEnteroPositivo("Chips por unidad: ");
        recursos[encontrado][1] = leerEnteroPositivo("Placas por unidad: ");
        recursos[encontrado][2] = leerEnteroPositivo("Cables por unidad: ");
    } else {
        printf("Producto no encontrado.\n");
    }
}

void eliminar(char nombres[][20], int tiempos[], int recursos[][3], int cantidades[], int *total) {
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
            cantidades[j] = cantidades[j + 1];
            for (int k = 0; k < 3; k++) {
                recursos[j][k] = recursos[j + 1][k];
            }
        }
        (*total)--;
        printf("Producto eliminado.\n");
    } else {
        printf("Producto no encontrado.\n");
    }
}

void calcular(char nombres[][20], int tiempos[], int recursos[][3], int cantidades[], int total) {
    int tiempo_total = 0;
    int recursos_total[3] = {0, 0, 0};

    for (int i = 0; i < total; i++) {
        tiempo_total += tiempos[i] * cantidades[i];
        for (int k = 0; k < 3; k++) {
            recursos_total[k] += recursos[i][k] * cantidades[i];
        }
    }

    int tiempo_max, recursos_max[3];
    tiempo_max = leerEnteroPositivo("Tiempo disponible (min): ");
    recursos_max[0] = leerEnteroPositivo("Chips disponibles: ");
    recursos_max[1] = leerEnteroPositivo("Placas disponibles: ");
    recursos_max[2] = leerEnteroPositivo("Cables disponibles: ");

    printf("Tiempo total requerido: %d min\n", tiempo_total);
    printf("Chips totales requeridos: %d\n", recursos_total[0]);
    printf("Placas totales requeridas: %d\n", recursos_total[1]);
    printf("Cables totales requeridos: %d\n", recursos_total[2]);

    if (tiempo_total <= tiempo_max &&
        recursos_total[0] <= recursos_max[0] &&
        recursos_total[1] <= recursos_max[1] &&
        recursos_total[2] <= recursos_max[2]) {
        printf("Si se puede cumplir con la produccion.\n");
    } else {
        printf("No se puede cumplir con la produccion.\n");
    }
}



