/*
Escreva uma função que receba um byte e o imprima em binário SEM UMA NOVA LINHA NO FINAL.

Sua função deve ser declarada da seguinte forma:

void print_bits(unsigned char octet);

Exemplo, se passar 2 para print_bits, imprimirá "00000010"

*/

/* void ft_putnbr(int nb)
{
    char    *numeros = "0123456789";

    if (nb > 9)
        ft_putnbr(nb / 10);
    write(1, &numeros[nb % 10], 1);
}
 */

#include <unistd.h>

void print_bits(unsigned char octet)
{
    int qtd = 7; //pq já começo no 1, né..

    while(qtd >= 0) //esse while serve somente para parar a impressão do numero, posise snao ele vai continuar netrando no if e imprimindo infinito.
    {
        if((octet >> qtd & 1) == 0) //faço o &(e) com 1 pq se for 0 com aqualquer coisa é 0. o que importa no & é o 1.
            write(1, "0", 1);
        else
            write(1, "1", 1);
        qtd--;
    }
}

/* int main()
{
    print_bits(3);
    return(0);
 */