/*
Escreva um programa que receba uma string e a exiba depois de girá-la uma palavra para a esquerda.

Assim, a primeira palavra passa a ser a última, e as demais ficam na mesma ordem.

Uma "palavra" é definida como parte de uma string delimitada por espaços/tabulações ou pelo início/fim da string.

As palavras serão separadas por apenas um espaço na saída.

Se houver menos de um argumento, o programa exibirá \n.

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

// Se houver menos de um argumento, o programa exibirá \n.

#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;

	if(argc >= 2)
	{
		while(argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		int start = i;

		while(argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0') //pulo a primeira palavra todinha
			i++;
		while(argv[1][i] == ' ' || argv[1][i] == '\t') //pulo todos os espaços entre a primeira e asegunda palavra, para nao imprimir espaços antes da primeira palavra.
			i++;
		while(argv[1][i])
		{
			write(1, &argv[1][i], 1);
			i++;
			if(argv[1][i] == ' ' || argv[1][i] == '\t' || argv[1][i] == '\0') // if para verificação de espaços a mais entre as palavras
			{
				write(1, " ", 1);
				while(argv[1][i] == ' ' || argv[1][i] == '\t') // para ignorar espaços ou tabs excedentes entre as palavras.
					i++;
			}
		}
		while(argv[1][start] != ' ' && argv[1][start] != '\t' && argv[1][start] != '\0') // pois a primeira palavra termina no espaço
		{
			write(1, &argv[1][start], 1);
			start++;
		}

	}
	write(1, "\n", 1);
	return(0);
}