#include "utilidades.h"
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
	menuBusqueda();	
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
                arrSucesivo(arreglo, datos);
                mezclarArreglo(arreglo, datos);
                
                cout << "Arreglo: ";
                imprimirArr(arreglo, datos);
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
			        
			        cout << "Promedio de busqueda binaria: ";
			        if (promedio[i].busquedaBinaria > promedio[i].busquedaExponencial) {
			            color(hConsole, 4);
			        } else if (promedio[i].busquedaBinaria < promedio[i].busquedaExponencial) {
			            color(hConsole, 10);
			        }
			        cout << promedio[i].busquedaBinaria << " ms" << endl;
			        
			        color(hConsole, 7); // Reset color
			        
			        cout << "Promedio de busqueda exponencial: ";
			        if (promedio[i].busquedaExponencial > promedio[i].busquedaBinaria) {
			            color(hConsole, 4);
			        } else if (promedio[i].busquedaExponencial < promedio[i].busquedaBinaria) {
			            color(hConsole, 10);
			        }
			        cout << promedio[i].busquedaExponencial << " ms" << endl;
		        
			        color(hConsole, 7); // Reset color
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

