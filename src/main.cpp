#include "../include/utilidades.h"
#include "../include/ordenacion.h"
#include "../include/busqueda.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void menudeMain();
void menuOrdenacion(int arr[], int n);

void menuBusqueda(int arr[], int n);

int main() {
    int n;
    cout << "Cantidad de terminos a comparar (mÃ¡ximo 1000000):\t";
    cin >> n;
    cout<<"\n";
    int* arr = new int[n];
    generarArreglo(arr, n);
    cout << "Arreglo generado: ";
    imprimirArr(arr, n);

    int opcion;
    do {
        menudeMain();
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuOrdenacion(arr, n);
                break;
            case 2:
                menuBusqueda(arr, n);
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "OpciÃ³n no vÃ¡lida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);

    delete[] arr;
    return 0;
}

void menudeMain() {
    cout << "=============================" << endl;
    cout << " Menu de Comparacion " << endl;
    cout << "=============================" << endl;
    cout << "1. Comparar Metodos de Ordenacion" << endl;
    cout << "2. Comparar Metodos de Busqueda" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void menuOrdenacion(int arr[], int n) {
    cout << "=============================" << endl;
    cout << " Metodos de Ordenacion a Comparar " << endl;
    cout << "=============================" << endl;
    cout << "1. ShellSort vs QuickSort" << endl;
    cout << "2. QuickSort vs InsercionBinaria" << endl;
    cout << "3. InsercionBinaria vs ShellSort" << endl;
    cout << "Seleccione una opcion: ";
    int opcionOrdenacion;
    cin >> opcionOrdenacion;

    int* Arr_crlV = new int[n];
    copiarArr(Arr_crlV, arr, n);

    switch (opcionOrdenacion) {
        case 1:
            shellsort(Arr_crlV, n);
            cout << "Arreglo ordenado (ShellSort): ";
            imprimirArr(Arr_crlV, n);
            break;
        case 2:
            // QuickSort(arrCopia, n);
            // cout << "Arreglo ordenado (QuickSort): ";
            // imprimirArr(arrCopia, n);
            break;
        case 3:
            // InsercionBinaria(arrCopia, n);
            // cout << "Arreglo ordenado (InsercionBinaria): ";
            // imprimirArr(arrCopia, n);
            break;
        default:
            cout << "Intente de nuevo." << endl;
    }

    delete[] Arr_crlV;
}

void menuBusqueda(int arr[], int n) {

    srand(time(0));
    int cantidadDatos[100], cantidadBusquedas[100]; 
	Metodos promedio[100];
    int C=0;
    char opcion;
    int datos, busquedas;
    do{
    	cout << "=============================" << endl;
	    cout << " Metodos de Busqueda a Comparar " << endl;
	    cout << "=============================" << endl << endl;
    	cout << "1) Hacer comparacion." << endl
    		<< "2) Historial." << endl
    		<< "3) Salir." << endl
    		<< "= "; cin >> opcion;
    		
    		system("cls");
    		cout << endl;
    		
    		switch(opcion){
    			case '1': {
    				//se piden los datos
    				cout << "Indique la cantidad de datos a buscar: ";
				    cin >> cantidadDatos[C];
				    cout << "Indique cuantas busquedas simultaneas quiere realizar: ";
				    cin >> cantidadBusquedas[C];
				    
				    datos = cantidadDatos[C];
				    busquedas = cantidadBusquedas[C];
				    int arreglo[datos], elementoBuscar[busquedas];
				    Metodos tiempo[busquedas];
				    clock_t inicio, fin;
				    int REPETICIONES=500000;
	
					cout << endl;
		            // Lógica para generar un arreglo sin números repetidos
		            for (int i = 0; i < datos; i++) {
		                arreglo[i] = i;
		            }
		
		            //Se muestra el arreglo
		            cout << "Arreglo: ";
		            mostrarArreglo(arreglo, datos);
		            cout << endl;
		
		            //Hallar el tiempo por busqueda establecida
		            for(int i=0; i<busquedas; i++) {
		                elementoBuscar[i] = rand() % datos;
		                
		                //Busqueda Binaria
		                inicio = clock();
		                for(int j=0; j<REPETICIONES; j++) {
		                    busquedaBinaria(arreglo, datos, elementoBuscar[j]);
		                }
		                fin = clock();
		                tiempo[i].busquedaBinaria = (double(fin - inicio) * 1000 / CLOCKS_PER_SEC)/REPETICIONES;
		                
		                //Busqueda Exponencial
		                inicio = clock();
		                for(int j=0; j<REPETICIONES; j++) {
		                    busquedaExponencial(arreglo, datos, elementoBuscar[j]);
		                }
		                fin = clock();
		                tiempo[i].busquedaExponencial = (double(fin - inicio) * 1000 / CLOCKS_PER_SEC)/REPETICIONES;
		            }
		            
		            //Hallar promedio
		            promedio[C].busquedaBinaria = 0;
		            promedio[C].busquedaExponencial = 0;
		            for(int i=0; i<busquedas; i++){
		            	promedio[C].busquedaBinaria += tiempo[i].busquedaBinaria;
		            	promedio[C].busquedaExponencial += tiempo[i].busquedaExponencial;
					}
					
					imprimirComparacion(tiempo, promedio, busquedas, C, datos, busquedas, elementoBuscar);
	            	break;
	            }
    			case '2':
    				cout << "HISTORIAL DE COMPARACIONES" << endl << endl;
	                for (int i = 0; i < C; i++) {
	                    cout << "COMPARACION " << i+1 << endl;
	                    cout << "Datos analizados: " << cantidadDatos[i] << endl;
	                    cout << "Busquedas realizadas: " << cantidadBusquedas[i] << endl;
	                    cout << "Promedio de busqueda binaria: " << promedio[i].busquedaBinaria << " ms." << endl;
	                    cout << "Promedio de busqueda exponencial: " << promedio[i].busquedaExponencial << " ms." << endl;
	                    cout << endl;
	                }
    				break;
    			case '3':
    				cout << "Saliendo del programa." << endl;
    				break;
    			default:
    				cout << "No valido." << endl;
    				break;
			}
	        system("pause");
	    } while(opcion!='3');
}
