#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funcion shellsort 
int shellsort(int A[], int n);

int main(){
    int num, Arr[100000];   
    cout << "Ingrese la cantidad de elementos: ";
    cin >> num;

    // Funcion que genera elementos aleatoriamente
    srand(time(0));
    for (int i = 0; i < num; i++) {
        Arr[i] = rand() % 1000;  // Números aleatorios entre 0 y 999
    }

    // Mostrar elementos generados
    cout << "Elementos generados: ";
    for (int i = 0; i < num; i++) {
        cout << Arr[i] << " ";
    }
    cout << endl <<endl;
    // Contar el tiempo empleado de la funcion shellsort
    clock_t start = clock();
    shellsort(Arr, num);
    clock_t end = clock();

    cout<<"Arreglo Ordenado usando ShellSort:";
    for(int i=0;i<num;i++){
        cout<<Arr[i]<<" ";
    }

    cout<<endl;
    cout<<"Tiempo empleaddo de la funcion ShellSort: "<< shellsort<<endl;
    return 0;
}

// Implementacion de shellsort
int shellsort(int A[], int n) {
    for (int k = n / 2; k > 0; k /= 2) {
        for (int i = k; i < n; i++) {
            int aux = A[i];
            int j;
            for (j = i; j >= k && A[j - k] > aux; j -= k) {
                A[j] = A[j - k];
            }
            A[j] = aux;
        }
    }
    return 0;
}