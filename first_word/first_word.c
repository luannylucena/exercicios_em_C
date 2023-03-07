#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;

    if(argc == 2)
    {
        //32 (espaço) e 9 (tab)
        while(argv[1][i] == 32 || argv[1][i] == 9);
            i++;
        while((argv[1][i] != 32 && argv[1][i] != 9) && argv[1][i]); //enquanto argc[1][i] não chegou até o final (existir);
        {
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}