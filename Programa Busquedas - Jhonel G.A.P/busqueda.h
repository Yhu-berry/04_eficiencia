#ifndef BUSQUEDA_H
#define BUSQUEDA_H

struct Metodos {
    double busquedaExponencial;
    double busquedaBinaria;
};

//Busqueda Secuencial 
int SecuencialOrd(int* Arr_crlV, int n, int dato);
//Busqueda Bianria (Requiere una funcion para ordenarlo)
int busquedaBinaria(int a[], int n, int dato);

int busquedaExponencial(int a[], int n, int x);
#endif 
