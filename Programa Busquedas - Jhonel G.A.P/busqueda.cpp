#include "busqueda.h"
#include "utilidades.h"
#include <algorithm>

using namespace std;

// Búsqueda binaria
// Función de búsqueda binaria
int busquedaBinaria(int a[], int n, int dato) {
    int izq = 0, der = n - 1, cen = 0, m, pos;
    while (izq <= der && cen == 0) {
        m = (izq + der) / 2;
        if (a[m] == dato) {
            cen = 1;
        } else if (a[m] < dato) {
            izq = m + 1;
        } else {
            der = m - 1;
        }
    }
    if (cen == 1) {
        pos = m;
    } else {
        pos = -izq;
    }
    return pos;
}


// Búsqueda exponencial
int busquedaExponencial(int a[], int n, int x) {
    if (n == 0){
    	return -1;
	}
    if (a[0] == x){
    	return 0;
	}
    int i = 1;
    while (i < n && a[i] <= x) {
        i = i * 2; 
    }
    return busquedaBinaria(a, min(i, n), x);  
}

// Búsqueda secuencial en datos desordenados
// Función de búsqueda secuencial ordenada
/*int SecuencialOrd(int* Arr_crlV, int n, int dato) {
    int i = 0;
    while (i < n && Arr_crlV[i] < dato) {
        i++;
    }
    if (i >= n || Arr_crlV[i] > dato) {
        return -i; // Retorna -i si el dato no fue encontrado
    } else {
        return i; // Retorna la posición del dato encontrado
    }
}*/

	


