/*
Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/

#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0; //um contador para guardar o início da primeira palavra

    if(argc < 2)
    {
        write(1, "\n", 1);
        return(1);
    }
    while(argv[1][i] == ' ' || argv[1][i] == '\t') //se houver espaços no início da string, pulo todos eles.
        i++;
    j = i; //cheguei no início da palavra, então guardo a posição dela. Essa posição será usada posteriormente para imprimir a primeira palavra.
    while(argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0') //aqui vou passando pelo resto da palavra...
        i++;
    while(argv[1][i] == ' ' || argv[1][i] == '\t') //pulando espaços que separa a palavra da próxima
        i++;
    //AQUI ENTRA A GAMBIARRA PARA IMPRIMIR O ESPAÇO ANTES DA ÚLTIMA PALAVRA 
    if (argv[1][i] == '\0') //se só houver a primeira palavra
    {
        while(argv[1][j] != ' ' && argv[1][j] != '\t' && argv[1][j] != '\0')
        {
            write(1, &argv[1][j], 1); //escrevo a primeira palavra
            j++;
        }
        write(1, "\n", 1); //pq é da questão que precisa exibir o '\n' ao final da exibição.
        return (0); //e temrina o programa mais cedo.. 
    }
    while(argv[1][i] != '\0')
    {
        while(argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0') //esse while escreve a segunda palavra.
        {
            write(1, &argv[1][i], 1);
            i++; // (BIZU:  incrementos de i++, geralmente, só acontecem dentro de while! =])
        }
        while(argv[1][i] == ' ' || argv[1][i] == '\t') //pulo tudo que separa a segunda palavra da terciera ou do '\0'
            i++;
        if(argv[1][i] != '\0') //se não for ainda o fim, imprimo um espaço.
            write(1, " ", 1);
    }
    i = j; //pois aqui vou escrever a primeira palavra, que está na posição 'j'.
    write(1, " ", 1); //antes de escrever a primeira palavra, acrescento o espaço.
    while(argv[1][i] != ' ' && argv[1][i] != '\t')
    {
        write(1, &argv[1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return(0);
}
   
