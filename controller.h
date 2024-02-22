#include "movies.h"
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

int pedirPath(char* path);
int parser_MoviesFromText(FILE* pFile , LinkedList* pLista);
int controller_cargarMoviesDesdeTexto(char* path , LinkedList* pLista);
int controller_listarMovie(eMovie* movie);
int controller_listarMovies(LinkedList* pLista);
int controller_asignarDuracion(LinkedList* lista);
void* controller_asignarDuracionAleatorio(void* elemento);
int filtrarPorHorror(void* movie);
int filtrarPorAventura(void* movie);
int filtrarPorDrama(void* movie);
int filtrarPorComedia(void* movie);
int filtrarPorRomance(void* movie);
int filtrarPorDocumentary(void* movie);
int filtrarPorMusical(void* movie);
int filtrarPorAnimation(void* movie);
int ordenarUsuariosPorGenero(void* movieI, void* movieJ);
int controller_guardarMoviesTexto(char* path , LinkedList* lista);
