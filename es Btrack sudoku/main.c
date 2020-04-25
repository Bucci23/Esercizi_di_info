#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 9

int leggiFile(char *s, int M[N][N]) {
	FILE *f;
	int i, j, rc;

	while (s[0] == '\0') {
		printf("Nome del file: ");
		scanf("%s", s);
	}
	if ((f = fopen(s, "rt"))) {
		for (i = 0; i < N && !feof(f); i++) {
			for (j = 0; j < N && !feof(f); j++) {
				fscanf(f, "%d", &M[i][j]);
			}
		}
		if (i == N && j == N) {
			rc = 1;
		}
		else {
			rc = 0;
		}
		fclose(f);
	}
	else {
		fprintf(stderr, "ERRORE: il file %s non puo' essere aperto in lettura\n\n", s);
		rc = 0;
	}
	return(rc);
}
void print(int m[N][N])
{
	for (int ii = 0; ii < N; ++ii)
	{
		for (int jj = 0; jj < N; ++jj)
			printf("%d ", m[ii][jj]);
		printf("\n");
	}
	return;
}
int verifica(int m[N][N],int i,int j)
{
	for (int ii = 0; ii < N; ++ii)
	{
		if ((m[ii][j] == m[i][j]) && (i != ii))
			return 0;
	}
	for (int jj = 0; jj < N; ++jj)
	{
		if ((m[i][jj] == m[i][j]) && (j != jj))
			return 0;
	}
	if (i <= 2)
	{
		if (j <= 2)
		{
			for (int ii = 0; ii < 3; ++ii)
			{
				for (int jj = 0; jj < 3; ++jj)
				{
					if ((m[ii][jj] == m[i][j])&&((i!=ii)||(j!=jj)))
						return 0;
				}
			}
		}
		else if (j <= 5)
		{
			for (int ii = 0; ii < 3; ++ii)
			{
				for (int jj = 3; jj < 6; ++jj)
				{
					if ((m[ii][jj] == m[i][j]) && ((i != ii) || (j != jj)))
						return 0;
				}
			}
		}
		else
		{
			for (int ii = 0; ii < 3; ++ii)
			{
				for (int jj = 6; jj < N; ++jj)
				{
					if ((m[ii][jj] == m[i][j]) && ((i != ii) || (j != jj)))
						return 0;
				}
			}
		}
	}
	else if (i <= 5)
	{
		if (j <= 2)
		{
			for (int ii = 3; ii < 6; ++ii)
			{
				for (int jj = 0; jj < 3; ++jj)
				{
					if ((m[ii][jj] == m[i][j]) && ((i != ii) || (j != jj)))
						return 0;
				}
			}
		}
		else if (j <= 5)
		{
			for (int ii = 3; ii < 6; ++ii)
			{
				for (int jj = 3; jj < 6; ++jj)
				{
					if ((m[ii][jj] == m[i][j]) && ((i != ii) || (j != jj)))
						return 0;
				}
			}
		}
		else
		{
			for (int ii = 3; ii < 6; ++ii)
			{
				for (int jj = 6; jj < N; ++jj)
				{
					if ((m[ii][jj] == m[i][j]) && ((i != ii) || (j != jj)))
						return 0;
				}
			}
		}
	}
	else
	{
		if (j <= 2)
		{
			for (int ii = 6; ii < N; ++ii)
			{
				for (int jj = 0; jj < 3; ++jj)
				{
					if ((m[ii][jj] == m[i][j]) && ((i != ii) || (j != jj)))
						return 0;
				}
			}
		}
		else if (j <= 5)
		{
			for (int ii = 6; ii < N; ++ii)
			{
				for (int jj = 3; jj < 6; ++jj)
				{
					if ((m[ii][jj] == m[i][j]) && ((i != ii) || (j != jj)))
						return 0;
				}
			}
		}
		else
		{
			for (int ii = 6; ii < N; ++ii)
			{
				for (int jj = 6; jj < N; ++jj)
				{
					if ((m[ii][jj] == m[i][j]) && ((i != ii) || (j != jj)))
						return 0;
				}
			}
		}
	}
	return 1;
}
void sudokuSolve(int m[N][N], int i, int j, int *sol)
{
	if (i == N)
	{
		*sol = *sol + 1;
		getchar();
		print(m);
		getchar();
		return;
	}
	if (j == N)
	{
		printf("soluzione parziale: \n");
		print(m);
		sudokuSolve(m, i + 1, 0, sol);
	}
	if (m[i][j] == 0)
	{
		for (int k = 1; k < 10; ++k)
		{
			if (m[i][j] == 0)
			{
				m[i][j] = k;
				if (verifica(m, i, j) == 1)
				{
					printf("inserisco %d \n", m[i][j]);
					sudokuSolve(m, i, j + 1, sol);
				}
				m[i][j] = 0;
			}
		}
	}
	else
	{
		printf("gia' presente \n");
		sudokuSolve(m, i, j + 1, sol);
		
	}
}


int main(int argc, char *argv[]) {
	char s[100];
	int m[N][N], i, sol = 0;

	s[0] = '\0';

	if (leggiFile(s, m) == 1) {
		print(m);
		getchar();
		getchar();
		sudokuSolve(m, 0, 0, &sol);

	}

	getchar();
	return(0);
}
