#include <unistd.h>

void ft_putnbr(int num)
{
    char str[10] = "0123456789";

    if(num > 9)
        ft_putnbr(num / 10);
    write(1, &str[num % 10], 1);
}

int ft_atoi(char *str)
{
    int i = 0;
    int signal = 1;
    int nb = 0;

    while(str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
        i++;
    while(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
        {
            signal *= (-1);
            i++;
        }
    }

    if(str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return(signal * nb);
}

int main(int argc, char **argv)
{
    int i = 0;
    int nb;

    if(argc != 2)
    {
        write(1, "\n", 1);
        return(0);
    }

    nb = ft_atoi(argv[1]);
    
    if(nb <= 0) //se for negativo ou igual a zero.
    {
        write(1, "\n", 1);
        return(0);
    }
    while(i < 10)
    {
        ft_putnbr(i); // colocamos o número do índice multiplicador
        write(1, " x ", 3); // espaço multiplicação e espaço
        ft_putnbr(nb); // colocamos o número 
        write(1, " = ", 3); // espaço igual e espaço
        ft_putnbr(i * nb); // colocamos o número do resultado da multiplicação
        write(1, "\n", 1); // colocamos a quebra de linha
        i++;  // repetimos 9 vezes
    }
    return(0);
}
