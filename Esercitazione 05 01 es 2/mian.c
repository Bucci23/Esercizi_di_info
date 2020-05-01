#include "gioielli.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char filename[] = { "gioielli_2.txt" };
	float b = 37.0;
	int size;
	Gioiello *zaino = Gioielli(filename, b, &size);
	return 0;
}