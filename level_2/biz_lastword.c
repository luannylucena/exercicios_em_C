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
		while(argv[1][i] == ' ' || argv[1][i] == '\t' && i > 0) //volto os espaços que possam haver depos da palavra.. e ponho i = 0 para evitar lixo de memória.
		{
			i--;
		}
		while(argv[1][i] != ' ' && argv[1][i] != '\t' && i >= 0) //paro na última letra da palavra e vou voltando. O i>=0 é para não imprimir lixo.
		{
			i--;//vou voltando até o começo da palavra
		}
		i++; //para ajustar e parar literalmente na primeira letra.
		while(argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i])
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}