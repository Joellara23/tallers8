#ifndef FUNCIONES_H
#define FUNCIONES_H

void inicializarRecursos();
int leerEnteroPositivo(const char *mensaje);
void ingresar(char nombres[][20], int tiempos[], int recursos[][3], int cantidades[], int *total, int MAX);
void mostrar(char nombres[][20], int tiempos[], int recursos[][3], int cantidades[], int total);
void editar(char nombres[][20], int tiempos[], int recursos[][3], int cantidades[], int total);
void eliminar(char nombres[][20], int tiempos[], int recursos[][3], int cantidades[], int *total);
void calcular(char nombres[][20], int tiempos[], int recursos[][3], int cantidades[], int total);

#endif
