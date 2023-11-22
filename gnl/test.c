#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	char *files[] = {"./testfiles/10lines.txt", "./testfiles/10lines_emptyfirst.txt", "./testfiles/10lines_emptyend.txt", "./testfiles/10lines_emptymiddle.txt", "./testfiles/1line_empty.txt", "./testfiles/3lines_empty.txt","falsename"};
	int	linelength[] = {10, 10, 10, 10, 1, 3, 0};
	int	i = 0;
	int	fd;

	fd = open("./testfiles/10lines.txt", O_RDONLY);
	while (i < 7)
	{
		printf("case: %s\n", files[i]);
		fd = open(files[i], O_RDONLY);
		if (fd == -1)
		{
			printf("error\n");
			return (0);
		}
		while (linelength[i]--)
			printf("%s",get_next_line(fd));
		close(fd);
		i++;
		printf("\n");
		printf("\n");
	}
}
