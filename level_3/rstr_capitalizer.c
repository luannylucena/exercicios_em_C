/*
Escreva um programa que receba uma ou mais strings e, para cada argumento, coloque o 
último caractere que é uma letra de cada palavra em maiúscula e o restante em minúscula, depois exiba o resultado seguido de um \n.

Uma palavra é uma seção de string delimitada por espaços/tabulações ou o início/fim da string. 
Se uma palavra tiver uma única letra, ela deve ser maiúscula.

Uma letra é um caractere no conjunto [a-zA-Z]

Se não houver parâmetros, exibe \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$

$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>
*/

#include <unistd.h>

void rstr_capitalizer(char *str)
{
    int i = 0;

    while(str[i])
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        if((str[i] >= 'a' && str[i] <= 'z') && (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
            str[i] -= 32;
        write(1, &str[i++], 1);
    }
}

    int main(int argc, char **argv)
    {
        int i;

        if(argc == 1)
            write(1, "\n", 1);
        else 
        {
            i = 1;
            while(i < argc)
            {
                rstr_capitalizer(argv[i]);
                write(1, "\n", 1);
                i = i + 1;
            }
        }
        return(0);
    }




