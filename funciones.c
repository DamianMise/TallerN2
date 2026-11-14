#include <stdio.h>
#include <string.h>
#include "funciones.h"

float validarFloatRango(float a, float b){
    float num = 0;
    int val;
    do
    {
        val = scanf("%f",&num);
        while((getchar())!='\n');
        if (val != 1 || num < a || num > b)
        {
            printf("Error: valor ingresado invalido\n");
        }
    } while (val != 1 || num < a || num > b);
    return num;
}

void leerCadena(char *cadena, int n){
    fgets(cadena,n,stdin);
    int len = strlen(cadena) - 1;
    if (len >= 0 && cadena[len] == '\n')
    {
        cadena[len] = '\0';
    }
}

void registrarProducto(char nombres[][50], int *demanda, float *tiempo,
                       float *recursos, int *cantidad){
    if (*cantidad == 5)
    {
        printf("Error: ya se registraron los 5 productos\n");
        return;
    }
    printf("Ingrese los datos del producto %d:\n",*cantidad + 1);
    printf("Nombre: ");
    leerCadena(nombres[*cantidad],50);
    printf("Cantidad demandada: ");
    demanda[*cantidad] = validarFloatRango(0,100000);
    printf("Tiempo de fabricacion por unidad (horas): ");
    tiempo[*cantidad] = validarFloatRango(0,10000);
    printf("Recursos necesarios por unidad: ");
    recursos[*cantidad] = validarFloatRango(0,10000);
    (*cantidad)++;
    printf("Producto registrado\n");
}

void mostrarProductos(char nombres[][50], int *demanda, float *tiempo,
                      float *recursos, int inicio, int fin){
    printf("N\t\tNombre\t\tDemanda\t\tHoras/u\t\tRecursos/u\n");
    for (int i = inicio; i < fin; i++)
    {
        printf("%d\t\t%s\t\t%d\t\t%.2f\t\t%.2f\n",i + 1,
                                                  nombres[i],
                                                  demanda[i],
                                                  tiempo[i],
                                                  recursos[i]);
    }
}

int buscarProducto(char nombres[][50], int cantidad){
    char nombreBuscado[50];
    int indice = -1;
    printf("Ingrese el nombre del producto: ");
    leerCadena(nombreBuscado,50);
    for (int i = 0; i < cantidad; i++)
    {
        if (strcmp(nombreBuscado,nombres[i]) == 0)
        {
            indice = i;
        }
    }
    return indice;
}

void editarProducto(char nombres[][50], int *demanda, float *tiempo,
                    float *recursos, int cantidad){
    int indice = buscarProducto(nombres,cantidad);
    if (indice == -1)
    {
        printf("Error: no existe el producto\n");
        return;
    }
    mostrarProductos(nombres,demanda,tiempo,recursos,indice,indice + 1);
    printf("Que desea editar 1.Nombre/2.Demanda/3.Tiempo/4.Recursos: ");
    int opc = validarFloatRango(1,4);
    switch (opc)
    {
    case 1:
        printf("Nuevo nombre: ");
        leerCadena(nombres[indice],50);
        break;
    case 2:
        printf("Nueva cantidad demandada: ");
        demanda[indice] = validarFloatRango(0,100000);
        break;
    case 3:
        printf("Nuevo tiempo por unidad (horas): ");
        tiempo[indice] = validarFloatRango(0,10000);
        break;
    case 4:
        printf("Nuevos recursos por unidad: ");
        recursos[indice] = validarFloatRango(0,10000);
        break;
    }
    printf("Producto editado\n");
}

void eliminarProducto(char nombres[][50], int *demanda, float *tiempo,
                      float *recursos, int *cantidad){
    int indice = buscarProducto(nombres,*cantidad);
    if (indice == -1)
    {
        printf("Error: no existe el producto\n");
        return;
    }
    for (int i = indice; i < *cantidad - 1; i++)
    {
        strcpy(nombres[i],nombres[i + 1]);
        demanda[i] = demanda[i + 1];
        tiempo[i] = tiempo[i + 1];
        recursos[i] = recursos[i + 1];
    }
    (*cantidad)--;
    printf("Producto eliminado\n");
}

void calcularProduccion(int *demanda, float *tiempo, float *recursos,
                        int cantidad, float *tiempoTotal, float *recursosTotal){
    *tiempoTotal = 0;
    *recursosTotal = 0;
    for (int i = 0; i < cantidad; i++)
    {
        *tiempoTotal = *tiempoTotal + demanda[i] * tiempo[i];
        *recursosTotal = *recursosTotal + demanda[i] * recursos[i];
    }
}

void verificarCapacidad(float tiempoTotal, float recursosTotal){
    printf("Tiempo total de fabricacion: %.2f horas\n",tiempoTotal);
    printf("Recursos necesarios: %.2f\n",recursosTotal);

    printf("Tiempo de produccion disponible (horas): ");
    float tiempoDisponible = validarFloatRango(0,1000000);
    printf("Recursos disponibles: ");
    float recursosDisponibles = validarFloatRango(0,1000000);

    if (tiempoTotal <= tiempoDisponible && recursosTotal <= recursosDisponibles)
    {
        printf("La fabrica SI puede cumplir con la demanda\n");
    }
    else
    {
        printf("La fabrica NO puede cumplir con la demanda\n");
        if (tiempoTotal > tiempoDisponible)
        {
            printf("Faltan %.2f horas\n",tiempoTotal - tiempoDisponible);
        }
        if (recursosTotal > recursosDisponibles)
        {
            printf("Faltan %.2f unidades de recursos\n",recursosTotal - recursosDisponibles);
        }
    }
}
