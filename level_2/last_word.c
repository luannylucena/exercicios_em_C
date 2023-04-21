/*
Write a program that takes a string and displays its last word followed by a \n.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY                                                                              " | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
"                                             "
*/

#include <unistd.h>

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        int i = 0;

        while(argv[1][i] != '\0')
        {
            i++;
        }
        while( i-- > 0)
        {
            if(argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] >= 'a' && argv[1][i] <= 'z')
                {
                    while(argv[1][i] != ' ' && argv[1][i] != '\t' && i > 0) //i > 0 pq para não ultrapassar o 0, a posição da memória, pq se não ele vai passando e imprime lixo.
                    {
                        i--;
                        if(argv[1][i] == ' ' || argv[1][i] == '\t' || i == 0)
                            {
                                if(i == 0)
                                    write(1, &argv[1][i], 1); 
                                while(argv[1][i + 1] != '\0' && argv[1][i + 1] != ' ' && argv[1][i + 1] != ' ')
                                {
                                    write(1, &argv[1][i + 1], 1);
                                i++;
                                }
                                return(0);
                            }      
                    }
                  
                }
            if(argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                {
                    while(argv[1][i] != ' ' && argv[1][i] != '\t' && i > 0)
                    {
                        i--;
                        if(argv[1][i] == ' ' || argv[1][i] == '\t' || i == 0)
                            {
                                if(i == 0)
                                    write(1, &argv[1][i], 1); 
                                while(argv[1][i + 1] != '\0' && argv[1][i + 1] != ' ' && argv[1][i + 1] != ' ')
                                {
                                    write(1, &argv[1][i + 1], 1);
                                i++;
                                }
                                return(0);
                            }  
                           
                    }
                    
                }
        }
    }
    write(1, "\n", 1);
    return(0);
}