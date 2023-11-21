//Genaro Bermudez |ID:179588

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void llenarMatriz(int matriz[30][30]) {
    for (int i= 0; i<30; ++i) {
        for (int j= 0; j<30; ++j) {
            matriz[i][j]= rand()%10;
        }
    }
}

void imprimirMatriz(int matriz[30][30]) {
    for (int i= 0; i<30; ++i) {
        for (int j= 0; j<30; ++j) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void multiplicarMatrices(int matriz1[30][30], int matriz2[30][30], int resultado[30][30]) {
    for (int i= 0; i<30; ++i) {
        for (int j= 0; j<30; ++j) {
            resultado[i][j]= 0;
            for (int k=0; k<30; ++k) {
                resultado[i][j]+=matriz1[i][k]*matriz2[k][j];
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int matrizA[30][30];
    int matrizB[30][30];
    int resultado[30][30];

    llenarMatriz(matrizA);
    llenarMatriz(matrizB);

    printf("Matriz A:\n");
    imprimirMatriz(matrizA);

    printf("\nMatriz B:\n");
    imprimirMatriz(matrizB);

    // Medir el tiempo de ejecución
    clock_t tic= clock();

    multiplicarMatrices(matrizA, matrizB, resultado);

    clock_t toc= clock();
    double elapsed_time = ((double) (toc-tic))*1000.0/ CLOCKS_PER_SEC;

    printf("\nResultado de la multiplicacion:\n");
    imprimirMatriz(resultado);

    printf("\nTiempo de ejecucion: %.2f milisegundos\n", elapsed_time);

    return 0;
}

