#include <stdio.h>
#include <stdlib.h>

void	find_subsets(int *set, int total, int size, int i, int target)
{
	int	sum;
	int	temp;

	sum = 0;
	temp = i;
    if (i >= total)
        return ;
	for (int j = 0; j < size; j++)
	{
		if (temp % 2 == 1)
			sum += set[j];
		temp /= 2;
	}
	if (sum == target)
	{
		temp = i;
		for (int j = 0; j < size; j++)
		{
			if (temp % 2 == 1)
				printf("%d ", set[j]);
			temp /= 2;
		}
		printf("\n");
	}
    find_subsets(set, total, size, i + 1, target);
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (1);

	int size = argc - 2;
	int target = atoi(argv[1]);
	int *set = malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
		set[i] = atoi(argv[i + 2]);
	int total = 1;
	for (int i = 0; i < size; i++)
		total *= 2;
	find_subsets(set, total, size, 0, target);
	free(set);
	return (0);
}