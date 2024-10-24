#ifndef UTILIDADES_H
#define UTILIDADES_H
#include "busqueda.h"
//Generar un arreglo aleatorio
void generarArreglo(int* arr,int n);

//Copiar el tamaño del arreglo para que todos posean el mismo
void copiarArr(int* Arr_crlV, const int* Arr_crlC, int n);
//Funcion para imprimir el arreglo
void imprimirArr(const int* arr, int n);

//Designar el tamaño maximo del arreglo
const int n_Max=1000000;

void mostrarArreglo(int a[], int n);

void imprimirComparacion(Metodos tiempo[], Metodos promedio[], int n, int c, int datos, int busquedas, int elementoBuscar[], int r[]);

void mezclarArreglo(int* arreglo, int tamano);

#endif
