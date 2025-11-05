#include <stdio.h>
#include <string.h>
#include "funciones.h"

// ---- Prototipos ----


// ---- Funcion principal ----
int main() {
    char nombres[10][50];
    float precios[10];
    int cantidad = 0, opcion;

    ingresarDatos(nombres, precios, &cantidad);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Mostrar productos\n");
        printf("2. Calcular precio total\n");
        printf("3. Producto mas caro y mas barato\n");
        printf("4. Calcular promedio de precios\n");
        printf("5. Buscar producto por nombre\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        opcion=leerEnteroValido();

        switch (opcion) {
            case 1:
                mostrarProductos(nombres, precios, cantidad);
                break;

            case 2:
                calcularTotal(precios, cantidad);
                break;

            case 3:
                encontrarExtremos(nombres, precios, cantidad);
                break;

            case 4:
                calcularPromedio(precios, cantidad);
                break;

            case 5:
                buscarProducto(nombres, precios, cantidad);
                break;

            case 6:
                printf("Saliendo del programa...\n");
                return 0;   // termina el programa

            default:
                printf("Opcion no valida.\n");
        }
    } while (1);

    return 0;
}
