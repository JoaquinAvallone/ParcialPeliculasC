#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "movies.h"
#include "menu.h"
#include "validaciones.h"
#include "LinkedList.h"
#include "controller.h"

int pedirPath(char* path)
{
    int retorno = 0;
    char auxPath[30];

    if(path != NULL)
    {
        system("cls");
        printf("         ***INGRESE PATH DEL ARCHIVO***\n\n");
        printf("Ingrese path(movies.csv): ");
        fflush(stdin);
        gets(auxPath);
        while(strlen(auxPath) <= 0 || strlen(auxPath) >= 20)
        {
            printf("Path demasiado largo/corto. Vuelva a ingresar path: ");
            fflush(stdin);
            gets(auxPath);
        }
        strcpy(path, auxPath);
        retorno = 1;
    }
    return retorno;
}


int parser_MoviesFromText(FILE* pFile , LinkedList* pLista)
{
	int retorno = 0;
	char buffer[4][100];
	int cant;
	eMovie* auxMovie = NULL;

	if(pFile!=NULL && pLista!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", buffer[0], buffer[1], buffer[2], buffer[3]);


        do{
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", buffer[0], buffer[1], buffer[2], buffer[3]);
            auxMovie = newMovieStr(buffer[0], buffer[1], buffer[2], buffer[3]);

            if(cant < 4)
            {
                break;
            }
			if(auxMovie != NULL)
			{
				ll_add(pLista, auxMovie);
			}
		}while(!feof(pFile));
		retorno = 1;
	}
    return retorno;
}

/** \brief Carga los datos de los paises desde el archivo vacunas.csv (modo texto).
 *
 * \param path char*
 * \param pLista LinkedList*
 * \return int
 *
 */
int controller_cargarMoviesDesdeTexto(char* path , LinkedList* pLista)
{
	int retorno=0;
	FILE* file = NULL;

	if(pLista!=NULL && path!=NULL)
	{
		file=fopen(path,"r");

		if(file!=NULL)
		{
			parser_MoviesFromText(file, pLista);
			retorno=1;
		}
		fclose(file);
	}
    return retorno;
}

int controller_listarMovie(eMovie* movie)
{
	int retorno = 0;
	int id;
	char titulo[100];
	char genero[100];
	float duracion;

	if(movie!=NULL)
	{
		if(getIdMovie(movie, &id) && getTituloMovie(movie, titulo) && getGeneroMovie(movie, genero) && getDuracionMovie(movie, &duracion))
		{
			printf("| %-3d |  %-30s  |   %-13s   |    %.2f     |\n", id, titulo, genero, duracion);
		}
	}
	return retorno;
}


int controller_listarMovies(LinkedList* pLista)
{
	int retorno = 0;
	int largo = ll_len(pLista);

	if(pLista != NULL && largo > 0)
	{
		system("cls");
		printf( "==============================================================================\n"
				"|                             ***LISTA PELICULAS***                          |\n"
				"==============================================================================\n"
				"| ID  |           TITULO                 |       GENERO      |   DURACION    |\n"
			    "------------------------------------------------------------------------------\n");

		for(int i=0; i < largo; i++)
		{
			controller_listarMovie((eMovie*) ll_get(pLista, i));
		}
		printf( "==============================================================================\n");
		retorno=1;
	}
    return retorno;
}

int controller_asignarDuracion(LinkedList* lista)
{
	int retorno = 0;
	if(lista!=NULL)
	{
		ll_map(lista, controller_asignarDuracionAleatorio);
		retorno = 1;
	}
	return retorno;
}

void* controller_asignarDuracionAleatorio(void* elemento)
{
	float duracion;
	eMovie* auxMovie = NULL;

	if(elemento!=NULL)
	{
		auxMovie = (eMovie*)elemento;
		duracion = ((float)rand() / RAND_MAX) * (240.0f - 100.0f) + 100.0f;
		setDuracionMovie(auxMovie, duracion);
	}

	return auxMovie;
}

int filtrarPorHorror(void* movie)
{

	int retorno=0;
	eMovie* auxMovie = NULL;
	char genero[100];

	if(movie!=NULL)
	{
		auxMovie=(eMovie*)movie;
		getGeneroMovie(auxMovie,genero);

		if(strcmp(genero, "Horror") == 0)
		{
			retorno=1;
		}
	}
    return retorno;
}

int filtrarPorAventura(void* movie)
{

	int retorno=0;
	eMovie* auxMovie = NULL;
	char genero[100];

	if(movie!=NULL)
	{
		auxMovie=(eMovie*)movie;
		getGeneroMovie(auxMovie,genero);

		if(strcmp(genero, "Adventure") == 0)
		{
			retorno=1;
		}
	}
    return retorno;
}
int filtrarPorDrama(void* movie)
{

	int retorno=0;
	eMovie* auxMovie = NULL;
	char genero[100];

	if(movie!=NULL)
	{
		auxMovie=(eMovie*)movie;
		getGeneroMovie(auxMovie,genero);

		if(strcmp(genero, "Drama") == 0)
		{
			retorno=1;
		}
	}
    return retorno;
}

int filtrarPorComedia(void* movie)
{

	int retorno=0;
	eMovie* auxMovie = NULL;
	char genero[100];

	if(movie!=NULL)
	{
		auxMovie=(eMovie*)movie;
		getGeneroMovie(auxMovie,genero);

		if(strcmp(genero, "Comedy") == 0)
		{
			retorno=1;
		}
	}
    return retorno;
}

int filtrarPorRomance(void* movie)
{

	int retorno=0;
	eMovie* auxMovie = NULL;
	char genero[100];

	if(movie!=NULL)
	{
		auxMovie=(eMovie*)movie;
		getGeneroMovie(auxMovie,genero);

		if(strcmp(genero, "Romance") == 0)
		{
			retorno=1;
		}
	}
    return retorno;
}

int filtrarPorDocumentary(void* movie)
{

	int retorno=0;
	eMovie* auxMovie = NULL;
	char genero[100];

	if(movie!=NULL)
	{
		auxMovie=(eMovie*)movie;
		getGeneroMovie(auxMovie,genero);

		if(strcmp(genero, "Documentary") == 0)
		{
			retorno=1;
		}
	}
    return retorno;
}

int filtrarPorMusical(void* movie)
{

	int retorno=0;
	eMovie* auxMovie = NULL;
	char genero[100];

	if(movie!=NULL)
	{
		auxMovie=(eMovie*)movie;
		getGeneroMovie(auxMovie,genero);

		if(strcmp(genero, "Musical") == 0)
		{
			retorno=1;
		}
	}
    return retorno;
}

int filtrarPorAnimation(void* movie)
{

	int retorno=0;
	eMovie* auxMovie = NULL;
	char genero[100];

	if(movie!=NULL)
	{
		auxMovie=(eMovie*)movie;
		getGeneroMovie(auxMovie,genero);

		if(strcmp(genero, "Animation") == 0)
		{
			retorno=1;
		}
	}
    return retorno;
}

int ordenarUsuariosPorGenero(void* movieI, void* movieJ)
{
    int returnAux=0;
    eMovie* movieIndiceI;
    eMovie* movieIndicej;
    char auxGeneroI[100];
    char auxGeneroJ[100];
    int auxDuracionI;
    int auxDuracionJ;

    if(movieI != NULL && movieJ != NULL)
    {
    	movieIndiceI = (eMovie*)movieI;
    	movieIndicej = (eMovie*)movieJ;

    	getGeneroMovie(movieIndiceI,auxGeneroI);
    	getGeneroMovie(movieIndicej,auxGeneroJ);
    	getDuracionMovie(movieIndiceI, &auxDuracionI);
    	getDuracionMovie(movieIndicej, &auxDuracionJ);

        if(strcmp(auxGeneroI, auxGeneroJ) > 0 || (strcmp(auxGeneroI, auxGeneroJ) == 0 && auxDuracionI < auxDuracionJ))
        {
            returnAux=1;
        }

    }
    return returnAux;
}

int controller_guardarMoviesTexto(char* path , LinkedList* lista)
{
	int retorno = 0;
	eMovie* auxMovie = NULL;
	int id;
	char titulo[100];
	char genero[100];
	float duracion;
	int tam;
	FILE* f=fopen(path,"w");

	tam=ll_len(lista);

	if(path!=NULL && lista!=NULL && f!=NULL)
	{
		fprintf(f,"id,titulo,genero,duracion\n");

		for(int i=0;i<tam;i++)
		{
			auxMovie=(eMovie*)ll_get(lista, i);
			getIdMovie(auxMovie, &id);
			getTituloMovie(auxMovie, titulo);
			getGeneroMovie(auxMovie, genero);
			getDuracionMovie(auxMovie, &duracion);
			fprintf(f,"%d,%s,%s,%f\n",id,titulo,genero,duracion);
			retorno = 1;
		}
	}
	fclose(f);

    return retorno;
}
