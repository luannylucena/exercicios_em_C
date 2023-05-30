/*
Escreva um programa que receba um int positivo e exiba seus fatores primos no
saída padrão, seguida por uma nova linha.

Os fatores devem ser apresentados em ordem crescente e separados por '*', para que
a expressão na saída fornece o resultado correto.

Se o número de parâmetros não for 1, simplesmente exiba uma nova linha.

A entrada, quando houver, será válida.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$

*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        int i = 1; //pq não existe primo igual a 1, mas pede essa tratativanos exemplos.
        int number = atoi(argv[1]); //transformo o argv em inteiro.

        //tratativa para o número 1.
        if(number == 1)
            printf("1");
        
        while(number >= i++) //já incrementa para virar 2
        {
            if(number % i == 0)
            {
                printf("%d", i);
                if(number != i) //tratativa para não imprimir um asterico a mais
                    printf("*");
                number /= i;

                i = 1; //reseto o i
            }
        }
    }
    printf("\n");
    return(0);
}