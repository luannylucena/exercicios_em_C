#include <unistd.h>

//Escreva um programa chamado search_and_replace que receba 3 argumentos, o primeiro
//argumentos é uma string na qual substituir uma letra (2º argumento) por
//outro (3º argumento).

//Se o número de argumentos não for 3, apenas exiba uma nova linha.

//Se o segundo argumento não estiver contido no primeiro (a string)
//então o programa simplesmente reescreve a string seguida por uma nova linha.

int main(int argc, char **argv)
{
    int i = 0;

    if (argc == 4 && !argv[2][1] && !argv[3][1]) //verifica se tem 3 argumentos e se o segundo e terceiro argumentos têm comprimento igual a 1 (ex: argv[2][0]));
    {
        while (argv[1][i] != '\0')
        {
            if (argv[1][i] == argv[2][0]) //se o segundo argumento estiver contido no primeiro
            {
                argv[1][i] = argv[3][0]; //o primeiro recebe o terceiro argumento
            }
            write (1, &argv[1][i], 1); //então se escreve a string, seguido por uma nova linha. 
            i++;
        }
    }
    write (1, "\n", 1); //se o número de argumentos não for 3, somente escreva uma nova linha. 
}