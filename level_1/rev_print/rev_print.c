#include <unistd.h>

//Write a program that takes a string, and displays the string in reverse
//followed by a newline.

//If the number of parameters is not 1, the program displays a newline.

int main(int argc, char **argv)
{
    int i = 0;

    if(argc == 2)
    {
        while(argv[1][i])
            i = i + 1;
        while(i)
            write(1, &argv[--i], 1);
    }
    write(1, "\n", 1);
    return(0);
}