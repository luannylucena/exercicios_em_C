/*
Escreva uma função que reverta (no local) uma string.

Ele deve retornar seu parâmetro.

Sua função deve ser declarada da seguinte forma: char *ft_strrev(char *str);

*/

#include <stdio.h>
#include <unistd.h>


#include <stdio.h>
#include <unistd.h>



char    *ft_strrev(char *str)
{
    int len = 0;
    int i = 0;
    char aux; 
    
    while (str[len])
        len++; 
    
    while (i < len) 
    {
        aux = str[i]; 
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