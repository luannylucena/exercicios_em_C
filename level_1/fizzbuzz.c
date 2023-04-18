#include <unistd.h>

void ft_write_number(int nb)
{
    /*Esse array é inicializado com os caracteres que representam os dígitos de 0 a 9 em ASCII. Essa tabela de conversão é utilizada para transformar os dígitos do número em caracteres que possam ser escritos na saída padrão.*/
    char str[10] = "0123456789"; 

    if(nb > 9)
        ft_write_number(nb / 10); //Essa operação tem o efeito de "separar" o último dígito do número e enviá-lo para a função "write" para ser impresso.
    write(1, &str[nb % 10], 1);
}

int main()
{
    int i = 1;

    while(i <= 100)
    {
        if(i % 15 == 0)
            write(1, "fizzbuzz", 8);
        else if(i % 3 == 0)
            write(1, "fizz", 4);
        else if(i % 5 == 0)
            write(1, "buzz", 4);
        else
            ft_write_number(i);
        i++;
        write(1, "\n", 1);
    }
}