//Genaro Bermudez| ID: 179588
//Mitad de pir�mide de n�meros

#include <stdio.h>

int main() {
    int i, j, lineas;

    printf("N�mero de l�neas en la pir�mide (0-50): ");
    scanf("%d", &lineas);

    if (lineas<0 || lineas>50) {
        printf("El n�mero de l�neas debe estar en el rango de 0 a 50.\n");
        return 1; 
    }

    for (i = 1; i <= lineas; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}

