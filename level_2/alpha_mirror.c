/* Escreva um programa chamado alpha_mirror que receba uma string e exiba essa string depois de substituir cada caractere alfabético pelo caractere alfabético oposto, seguido por uma nova linha.

'a' torna-se 'z', 'Z' torna-se 'A'
'd' torna-se 'w', 'M' torna-se 'N'

Se o número de argumentos não for 1, exibe apenas uma nova linha.*/

#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;

    if(argc == 2)
    {
        while(argv[1][i])
        {
            if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
                argv[1][i] = 'z' - argv[1][i] + 'a';
            else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                argv[1][i] = 'Z' - argv[1][i] + 'A';
            write(1, &argv[1][i], 1);
            i++;          
        }
    }
    write(1, "\n", 1);
}