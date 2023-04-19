
int	ft_atoi(const char *str)
{
    int i = 0;
    int nb = 0;
    int signal = 1;
    
    while(str[i] == ' ' || str[i] == '\t')
        i++;
    while(str[i] == '-' || str[i] == '+') //se for sinal
    {
        if(str[i] == '-')
            signal = signal * (-1);
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10  + (str[i] - '0'); 
        i++;
    }
    return(nb * signal);
}