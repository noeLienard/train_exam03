/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlienard <nlienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:51:37 by nlienard          #+#    #+#             */
/*   Updated: 2025/08/21 13:03:03 by nlienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void	powerset(int target, int size, int *set, int total, int i)
{
	int	sum;
	int	temp;

	sum = 0;
	if (i >= total)
		return ;
	temp = i;
	for (int j = 0; j < size; j++)
	{
		if (temp % 2 == 1)
			sum += set[j];
		temp /= 2;
	}
	temp = i;
	if (sum == target)
	{
		for (int j = 0; j < size; j++)
		{
			if (temp % 2 == 1)
				printf("%d ", set[j]);
			temp /= 2;
		}
		printf("\n");
	}
	powerset(target, size, set, total, i + 1);
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (1);

	int size = argc - 2;
	int target = atoi(argv[1]);
	int *set = malloc(sizeof(int) * size);
	int total = 1;

	for (int i = 0; i < size; i++)
		set[i] = atoi(argv[i + 2]);
	for (int i = 0; i < size; i++)
		total *= 2;
	powerset(target, size, set, total, 0);
	free(set);
	return (0);
}