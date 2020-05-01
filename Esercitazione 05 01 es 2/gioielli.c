#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "gioielli.h"
int massimo(float *appet,int dim)
{
	float max = appet[0];
	int pos = 0;
	for(int i=0;i<dim;++i)
	{
		if (appet[i] > max)
		{
			max = appet[i];
			pos = i;
		}
	}
	return pos;
}
Gioiello *Gioielli(const char* filename, float b, int *ret_size)
{
	Gioiello *lista = malloc(1 * sizeof(Gioiello));
	FILE *f = fopen(filename, "rt");
	int ptot=0;
	Gioiello *zaino = NULL;
	int dim = 1;
	int dimzaino = 0;
	float *appet = NULL;
	while (1)
	{
		;
		if (fscanf(f, "%i", &(lista[dim-1].codice))==EOF)
			break;
		else
		{
			fscanf(f, "%f", &(lista[dim - 1].peso));
			fscanf(f, "%f", &(lista[dim - 1].prezzo));
			lista = realloc(lista, (dim + 1) * sizeof(Gioiello));
			++dim;
		}
	}
	dim--;
	appet = calloc(dim , sizeof(float));
	for (int i = 0; i < dim; ++i)
		appet[i] = lista[i].prezzo / lista[i].peso;
	for (int i = 0; i < dim; ++i)
	{
		if (ptot + lista[massimo(appet, dim)].peso <= b)
		{
			dimzaino++;
			zaino = realloc(zaino, dimzaino * sizeof(Gioiello));
			zaino[dimzaino - 1].codice = lista[massimo(appet, dim)].codice;
			zaino[dimzaino - 1].peso = lista[massimo(appet, dim)].peso;
			zaino[dimzaino - 1].prezzo = lista[massimo(appet, dim)].prezzo;
			ptot += lista[massimo(appet, dim)].peso;
		}
		appet[massimo(appet, dim)] = 0;
	}
	*ret_size = dimzaino;
	return zaino;

}