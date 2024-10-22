#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <iostream>
using namespace std;

void reduce(int a[], int inicio, int final);

void QuickSort(int a[], int n){
	reduce(a, 0, n-1);
}

void reduce(int a[], int inicio, int final){
	
	int izq=inicio;
	int der=final;
	int pos=izq;
	int cen=1;
	
	while(cen==1){
		cen=0;
		//recorrido de derecha a izquierda
		while(a[pos]<=a[der] && pos!=der){
			der--;
		}
		if(pos!=der){
			int aux=a[pos];
			a[pos]=a[der];
			a[der]=aux;
			pos=der;
			//recorrido de izquierda a derecha
			while(a[pos]>=a[izq] && pos!=izq){
				izq++;
			}
			if(pos!=izq){
				int aux=a[pos];
				a[pos]=a[izq];
				a[izq]=aux;
				pos=izq;
				cen=1;
			}
		}
		if(pos-1 > inicio){
			//llamado recursivo a Quicksort para el subarreglo izquierdo
			reduce(a, inicio, pos-1);
		}
		if(pos+1 < final){
			//llamado recursivo a Quicksort para el subarreglo derecho
			reduce(a, pos+1, final);
		}
	}
}

int busquedaBinaria(int a[], int n, int dato){
	
	int izq=0;
	int der=n-1;
	int cen=0, m, pos;
	
	while(izq<=der && cen==0){
		m=(izq+der)/2;
		if(a[m]==dato){	
			cen=1;
		} else if(a[m]<dato){
			izq=m+1;
		} else {
			der=m-1;
		}
	}
	if(cen==1){
		pos=m;
	}else{
		pos=-izq;
	}
	return pos;
}

#endif 