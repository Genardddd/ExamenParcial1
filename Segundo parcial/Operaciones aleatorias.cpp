//Genaro Bermudez| ID: 179588
//Operaciones aleatorias

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int opcion;
    do { 
        opcion= rand()%5+1;

        int num1= rand()%100; 
        int num2= rand()%100; 

        int resultado;

        switch (opcion) {
            case 1:
                resultado= num1+num2;
                printf("Suma de %d mas %d es: %d\n", num1, num2, resultado);
                break;
                
            case 2:
                resultado= num1-num2;
                printf("Resta de %d menos %d es: %d\n", num1, num2, resultado);
                break;
                
            case 3:
                resultado= num1*num2;
                printf("Multiplicacion de %d por %d es: %d\n", num1, num2, resultado);
                break;
                
            case 4:
                if (num2 != 0) {
                    resultado= num1/num2;
                    printf("Division de %d entre %d es: %d\n", num1, num2, resultado);
                } else {
                    printf("Indefinido");
                }
                break;
                
            case 5:
                printf("Programa terminado.\n");
                break;
                
            default:
                printf("Opción no válida.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}

