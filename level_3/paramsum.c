#include <unistd.h>

// void ft_putnbr(int n)
// {
//     char digit;

//     if(n >= 10)
//         ft_putnbr(n / 10);
//     digit = (n % 10) + '0';
//     write(1, &digit, 1);
// }

void ft_putnbr(int num)
{
    char str[10] = "01234567";

    if(num > 9)
        ft_putnbr(num / 10);
    write(1, &str[num % 10], 1);
}
int main(int argc, char **argv)
{
    (void) argv;

    ft_putnbr(argc - 1);
    write(1, "\n", 1);
    return(0);
}