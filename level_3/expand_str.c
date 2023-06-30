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


int is_space(char str)
{
    if (str == ' ' || str == '\t')
        return 1;
    else
        return 0;
}

int main(int argc, char const **argv)
{
	int i = 0;
	int flg = 0;

	if (argc == 2)
	{
		while(is_space(argv[1][i]))
			i++;
		while(argv[1][i])
		{
			if(is_space(argv[1][i]))
				flg = 1;
			else
			{
				if(flg)
					write(1, "   ", 3);
				flg = 0;
				write(1, &argv[1][i], 1);
			}
            ++i;
		}
	}
	write(1, "\n", 1);
	return (0);
}