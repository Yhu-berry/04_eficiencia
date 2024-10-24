#include "ordenacion.h"
#include "busqueda.h"
#include <chrono>   //Libreria para medir el tiempo en milisegundos
#include <iomanip>  // Libreria para manipulacion de flujo de salida
#include <cstdlib>  // Libreria necesaria para la funcion rand()
#include <iostream>
using namespace std;

void menudeMain();
void menuOrdenacion(int arr[], int n);
void menuBusqueda(int arr[], int n);

int main() {
    int n;
    cout << "Cantidad de terminos a comparar (maximo 1000000):\t";
    cin >> n;
    cout<<"\n";

    int* arr = new int[n];
    generarArreglo(arr, n);
   
    int opcion;
    do {
        system("CLS"); // Limpia la pantalla
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
                cout << "Intente de nuevo." << endl;
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
    int opcionOrdenacion;
    system("CLS");
    cout << "=============================" << endl;
    cout << " Metodos de Ordenacion a Comparar " << endl;
    cout << "=============================" << endl;
    cout << "1. ShellSort vs QuickSort" << endl;
    cout << "2. QuickSort vs InsercionBinaria" << endl;
    cout << "3. InsercionBinaria vs ShellSort" << endl;
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

void menuBusqueda(int arr[], int n) {
    int opcionBusqueda;
    system("CLS");
    cout << "=============================" << endl;
    cout << " Metodos de Busqueda a Comparar " << endl;
    cout << "=============================" << endl;
    cout << "1. Busqueda Binaria vs Busqueda Secuencial" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcionBusqueda;
    system("CLS");

    int* Arr_crlV = new int[n];
    copiarArr(Arr_crlV, arr, n);
    
    // Ordenar el arreglo antes de realizar las búsquedas
    shellsort(Arr_crlV, n);

    // Mostrar el arreglo ordenado
    cout << "Arreglo ordenado: ";
    imprimirArr(Arr_crlV, n);

    // Variables para medir el tiempo
    chrono::steady_clock::time_point start, end;
    chrono::duration<double, milli> elapsedTime1, elapsedTime2;

    if (opcionBusqueda == 1) {
        int dato;
        cout << "Ingrese el dato a buscar: ";
        cin >> dato;
        // Comparación Búsqueda Binaria
        start = chrono::steady_clock::now();
        int resultadoBinaria = BusquedaBinaria(Arr_crlV, n, dato);
        end = chrono::steady_clock::now();
        elapsedTime1 = end - start;
        cout << "Busqueda Binaria: " << elapsedTime1.count() <<"ms, Posicion: "<<resultadoBinaria<<endl;
        
        // Comparación Búsqueda Secuencial
        start = chrono::steady_clock::now();
        int resultadoSecuencial = SecuencialOrd(Arr_crlV, n, dato);
        end = chrono::steady_clock::now();
        elapsedTime2 = end - start;
        cout << "Busqueda Secuencial: " << elapsedTime2.count()<< "ms, Posicion: "<<resultadoSecuencial<<endl;
    } else {
        cout << "Opcion no valida." << endl;
    }

    delete[] Arr_crlV;
    system("pause"); // Pausa para que el usuario pueda ver lo
}

