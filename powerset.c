#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include <fcntl.h>

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	powerset(int size, int target, int i, int *set)
{
	int	sum;
	int	n;

	sum = 0;
	n = i;
	if (i == size)
		return ;
	for (int j = 0; j < size; j++)
	{
		if (n % 2 == 1)
			sum += set[j];
        if (sum == target)
            break ;
		n /= 2;
	}
	if (sum == target)
	{
		for (int j = 0; j < size; j++)
		{
			if (n % 2 == 1)
				printf("%d ", set[j]);
			n /= 2;
		}
        printf("\n");
	}
	powerset(size, target, i + 1, set);
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (1);
	int size = argc - 2;
	int *set = malloc(sizeof(int) * size);
	if (!set)
		return (1);
	for (int i = 0; argv[i + 2]; i++)
		set[i] = ft_atoi(argv[i + 2]);
	powerset(size, ft_atoi(argv[1]), 1, set);
}