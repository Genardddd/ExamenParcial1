//Genaro Bermudez| ID: 179588
//Multiplos de 3

#include <stdio.h>

int main() {
    int numero;

    printf("Ingrese un numero del 0 al 100: ");
    scanf("%d", &numero);

    while (numero>=0 && numero<=100 && numero%3== 0) {
        printf("Es multiplo de 3\n");
        printf("Ingrese otro numero: ");
        scanf("%d", &numero);
    }

    printf("No es multiplo de 3 o el numero esta fuera del rango.\n");

    return 0;
}

