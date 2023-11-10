//Genaro Bermúdez Itriago
//ID: 179588

#include <stdio.h>

int main() {
    // Define el nombre del archivo CSV y el ID proporcionado por el usuario.
    const char* archivoCSV = "emails.csv";
    const int IDUsuario = 179588;
    char nombreArchivoSalida[20];
    sprintf(nombreArchivoSalida, "%d.txt", IDUsuario);

    // Abre el archivo CSV para lectura.
    FILE* archivoCSVPtr = fopen(archivoCSV, "r");
    if (archivoCSVPtr == NULL) {
        printf("Error: No se pudo abrir el archivo CSV.\n");
        return 1;
    }

    // Abre el archivo de salida para escritura.
    FILE* archivoSalidaPtr = fopen(nombreArchivoSalida, "w");
    if (archivoSalidaPtr == NULL) {
        printf("Error: No se pudo abrir el archivo de salida.\n");
        fclose(archivoCSVPtr);
        return 1;
    }

    char lineaUsuario[10000];
    printf("Ingrese el numero de linea de inicio (1-5172): ");
    int lineaInicio;
    scanf("%d", &lineaInicio);

    for (int i = 1; i < lineaInicio; i++) {
        if (fgets(lineaUsuario, sizeof(lineaUsuario), archivoCSVPtr) == NULL) {
            printf("Error: Linea de inicio fuera de rango.\n");
            fclose(archivoCSVPtr);
            fclose(archivoSalidaPtr);
            return 1;
        }
    }

    int conteoPalabras[3000] = {0};
    char palabra[100];
    int cantidad;

    // Leer las palabras y contar la cantidad.
    if (fgets(lineaUsuario, sizeof(lineaUsuario), archivoCSVPtr) != NULL) {
        int i = 0;
        int indice = 0;
        while (lineaUsuario[i] != '\0') {

            while (lineaUsuario[i] == ' ' || lineaUsuario[i] == ',') {
                i++;
            }

            int j = 0;
            while (lineaUsuario[i] != ' ' && lineaUsuario[i] != ',') {
                palabra[j++] = lineaUsuario[i++];
            }
            palabra[j] = '\0';

            while (lineaUsuario[i] == ' ' || lineaUsuario[i] == ',') {
                i++;
            }
            sscanf(&lineaUsuario[i], "%d", &cantidad);

            conteoPalabras[indice] += cantidad;
            indice++;


            while (lineaUsuario[i] != ' ' && lineaUsuario[i] != ',' && lineaUsuario[i] != '\0') {
                i++;
            }
        }
    }

    for (int i = 0; i < 3000; i++) {
        fprintf(archivoSalidaPtr, "%s, %d\n", palabra, conteoPalabras[i]);
    }

    fclose(archivoCSVPtr);
    fclose(archivoSalidaPtr);

    printf("Resultado guardado en %s\n", nombreArchivoSalida);

    return 0;
}

