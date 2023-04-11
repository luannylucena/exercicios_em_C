#include <unistd.h>

// Escreva um programa que pegue uma string e a exiba, substituindo cada uma de suas letras pela letra 13 espaços à frente em ordem alfabética.

//'z' torna-se 'm' e 'Z' torna-se 'M'. O caso permanece inalterado.

//A saída será seguida por uma nova linha.

//Se o número de argumentos não for 1, o programa exibe uma nova linha.


//A cifra de César é uma técnica de criptografia simples em que cada letra em um texto é substituída por outra letra que 
//está um certo número de posições adiante no alfabeto. Nesse caso, o deslocamento é de 13 posições, o que significa que cada letra é 
//substituída pela letra que está 13 posições adiante dela.

//A linha de código "argv[1][i] = (argv[1][i] - 'a' + 13) % 26 + 'a';" implementa essa técnica de criptografia para caracteres minúsculos. Aqui está como ela funciona:

   // "argv[1][i]" é o caractere atual na string do primeiro argumento que está sendo processado no loop.
   //  "'a'" é o valor ASCII do caractere 'a', que é usado como base para converter o caractere atual em um número entre 0 e 25. Subtraindo 'a' do caractere atual, obtemos um valor de 0 a 25 que representa a posição da letra no alfabeto.
   // Adicionando 13 ao valor obtido na etapa anterior, estamos aplicando a cifra de César com um deslocamento de 13 posições. Se o valor resultante for maior que 25, precisamos aplicar a operação módulo 26 para garantir que ele esteja dentro do intervalo de 0 a 25.
   // Adicionando 'a' novamente ao valor resultante, estamos convertendo o valor de volta em um caractere minúsculo.

int main(int argc, char **argv)
{
    int i = 0;

    if(argc > 1) // garanto que tudo que for lixo ou que -1, por exemplo, não entra nesse caso. E verifica se tenho pelo menos 1 argumento.
    {
        while(argv[1][i])
        {
            if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
                argv[1][i] = (argv[1][i] - 'a' + 13) % 26 + 'a'; // cifra de cesár
            else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                argv[1][i] = (argv[1][i] - 'A' + 13) % 26 + 'A';
            write(1, &argv[1][i], 1);
            i++; // incrementa para passar pro próximo caractere na string.
        }
    }
    write(1, "\n", 1);
    return (0);
}