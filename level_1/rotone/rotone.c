// Escreva um programa que receba uma string e a exiba, substituindo cada uma de suas letras pela próxima em ordem alfabética.

//'z' torna-se 'a' e 'Z' torna-se 'A'. O caso permanece inalterado.

//A saída será seguida por um \n.

//Se o número de argumentos não for 1, o programa exibirá \n.

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void rotone(char *s)
{
    while(*s)
    {
        if((*s >= 'a' && *s <= 'y') || (*s >= 'A' && *s <= 'Y'))
            ft_putchar(*s + 1);
        else if((*s == 'z') || (*s == 'Z'))
            ft_putchar(*s - 25);
        else
            ft_putchar(*s);
        ++s;
    }
}

    int main(int argc, char **argv)
    {
        if(argc == 2)
            rotone(argv[1]);
        ft_putchar('\n');
        return(0);
    }
