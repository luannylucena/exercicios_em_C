#include <unistd.h>

/*
Escreva um programa que receba uma string e exiba sua última palavra seguida por um \n.

Uma palavra é uma seção de string delimitada por espaços/tabulações ou pelo início/fim de
a corda.

Se o número de parâmetros não for 1 ou não houver palavras, exiba uma nova linha.

*/

int main(int argc, char **argv)
{
	int i = 0;

	if(argc == 2)
	{
		while(argv[1][i])
		{
			i++;
		}
		i--;
		while(argv[1][i] == ' ' || argv[1][i] == '\t' && i > 0)
		{
			i++;
		}
		while(argv[1][i] != ' ' && argv[1][i] != '\t' && i >= 0)
		{
			i--;
		}
		i++;
		while(argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i])
		{
			white(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}