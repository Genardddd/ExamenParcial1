//Genaro Bermudez| ID: 179588
//Año bisiesto

#include <stdio.h>

int main() {
    int a;

    printf("Introduzca un año: ");
    scanf("%d", &a);

    while ((a%4==0 && a%100 != 0) || a%400==0) {
        printf("Es bisiesto\n");
        printf("Introduzca otro año: ");
        scanf("%d", &a);
    }

    printf("No es bisiesto\n");

    return 0;
}
 
