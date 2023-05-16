#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(char *src)
{
    int len = 0;
    int i = 0;
    char *dup;

    while(src[i] != '\0')
    {
        i++;
    }
    dup = malloc(sizeof(char)* (i + 1)); //o dup é que vou retornar e ela é o tamanho da minha src + 1 (para contar o nullo).
    if(dup == NULL)
        return(NULL);
    i = 0;
    while(src[i])
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return(dup);
}