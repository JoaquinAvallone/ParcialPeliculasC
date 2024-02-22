#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "movies.h"

eMovie* newMovie()
{
    eMovie* m = (eMovie*) malloc(sizeof(eMovie));

    if(m != NULL)
    {
        m->id_peli = 0;
        strcpy(m->titulo, "");
        strcpy(m->genero, "");
        m->duracion = 0;
    }
    return m;
}
eMovie* newMovieStr(char* id, char* titulo, char* genero, char* duracion)
{
    eMovie* m = newMovie();

    if(id != NULL && titulo != NULL && genero != NULL && duracion != NULL)
    {
        if(!(setIdMovie(m, atoi(id)) && setTituloMovie(m, titulo) && setGeneroMovie(m, genero) && setDuracionMovie(m, atof(duracion))))
        {
            free(m);
            m = NULL;
        }
    }
    return m;
}

//setters
int setIdMovie(eMovie* movie, int id)
{
    int retorno = 0;

    if(movie != NULL && id >= 0)
    {
        movie->id_peli = id;
        retorno = 1;
    }
    return retorno;
}

int setTituloMovie(eMovie* movie, char* titulo)
{
    int retorno = 0;

    if(movie != NULL && titulo != NULL && strlen(titulo) < 100)
    {
        strcpy(movie->titulo, titulo);
        retorno = 1;
    }
    return retorno;
}

int setGeneroMovie(eMovie* movie, char* genero)
{
    int retorno = 0;

    if(movie != NULL && genero != NULL && strlen(genero) < 100)
    {
        strcpy(movie->genero, genero);
        retorno = 1;
    }
    return retorno;
}

int setDuracionMovie(eMovie* movie, float duracion)
{
    int retorno = 0;

    if(movie != NULL && duracion >= 0)
    {
        movie->duracion = duracion;
        retorno = 1;
    }
    return retorno;
}

//getters
int getIdMovie(eMovie* movie, int* id)
{
    int retorno = 0;

    if(movie != NULL && id != NULL)
    {
        *id = movie->id_peli;
        retorno = 1;
    }
    return retorno;
}

int getTituloMovie(eMovie* movie, char* titulo)
{
    int retorno = 0;

    if(movie != NULL && titulo != NULL)
    {
        strcpy(titulo, movie->titulo);
        retorno = 1;
    }
    return retorno;
}

int getGeneroMovie(eMovie* movie, char* genero)
{
    int retorno = 0;

    if(movie != NULL && genero != NULL)
    {
        strcpy(genero, movie->genero);
        retorno = 1;
    }
    return retorno;
}

int getDuracionMovie(eMovie* movie, float* duracion)
{
    int retorno = 0;

    if(movie != NULL && duracion != NULL)
    {
        *duracion = movie->duracion;
        retorno = 1;
    }
    return retorno;
}
