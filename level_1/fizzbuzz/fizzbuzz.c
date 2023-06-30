#include <unistd.h>

int ft_write_number(int number)
{
    char str[10] = "0123456789"; // array de caracteres

    // se for maior que 9, tem mais de 1 dígito. Então, a função chama recursivamnte a ela mesma, divididin o parâmetro 'num' por 10, removendo o último dígito, até que todos sejam processados.

    if (number > 9) 
        ft_write_number(number / 10);
    write(1, &str[number % 10], 1);
}

int main()
{
    int i = 1; //pq igual a 1?

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