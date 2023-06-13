#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa que receba duas strings representando dois inteiros estritamente positivos que caibam em um int.

Exiba seu maior denominador comum seguido por uma nova linha (é sempre um inteiro estritamente positivo).

Se o número de parâmetros não for 2, exibe uma nova linha.
*/

int main(int argc, char const *argv[])
{
    int string1 = atoi(argv[1]);
    int string2 = atoi(argv[2]);

    if(argc != 3)
    {
        printf("\n");
        return(0);
    }
    if(string1 <= 0 || string2 <= 0)
    {
        printf("\n");
        return(0);
    }
    while(string2 != 0)
    {
        int temporary = string2;
        string2 = string1 % string2;
        string1 = temporary;
    }
    printf("%d\n", string1);
    return(0);
}