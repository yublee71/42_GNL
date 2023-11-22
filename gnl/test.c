#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
//	char *files[] = {"./testfiles/10lines.txt", "./testfiles/10lines_emptyfirst.txt", "./testfiles/10lines_emptyend.txt", "./testfiles/10lines_emptymiddle.txt", "./testfiles/1line_empty.txt", "./testfiles/3lines_empty.txt","falsename"};
//	int	i = 0;
	int	fd;
	int j = 10;

	fd = open("./testfiles/10lines.txt", O_RDONLY);
	while(j--)
	{
		printf("%s", get_next_line(fd));
	}
/*
	while (i < 7)
	{
		fd = open(files[i], O_RDONLY);
		printf("case: %s\n", files[i]);
		if (fd == -1)
		{
			printf("error\n");
			return (0);
		}
		while (get_next_line(fd))
			printf("\"%s\"",get_next_line(fd));
		close(fd);
	}
	*/
}
