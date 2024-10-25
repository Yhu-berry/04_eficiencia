#include "utilidades.h"
#include <iostream> 
#include <cstdlib> //Libreria necesaria para la funcion rand()
#include <ctime>
#include <algorithm>
#include <random> 
#include <iomanip> 
using namespace std;

void imprimirArr(const int* arr, int n){
    for(int i=0; i<n ; i++){
        std::cout << arr[i]<<" ";
    }
    std::cout<<std::endl;
}


void imprimirComparacion(Metodos tiempo[], Metodos promedio[], int n, int c, int datos, int busquedas, int elementoBuscar[], int r[]) {
	cout << endl << endl;
    cout << "C O M P A R A C I O N    " << c + 1 << endl << endl
         << "Elemento a buscar: Aletorio por busqueda." << endl
         << "Arreglo: Sin repetir, aleatorio." << endl 
         << "Total de datos: " << datos << endl
         << "Total de busquedas: " << busquedas << endl << endl;
                cout << "\tBUSQUEDA BINARIA" << "\t\t\t" << "BUSQUEDA EXPONENCIAL" << endl << endl;
    for (int i = 0; i < n; i++) {

        cout << "Busqueda " << i + 1 << " (" << elementoBuscar[i] << "):" 
		<< fixed << setprecision(7) << tiempo[i].busquedaBinaria << " ms" << "\t\t\t"  
		<< tiempo[i].busquedaExponencial << " ms" << endl;
    }
    cout << endl;
    cout << "\tPromedio: " << promedio[c].busquedaBinaria 
         << "\t\t\t" << "Promedio: " << promedio[c].busquedaExponencial << endl;
}


void mezclarArreglo(int* arreglo, int tamano) {
    default_random_engine engine(static_cast<unsigned int>(time(0)));
    shuffle(arreglo, arreglo + tamano, engine);
}

void arrSucesivo(int* a, int n){
	for (int i = 0; i < n; i++) {
        a[i] = i;
    }
}

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

