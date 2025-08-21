/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlienard <nlienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:03:22 by nlienard          #+#    #+#             */
/*   Updated: 2025/08/21 15:10:26 by nlienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *return_line(char *str)
{
    int i = 0;
    char *line;

    line = malloc(100000);
    while (str[i] && str[i] != '\n')
    {
        line[i] = str[i];
        i++;
    }
    line[i] = '\n';
    return (line);
}

char *read_until_newline(char *stash, int fd)
{
    char *buf;

    if (!stash)
        stash = malloc(1);
    if (!stash)
        return (NULL);
    while (1)
    {
        buf = malloc(BUFFER_SIZE + 1);
        if (!buf)
            return (NULL);
        int nb_read = read(fd, buf, BUFFER_SIZE);
        if (nb_read < 0)
            return (free(buf), NULL);
        if (nb_read == 0)
            return (free(buf), NULL);
        buf[nb_read] = '\0';
        stash = ft_strjoin(stash, buf);
        if (find_newline(buf))
            return (free(buf), stash);
        free(buf);
        
    }
}

char *clear_line(char *str)
{
    char *dest;
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i] && str[i] != '\n')
        i++;
    i++;
    dest = malloc(ft_strlen(&str[i]) + 1);
    while (str[i])
    {
        dest[j] = str[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return (dest);
}

char *get_next_line(int fd)
{
    char *buf;
    char *line;
    static char *stash = NULL;
    buf = read_until_newline(stash, fd);
    if (!buf)
        return (NULL);
    stash = clear_line(buf);
    if (!stash)
        return (NULL);
    return (return_line(buf));
}

// int	main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("sudoku.txt", O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }