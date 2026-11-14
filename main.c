#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {

    char nombres[5][50];
    int demanda[5];
    float tiempo[5];
    float recursos[5];
    int cantidad = 0, opc, opc2, indice;
    float tiempoTotal, recursosTotal;

    do
    {
        printf("\nSeleccione una opcion:\n");
        printf("1.Registrar producto\n");
        printf("2.Mostrar productos\n");
        printf("3.Buscar producto\n");
        printf("4.Editar producto\n");
        printf("5.Eliminar producto\n");
        printf("6.Calcular produccion y verificar capacidad\n");
        printf(">> ");

        opc = validarFloatRango(1,6);
        switch (opc)
        {
        case 1:
            registrarProducto(nombres,demanda,tiempo,recursos,&cantidad);
            break;
        case 2:
            mostrarProductos(nombres,demanda,tiempo,recursos,0,cantidad);
            break;
        case 3:
            indice = buscarProducto(nombres,cantidad);
            if (indice == -1)
            {
                printf("Error: no existe el producto\n");
            }
            else
            {
                mostrarProductos(nombres,demanda,tiempo,recursos,indice,indice + 1);
            }
            break;
        case 4:
            editarProducto(nombres,demanda,tiempo,recursos,cantidad);
            break;
        case 5:
            eliminarProducto(nombres,demanda,tiempo,recursos,&cantidad);
            break;
        case 6:
            if (cantidad == 0)
            {
                printf("Error: no hay productos registrados\n");
            }
            else
            {
                calcularProduccion(demanda,tiempo,recursos,cantidad,&tiempoTotal,&recursosTotal);
                verificarCapacidad(tiempoTotal,recursosTotal);
            }
            break;
        }

        printf("Desea seleccionar otra opcion 1.Si/2.No: ");
        opc2 = validarFloatRango(1,2);
    } while (opc2==1);

    return 0;
}
