/*
Escreva uma função que reverta (no local) uma string.

Ele deve retornar seu parâmetro.

Sua função deve ser declarada da seguinte forma: char *ft_strrev(char *str);

*/

#include <stdio.h>
#include <unistd.h>


int ft_strlen(char str)
{
    int i = 0;

    while(str[i])
        i++;
    return(i);
}

char *ft_strrev(char *str)
{
    int i = 0;
    int len;
    char str;

    len = ft_strlen(str);

    while(i <= len/2)
    {
        aux = str[i]
        str[i] = str[len - 1];
        str[len - 1] = aux; 
        i++;
        len--;
    }
    return(str);
}



int main(int argc, char **argv)
{
  char *novastr;

   if(argc != 2)
   {
       write(1,"\n", 1);
       return (1);
   }
   novastr = ft_strrev(argv[1]);
   printf("%s\n", novastr);
}