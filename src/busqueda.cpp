#include "busqueda.h"
#include "utilidades.h"

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


int busquedaExponencial(int a[], int n, int x) {
    if (n == 0) return -1; // Si el arreglo está vacío
    if (a[0] == x) return 0;
    
    int i = 1;
    while (i < n && a[i] <= x) {
        i = i * 2; // Incrementa exponencialmente
    }
    
    // Realiza búsqueda binaria en el rango adecuado
    return busquedaBinaria(a, min(i, n), x);  
}


