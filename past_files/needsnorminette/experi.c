#include <stdlib.h>

/*
int main(void)
{
	char *s;
	char *temp;

	s = (char*)malloc(3);
	temp = s;
	s = (char*)malloc(5);
	free(temp);
}
*/

char *ft_malloc(char *s)
{
	char *temp;

	temp = s;
	s = (char*)malloc(5);
	free(temp);
	return (s);
}

int main(void)
{
	char *s;

	s = (char*)malloc(3);
	s = ft_malloc(s);
	free(s);
}
