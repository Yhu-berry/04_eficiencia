#ifndef UTILIDADES_H
#define UTILIDADES_H
#include "busqueda.h"
#include <windows.h>
#define color SetConsoleTextAttribute

extern HANDLE hConsole;

//Funcion para imprimir el arreglo
void imprimirArr(const int* arr, int n);

void imprimirComparacion(Metodos tiempo[], Metodos promedio[], int n, int c, int datos, int busquedas, int elementoBuscar[], int r[]);

void mezclarArreglo(int* arreglo, int tamano);

void shellsort(int* Arr_crlV, int n);

void arrSucesivo(int* a, int n);
#endif
