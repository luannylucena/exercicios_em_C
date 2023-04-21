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

/* int main(int argc, char **argv)
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
} */



/* int ft_isalpha(char c)
{
	if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
		return 1;
	return 0;
}

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		int i = 0;

		while(argv[1][i] != '\0')
		{
			i++;
		}
		while(i-- > 0)
		{
			if(ft_isalpha(argv[1][i]) == 1) //entao, aqui encontrei onde temrina a palavra, pois não é um espaço.
			{
				while(ft_isalpha(argv[1][i]) == 1)
				{
					i--;
					if(argv[1][i] == ' ' || argv[1][i] == '\t' || i == 0)
					{
						if(i == 0)
							write(1, &argv[1][i], 1);
						while(ft_isalpha(argv[1][i + 1]) == 1)
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
} */

int main(int argc, char **argv)
{
	int i = 0;

	if(argc == 2)
	{
		while(argv[1][i] != '\0')
		{
			i++;
		}
		i--;
		while(argv[1][i] == ' ' || argv[1][i] == '\t' && i > 0) //volto os espaços que possam haver depos da palavra/ o i = 0 é para evitar lixo de memória
		{
			i--;
		}
		while(argv[1][i] != ' ' && argv[1][i] != '\t' && i >= 0) //paro na última letra da palavra. O i>=0 é para n]ao imprimri lixo.
		{
			i--;//então, ando até o começo da palavra
		}
		i++; //para ajustar e para rliteralmente na primeira letra.
		while(argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
		{
			write(1, &argv[1][i], 1);
			i++;
		}
		
	}
	write(1, "\n", 1);
	return(0);
}