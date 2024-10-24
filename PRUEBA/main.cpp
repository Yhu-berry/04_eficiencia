#include "utilidades.h"
#include "ordenacion.h"
#include "busqueda.h"
#include <chrono>   //Libreria para medir el tiempo en milisegundos
#include <iomanip>  // Libreria para manipulacion de flujo de salida
#include <cstdlib>  // Libreria necesaria para la funcion rand()
#include <iostream>
#include <algorithm>
#include <random> 
using namespace std;

void menudeMain();
void menuOrdenacion(int arr[], int n);
void menuBusqueda();

int main() {
    int opcion;
    int n;            // Declarar n aquí para que sea accesible en todo el scope
    int* arr = nullptr; // Inicializar arr como un puntero nulo para que no dé error al usar delete

    do {// Limpia la pantalla
        system("cls"); 
        menudeMain();
        cin >> opcion;
		system("cls"); 
        switch (opcion) {
            case 1: {
                cout << "Cantidad de terminos a comparar (maximo 1000000):\t";
                cin >> n;
                cout << "\n";
                
                arr = new int[n]; // Asigna memoria para el arreglo
                generarArreglo(arr, n);
                menuOrdenacion(arr, n);
                break;
            }
            case 2: {
                menuBusqueda();
                break;
            }
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Intente de nuevo." << endl;
        }
    } while (opcion != 3);

    delete[] arr; // Libera la memoria del arreglo
    return 0;
}

void menudeMain() {
    cout << "=============================" << endl;
    cout << " Menu de Comparacion " << endl;
    cout << "=============================" << endl;
    cout << "1. Comparar Metodos de Ordenacion" << endl;
    cout << "2. Comparar Metodos de Busqueda" << endl;
    cout << "3. Salir" << endl << endl;
    cout << "Seleccione una opcion: ";
}

void menuOrdenacion(int arr[], int n) { 
    int opcionOrdenacion;
    system("CLS");
    cout << "=============================" << endl;
    cout << " Metodos de Ordenacion a Comparar " << endl;
    cout << "=============================" << endl;
    cout << "1. ShellSort vs QuickSort" << endl;
    cout << "2. QuickSort vs InsercionBinaria" << endl;
    cout << "3. InsercionBinaria vs ShellSort" << endl << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcionOrdenacion;
    system("CLS");

    //Crear copias del arreglo original para cada método de ordenación
    int* Arr_crlV1 = new int[n];
    int* Arr_crlV2 = new int[n];
    copiarArr(Arr_crlV1, arr, n);
    copiarArr(Arr_crlV2, arr, n);

    //Variables para medir el tiempo de ejecucion
    chrono::steady_clock::time_point start,end;
    chrono::duration<double,milli> elapsedTime1, elapsedTime2;

    switch (opcionOrdenacion) {
        case 1:
            // Comparación ShellSort
            start = chrono::steady_clock::now();
            shellsort(Arr_crlV1, n);
            end = chrono::steady_clock::now();
            elapsedTime1 = end - start;
            cout << "ShellSort: " << elapsedTime1.count() << " ms" << endl;

            // Comparación QuickSort
            start = chrono::steady_clock::now();
            QuickSort(Arr_crlV2, 0, n - 1);
            end = chrono::steady_clock::now();
            elapsedTime2 = end - start;
            cout << "QuickSort: " << elapsedTime2.count() << " ms" << endl;
            break;
        case 2:
            start = chrono::steady_clock::now();
            QuickSort(Arr_crlV1, 0, n - 1);
            end = chrono::steady_clock::now();
            elapsedTime1 = end - start;
            cout << "QuickSort: " << elapsedTime1.count() << " ms" << endl;

            start = chrono::steady_clock::now();
            InsercionBinaria(Arr_crlV2, n);
            end = chrono::steady_clock::now();
            elapsedTime2 = end - start;
            cout << "Insercion Binaria: " << elapsedTime2.count() << " ms" << endl;
            break;
        case 3:
            start = chrono::steady_clock::now();
            InsercionBinaria(Arr_crlV1, n);
            end = chrono::steady_clock::now();
            elapsedTime1 = end - start;
            cout << "Insercion Binaria: " << elapsedTime1.count() << " ms" << endl;
            
            start = chrono::steady_clock::now();
            shellsort(Arr_crlV2, n);
            end = chrono::steady_clock::now();
            elapsedTime2 = end - start;
            cout << "ShellSort: " << elapsedTime2.count() << " ms" << endl;
            break;
        default:
            cout << "Intente de nuevo." << endl;
    }

    // Liberar memoria
    delete[] Arr_crlV1;
    delete[] Arr_crlV2;
    system("pause"); 
}

void menuBusqueda() {
    srand(time(0));
    int cantidadDatos[100], cantidadBusquedas[100]; 
    Metodos promedio[100];
    int C = 0, opcion;
    int datos, busquedas;

    do {
    	system("cls");
        cout << "=============================" << endl;
        cout << " Metodos de Busqueda a Comparar " << endl;
        cout << "=============================" << endl << endl;
        cout << "1) Hacer comparacion." << endl
             << "2) Historial." << endl
             << "3) Salir." << endl
             << "= "; cin >> opcion;
        
        system("cls");
        cout << endl;
        switch(opcion) {
            case 1: {
                cout << "Indique la cantidad de datos a buscar: ";
                cin >> cantidadDatos[C];
                cout << "Indique cuantas busquedas simultaneas quiere realizar: ";
                cin >> cantidadBusquedas[C];

                datos = cantidadDatos[C];
                busquedas = cantidadBusquedas[C];

                // Cambiado a arreglos dinámicos
                int* arreglo = new int[datos];
                int* elementoBuscar = new int[busquedas];
                int r[busquedas];
                Metodos* tiempo = new Metodos[busquedas];
				
                clock_t inicio, fin;
                int REPETICIONES = 500000;

                cout << endl;
                for (int i = 0; i < datos; i++) {
                    arreglo[i] = i;
                }
                mezclarArreglo(arreglo, datos);
                
                cout << "Arreglo: ";
                mostrarArreglo(arreglo, datos);
                cout << endl;
				
				shellsort(arreglo, datos);
                for (int i = 0; i < busquedas; i++) {
                    elementoBuscar[i] = rand() % datos;  // Elementos aleatorios a buscar
                    
                    // Búsqueda Binaria
                    inicio = clock();
                    for (int j = 0; j < REPETICIONES; j++) {
                        r[i] = busquedaBinaria(arreglo, datos, elementoBuscar[i]);
                    }
                    fin = clock();
                    tiempo[i].busquedaBinaria = (double(fin - inicio) * 1000 / CLOCKS_PER_SEC) / REPETICIONES;
                    
                    // Búsqueda Exponencial
                    inicio = clock();
                    for (int j = 0; j < REPETICIONES; j++) {
                        r[i] = busquedaExponencial(arreglo, datos, elementoBuscar[i]);
                    }
                    fin = clock();
                    tiempo[i].busquedaExponencial = (double(fin - inicio) * 1000 / CLOCKS_PER_SEC) / REPETICIONES;
                }
                
                // Calcular promedios
               	double sumaTiemposBinaria = 0, sumaTiemposExponencial = 0;
                promedio[C].busquedaExponencial = 0;
                for (int i = 0; i < busquedas; i++) {
                    sumaTiemposBinaria += tiempo[i].busquedaBinaria;
                    sumaTiemposExponencial += tiempo[i].busquedaExponencial;
                }
                promedio[C].busquedaBinaria = sumaTiemposBinaria/busquedas;
                promedio[C].busquedaExponencial = sumaTiemposExponencial/busquedas;
                imprimirComparacion(tiempo, promedio, busquedas, C, datos, busquedas, elementoBuscar, r);
                C++;  // Incrementar C después de la comparación
                
                // Liberar memoria dinámica
                delete[] arreglo;
                delete[] elementoBuscar;
                delete[] tiempo;
                break;
            }
            case 2:
                cout << "HISTORIAL DE COMPARACIONES" << endl << endl;
                for (int i = 0; i < C; i++) {
                    cout << "COMPARACION " << i + 1 << endl;
                    cout << "Datos analizados: " << cantidadDatos[i] << endl;
                    cout << "Busquedas realizadas: " << cantidadBusquedas[i] << endl;
                    cout << "Promedio de busqueda binaria: " << promedio[i].busquedaBinaria << " ms." << endl;
                    cout << "Promedio de busqueda exponencial: " << promedio[i].busquedaExponencial << " ms." << endl;
                    cout << endl;
                }
                break;
            case 3:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
        cout << endl;
        system("pause");
    } while (opcion != 3);
}

