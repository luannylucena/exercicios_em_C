/*
Escreva um programa que receba uma string e exiba essa string com exatamente um espaço entre as palavras, sem espaços ou 
tabulações no início ou no final, seguido por um \n.

Uma "palavra" é definida como parte de uma string delimitada por espaços/tabulações ou pelo início/fim da string.

Se o número de argumentos não for 1 ou se não houver palavras a serem exibidas, o programa exibirá \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>
*/

int main(int argc, char const *argv[])
{
    int i;
    int flag;

    if(argc == 2)
    {   
        i = 0;
        while(argv[1][i] == ' ' || argv[1][i] == '\t')
            i += 1;
        while(argv[1][i])
        {
            if(argv[1][i] == ' ' || argv[1][i] == '\t')
                flag = 1;
            if(argv[1][i] != ' ' || argv[1][i] != '\t')
            {
                if(flag)
                {
                    write(1, " ", 1);
                    flag = 0;
                    write(1, &argv[1][i], 1);
                }
            }
            i += 1;
        }
    }
    write(1, "\n", 1);
    return(0);
}