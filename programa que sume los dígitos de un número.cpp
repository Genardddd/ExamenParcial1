#include <stdio.h>

// Programa que suma los d�gitos de un n�mero.

int main(){
	
	int numero, digito, suma=0;
	
	printf("Ingrese una cantidad: ");
	scanf("%d", &numero);
	

	while (numero != 0) {
        digito = numero % 10;
        suma += digito;     
        numero /= 10;  
        }
		
		printf("La suma de los d�gitos es: %d\n", suma);
	
	return 0;
}
