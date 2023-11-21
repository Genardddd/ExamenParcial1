//Genaro Bermudez |ID:179588

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Búsqueda secuencial
int busquedaSecuencial(int arr[], int n, int clave) {
    for (int i= 0; i<n; ++i) {
        if (arr[i]==clave) {
            return i;
        }
    }
    return -1;
}

//Búsqueda binaria
int busquedaBinaria(int arr[], int inicio, int fin, int clave) {
    while (inicio<=fin) {
        int medio= inicio+(fin-inicio)/2;

        if (arr[medio]==clave) {
            return medio;
        }

        if (arr[medio] < clave) {
            inicio= medio+1;
        } else {
            fin= medio-1;
        }
    }
    return -1;
}

void imprimirArreglo(int arr[], int n) {
    for (int i= 0; i<n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generarArregloOrdenado(int arr[], int n) {
    for (int i= 0; i<n; ++i) {
        arr[i]= i*2;
    }
}

double medirTiempoBusqueda(int arr[], int n, int clave, int tipoBusqueda) {
    clock_t tic= clock();

    if (tipoBusqueda==0) {
        busquedaSecuencial(arr, n, clave);
    } else {
        busquedaBinaria(arr, 0, n-1, clave);
    }

    clock_t toc= clock();
    return ((double)(toc-tic))*1000.0 / CLOCKS_PER_SEC;
}

int main() {
    const int tamanoArreglo= 50000;
    const int ejecuciones= 100;

    int arreglo[tamanoArreglo];

    srand(time(NULL));

    //Ejecuciones para búsqueda secuencial
    double tiemposSecuencial[ejecuciones];
    double tiempoPromedioSecuencial= 0.0;
    double tiempoMinimoSecuencial= -1.0;
    double tiempoMaximoSecuencial= -1.0;

    for (int i= 0; i<ejecuciones; ++i) {
        int clave = rand()%tamanoArreglo;
        generarArregloOrdenado(arreglo, tamanoArreglo);
        tiemposSecuencial[i]= medirTiempoBusqueda(arreglo, tamanoArreglo, clave, 0);

        tiempoPromedioSecuencial+=tiemposSecuencial[i];

        if (tiempoMinimoSecuencial==-1.0 || tiemposSecuencial[i]<tiempoMinimoSecuencial) {
            tiempoMinimoSecuencial= tiemposSecuencial[i];
        }

        if (tiempoMaximoSecuencial==-1.0 || tiemposSecuencial[i]>tiempoMaximoSecuencial) {
            tiempoMaximoSecuencial= tiemposSecuencial[i];
        }
    }

    tiempoPromedioSecuencial /= ejecuciones;

    //Ejecuciones para búsqueda binaria
    double tiemposBinaria[ejecuciones];
    double tiempoPromedioBinaria= 0.0;
    double tiempoMinimoBinaria= -1.0;
    double tiempoMaximoBinaria= -1.0;

    for (int i= 0; i<ejecuciones; ++i) {
        int clave= rand()%tamanoArreglo;
        generarArregloOrdenado(arreglo, tamanoArreglo);
        tiemposBinaria[i]= medirTiempoBusqueda(arreglo, tamanoArreglo, clave, 1);

        tiempoPromedioBinaria+=tiemposBinaria[i];

        if (tiempoMinimoBinaria== -1.0 || tiemposBinaria[i]<tiempoMinimoBinaria) {
            tiempoMinimoBinaria= tiemposBinaria[i];
        }

        if (tiempoMaximoBinaria== -1.0 || tiemposBinaria[i]>tiempoMaximoBinaria) {
            tiempoMaximoBinaria= tiemposBinaria[i];
        }
    }

    tiempoPromedioBinaria /= ejecuciones;

    // Mostrar estadísticas para búsqueda secuencial
    printf("Estadisticas para busqueda secuencial:\n");
    printf("Tiempo promedio: %.2f milisegundos\n", tiempoPromedioSecuencial);
    printf("Tiempo minimo: %.2f milisegundos\n", tiempoMinimoSecuencial);
    printf("Tiempo maximo: %.2f milisegundos\n", tiempoMaximoSecuencial);

    // Mostrar estadísticas para búsqueda binaria
    printf("\nEstadisticas para busqueda binaria:\n");
    printf("Tiempo promedio: %.2f milisegundos\n", tiempoPromedioBinaria);
    printf("Tiempo minimo: %.2f milisegundos\n", tiempoMinimoBinaria);
    printf("Tiempo maximo: %.2f milisegundos\n", tiempoMaximoBinaria);

    return 0;
}

