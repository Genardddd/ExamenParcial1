//Genaro Bermudez| ID: 179588
//Detectar los errores en el programa (Este programa ya funciona)

#include <stdio.h>

int main(){
	int n1, n2, resultado, suma;

printf("Introduzca un numero: ");
scanf("%d", &n1);

printf("\nIntroduzca otro numero: ");
scanf("%d", &n2);

printf("\nCuanto suman?: ");
scanf("%d",&suma);

resultado= n1+n2;

if (suma==resultado)
	{printf("\nCORRECTO");
	}else{
		printf("\nINCORRECTO: La suma es %d", resultado);
	}
	return 0;
}
