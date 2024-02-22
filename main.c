#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "movies.h"
#include "menu.h"
#include "validaciones.h"
#include "LinkedList.h"
#include "controller.h"

int main()
{
    char respuesta = 's';
    char path[20];
    int flagDuracion = 0;
    int flagOrdenamiento = 0;
    LinkedList* listaPeliculas = ll_newLinkedList();
    LinkedList* listaPeliculasPorTipo = ll_newLinkedList();
    LinkedList* listaAux = ll_newLinkedList();

    do{
        switch(menuPrincipal())
        {
        case 1:
            pedirPath(path);
            if(strcmp(path, "movies.csv") == 0)
            {
                if(controller_cargarMoviesDesdeTexto(path, listaPeliculas))
                {
                    printf("Archivo cargado con exito!!!\n");
                }
                else
                {
                    printf("Hubo un problema con la carga del archivo\n");
                }
            }
            else
            {
                printf("El path ingresado es incorrecto. Pruebe con: movies.csv \n");
            }
            system("pause");
            break;
        case 2:
            if(ll_isEmpty(listaPeliculas))
            {
                printf("Primero debe cargar el archivo en el punto 1.\n");
            }
            else
            {
                controller_listarMovies(listaPeliculas);
            }
            system("pause");
            break;
        case 3:
            if(ll_isEmpty(listaPeliculas))
            {
                printf("Primero debe cargar el archivo en el punto 1.\n");
            }
            else
            {
                if(controller_asignarDuracion(listaPeliculas))
                {
                    flagDuracion = 1;
                    controller_listarMovies(listaPeliculas);
                }
                else
                {
                    printf("Hubo un problema al asignar las duraciones\n");
                }
            }
            system("pause");
            break;
        case 4:
            if(ll_isEmpty(listaPeliculas))
            {
                printf("Primero debe cargar el archivo en el punto 1.\n");
            }
            else
            {
                if(!flagDuracion)
                {
                    printf("primero debe ingresar a la asignacion de duracion\n");
                }
                else
                {
                    switch(menuFiltrados())
                    {
                    case 1:
                        listaPeliculasPorTipo = ll_filter(listaPeliculas, filtrarPorHorror);
                        controller_listarMovies(listaPeliculasPorTipo);
                        break;
                    case 2:
                        listaPeliculasPorTipo = ll_filter(listaPeliculas, filtrarPorAventura);
                        controller_listarMovies(listaPeliculasPorTipo);
                        break;
                    case 3:
                        listaPeliculasPorTipo = ll_filter(listaPeliculas, filtrarPorDrama);
                        controller_listarMovies(listaPeliculasPorTipo);
                        break;
                    case 4:
                        listaPeliculasPorTipo = ll_filter(listaPeliculas, filtrarPorComedia);
                        controller_listarMovies(listaPeliculasPorTipo);
                        break;
                    case 5:
                        listaPeliculasPorTipo = ll_filter(listaPeliculas, filtrarPorRomance);
                        controller_listarMovies(listaPeliculasPorTipo);
                        break;
                    case 6:
                        listaPeliculasPorTipo = ll_filter(listaPeliculas, filtrarPorDocumentary);
                        controller_listarMovies(listaPeliculasPorTipo);
                        break;
                    case 7:
                        listaPeliculasPorTipo = ll_filter(listaPeliculas, filtrarPorMusical);
                        controller_listarMovies(listaPeliculasPorTipo);
                        break;
                    case 8:
                        listaPeliculasPorTipo = ll_filter(listaPeliculas, filtrarPorAnimation);
                        controller_listarMovies(listaPeliculasPorTipo);
                        break;
                    case 9:
                        break;
                    default:
                        printf("La opcion ingresada no existe.\n");
                        system("pause");
                        break;
                    }
                }
            }
            system("pause");
            break;
        case 5:
             if(ll_isEmpty(listaPeliculas))
            {
                printf("Primero debe cargar el archivo en el punto 1.\n");
            }
            else
            {
                if(!flagDuracion)
                {
                    printf("primero debe ingresar a la asignacion de duracion\n");
                }
                else
                {
                    listaAux = ll_clone(listaPeliculas);
                    ll_sort(listaAux, ordenarUsuariosPorGenero, 1);
                    flagOrdenamiento = 1;
                    controller_listarMovies(listaAux);
                }
            }
            system("pause");
            break;
        case 6:
             if(ll_isEmpty(listaPeliculas))
            {
                printf("Primero debe cargar el archivo en el punto 1.\n");
            }
            else
            {
                if(!flagDuracion)
                {
                    printf("primero debe ingresar a la asignacion de duracion\n");
                }
                else
                {
                     if(!flagOrdenamiento)
                     {
                         printf("Primero debe ingresar al punto 5\n");
                     }
                     else
                     {
                         if(controller_guardarMoviesTexto("moviesOrdenadas.csv", listaAux))
                         {
                             printf("La lista fue guardada con exito!!!\n");
                         }
                         else
                         {
                             printf("Error al guardar la lista\n");
                         }
                     }
                }
            }
            system("pause");
            break;
        case 7:
            confirmaSalida(&respuesta, 'n', 's');
            break;
        default:
            printf("La opcion ingresada no existe.\n");
            system("pause");
            break;
        }
    }while(respuesta == 's');





    return 0;
}
