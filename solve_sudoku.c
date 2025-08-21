/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlienard <nlienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:55:03 by nlienard          #+#    #+#             */
/*   Updated: 2025/08/21 15:13:07 by nlienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd);

int	count_words(char const *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (j);
}

void	fill_split(char *dest, const char *s, int start, int k)
{
	int	j;

	j = 0;
	while (start < k)
	{
		dest[j] = s[start];
		start++;
		j++;
	}
	dest[j] = '\0';
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	int		start;
	char	**split;

	i = 0;
	k = 0;
	split = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!split)
		return (NULL);
	while (i < count_words(s, c))
	{
		while (s[k] == c)
			k++;
		start = k;
		while (s[k] != c && s[k])
			k++;
		split[i] = malloc(sizeof(char) * (k - start + 1));
		if (split[i] == NULL)
			return (NULL);
		fill_split(split[i], s, start, k);
		i++;
	}
	split[i] = NULL;
	return (split);
}

int *put_in_tab_int(char *line)
{
    int *sudoku = malloc(sizeof(int) * 9);
    char **split_line = ft_split(line, ' ');
    if (!split_line)
        return (0);
    for (int i = 0; split_line[i]; i++)
        sudoku[i] = atoi(split_line[i]);
    return (sudoku);
        
}

int main(int argc, char **argv)
{
    int fd = open("sudoku.txt", O_RDONLY);
    char *line;
    int i = 0;
    int **sudoku = malloc(sizeof(int *) * 9);
    if (!sudoku)
        return (0);
    while (i < 9)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        sudoku[i] = put_in_tab_int(line);
        free(line);
        i++;
    }
}