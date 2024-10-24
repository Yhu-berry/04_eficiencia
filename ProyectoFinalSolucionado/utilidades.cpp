#include "utilidades.h"
#include <iostream> 
#include <cstdlib> //Libreria necesaria para la funcion rand()
#include <ctime>

//Funcion para generar arreglo aleatorio
void generarArreglo(int* arr, int n){
    srand(time(0)); //Genera una semilla random

    for(int i=0; i<n; ++i)
        arr[i] = rand() % 1000000 + 1; //Genera un numero aleatorio entre 0 y 1mill
}

//Funcion para copiar arreglo aleatorio
void copiarArr(int* Arr_crlV, const int* Arr_crlC, int n){
    for(int i=0;i<n;i++){
        Arr_crlV[i]=Arr_crlC[i]; //El arreglo copiado sera igual original 
    }
}

//Funcion para imprimir arreglo
void imprimirArr(const int* arr, int n){
    for(int i=0; i<n ; i++){
        std::cout << arr[i]<<" ";
    }
    std::cout<<std::endl;
}
