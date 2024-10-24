#include "utilidades.h"
#include <iostream> 
#include <cstdlib> //Libreria necesaria para la funcion rand()
#include <ctime>
#include <algorithm>
#include <random> 
using namespace std;

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

void mostrarArreglo(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

void imprimirComparacion(Metodos tiempo[], Metodos promedio[], int n, int c, int datos, int busquedas, int elementoBuscar[], int r[]) {
	cout << endl << endl;
    cout << "C O M P A R A C I O N    " << c + 1 << endl << endl // Cambiado c a c + 1 para mostrar correctamente el índice
         << "Elemento a buscar: Aletorio por busqueda." << endl
         << "Arreglo: Sin repetir, aleatorio." << endl 
         << "Total de datos: " << datos << endl
         << "Total de busquedas: " << busquedas << endl << endl;
                cout << "\tBUSQUEDA BINARIA" << "\t\t\t" << "BUSQUEDA EXPONENCIAL" << endl << endl;
    for (int i = 0; i < n; i++) {

        cout << /*" (" << elementoBuscar[i] << ") " << */ "Busqueda " << i + 1 << " (" << elementoBuscar[i] << "):" << tiempo[i].busquedaBinaria << " ms" << "\t\t\t"  << tiempo[i].busquedaExponencial << " ms" << endl;
    }
    cout << endl;
    cout << "\tPromedio: " << promedio[c].busquedaBinaria 
         << "\t\t\t" << "Promedio: " << promedio[c].busquedaExponencial << endl;
}

void mezclarArreglo(int* arreglo, int tamano) {
    // Inicializa el generador de números aleatorios con la semilla actual
    default_random_engine engine(static_cast<unsigned int>(time(0)));
    
    // Mezcla el arreglo
    shuffle(arreglo, arreglo + tamano, engine);
}
