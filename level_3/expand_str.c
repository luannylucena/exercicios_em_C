#include <unistd.h>
/*
Examples:

$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
$>
____
*/


#include <unistd.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int i = 0;;
    int space;

    if (argc == 2)
    {
        while(argv[1][i] == ' ' || argv[1][i] == '\t') //pulo espaços iniciais
            i++;
        while(argv[1][i])
        {
            if(argv[1][i] == ' ' || argv[1][i] == '\t')
                space = 1; //verdadeiro para espaços.
            if(argv[1][i] != ' ' && argv[1][i] != '\t')
            {
                if(space) //se houver espaço
                    write(1, "   ", 3);
                space = 0; //é definida como 0 para indicar que não há espaços consecutivos após o caractere atual.
                write(1, &argv[1][i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}