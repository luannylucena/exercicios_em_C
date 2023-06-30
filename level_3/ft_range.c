#include <stdlib.h>
/*
Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/
#include <stdlib.h>

int *ft_range(int start, int end)
{
    int len;
    int *res;
    int step;
    int i;

    if (end >= start)
    {
        len = end - start;
        step = 1;
    }
    else
    {
        len = start - end;
        step = -1;
    }

    res = (int *)malloc(sizeof(int) * (len + 1));
    if (res == NULL)
        return NULL;

    i = 0;
    while (i <= len)
    {
        res[i] = start;
        start += step;
        i++;
    }

    return res;
}
