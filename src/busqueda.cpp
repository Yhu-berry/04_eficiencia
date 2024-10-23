#include "../include/busqueda.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void reduce(int a[], int inicio, int final);

void QuickSort(int a[], int n) {
    reduce(a, 0, n-1);
}

void reduce(int a[], int inicio, int final) {

    int izq=inicio;
    int der=final;
    int pos=izq;
    int cen=1;

    while(cen==1) {
        cen=0;
        //recorrido de derecha a izquierda
        while(a[pos]<=a[der] && pos!=der) {
            der--;
        }
        if(pos!=der) {
            int aux=a[pos];
            a[pos]=a[der];
            a[der]=aux;
            pos=der;
            //recorrido de izquierda a derecha
            while(a[pos]>=a[izq] && pos!=izq) {
                izq++;
            }
            if(pos!=izq) {
                int aux=a[pos];
                a[pos]=a[izq];
                a[izq]=aux;
                pos=izq;
                cen=1;
            }
        }
        if(pos-1 > inicio) {
            //llamado recursivo a Quicksort para el subarreglo izquierdo
            reduce(a, inicio, pos-1);
        }
        if(pos+1 < final) {
            //llamado recursivo a Quicksort para el subarreglo derecho
            reduce(a, pos+1, final);
        }
    }
}

int busquedaBinaria(int a[], int n, int dato) {

    int izq=0;
    int der=n-1;
    int cen=0, m, pos;

    while(izq<=der && cen==0) {
        m=(izq+der)/2;
        if(a[m]==dato) {
            cen=1;
        } else if(a[m]<dato) {
            izq=m+1;
        } else {
            der=m-1;
        }
    }
    if(cen==1) {
        pos=m;
    } else {
        pos=-izq;
    }
    return pos;
}

void imprimirComparacion(Metodos tiempo[], Metodos promedio[], int n, int c, int datos, int busquedas, int elementoBuscar[]){
	
	cout << "C O M P A R A C I O N    " << c << endl
		<< "Elemento a buscar: Aletorio por busqueda." << endl
		<< "Arreglo: Sin repetir, aleatorio." << endl 
		<< "Total de datos: " << datos << endl
		<< "Total de busquedas: " << busquedas << endl << endl;
		
 	for(int i=0; i<n; i++){
 		cout << "\tBUSQUEDA BINARIA" << "\t\t\t" << "BUSQUEDA EXPONENCIAL" << endl << endl;
		cout << "Busqueda " << i+1 << " (" << elementoBuscar[i] << "): " << tiempo[i].busquedaBinaria << " ms" << "\t\t\t"  << tiempo[i].busquedaExponencial << " ms" << endl;
	}
	cout << "\tPromedio: " << promedio[c].busquedaBinaria << "\t\t\t" << "Promedio: " << promedio[c].busquedaExponencial << endl;
}

int busquedaExponencial(int a[], int n, int x){
	return 1;
}

