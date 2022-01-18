#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void getline1(int fd)
{
	char *str = get_next_line(fd);
	printf("(%d) => (%s", fd, str);
	free(str);
}

void real_all(int fd)
{
	char *str;

	while ( (str = get_next_line(fd)))
	{
		printf("(%d) => (%s", fd, str);
		free(str);
	}
}

int main (int argc, char *argv[])
{
	int fd = open("test.txt", O_RDONLY);
	int fd1 = open("test1.txt", O_RDONLY);

	getline1(fd);
	getline1(fd1);
	getline1(fd);
	getline1(fd1);
	getline1(fd1);
	getline1(fd);
	getline1(fd1);
	real_all(fd);
	real_all(fd1);
	return 0;
}
