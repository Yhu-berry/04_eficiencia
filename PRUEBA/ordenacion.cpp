#include "utilidades.h"
#include "ordenacion.h"

//Implementacion de las funciones de los metodos de ordenacion

//Shellsort
void shellsort(int* Arr_crlV, int n){
    int k=n;
    while(k>1){
        k = k/2;
        bool cen=true;
        while(cen){
            cen=false;
            for(int i=0; i + k < n ; i++){
                if(Arr_crlV[i] > Arr_crlV[i+k]){
                    int aux=Arr_crlV[i];

                    Arr_crlV[i]=Arr_crlV[i+k];
                    Arr_crlV[i+k]=aux;
                    cen=true;
                }
            }
        }
    }
}

//Quicksort
void Reduce(int* Arr_crlV, int inicio, int final) {
    int izq = inicio;
    int der = final;
    int pos = izq;
    int cen = 1;
    while (cen == 1) {
        cen = 0;
        while (Arr_crlV[pos] <= Arr_crlV[der] && pos != der) {
            der--;
        }
        if (pos != der) {
            int aux = Arr_crlV[pos];
            Arr_crlV[pos] = Arr_crlV[der];
            Arr_crlV[der] = aux;
            pos = der;
            cen = 1;
        }
        while (Arr_crlV[pos] >= Arr_crlV[izq] && pos != izq) {
            izq++;
        }
        if (pos != izq) {
            int aux = Arr_crlV[pos];
            Arr_crlV[pos] = Arr_crlV[izq];
            Arr_crlV[izq] = aux;
            pos = izq;
            cen = 1;
        }
    }
    if (pos - 1 > inicio) {
        Reduce(Arr_crlV, inicio, pos - 1);
    }
    if (pos + 1 < final) {
        Reduce(Arr_crlV, pos + 1, final);
    }
}

void QuickSort(int* Arr_crlV, int inicio, int final) {
    Reduce(Arr_crlV, inicio, final);
}

//Insercion Binaria
void InsercionBinaria(int* Arr_crlV, int n) {
    for (int i = 1; i < n; ++i) {
        int aux = Arr_crlV[i];
        int izq = 0;
        int der = i - 1;
        while (izq <= der) {
            int m = (izq + der) / 2;
            if (aux < Arr_crlV[m]) {
                der = m - 1;
            } else {
                izq = m + 1;
            }
        }
        for (int j = i - 1; j >= izq; --j) {
            Arr_crlV[j + 1] = Arr_crlV[j];
        }
        Arr_crlV[izq] = aux;
    }
}


