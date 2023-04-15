/*Escreva um programa que receba três strings:
- O primeiro e o terceiro são representações de números inteiros com sinal de base 10 que cabem em um int.
- O segundo é um operador aritmético escolhido entre: + - * / %

O programa deve exibir o resultado da operação aritmética solicitada,
seguido por uma nova linha. Se o número de parâmetros não for 3, o programa
apenas exibe uma nova linha.

Você pode assumir que a string não contém erros ou caracteres estranhos. Números negativos, na entrada ou na saída, 
terão um e apenas um '-' inicial. O resultado da operação cabe em um int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$*/

//atoi converte strings em números inteiros. (chAr TO Int)

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if(argc == 4)
    {
        if(argv[2][0] == '+')
            printf("%d", (atoi(argv[1]) + atoi(argv[3])));
        if(argv[2][0] == '-')
            printf("%d", (atoi(argv[1]) - atoi(argv[3])));
        if(argv[2][0] == '*')
            printf("%d", (atoi(argv[1]) * atoi(argv[3])));
        if(argv[2][0] == '/')
            printf("%d", (atoi(argv[1]) /  atoi(argv[3])));
    }
    printf("\n");
    return(0);
}