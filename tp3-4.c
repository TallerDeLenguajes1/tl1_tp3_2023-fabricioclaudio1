#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}typedef Producto;
 
struct {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
                        // "CantidadProductosAPedir"
}typedef Cliente;

void cargarClientes(Cliente *clientes, int n);
void mostrarClientes(Cliente *clientes, int n);
void liberarClientes(Cliente *clientes, int n);
void costoTotalProducto(Cliente *clientes, int id, int idProd);
void totalPagarCliente(Cliente *clientes, int n);
int main(){
    Cliente *clientes;
    int cantClientes;

    printf("Ingrese la CANTIDAD de clientes:  \n");
    scanf("%d", &cantClientes);
    clientes= malloc(cantClientes * (sizeof(Cliente)));
    
    cargarClientes(clientes, cantClientes);
    mostrarClientes(clientes, cantClientes);

    //iv)
    int idCliente, idProd;
    printf("|Calculo del Costo Total de un Producto|\n");
    printf("Ingrese El ID del Cliente: \n");
    scanf("%d", &idCliente);
    printf("Ingrese ID del Producto: \n");
    scanf("%d", &idProd);
    costoTotalProducto(clientes, idCliente, idProd);

    //4, v) Total a pagar por Cliente
    totalPagarCliente(clientes, cantClientes);

    liberarClientes(clientes, cantClientes);
    return 0;
}

void cargarClientes(Cliente *clientes, int n){
    srand(time(NULL));
    int aleatorioProducto;
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

    for (int i = 0; i < n; i++)
    {
        //Cliente ID
        clientes[i].ClienteID=i+1;
        //Nombre del Cliente
        clientes[i].NombreCliente=malloc(40 * sizeof(char));
        printf("Ingrese el NOMBRE del cliente %d: \n", i+1);
        fflush(stdin);
        gets(clientes[i].NombreCliente);
        //Cantidad de productos a pedir
        clientes[i].CantidadProductosAPedir=1 + rand() % 5;
        //Productos
        clientes[i].Productos=malloc((clientes[i].CantidadProductosAPedir)*sizeof(Producto));

        //Producto
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            //Producto ID
            clientes[i].Productos[j].ProductoID=j+1;
            //Cantidad
            clientes[i].Productos[j].Cantidad=1+rand() % 10;
            //Tipo de Producto
            aleatorioProducto=rand()%5;
            printf("Aleatorio: %d\n", aleatorioProducto);
            clientes[i].Productos[j].TipoProducto=malloc(15*sizeof(char));
            for(int k = 0; k < 15; k++) //Preguntar si esta bien usado el array tipoProductos
            {
                clientes[i].Productos[j].TipoProducto[k]=TiposProductos[aleatorioProducto][k];
            }
            //Precio Unitario
            clientes[i].Productos[j].PrecioUnitario= (100 + rand() % 10001);

        }

    }

}

void mostrarClientes(Cliente *clientes, int n){
    for (int i = 0; i < n; i++)
    {
        printf("---------------------\n");
        printf("Cliente: %s\n", clientes[i].NombreCliente);
        printf("Cliente ID: %d\n", clientes[i].ClienteID);
        printf("\n");

        //Productos
        printf("Cantidad de Productos: %d\n", clientes[i].CantidadProductosAPedir);
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("|ProductoID: %d|\n", clientes[i].Productos[j].ProductoID);
            printf("Cantidad: %d\n", clientes[i].Productos[j].Cantidad);
            printf("Tipo de Producto: ");
            puts(clientes[i].Productos[j].TipoProducto);
            printf("Precio Unitario: %.2f\n", clientes[i].Productos[j].PrecioUnitario/100);//Por qué tengo que dividir aca entre 100 para que me dé decimales?
            printf("\n");
        }
        
        //4, v) Total a pagar por Cliente

        
    }
}

void liberarClientes(Cliente *clientes, int n) {
    for (int i = 0; i < n; i++) {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
        for (int j = 0; i < clientes[i].CantidadProductosAPedir; i++)
        {
            free(clientes[i].Productos[j].TipoProducto);
        }
    }
    free(clientes);
}

void costoTotalProducto(Cliente *clientes, int id, int idProd){
    float calculoCostoProd=0;

    for (int i = 0; i < 10; i++)
    {
        if (idProd== clientes[id-1].Productos[i].ProductoID)
        {
            calculoCostoProd=(clientes[id-1].Productos[i].Cantidad)*(clientes[id-1].Productos[i].PrecioUnitario/100);
        }
    }
    printf("Costo Total del Producto %d: %.1f \n", idProd, calculoCostoProd);
    
}

void totalPagarCliente(Cliente *clientes, int n){
    float costo=0;
    printf("|Total a pagar por acada Cliente|\n");
    for (int i = 0; i < n; i++)
    {
        printf("|Cliente %d|\n", i+1);

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            costo += (clientes[i].Productos[j].Cantidad)*(clientes[i].Productos[j].PrecioUnitario/100);
        }
        printf("Total a pagar: %.1f\n", costo);
        costo=0;   
    }
}