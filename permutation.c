#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include <fcntl.h> 

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

void bubble_sort(char *str)
{
    for (int i = 0; i < ft_strlen(str); i++)
    {
        for (int j = 0; j < ft_strlen(str) - i - 1; j++)
        {
            if (str[j] > str[j + 1])
            {
                int swap = str[j];
                str[j] = str[j + 1];
                str[j + 1] = swap;
            }
        }
    }
}

void swap(char *a, char *b)
{
    int swap;
    swap = *a;
    *a = *b;
    *b = swap;
}


void permutation(char *str, int r, int len)
{
    if (len == r)
    {
        printf("%s\n", str);
        return ;
    }
    for (int i = r; i <= len; i++)
    {
        swap(&str[r], &str[i]);
        permutation(str, r + 1, len);
        swap(&str[i], &str[r]);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    bubble_sort(argv[1]);
    permutation(argv[1], 0, ft_strlen(argv[1]) - 1);
}