#include "utilidades.h"
#include "ordenacion.h"
#include "busqueda.h"
#include <iostream>

using namespace std;

void menudeMain();
void menuOrdenacion(int arr[], int n);

void menuBusqueda(int arr[], int n);

int main() {
    int n;
    cout << "Cantidad de terminos a comparar (máximo 1000000):\t";
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
                cout << "Opción no válida. Intente de nuevo." << endl;
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
    cout << "=============================" << endl;
    cout << " Metodos de Busqueda a Comparar " << endl;
    cout << "=============================" << endl;
    cout << "1. Busqueda Binaria vs Busqueda Secuencial" << endl;
    cout << "Seleccione una opcion: ";
    int opcionBusqueda;
    cin >> opcionBusqueda;

    switch (opcionBusqueda) {
        case 1:
            // Llamar a las funciones correspondientes para la comparación de búsqueda
            break;
        default:
            cout << "Intente de nuevo." << endl;
    }
}
