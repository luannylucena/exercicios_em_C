/*
Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/



#include <stdlib.h>
#include <stdio.h>
#define HEX "0123456789abcdef"



void print_hex(int num)
{
    if(num > 0)
    {
        print_hex(num / 16);
        int rest = num % 16;
        printf("%c", HEX[rest]);

    }
}

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        print_hex(atoi(argv[1]));
    }
    printf("\n");
    return(0);

}

