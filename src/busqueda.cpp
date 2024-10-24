#include "busqueda.h"

//Busqueda secuencial en datos desordenados
// Función de búsqueda secuencial ordenada
int SecuencialOrd(int* Arr_crlV, int n, int dato) {
    int i = 0;
    while (i < n && Arr_crlV[i] < dato) {
    i++;
    }
    if (i >= n || Arr_crlV[i] > dato) {
    return -i; // Retorna -i si el dato no fue encontrado
    } else {
    return i; // Retorna la posición del dato encontrado
 }
}

//Busqueda binaria
// Función de búsqueda binaria
int BusquedaBinaria(int* Arr_crlV, int n, int dato) {
    int izq = 0;
    int der = n - 1;
    while (izq <= der) {
    int m = (izq + der) / 2;
    if (Arr_crlV[m] == dato) {
    return m; // Retorna la posición del dato encontra
    } else if (dato > Arr_crlV[m]) {
    izq = m + 1;
    } else {
    der = m - 1;
    }
    }
    return -1; // Retorna -1 si el dato no fue encontrado
}

