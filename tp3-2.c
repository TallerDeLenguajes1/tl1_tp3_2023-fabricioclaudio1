#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int produccion[5][12];

    //Creo valores aleatorios a 'produccion' y lo muestro
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            //Creo valores aleatorios
            produccion[i][j]=10000 + rand()%40001;
            //Muestro
            printf("Anio %d, Mes %d: %d\n", i+1, j+1, produccion[i][j]);
        }
    }

    //Promedio de ganancia por año
    int sumaAnio[5]={0,0,0,0,0};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            //Sumo los meses correspondientes a cada año
            sumaAnio[i]+=produccion[i][j];
        }
        //Saco promedio de cada año
        sumaAnio[i]=sumaAnio[i]/12;
        printf("Promedio de ganancia anio %d: %d \n", i+1, sumaAnio[i]);
    }

    //Valor maximo por mes
    int valorMax=0, valorMin=50000, mesMax, anioMax, mesMin, anioMin;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (produccion[i][j]>valorMax)
            {
                valorMax=produccion[i][j];
                mesMax=j+1;
                anioMax=i+1;
            }

            if (produccion[i][j]<valorMin)
            {
                valorMin=produccion[i][j];
                mesMin=j+1;
                anioMin=i+1;
            }
        }
    }
    printf("Valor Maximo, Mes %d, Anio %d: %d \n", mesMax, anioMax, valorMax);
    printf("Valor Minimo, Mes %d, Anio %d: %d \n", mesMin, anioMin, valorMin);
    return 0;
}