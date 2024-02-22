#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"

int menuPrincipal()
{
    int opcion;

    system("cls");

    printf("         ***MENU PRINCIPAL***\n\n");
    printf("1.Cargar archivo\n"
           "2.Imprimir lista\n"
           "3.Asignar tiempos\n"
           "4.Filtrar por tipo\n"
           "5.Mostrar duraciones\n"
           "6.Guardar peliculas\n"
           "7.Salir\n");

    utn_getNumeroInt(&opcion, "Ingrese opcion: ", "Error\n", 1, 7, 4);
    return opcion;
}

int menuFiltrados()
{
    int opcion;

    system("cls");

    printf("         ***MENU GENEROS***\n\n");
    printf("1.Horror\n"
           "2.Aventura\n"
           "3.Drama\n"
           "4.comedia\n"
           "5.Romance\n"
           "6.Documentary\n"
           "7.Musical\n"
           "8.Animation\n"
           "9.Volver\n");

    utn_getNumeroInt(&opcion, "Ingrese opcion: ", "Error\n", 1, 9, 4);
    return opcion;
}
