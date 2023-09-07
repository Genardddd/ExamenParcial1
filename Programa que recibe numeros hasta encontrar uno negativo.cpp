#include <stdio.h>

//Programa que recibe números hasta encontrar uno negativo.

int main() {	

	int a;

	printf("Ingrese un numero natural: ");
	
	if (scanf("%d", &a)!=1){
		printf("Entrada no valida. Debe ingresar un numero.\n\a");
    	return 1;
		}
		
		while (a>=0){
		printf("Ingrese otro numero natural: "); 
		if (scanf("%d", &a) != 1) {
            printf("Entrada no valida. Debe ingresar un numero.\n\a");
            return 1;
			}
		}
		
		printf("Este numero es un negativo, no es valido\a");

return 0;
}
