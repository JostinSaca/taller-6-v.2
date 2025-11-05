#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarDatos(char nombres[][50], float precios[], int *cantidad) {
    int i;
    printf("Ingrese la cantidad de productos (maximo 10): ");

    while (scanf("%d", cantidad) != 1 || *cantidad <= 0 || *cantidad > 10) {
        printf("Entrada invalida. Ingrese un numero entre 1 y 10: ");
        while (getchar() != '\n'); // limpia el buffer
    }

    for (i = 0; i < *cantidad; i++) {
        printf("\nProducto %d:\n", i + 1);

        printf("Nombre: ");
        scanf(" %[^\n]", nombres[i]);

        printf("Precio: ");
        while (scanf("%f", &precios[i]) != 1 || precios[i] < 0) {
            printf("Precio invalido. Ingrese un numero mayor o igual a 0: ");
            while (getchar() != '\n');
        }
    }
}

void mostrarProductos(char nombres[][50], float precios[], int cantidad) {
    int i;
    printf("\n--- Lista de productos ---\n");
    for (i = 0; i < cantidad; i++) {
        printf("%d. %s - $%.2f\n", i + 1, nombres[i], precios[i]);
    }
}

void calcularTotal(float precios[], int cantidad) {
    float total = 0;
    int i;
    for (i = 0; i < cantidad; i++) {
        total += precios[i];
    }
    printf("\nPrecio total del inventario: $%.2f\n", total);
}

void encontrarExtremos(char nombres[][50], float precios[], int cantidad) {
    int i, posMax = 0, posMin = 0;

    for (i = 1; i < cantidad; i++) {
        if (precios[i] > precios[posMax])
            posMax = i;
        if (precios[i] < precios[posMin])
            posMin = i;
    }

    printf("\nProducto mas caro: %s ($%.2f)\n", nombres[posMax], precios[posMax]);
    printf("Producto mas barato: %s ($%.2f)\n", nombres[posMin], precios[posMin]);
}

void calcularPromedio(float precios[], int cantidad) {
    float suma = 0;
    int i;
    for (i = 0; i < cantidad; i++) {
        suma += precios[i];
    }
    printf("\nPrecio promedio: $%.2f\n", suma / cantidad);
}

void buscarProducto(char nombres[][50], float precios[], int cantidad) {
    char buscado[50];
    int i, encontrado = 0;

    printf("\nIngrese el nombre del producto a buscar: ");
    scanf(" %[^\n]", buscado);

    for (i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], buscado) == 0) {
            printf("El precio de '%s' es: $%.2f\n", nombres[i], precios[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
        printf("Producto no encontrado.\n");
}

int leerEnteroValido() {
    int numero;
    char c;

    while (1) {
        // Intentar leer un número
        if (scanf("%d", &numero) != 1) {
            printf("Entrada inválida. Ingrese solo números: ");
            while ((c = getchar()) != '\n');
        } else {
            while ((c = getchar()) != '\n');
            return numero;
        }
    }
}