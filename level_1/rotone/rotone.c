// Escreva um programa que receba uma string e a exiba, substituindo cada uma de suas letras pela próxima em ordem alfabética.

//'z' torna-se 'a' e 'Z' torna-se 'A'. O caso permanece inalterado.

//A saída será seguida por um \n.

//Se o número de argumentos não for 1, o programa exibirá \n.

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void rotone(char *str)
{
    while(*str != '\0')
    {
        if((*str >= 'a' && *str <= 'y')|| (*str >= 'A' & *str <= 'Y'))
            ft_putchar(*str + 1);
        else if(*str == 'z' || *str == 'Z')
            ft_putchar(*str - 25);
        else
            ft_putchar(*str);
        ++str;
    }
}

int main(int argc, char **argv)
{
    if(argc == 2)
        rotone(argv[1]);
    write(1, "\n", 1);
    return(0);
}
