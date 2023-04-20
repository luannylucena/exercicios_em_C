/*

Escreva um programa que receba uma string como parâmetro e imprima suas palavras na ordem inversa.
Uma "palavra" é uma parte da string delimitada por espaços e/ou tabulações, ou o
início/fim da string.

Se o número de parâmetros for diferente de 1, o programa exibirá
'\n'.

Nos parâmetros que vão ser testados, não haverá nenhum "adicional"
espaços (o que significa que não haverá espaços adicionais no início ou no
o final da string, e as palavras sempre serão separadas por exatamente um espaço).

Examples:
$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/
#include <unistd.h>

int main(int argc, char **argv)
{
	int start;
	int end;
	int i = 0;
		
	if(argc == 2)
	{   
		while(argv[1][i] != '\0')
			i++;
		while(i >= 0)
		{
			while( argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t')
				i--; //considerando que tem espaços e tabs no final
			end = i; //guardo a posição do final da palavra
			while(argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				i--; //ando até o próximo espaço
			start = i + 1; //guardo a posiçãod o espaço + 1, que é o caracter. que daí, é o star da palavra, não da string.
			int  flag; //quero se é a primeira palavra da string. 
			flag = start; //daí, declaro a flag. 
			while(start <= end)
			{
				write (1, &argv[1][start],1);
				start++;		
			}
			if (flag != 0) //0 é a posição do primeiro caracter da string. 
			{
				write(1, " ", 1); //se não for o primeiro, cooloco o espaço, pq vou ter mais palavras. 
			}
		}
	}
	write(1, "\n", 1);
    return(0);
}
