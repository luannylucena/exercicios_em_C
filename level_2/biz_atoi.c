#include <unistd.h>

int ft_atoi(const char *str)
{
    int signal = 1;
    int i = 0;
    int nb = 0;

    while(str[i] == ' ' || str[i] == '\t')
        i++;
    while(str[i] == '+' || str[i] == '-')
    {
        if(signal == '-')
            signal = signal * -1;
        i++;   
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10 + (str[i] - '0');
        i++;    
    }
    return(nb * signal);
}


