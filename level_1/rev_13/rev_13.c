#include <unistd.h>

//Escreva um programa que receba uma string e a exiba, substituindo cada uma de suas letras pela letra 13 espaços à frente em ordem alfabética.
//'z' torna-se 'm' e 'Z' torna-se 'M'. O caso permanece inalterado.

//A saída será seguida por uma nova linha.

//Se o número de argumentos não for 1, o programa exibe uma nova linha.

int main(int argc, char **argv)
{
    int i = 0;

    if(argc > 1) //pq aqui é maior que 1? 
    {
        while(argv[1][i])
        {
            if(argv[1][i] >= 'a' && argv[1][i] <= 'z') 
                argv[1][i] = (argv[1][i] - 'a' + 13) % 26 + 'a'; //pq módulo 26?m
            else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                argv[1][i] = (argv[1][i] - 'A' + 13) % 26 + 'A';
            write(1, &argv[1][i], 1);
            i++;
        }
        write(1, "\n", 1);
        return(0);
    }
}
