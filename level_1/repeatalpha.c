#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    char *str = "abcdefghijklmnopqrstuvwxyz";
    char *str2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (argc == 2)
    {
        while(argv[1][i] != '\0')
        {
            if((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
            {
                while(str[j] != '\0' && str2[j] != '\0')
                {
                    if(str[j] == argv[1][i] || str2[j] == argv[1][i]) // qdo eu encontrar vou ter um numero no J, ele que eu quero
                        break; // então eu paro aqui e saio do while.
                   
                    else
                        j++; //se nao for igual continuo percorrendo..
                }
                j++;
                while(j > 0)
                {
                    write(1, &argv[1][i], 1);
                    j--;
                } 
            }
            else
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return(0);
}