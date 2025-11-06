#include <stdio.h>
#include <string.h>
#include "funciones.h"

// main.c
// ---- Funcion principal ----
int main() {
    char nombres[10][50];
    float precios[10];
    int cantidad = 0, opcion;

    do {
        printf("--- MENU ---\n");
        printf("1. Ingresar productos (minimo 1, maximo 10)\n");
        printf("2. Mostrar productos\n");
        printf("3. Calcular precio total\n");
        printf("4. Producto mas caro y mas barato\n");
        printf("5. Calcular promedio de precios\n");
        printf("6. Buscar producto\n");
        printf("7. Agregar mas productos\n");
        printf("8. Salir\n");
        printf("Seleccione una opcion: ");
        opcion = leerEnteroValido();

        // Bloqueo general
        if (opcion != 1 && opcion != 8 && cantidad == 0) {
            printf("Debe ingresar al menos un producto antes de usar esta opcion.\n");
            continue;
        }

        switch (opcion) {
            case 1:
                if (cantidad == 10) {
                    printf("Ya se alcanzo el maximo de 10 productos.\n");
                } else {
                    cantidad = ingresarDatos(nombres, precios, cantidad);
                }
                break;

            case 2:
                mostrarProductos(nombres, precios, cantidad);
                break;

            case 3:
                calcularTotal(precios, cantidad);
                break;

            case 4:
                encontrarExtremos(nombres, precios, cantidad);
                break;

            case 5:
                calcularPromedio(precios, cantidad);
                break;

            case 6:
                buscarProducto(nombres, precios, cantidad);
                break;

            case 7:
                if (cantidad < 10) {
                    cantidad = ingresarDatos(nombres, precios, cantidad);
                } else {
                    printf("Ya tiene el maximo de 10 productos.\n");
                }
                break;

            case 8:
                printf("Saliendo del programa...\n");
                return 0;

            default:
                printf("Opcion no valida.\n");
        }

    } while (1);

    return 0;
}