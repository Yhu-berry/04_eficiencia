#include "busqueda.h"
#include "utilidades.h"
#include <algorithm>
using namespace std;

// B�squeda secuencial en datos desordenados
// Funci�n de b�squeda secuencial ordenada
int SecuencialOrd(int* Arr_crlV, int n, int dato) {
    int i = 0;
    while (i < n && Arr_crlV[i] < dato) {
        i++;
    }
    if (i >= n || Arr_crlV[i] > dato) {
        return -i; // Retorna -i si el dato no fue encontrado
    } else {
        return i; // Retorna la posici�n del dato encontrado
    }
}

// B�squeda binaria
// Funci�n de b�squeda binaria
int busquedaBinaria(int a[], int n, int dato) {
    int izq = 0, der = n - 1;
    while (izq <= der) {
        int m = izq + (der - izq) / 2; // Evitar overflow
        if (a[m] == dato) {
            return m; // Retorna la posici�n del dato encontrado
        } else if (a[m] < dato) {
            izq = m + 1;
        } else {
            der = m - 1;
        }
    }
    return -izq; // Retorna -izq si el dato no fue encontrado
}

// B�squeda exponencial
int busquedaExponencial(int a[], int n, int x) {
    if (n == 0) return -1; // Si el arreglo est� vac�o
    if (a[0] == x) return 0;
    
    int i = 1;
    while (i < n && a[i] <= x) {
        i = i * 2; // Incrementa exponencialmente
    }
    
    // Realiza b�squeda binaria en el rango adecuado
    return busquedaBinaria(a, min(i, n), x);  
}

