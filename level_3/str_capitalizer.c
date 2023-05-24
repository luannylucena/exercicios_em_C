/*Escreva um programa que receba uma ou várias strings e, para cada argumento,
coloca o primeiro caractere de cada palavra em maiúscula (se for uma letra, obviamente), coloca o restante em letras minúsculas e exibe 
o resultado na saída padrão, seguido por um \n.

Se uma palavra tiver apenas uma letra, ela deve ser
capitalizado.

Se não houver argumentos, o programa deve exibir \n.*/

/*Escreva um programa que receba uma ou várias strings e, para cada argumento,
coloca o primeiro caractere de cada palavra em maiúscula (se for uma letra, obviamente), coloca o restante em letras minúsculas e exibe 
o resultado na saída padrão, seguido por um \n.

Se uma palavra tiver apenas uma letra, ela deve ser capitalizado.

Se não houver argumentos, o programa deve exibir \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>

*/

#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0; 
    int arg_i = 1; // para pular o a.out

    if (argc == 1) 
    {
        write(1, "\n", 1); 
        return (1); 
    }
    while (argv[arg_i])
    {
        i = 0; 
        while (argv[arg_i][i]) // enquanto ainda houver caractere no argv[arg_i]
        {
            if ((argv[arg_i][i] >= 'A' && argv[arg_i][i] <= 'Z') && (argv[arg_i][i - 1] != ' ' && argv[arg_i][i - 1] != '\t')) 
            {
                argv[arg_i][i] += 32; 
                write(1, &argv[arg_i][i], 1); 
            }
            else if ((argv[arg_i][i] >= 'a' && argv[arg_i][i] <= 'z') && ((i > 0 && (argv[arg_i][i - 1] == ' ' || argv[arg_i][i - 1] == '\t')) || (i == 0)))
            {
                argv[arg_i][i] -= 32; 
                write(1, &argv[arg_i][i], 1); 
            }
            else 
                write(1, &argv[arg_i][i], 1); 
            i++;
        }
        write(1, "\n", 1); 
        arg_i++; 
    }
    return (0); 
}
