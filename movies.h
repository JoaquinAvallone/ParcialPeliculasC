#ifndef MOVIES_H_INCLUDED
#define MOVIES_H_INCLUDED

typedef struct
{
    int id_peli;
    char titulo[100];
    char genero[100];
    float duracion;
}eMovie;

#endif // MOVIES_H_INCLUDED

eMovie* newMovie();
eMovie* newMovieStr(char* id, char* titulo, char* genero, char* duracion);

//setters
int setIdMovie(eMovie* movie, int id);
int setTituloMovie(eMovie* movie, char* titulo);
int setGeneroMovie(eMovie* movie, char* genero);
int setDuracionMovie(eMovie* movie, float duracion);

//getters
int getIdMovie(eMovie* movie, int* id);
int getTituloMovie(eMovie* movie, char* titulo);
int getGeneroMovie(eMovie* movie, char* genero);
int getDuracion(eMovie* movie, float* duracion);
