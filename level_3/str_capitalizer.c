/*Escreva um programa que receba uma ou várias strings e, para cada argumento,
coloca o primeiro caractere de cada palavra em maiúscula (se for uma letra, obviamente), coloca o restante em letras minúsculas e exibe o resultado na saída padrão, seguido por um \n.

Se uma palavra tiver apenas uma letra, ela deve ser
capitalizado.

Se não houver argumentos, o programa deve exibir \n.*/

#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0; //percorre a string dos argumentos
    int arg_i = 1; //percorre os argc, começa em 1 para pular o a.out.
    
    if(argc == 1) // se só tem o a.out
    {
        write(1, "\n", 1);
        return(1); //sai do programa
    }
    while(argv[arg_i]) //enquanto não acabaram os argumentos
    {
        i = 0;
        while(argv[arg_i][i]) //enquanto houver carcteres no argv[arg_i]
        {
            if((argv[arg_i][i] >= 'A' && argv[arg_i][i] <= 'Z') && (argv[arg_i][i - 1] != ' ' && argv[arg_i][i - 1] != '\t'))
            {
                argv[arg_i][i] = argv[arg_i][i] + 32; 
                write(1, &argv[arg_i][i], 1); // imprimimos essa letra
            } 
            else if((argv[arg_i][i] >= 'a' && argv[arg_i][i] <= 'z') && (argv[arg_i][i - 1] == ' ' && argv[arg_i][i - 1] == '\t')|| (i == 0))
            {
                argv[arg_i][i] = argv[arg_i][i] - 32;
                write(1, &argv[arg_i][i], 1);
            }
                
            else
                write(1, &argv[arg_i][i], 1);
            i++;
        }
        write(1, "\n", 1);
        arg_i++; //passa para o próximo argumento
    }
    return(0);
   
}