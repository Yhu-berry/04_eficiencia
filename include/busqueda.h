#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Estructura para almacenar tiempos de búsqueda
struct Metodos {
    double busquedaExponencial;
    double busquedaBinaria;
};

// Funciones de ordenación y búsqueda
void QuickSort(int a[], int n);
int busquedaBinaria(int a[], int n, int dato);
void mostrarArreglo(int a[], int n);
void imprimirComparacion(Metodos tiempo[], Metodos promedio[], int n, int c, int datos, int busquedas, int elementoBuscar[]);
int busquedaExponencial(int a[], int n, int x);

#endif // BUSQUEDA_H

