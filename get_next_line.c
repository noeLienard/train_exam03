#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include <fcntl.h> 

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

int find_newline(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
    char *line;
    int i;
    int j;

    line = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!line)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i])
    {
        line[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        line[i + j] = s2[j];
        j++;
    }
    line[i + j] = '\0';
    free(s1);
    return (line);
}

int	main(void)
{
	int fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}