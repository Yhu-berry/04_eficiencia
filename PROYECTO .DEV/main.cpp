#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Metodos {
    double busquedaExponencial;
    double busquedaBinaria;
};

int busquedaBinaria(int a[], int n, int dato) {

    int izq=0;
    int der=n-1;
    int cen=0, m, pos;
    while(izq<=der && cen==0) {
        m=(izq+der)/2;
        if(a[m]==dato) {
            cen=1;
        } else if(a[m]<dato) {
            izq=m+1;
        } else {
            der=m-1;
        }
    }
    if(cen==1) {
        pos=m;
    } else {
        pos=-izq;
    }
    return pos;
}

int busquedaExponencial(int a[], int n, int x){
	return 1;
}

void imprimirComparacion(Metodos tiempo[], Metodos promedio[], int n, int c, int datos, int busquedas, int elementoBuscar[]){
	
	cout << "C O M P A R A C I O N    " << c+1 << endl
		<< "Elemento a buscar: Aletorio por busqueda." << endl
		<< "Arreglo: Sin repetir, aleatorio." << endl 
		<< "Total de datos: " << datos << endl
		<< "Total de busquedas: " << busquedas << endl << endl;
		
		cout << "\tBUSQUEDA BINARIA" << "\t\t\t" << "BUSQUEDA EXPONENCIAL" << endl << endl;
		
 	for(int i=0; i<n; i++){
		cout << "--> Busqueda " << i+1 << " (" << elementoBuscar[i] << "): " << tiempo[i].busquedaBinaria << " ms" << "\t\t\t"  << tiempo[i].busquedaExponencial << " ms" << endl;
	}
	cout << "\tPromedio: " << promedio[c].busquedaBinaria << "\t\t\t" << "Promedio: " << promedio[c].busquedaExponencial << endl;
}

void mostrarArreglo(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}


int main(){

    srand(time(0));
    int cantidadDatos[100], cantidadBusquedas[100]; 
	Metodos promedio[100];
    int C=0, opcion;
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
    			case 1: {
    				//se piden los datos
    				cout << "Indique la cantidad de datos a buscar: ";
				    cin >> cantidadDatos[C];
				    cout << "Indique cuantas busquedas simultaneas quiere realizar: ";
				    cin >> cantidadBusquedas[C];
				    
				    datos = cantidadDatos[C];
				    busquedas = cantidadBusquedas[C];
				    int* arreglo = new int[datos];
	                int* elementoBuscar = new int[busquedas];
	                Metodos* tiempo = new Metodos[busquedas];
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
					cout << endl << "Fin de la impresión de comparación." << endl;
					C++;
					
					delete[] arreglo;
	                delete[] elementoBuscar;
	                delete[] tiempo;
	            	break;
	            }
    			case 2:
    				if(C==0){
    					cout << "HISTORIAL DE COMPARACIONES" << endl << endl;
		                for (int i = 0; i < C; i++) {
		                    cout << "COMPARACION " << i+1 << endl;
		                    cout << "Datos analizados: " << cantidadDatos[i] << endl;
		                    cout << "Busquedas realizadas: " << cantidadBusquedas[i] << endl;
		                    cout << "Promedio de busqueda binaria: " << promedio[i].busquedaBinaria << " ms." << endl;
		                    cout << "Promedio de busqueda exponencial: " << promedio[i].busquedaExponencial << " ms." << endl;
		                    cout << endl;
		                }
					} else {
						cout << "No hay comparaciones registradas." << endl;
					}
    			
    				break;
    			case 3:
    				cout << "Saliendo del programa." << endl;
    				break;
    			default:
    				cout << "No valido." << endl;
    				break;
			}
	        system("pause");
	    } while(opcion!=3);
	    
	    return 0;
}
