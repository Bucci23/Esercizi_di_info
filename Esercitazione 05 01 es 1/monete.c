#include <stdlib.h>
int *Monete(int *t, int size, int b)
{
	int *s = malloc(1 * sizeof(int));
	int somma = 0;
	int dim = 1;
	while (somma < b)
	{
		for (int i = 0; i < size; ++i)
		{
			if (somma + t[i] <= b)
			{
				s = realloc(s, (dim) * sizeof(int));
				s[dim - 1] = t[i];
				++dim;
				somma += t[i];
				break;
			}
		}
	}
	return s;
}