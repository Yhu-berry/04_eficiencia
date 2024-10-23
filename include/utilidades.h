#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <iostream>
using namespace std;

// Generar un arreglo aleatorio
void generarArreglo(int* arr, int n);

// Copiar el tama�o del arreglo para que todos posean el mismo
void copiarArr(int* Arr_crlV, const int* Arr_crlC, int n);

// Funci�n para imprimir el arreglo
void imprimirArr(const int* arr, int n);

// Mostrar el arreglo
void mostrarArreglo(int a[], int n);

// Designar el tama�o m�ximo del arreglo
const int n_Max = 1000000;

#endif

