#include <unistd.h>

void ft_putnbr(int num)
{
    char str[10] = "0123456789";

    if(num > 9)
        ft_putnbr(num/10);
    write(1, str[num%10], 1);
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