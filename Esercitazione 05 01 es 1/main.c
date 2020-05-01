#include <stdlib.h>
extern int *Monete(int *t, int size, int b);
int main()
{
	int t[6] = { 50,20,10,5,2,1 };
	int *s=Monete(t, 6, 126);
	free(s);
}