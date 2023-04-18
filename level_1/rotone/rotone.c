// Escreva um programa que receba uma string e a exiba, substituindo cada uma de suas letras pela próxima em ordem alfabética.

//'z' torna-se 'a' e 'Z' torna-se 'A'. O caso permanece inalterado.

//A saída será seguida por um \n.

//Se o número de argumentos não for 1, o programa exibirá \n.

#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    char aux; //para armazenar a letra nova

    if(argc == 2)
    {
        while(argv[1][i])
        {
            if(argv[1][i] >= 'a' && argv[1][i] <= 'y' || argv[1][i] >= 'A' && argv[1][i] <='Y')
            {
                aux = argv[1][i] + 1; //o aux vai virar a próxima letra.
                write(1, &aux, 1); //então, escreve a letra nova.

            }
            else if(argv[1][i] == 'z' || argv[1][i] == 'Z')
            {
                aux = argv[1][i] - 25;
                write(1, &aux, 1);
            }
            else
                write(1, &argv[1][i], 1);
            i++;
        }
        write(1, "\n", 1);
        return(0);
    }    
}