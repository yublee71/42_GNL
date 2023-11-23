#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("%zu\n", sizeof(int));
	printf("%zu\n", sizeof(long));
	printf("%zu\n", sizeof(long long));
	printf("%zu\n", sizeof(size_t));
	printf("%d\n", INT_MAX);
	printf("%lu\n", LONG_MAX);
}