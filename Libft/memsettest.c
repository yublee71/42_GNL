#include <string.h>
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int array[4] = {0};
	memset(array, INT_MAX, 1); 
	for(int	i = 0; i < 4; i++)
		printf("%i\n", array[i]);
}
