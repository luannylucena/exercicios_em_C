#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;

    if(argc != 2)
    {
        write(1, "\n", 1);
        return(1);
    }
    while(argv[1][i] == ' ' && argv[1][i] == '\t')
        i++;
    while(argv[1][i])
    {
        if(argv[1][i] == ' ' || argv[1][i] == '\t')
        {
            while(argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
                i++;
            if(!argv[1][i])
                break;
            write(1, "   ", 3);
        }
        if(argv[1][i] != ' ' || argv[1][i] != '\t')
            write(1, &argv[1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return(0);
}
