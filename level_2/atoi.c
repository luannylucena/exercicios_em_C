#include <stdio.h>

int	ft_atoi(const char *str)
{
    int i = 0;
    int nb = 0;
    int signal = 1;

    while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            signal = signal * (-1);
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return(nb * signal);
}

int main()
{
    int str;

    str = ft_atoi("-11113423");
    printf("%d", str);
    return(0);
}