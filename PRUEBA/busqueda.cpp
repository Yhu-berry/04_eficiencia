#include "busqueda.h"
#include "utilidades.h"
#include <algorithm>
using namespace std;

// Búsqueda secuencial en datos desordenados
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

// Búsqueda binaria
// Función de búsqueda binaria
int busquedaBinaria(int a[], int n, int dato) {
    int izq = 0, der = n - 1;
    while (izq <= der) {
        int m = izq + (der - izq) / 2; // Evitar overflow
        if (a[m] == dato) {
            return m; // Retorna la posición del dato encontrado
        } else if (a[m] < dato) {
            izq = m + 1;
        } else {
            der = m - 1;
        }
    }
    return -izq; // Retorna -izq si el dato no fue encontrado
}

// Búsqueda exponencial
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

