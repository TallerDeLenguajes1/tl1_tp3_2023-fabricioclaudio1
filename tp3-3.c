#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *nombres[5];
    char nombre[50];

    printf("Escriba 5 nombres: \n");
    for (int i = 0; i < 5; i++)
    {
        gets(nombre);
        nombres[i]= malloc((strlen(nombre)+1)*(sizeof(char)));
        strcpy(nombres[i],nombre);
    }

    printf("Los nombres ingresados son: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", nombres[i]);
        free(nombres[i]);
    }
    
    return 0;
}