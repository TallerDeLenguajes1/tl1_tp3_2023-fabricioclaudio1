#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    char **nombres;
    char nombre[50];

    printf("Ingrese la CANTIDAD de NOMBRES que desea ingresar: \n");
    scanf("%d", &n);
    getchar(); // consume el caracter de nueva línea pendiente en el buffer
    nombres= (char **)malloc(n*sizeof(char*));
    if (nombres == NULL) {
        printf("Error: no se pudo asignar memoria\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("Ahora escriba el nombre %d: \n", i+1);
        fgets(nombre, sizeof(nombre), stdin);
        strtok(nombre, "\n"); // elimina el caracter de nueva línea
        nombres[i]= malloc((strlen(nombre)+1)*(sizeof(char)));
        strcpy(nombres[i],nombre);
    }

    printf("Los nombres ingresados son: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", nombres[i]);
        free(nombres[i]);
    }
    free(nombres);
    
    
    return 0;
}