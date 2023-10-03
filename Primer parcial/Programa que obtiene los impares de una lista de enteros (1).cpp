#include <stdio.h>

//Programa que obtiene los impares de una lista de enteros
//Genaro Bermudez. 179588

int main(){
	
	int numero;
    int impares = 0;

    printf("Ingrese los numeros uno por uno (ingrese 0 para finalizar):\n");

    while (true) {
        scanf("%d", &numero);

        if (numero == 0) {
            break;
        }

        if (numero % 2 != 0) {
            printf("%d es impar.\n", numero);
            impares++;
        }
    }

    if (impares == 0) {
        printf("No se ingresaron numeros impares.\n\a");
    }
    
	return 0;
}
