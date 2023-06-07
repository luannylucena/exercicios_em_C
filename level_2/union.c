#include <unistd.h>
/*
Escreva um programa que receba duas strings e exiba, sem duplicações, os caracteres que aparecem em qualquer uma das strings.

A exibição será na ordem em que os caracteres aparecem na linha de comando e será seguida por um \n.

Se o número de argumentos não for 2, o programa exibirá \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
*/


/*
A função remove carcteres duplicados. Recebe três argumentos: "c" (o caractere a ser verificado), "str" (a string onde o caractere será procurado) e "index" 
(a posição atual do caractere na string). A função percorre a string do início até a posição "index", verificando se o caractere "c" já apareceu anteriormente 
na string. Se o caractere já tiver aparecido antes, a função retorna 0, indicando que o caractere atual deve ser ignorado. Se o caractere não tiver aparecido antes, 
a função retorna 1, indicando que o caractere atual deve ser mantido na string final.*/

int check(int c, char *str, int index)
{
	int i = 0;
	
	while(i < index) //index é a posição atual do caracter que está sendo procurado
	{
		if (str[i] == c)
			return 0; //Se o caractere já tiver aparecido antes, a função retorna 0, indicando que o caractere atual deve ser ignorado.
		i++;
	}
	return  1; //Se o caractere não tiver aparecido antes, a função retorna 1, indicando que o caractere atual deve ser mantido na string final.
}

int main(int argc, char **argv)
{	
	int i = 0;
	int j = 0;
	int k = 0;
	
	if (argc == 3)
	{
        //O primeiro while é responsável por encontrar o fim da string correspondente ao primeiro argumento.
		while(argv[1][i] != '\0')
		{
			i++;
		}
        /*O segundo while é responsável por copiar todos os caracteres do segundo argumento para o final do primeiro argumento.
		 No final dessa etapa, a string correspondente ao primeiro argumento contém a concatenação dos dois argumentos.*/
		while(argv[2][j] != '\0')
		{
            //Na primeira iteração do loop, o caractere na posição zero da segunda string é copiado para a posição i da primeira string. 
			//As variáveis i e j são então incrementadas em uma unidade para que apontem para a próxima posição nas respectivas strings.
			argv[1][i] = argv[2][j];
			i++;
			j++;
		}
		i--; //Após o final do loop, a variável i é decrementada em 1, para que ela aponte para o último caractere da string concatenada, 
		//já que antes da decrementação, a variável i apontava para o caractere nulo ('\0') que indica o fim da string concatenada.
		while(k <= i) // onde i é a posição do último caractere da string concatenada (resultado da concatenação das duas strings).
		{
            //Para cada caractere na string, a função check é chamada para verificar se ele é um caractere duplicado. 
			if(check(argv[1][k], argv[1], k) == 1) 
				write (1, &argv[1][k], 1); 
			k++;
		}
	}
	write (1, "\n", 1);
}