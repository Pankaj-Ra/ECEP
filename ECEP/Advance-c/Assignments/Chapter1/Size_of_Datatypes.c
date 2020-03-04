#include <stdio.h>
int main()
{
	int s, i, ui, li, ch, f, d;

	s = sizeof(short);
	i = sizeof(int);
	li = sizeof(long int);
	ch = sizeof(char);
	f = sizeof(float);
	d = sizeof(double);
	printf ("Short=%d\n int=%d\n longint=%d\n char=%d\n float=%d\n double=%d\n",s, i, li, ch, f, d);

	return 0;
}
