#include <stdio.h>

//Programa que imprime los 10 números siguientes a partir del que eliges.
//Genaro Bermudez. 179588

int main() {

int numero;
int contador=0;

printf("¿A partir de que numero quieres contar?\n");
scanf("%d", &numero);

printf("Los 10 numeros siguientes a %d son\n", numero);

while (contador<11){
	printf("%d\n", numero);
	numero++;
	contador++;
}

return 0;
}

