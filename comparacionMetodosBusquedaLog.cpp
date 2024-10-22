#include <iostream>
#include <cstdlib>
#include <ctime>
#include "include/busqueda.h"
#include "include/utilidades.h"

using namespace std;

int main(){

    srand(time(0));
    int cantidadDatos, cantidadBusquedas;
    cout << "Indique la cantidad de datos a buscar: ";
    cin >> cantidadDatos;
    cout << "Indique cuantas busquedas simultaneas quiere realizar: ";
    cin >> cantidadBusquedas;

    int arreglo[cantidadDatos], b=0, elementoBuscar[cantidadBusquedas];
    char opcion;
    double tiempoBinaria[cantidadBusquedas];

    cout << endl;
    do{
        cout << "A) Arreglo sin repetir (no aplica ordenacion)" << endl
            << "B) Arreglo aleatorio (se repite, necesita ordenacion)" << endl  
            << "C) Salir" << endl
            << "= "; cin >> opcion;
        system("cls");

        clock_t inicio, fin;
		int REPETICIONES=50000, r;

        switch(opcion){
            case 'A': {
                // Lógica para generar un arreglo sin números repetidos
                for (int i = 0; i < cantidadDatos; i++) {
                    arreglo[i] = i;  // Inicializamos con números consecutivos
                }

				//Se muestra el arreglo
                cout << "Arreglo: "; 
                mostrarArreglo(arreglo, cantidadDatos); 
                cout << endl;

				//hallar el tiempo que tarda en hacer esa unica busqueda
                for(int i=0; i<cantidadBusquedas; i++){
                    elementoBuscar[b] = rand() % cantidadDatos;
                    inicio = clock();
                        for(int i=0; i<REPETICIONES; i++){
                            r = busquedaBinaria(arreglo, cantidadDatos, elementoBuscar[b]);
                        }
                    fin = clock();
                    tiempoBinaria[b] = (double(fin - inicio) * 1000 / CLOCKS_PER_SEC)/REPETICIONES;
                    b++;
                }


				//Imprime el tiempo que tarda
                for(int i=0; i<cantidadBusquedas; i++){
                    cout << "Tiempo de busqueda "<< i+1 << "("<< elementoBuscar[i] << "): " << tiempoBinaria[i] << endl;
                }
                break;
            }
			case 'B':{
                // Lógica para generar un arreglo aleatorio
                /*
				elementoBuscar = rand() % 100;
                for (int i = 0; i < cantidadDatos; i++) {
                    arreglo[i] = rand() % 100;
                }

                cout << "Arreglo: "; 
                mostrarArreglo(arreglo, cantidadDatos); 
                cout << endl;

                inicio = clock();
				for(int i=0; i<REPETICIONES; i++){
					r = busquedaBinaria(arreglo, cantidadDatos, elementoBuscar);
				}
                
                fin = clock();

                double tiempo = (double(fin - inicio) * 1000 / CLOCKS_PER_SEC)/REPETICIONES;
                cout << "Tiempo (" << elementoBuscar << "): ";
                if (r < 0) {
                    cout << "No encontrado." << endl;
                } else {
                    cout << tiempo << " ms" << endl;
                }
                break;
            }
            */
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