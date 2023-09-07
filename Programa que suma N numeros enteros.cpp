#include <stdio.h>

//Programa que suma N números enteros.
//Genaro Bermudez. 179588

int main() {	
int n;
int suma=0;
int i=1;

printf("Ingrese un numero entero N: ");
scanf("%d",&n);

if(n<=0){
printf("Por favor, ingrese un numero entero positivo.\n");	
} else{
	while (i<=n){
	suma +=i;
	i++;
}
printf("La suma de los enteros desde 1 hasta %d es: %d\n", n, suma);
}
return 0;
}
