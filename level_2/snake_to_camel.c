/*
Escreva um programa que receba uma única string no formato snake_case
e o converte em uma string no formato lowerCamelCase.

Uma string snake_case é uma string onde cada palavra está em letras minúsculas, separadas por um sublinhado "_".

Uma string lowerCamelCase é uma string onde cada palavra começa com uma letra maiúscula, exceto a primeira.

Examples:
$>./snake_to_camel "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./snake_to_camel "hello_world" | cat -e
helloWorld$
$>./snake_to_camel | cat -e
$

*/

int main(int argc, char **argv)
{
    int i = 0;

    if(argc == 2)
    {
        while(argv[1][i])
        {
            if(argv[1][i] == '_')
            {
                i++;
                argv[1][i] = argv[1][i] - ' '; //diminui um espaço de argv[1][i]
            }
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return(0);
}