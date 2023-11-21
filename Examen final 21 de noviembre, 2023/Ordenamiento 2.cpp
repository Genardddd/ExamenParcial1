//Genaro Bermudez|ID:179588

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int size) {
    for (int i= 0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i= 1; i<size; i++) {
        int temporal= arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>temporal) {
            arr[j+1]= arr[j];
            j= j-1;
        }
        arr[j+1]= temporal;
    }
}

//Quick Sort
int partition(int arr[], int low, int high) {
    int pivote= arr[high];
    int i= (low-1);
    for (int j= low; j<=high-1; j++) {
        if (arr[j]<pivote) {
            i++;
            int temp= arr[i];
            arr[i]= arr[j];
            arr[j]= temp;
        }
    }
    int temp= arr[i+1];
    arr[i+1]= arr[high];
    arr[high]= temp;
    return (i+1);
}

void quickSort(int arr[], int low, int high) {
    if (low<high) {
        int pi= partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

//Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i= 0; i<size-1; i++) {
        for (int j = 0; j<size-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                int temp= arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
}

int main() {
    const int arraySize= 10000;
    const int numEjecuciones= 100;
    clock_t start, end;
    double cpu_time_usado;

    int originalArray[arraySize];
    for (int i= 0; i<arraySize; i++) {
        originalArray[i]= rand();
    }

    // Ejecutar Insertion Sort
    printf("Insertion Sort:\n");
    double insertionTimes[numEjecuciones];
    for (int i= 0; i<numEjecuciones; i++) {
        int arr[arraySize];
        for (int j= 0; j<arraySize; j++) {
            arr[j]= originalArray[j];
        }

        start= clock();
        insertionSort(arr, arraySize);
        end= clock();

        cpu_time_usado= ((double)(end-start)) / CLOCKS_PER_SEC * 1000;
        insertionTimes[i]= cpu_time_usado;
    }

    // Calcular estadísticas de Insertion Sort
    double insertionSum= 0, insertionMin= insertionTimes[0], insertionMax= insertionTimes[0];
    for (int i= 0; i<numEjecuciones; i++) {
        insertionSum+=insertionTimes[i];
        if (insertionTimes[i]<insertionMin) {
            insertionMin= insertionTimes[i];
        }
        if (insertionTimes[i]>insertionMax) {
            insertionMax= insertionTimes[i];
        }
    }
    printf("Promedio: %f milisegundos\n", insertionSum / numEjecuciones);
    printf("Minimo: %f milisegundos\n", insertionMin);
    printf("Maximo: %f milisegundos\n\n", insertionMax);

    // Ejecutar Quick Sort
    printf("Quick Sort:\n");
    double quickTimes[numEjecuciones];
    for (int i= 0; i<numEjecuciones; i++) {
        int arr[arraySize];
        for (int j= 0; j<arraySize; j++) {
            arr[j]= originalArray[j];
        }

        start= clock();
        quickSort(arr, 0, arraySize-1);
        end= clock();

        cpu_time_usado= ((double)(end-start)) / CLOCKS_PER_SEC * 1000;
        quickTimes[i]= cpu_time_usado;
    }

    // Calcular estadísticas de Quick Sort
    double quickSum= 0, quickMin= quickTimes[0], quickMax= quickTimes[0];
    for (int i= 0; i<numEjecuciones; i++) {
        quickSum+=quickTimes[i];
        if (quickTimes[i]<quickMin) {
            quickMin= quickTimes[i];
        }
        if (quickTimes[i]>quickMax) {
            quickMax= quickTimes[i];
        }
    }
    printf("Promedio: %f milisegundos\n", quickSum / numEjecuciones);
    printf("Minimo: %f milisegundos\n", quickMin);
    printf("Maximo: %f milisegundos\n\n", quickMax);

    // Ejecutar Bubble Sort
    printf("Bubble Sort:\n");
    double bubbleTimes[numEjecuciones];
    for (int i= 0; i<numEjecuciones; i++) {
        int arr[arraySize];
        for (int j= 0; j<arraySize; j++) {
            arr[j]= originalArray[j];
        }

        start= clock();
        bubbleSort(arr, arraySize);
        end= clock();

        cpu_time_usado= ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        bubbleTimes[i]= cpu_time_usado;
    }

    // Calcular estadísticas de Bubble Sort
    double bubbleSum= 0, bubbleMin = bubbleTimes[0], bubbleMax = bubbleTimes[0];
    for (int i= 0; i<numEjecuciones; i++) {
        bubbleSum+=bubbleTimes[i];
        if (bubbleTimes[i]<bubbleMin) {
            bubbleMin= bubbleTimes[i];
        }
        if (bubbleTimes[i]>bubbleMax) {
            bubbleMax= bubbleTimes[i];
        }
    }
    printf("Promedio: %f milisegundos\n", bubbleSum / numEjecuciones);
    printf("Minimo: %f milisegundos\n", bubbleMin);
    printf("Maximo: %f milisegundos\n\n", bubbleMax);

    return 0;
}

