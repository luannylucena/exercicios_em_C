#include <unistd.h>

void ft_putnbr(int nb) 
{
    int ten; // será uma potência de 10 para permitir a impressão do nb
    char c; // char c que será usado para imprimir cada caractere do número

    ten = 1; // a potência de 10 começa com 1
    if (nb > 2147483647) // se estourar o int max
        return; // saímos dessa função
    while (ten <= nb / 10) //chegamos numa potência de 10 que seja do tamanho do número ex nb = 205 e ten - 100
        ten *= 10;
    while (ten / 10) // enquanto ainda tiver algo no ten
    {
        c = (nb / ten) + '0'; //pegamos cada um dos caracteres do nb
        write(1, &c, 1); // imprimimos esse caractere
        nb %= ten; // o número perde uma casa
        ten /= 10; // a dezena também
    }
    c = (nb % 10) + '0'; // imprimimos a última casa
    write(1, &c, 1); // imprimimos esse caractere
    write(1, "\n", 1); // colocamos a quebra de linha
}

int main (int argc, char **argv)
{
    (void)argv;

    if (argc == 1) // se o número dos args for só o a.out
    {
        write(1, "0\n", 2); // colocamos o 0 e a quebra de linha
        return (1); // saímos do programa
    }
    argc--; // descontamos o a.out
    ft_putnbr(argc); // imprimimos o argv
    return (0);  // saímos do programa
}