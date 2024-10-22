#include <iostream>
#include <cstdlib>
#include <ctime>
#include "include/busqueda.h"
#include "include/utilidades.h"

using namespace std;

int main(){

    srand(time(0));
    int cantidadDatos, elementoBuscar;
    cout << "Indique la cantidad de datos a buscar: ";
    cin >> cantidadDatos;
    
    int arreglo[cantidadDatos];

    elementoBuscar = rand() % cantidadDatos;

    char opcion;
    cout << endl;
    
    do{
        cout << "A) Arreglo sin repetir (no aplica ordenacion)" << endl
            << "B) Arreglo aleatorio (se repite, necesita ordenacion)" << endl  
            << "C) Salir" << endl;
        cout << "= "; cin >> opcion;
        
        system("cls");
        clock_t inicio, fin;
        switch(opcion){
            case 'A': {
                // Lógica para generar un arreglo sin números repetidos
                for (int i = 0; i < cantidadDatos; i++) {
                    arreglo[i] = i;  // Inicializamos con números consecutivos
                }

                cout << "Arreglo: "; 
                mostrarArreglo(arreglo, cantidadDatos); 
                cout << endl;

                inicio = clock();
                int r = busquedaBinaria(arreglo, cantidadDatos, elementoBuscar);
                fin = clock();

                double tiempo = (double(fin - inicio) * 1000 / CLOCKS_PER_SEC);
                cout << "Tiempo (" << elementoBuscar << "): ";
                if (r < 0) {
                    cout << "No encontrado." << endl;
                } else {
                    cout << tiempo << " ms" << endl;
                }
                break;
            }
            case 'C':{
                
                break;
            }
            default:{
                
                break;
            }
        }
    } while(opcion!='C');
    

    
    return 0;
}