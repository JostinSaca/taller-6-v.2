#include <stdio.h>
#include <string.h>
#include "funciones.h"

int ingresarDatos(char nombres[][50], float precios[], int cantidad) {
    int cantidadNueva;
    printf("Cuantos productos desea ingresar? (maximo %d): ", 10 - cantidad);

    while (scanf("%d", &cantidadNueva) != 1 || cantidadNueva <= 0 || cantidadNueva > 10 - cantidad) {
        printf("Entrada invalida. Ingrese un numero entre 1 y %d: ", 10 - cantidad);
        while (getchar() != '\n');
    }

    for (int i = cantidad; i < cantidad + cantidadNueva; i++) {
        int repetido;
        do {
            repetido = 0;
            printf("\nProducto %d:\n", i + 1);
            printf("Nombre: ");
            scanf(" %[^\n]", nombres[i]);

            for (int j = 0; j < i; j++) {
                if (strcmp(nombres[i], nombres[j]) == 0) {
                    printf("Error: El producto '%s' ya fue ingresado.\n", nombres[i]);
                    repetido = 1;
                    break;
                }
            }
        } while (repetido);

        printf("Precio: ");
        while (scanf("%f", &precios[i]) != 1 || precios[i] < 0) {
            printf("Precio invalido. Ingrese un numero mayor o igual a 0: ");
            while (getchar() != '\n');
        }
    }

    cantidad += cantidadNueva;
    return cantidad;
}

// Mostrar productos
void mostrarProductos(char nombres[][50], float precios[], int cantidad) {
    printf("\n--- Lista de productos ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d. %s - $%.2f\n", i + 1, nombres[i], precios[i]);
    }
}

// Calcular total
void calcularTotal(float precios[], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++)
        total += precios[i];
    printf("\nPrecio total del inventario: $%.2f\n", total);
}

// Producto mas caro y barato
void encontrarExtremos(char nombres[][50], float precios[], int cantidad) {
    int posMax = 0, posMin = 0;
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > precios[posMax])
            posMax = i;
        if (precios[i] < precios[posMin])
            posMin = i;
    }

    printf("\nProducto mas caro: %s ($%.2f)\n", nombres[posMax], precios[posMax]);
    printf("Producto mas barato: %s ($%.2f)\n", nombres[posMin], precios[posMin]);
}

// Calcular promedio
void calcularPromedio(float precios[], int cantidad) {
    float suma = 0;
    for (int i = 0; i < cantidad; i++)
        suma += precios[i];
    printf("\nPrecio promedio: $%.2f\n", suma / cantidad);
}

// Buscar producto
void buscarProducto(char nombres[][50], float precios[], int cantidad) {
    char buscado[50];
    int encontrado = 0;

    printf("\nIngrese el nombre del producto a buscar: ");
    scanf(" %[^\n]", buscado);

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], buscado) == 0) {
            printf("El precio de '%s' es: $%.2f\n", nombres[i], precios[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
        printf("Producto no encontrado.\n");
}

// Leer enteros validos
int leerEnteroValido() {
    int numero;
    while (1)
    {
        if (scanf("%d", &numero) ==1 && numero>0 )
        {
            while (getchar() != '\n');
            return numero;
            
        } else{
            printf("Error, dato invalido. Ingrese numeros mayor a 0: ");
            while(getchar() != '\n');
        }  
    }  
}