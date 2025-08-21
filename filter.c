/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlienard <nlienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:03:19 by nlienard          #+#    #+#             */
/*   Updated: 2025/08/21 13:03:20 by nlienard         ###   ########.fr       */
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

char *read_all()
{
    char *buf;
    char *line = malloc(1);
    int read_n;

    while (1)
    {
        buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buf)
            return (free(buf), NULL);
        read_n = read(0, buf, BUFFER_SIZE);
        if (read_n < 1)
            return (NULL);
        if (find_newline(buf) == 1 || read_n == 0)
        {
            line = ft_strjoin(line, buf);
            free(buf);
            break ;
        }
        line = ft_strjoin(line, buf);
        free(buf);
    }
    return (line);
}

void filter(char *line, char *arg)
{
    int i;
    int j;

    i = 0;
    while (line[i])
    {
        if (strncmp(&line[i], arg, ft_strlen(arg)) == 0)
        {
            j = 0;
            while (j < ft_strlen(arg))
            {
                write(1, "*", 1);
                j++;
                i++;
            }
        }
        else
        {
            write(1, &line[i], 1);
            i++;
        }
    }
}

int main(int argc, char **argv)
{
    char *line;

    if (argc != 2)
        return (1);
    line = read_all();
    filter(line, argv[1]);
}