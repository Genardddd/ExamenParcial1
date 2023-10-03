#include <stdio.h>

//Programa que suma los digitos de un numero.
//Genaro Bermudez. 179588

int main(){
	
	int numero, digito, suma=0;
	
	printf("Ingrese una cantidad: ");
	scanf("%d", &numero);
	

	while (numero != 0) {
        digito = numero % 10;
        suma += digito;     
        numero /= 10;  
        }
		
		printf("La suma de los digitos es: %d\n", suma);
	
	return 0;
}
